template <class S>
class SList {
  private:
    struct Node {
      S data;
      Node* next;

      Node(S data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;
    Node* tail;

  public:
    SList() : head(nullptr), tail(nullptr) {}

    ~SList() {
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
    void push_front(S x) {
      head = new Node(x, head); // Insert new node

      // Update tail if necessary
      if (tail == nullptr) {
        tail = head;
      }
    }

    // O(n)
    void push_at(S x, int pos) {
      Node** pp = &head; // Pointer to pointer

      // Move to the position
      for (int i = 0; i < pos && *pp; ++i) {
        pp = &(*pp)->next; // Move to next pointer
      }
      *pp = new Node(x, *pp); // Insert new node

      // If the new node is the last node, update tail
      if ((*pp)->next == nullptr) {
        tail = *pp; // Update tail if necessary
      }
    }

    // O(1)
    void push_back(S x) {
      Node** pp = &head; // Pointer to pointer

      // Move to the last node
      while (*pp) {
        pp = &(*pp)->next; // Move to next pointer
      }

      *pp = new Node(x); // Insert new node
      tail = *pp; // Update tail
    }

    // O(1)
    void erase(S x) {
      Node** pp = &head; // Pointer to pointer

      // Move to the node to delete
      while (*pp && (*pp)->data != x) {
        pp = &(*pp)->next; // Move to next pointer
      }

      // Delete the node
      if (*pp) {
        Node* toDelete = *pp; // Node to delete
        *pp = (*pp)->next; // Update the pointer

        // Update tail if necessary
        if (toDelete == tail) {
          tail = *pp; // Update tail if necessary
        }
        delete toDelete;
      }
    }

    // O(n)
    bool search(S x) const {
      // Search for x
      for (Node* p = head; p != nullptr; p = p->next) {
        // If found, return true
        if (p->data == x) {
          return true;
        }
      }
      return false;
    }
};