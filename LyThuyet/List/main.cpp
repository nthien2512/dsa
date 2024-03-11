#include "List.h"

int main() {
  Node A, B, C, D;
  A.elem = 40;
  A.next = &B;
  B.elem = 50;
  B.next = &C;
  C.elem = 70;
  C.next = &D;
  D.elem = 10;

  Node *p;
  return 0;
}