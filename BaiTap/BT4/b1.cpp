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
      Node *temp = new Node();
      temp->elem = a;
      if (head == NULL) {
        head = temp;
        trail = temp;
      } else {
        trail->next = temp;
        trail = temp;
      }
      num++;
    }

    void add_front(int a) {
      Node *temp = new Node();
      temp->elem = a;
      if (head == NULL) {
        head = temp;
        trail = temp;
      } else {
        temp->next = head;
        head = temp;
      }
      num++;
    }

    void insert(int x, int a) {
      Node *cur = head;
      while (cur != NULL) {
        if (cur->elem == x) {
          Node *temp = new Node();
          temp->elem = a;
          temp->next = cur->next;
          cur->next = temp;
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
          Node *temp = head;
          if (cur == head) {
            head = head->next;
            delete temp;
          } else {
            while (temp->next != cur) {
              temp = temp->next;
            }
            temp->next = cur->next;
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
  // 1 2 3 4

  l.add_front(-1);
  l.add_front(-2);
  // -2 -1 0 1 2 3 4

  l.insert(3, 0);
  l.insert(1, 7);
  // -2 -1 1 7 2 3 0 4

  l.remove(0);
  l.remove(7);
  // -2 -1 1 2 3 4

  Node *cur = l.head;
  while (cur != NULL) {
    std::cout << cur->elem << " ";
    cur = cur->next;
  }
  std::cout << std::endl;


  return 0;
}