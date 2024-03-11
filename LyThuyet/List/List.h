#include <iostream>
#include <list>

class Node {
  public:
    int elem;
    Node *next;

    Node() {
      next = NULL;
    }
};