/**
 * Updated by thiendev.id.vn's author on August 17 2023
 * Github: https://github.com/@ntdev204
 * "A bit of fragrance clings to the hand that gives flowers!"
 */

#include <iostream>
#include <cmath>

class Point {
public:
  float x, y;

  void input() {
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
  }

  void inputPoint(std::string point) {
    std::cout << point << std::endl;
    input();
  }

  void display() {
    std::cout << "(" << x << ", " << y << ")\n";
  }

  float distance(Point d) {
    float dx = x - d.x;
    float dy = y - d.y;
    return std::sqrt(dx*dx + dy*dy);
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
};

int main() {
  Point p1, p2;
  p1.inputPoint("Enter point 1:");
  p2.inputPoint("Enter point 2:");
  p1.display();
  p2.display();
  std::cout << "Distance between " << p1 << " and " << p2 << " is " << p1.distance(p2) << std::endl;
  return 0;
}