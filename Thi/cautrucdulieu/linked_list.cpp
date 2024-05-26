// Khái niệm danh sách liên kết đơn
/*
Danh sách liên kết đơn (Singly Linked List) là một cấu trúc dữ liệu động,
trong đó các phần tử được liên kết với nhau theo một thứ tự tuyến tính.
*/

// Cấu trúc lớp của danh sách liên kết đơn

#include <iostream>

template <class S>
class Node {
  public:
    S data;
    Node* next;

    Node(S data, Node* next = nullptr) : data(data), next(next) {}
};

template <class S>
class SList {
  private:
    Node<S>* head;
    Node<S>* tail;

  public:
    SList() : head(nullptr), tail(nullptr) {}

    ~SList() {
      Node<S>* node;
      while (head != nullptr) {
        node = head;
        head = head->next;
        delete node;
      }
    }

    void printList() const {
      for (Node<S>* p = head; p != nullptr; p = p->next) {
        std::cout << p->data << std::endl;
      }
    }

    void push_front(S x) {
      head = new Node<S>(x, head);
      if (tail == nullptr) {
        tail = head;
      }
    }

    void push_at(S x, int pos) {
      Node<S>** pp = &head;
      for (int i = 0; i < pos && *pp; ++i) {
        pp = &(*pp)->next;
      }
      *pp = new Node<S>(x, *pp);
      if ((*pp)->next == nullptr) {
        tail = *pp;
      }
    }

    void push_back(S x) {
      Node<S>** pp = &head;
      while (*pp) {
        pp = &(*pp)->next;
      }
      *pp = new Node<S>(x);
      tail = *pp;
    }

    void erase(S x) {
      Node<S>** pp = &head;
      while (*pp && (*pp)->data != x) {
        pp = &(*pp)->next;
      }
      if (*pp) {
        Node<S>* toDelete = *pp;
        *pp = (*pp)->next;
        if (toDelete == tail) {
          tail = *pp;
        }
        delete toDelete;
      }
    }

    bool search(S x) const {
      for (Node<S>* p = head; p != nullptr; p = p->next) {
        if (p->data == x) {
          return true;
        }
      }
      return false;
    }
};