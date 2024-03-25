template <class T>
class SList {
  private:

    struct Node {
      T elem;
      Node* next;

      Node(T elem, Node* next = nullptr) : elem(elem), next(next) {}
    };

    Node* head;
    Node* tail;

  public:

    SList() : head(nullptr), tail(nullptr) {}

    ~SList() {
      while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
      }
    }

    void printList() {
      for (Node* p = head; p != nullptr; p = p->next) {
        std::cout << p->elem << std::endl;
      }
    }

    // Add point to the front of the list
    void push_front(T x) {
      Node* p = new Node(x, head);
      head = p;
      if (tail == nullptr) {
        tail = p;
      }
    }

    void push_back(T x) {
      Node* p = new Node(x);
      if (head == nullptr) {
        head = tail = p;
      } else {
        tail = tail->next = p;
      }
    }

    void erase(T x) {
      Node* p = head;
      Node* prev = nullptr;
      while (p != nullptr && p->elem != x) {
        prev = p;
        p = p->next;
      }
      if (p != nullptr) {
        if (prev == nullptr) {
          head = p->next;
        } else {
          prev->next = p->next;
        }
        delete p;
      }
    }
};