#include <iostream>
#include "SList.h"
#include "Point.h"

int main() {
  SList<Point<double>> listPoint;

  Point p1(1.0, 2.0);
  Point p2(2.0, 2.5);
  Point p3(3.4, 2.7);

  listPoint.push_back(p1);
  listPoint.push_front(p2);
  listPoint.push_back(p3);
  listPoint.printList();
  listPoint.erase(p2);
  listPoint.printList();
  

  return 0;
}