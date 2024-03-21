#include "SList.h"

int main() {
  SList<int> list;

  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_back(4);
  list.printList();
  // 3 2 1 4

  list.erase(2);
  list.printList();
  // 3 1 4
  

  return 0;
}