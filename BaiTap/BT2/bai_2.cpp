#include <iostream>
#include <cmath>

class Point {
public:
  float x, y;

  void input(const std::string& point) {
    std::cout << point << "\nEnter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
  }

  void display() const {
    std::cout << "(" << x << ", " << y << ")\n";
  }

  float distance(const Point& d) const {
    float dx = x - d.x;
    float dy = y - d.y;
    return std::sqrt(dx*dx + dy*dy);
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
  }
};

int main() {
  Point p1, p2;
  p1.input("Enter point 1:");
  p2.input("Enter point 2:");
  std::cout << "Point 1: ";
  p1.display();
  std::cout << "Point 2: ";
  p2.display();
  std::cout << "Distance between " << p1 << " and " << p2 << " is " << p1.distance(p2) << std::endl;
  return 0;
}