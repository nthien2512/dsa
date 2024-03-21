#include <iostream>

template <class T>
class SList {
  private:

    struct Node {
      T elem;
      Node* next;

      Node(T elem, Node* next = nullptr) : elem(elem), next(next) {}
    };

    Node* head;
    Node* trail;

  public:

    SList() : head(nullptr), trail(nullptr) {}

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

    void push_front(T x) {
      head = new Node(x, head);
      if (trail == nullptr) {
        trail = head;
      }
    }

    void push_back(T x) {
      Node* node = new Node(x);
      if (head == nullptr) {
        head = trail = node;
      } else {
        trail = trail->next = node;
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