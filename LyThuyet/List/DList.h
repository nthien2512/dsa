template <class D>
class DList {
  private:
    struct Node {
      D data;
      Node* prev;
      Node* next;

      Node(D data, Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}
    };

    Node* head;
    Node* tail;

  public:
    DList() : head(nullptr), tail(nullptr) {}

    ~DList() {
      Node* node;
      while (head != nullptr) {
        node = head;
        head = head->next;
        delete node;
      }
    }

    void printList() const {
      for (Node* p = head; p != nullptr; p = p->next) {
        std::cout << p->data << std::endl;
      }
    }

    // O(1)
    void push_front(D x) {
      head = new Node(x, nullptr, head); // Insert new node

      // Update tail if necessary
      if (tail == nullptr) {
        tail = head;
      }
    }

    // O(n)
    void push_at(D x, int pos) {
      Node** pp = &head; // Pointer to pointer

      // Move to the position
      for (int i = 0; i < pos && *pp; ++i) {
        pp = &(*pp)->next; // Move to next pointer
      }

      Node* newNode = new Node(x, *pp ? (*pp)->prev : nullptr, *pp); // Insert new node
      *pp = newNode;
      if (newNode->next) {
        newNode->next->prev = newNode;
      }

      // If the new node is the last node, update tail
      if ((*pp)->next == nullptr) {
        tail = *pp; // Update tail if necessary
      }
    }

    // O(1)
    void push_back(D x) {
      Node** pp = &head; // Pointer to pointer

      // Move to the last node
      while (*pp) {
        pp = &(*pp)->next; // Move to next pointer
      }
      Node* newNode = new Node(x, tail); // Insert new node
      *pp = newNode;

      // Update tail
      tail = newNode;
    }

    // O(n)
    void pop_front() {
      if (head == nullptr) {
        return;
      }

      Node* node = head;
      head = head->next;
      delete node;

      // Update tail if necessary
      if (head == nullptr) {
        tail = nullptr;
      }
    }

    // O(n)
    void pop_at(int pos) {
      Node** pp = &head; // Pointer to pointer

      // Move to the position
      for (int i = 0; i < pos && *pp; ++i) {
        pp = &(*pp)->next; // Move to next pointer
      }
      if (*pp == nullptr) {
        return;
      }

      Node* node = *pp;
      *pp = node->next; // Update the pointer
      if (*pp) {
        (*pp)->prev = node->prev;
      }

      // Update tail if necessary
      if (node == tail) {
        tail = node->prev; // Update tail if necessary
      }
      delete node;  
    }

    // O(n)
    void pop_back() {
      if (head == nullptr) {
        return;
      }

      Node** pp = &head; // Pointer to pointer

      // Move to the last node
      while (*pp && (*pp)->next) {
        pp = &(*pp)->next; // Move to next pointer
      }

      Node* node = *pp;
      *pp = node->prev; // Update the pointer
      if (*pp) {
        (*pp)->next = nullptr;
      }

      // Update tail
      tail = *pp;
      delete node;
    }

    // O(n)
    bool search(D x) const {
      for (Node* p = head; p != nullptr; p = p->next) {
        if (p->data == x) {
          return true;
        }
      }
      return false;
    }
};