#include <iostream>

class Node {
  public: 
    int elem;
    Node *next;

    Node() {
      elem = 0;
      next = NULL;
    }
};

class List {
  public:
    Node *head, *trail;
    int num;

    List() {
      head = NULL;
      trail = NULL;
      num = 0;
    }

    void add_back(int a) {
      if (head == NULL) {
        head = trail = new Node();
        head->elem = a;
      } else {
        trail = trail->next = new Node();
        trail->elem = a;
      }
      num++;
    }

    void add_front(int a) {
      if (head == NULL) {
        head = trail = new Node();
        head->elem = a;
      } else {
        Node* oldHead = head;
        head = new Node();
        head->elem = a;
        head->next = oldHead;
      }
      num++;
    }

    void insert(int x, int a) {
      Node *cur = head;
      while (cur != NULL) {
        if (cur->elem == x) {
          Node *newNode = new Node();
          newNode->elem = a;
          newNode->next = cur->next;
          cur->next = newNode;
          num++;
          return;
        }
        cur = cur->next;
      }
    }

    void remove(int a) {
      Node *cur = head;
      while (cur != NULL) {
        if (cur->elem == a) {
          if (cur == head) {
            head = head->next;
            delete cur;
          } else {
            Node *prev = head;
            while (prev->next != cur) {
              prev = prev->next;
            }
            prev->next = cur->next;
            delete cur;
          }
          num--;
          return;
        }
        cur = cur->next;
      }
    }
};

int main() {
  List l;

  l.add_back(1);
  l.add_back(2);
  l.add_back(3);
  l.add_back(4);

  l.add_front(-1);
  l.add_front(-2);

  l.insert(3, 0);
  l.insert(4, 7);

  l.remove(0);
  l.remove(7);

  Node *cur = l.head;
  while (cur != NULL) {
    std::cout << cur->elem << " ";
    cur = cur->next;
  }
  std::cout << std::endl;

  return 0;
}