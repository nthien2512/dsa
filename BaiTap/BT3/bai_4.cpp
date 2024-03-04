#include <iostream>
#include <vector>

class Point {
  public:
    float x, y;

    Point(int x, int y) {
      this -> x = x;
      this -> y = y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
      os << "(" << p.x << ", " << p.y << ")";
      return os;
    }
};

void input(std::vector<Point>& listPoint, int n) {
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cout << "Point " << i + 1 << ": ";
    std::cin >> x >> y;
    listPoint.push_back(Point(x, y));
  }
}

void display(const std::vector<Point>& listPoint) {
  auto it = listPoint.begin();
  while (it != listPoint.end()) {
    std::cout << *it;
    if (it != listPoint.end() - 1) {
      std::cout << ", ";
    }
    ++it;
  }
  std::cout << ".\n";
}

int main() {
  int n = 5;
  std::vector<Point> listPoint;
  input(listPoint, n);
  display(listPoint);
  return 0;
}