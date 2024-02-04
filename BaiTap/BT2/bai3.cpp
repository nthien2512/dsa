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

class Triangle {
public:
  Point a, b, c;


  void input() {
    a.inputPoint("Enter point A:");
    b.inputPoint("Enter point B:");
    c.inputPoint("Enter point C:");
  }



  void display() {
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;
  }

  float area() {
    float ab = a.distance(b);
    float bc = b.distance(c);
    float ca = c.distance(a);
    float p = (ab + bc + ca) / 2.0;
    return std::sqrt(p * (p - ab) * (p - bc) * (p - ca));
  }

  float perimeter() {
    float ab = a.distance(b);
    float bc = b.distance(c);
    float ca = c.distance(a);
    return ab + bc + ca;
  }
};

int main() {
  Triangle t;
  t.input();
  t.display();
  std::cout << "Area: " << t.area() << std::endl;
  std::cout << "Perimeter: " << t.perimeter() << std::endl;
  return 0;
}