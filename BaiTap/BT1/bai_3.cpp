#include <iostream>
#include <cmath>

struct Point {
  int x, y;
};

void input(Point &p) {
  std::cin >> p.x >> p.y;
}

void intput(Point a[], int &n) {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cout << "Nhap diem thu " << i + 1 << ": ";
    input(a[i]);
  }
}

void output(Point &p) {
  std::cout << "(" << p.x << ", " << p.y << ")";
}

void output(Point a[], int idx) {
  output(a[idx]);
}

double distance(Point &p) {
  return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

int maxDistance(Point a[], int n) {
  int idx = 0;
  double max = distance(a[0]);
  for (int i = 1; i < n; i++) {
    double d = distance(a[i]);
    if (d > max) {
      max = d;
      idx = i;
    }
  }
  return idx;
}

double distance(Point &p1, Point &p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void minDistance(Point a[], int n) {
  double min = distance(a[0], a[1]);
  int idx_1 = 0, idx_2 = 1;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i].x == a[j].x && a[i].y == a[j].y) {
        continue;
      }
      double d = distance(a[i], a[j]);
      if (d < min) {
        min = d;
        idx_1 = i;
        idx_2 = j;
      }
    }
  }
  std::cout << "b: ";
  output(a, idx_1);
  std::cout << " va ";
  output(a, idx_2);
  std::cout << std::endl;
}

void minRectangle(Point a[], int n) {
  int min_x = a[0].x, min_y = a[0].y;
  int max_x = a[0].x, max_y = a[0].y;
  for (int i = 1; i < n; i++) {
    if (a[i].x < min_x) {
      min_x = a[i].x;
    }
    if (a[i].y < min_y) {
      min_y = a[i].y;
    }
    if (a[i].x > max_x) {
      max_x = a[i].x;
    }
    if (a[i].y > max_y) {
      max_y = a[i].y;
    }
  }
  std::cout << "c: (" << min_x << ", " << max_y << "), (" << max_x << ", " << min_y << ")" << std::endl;
}

int main() {
  Point a[100];
  int n;
  intput(a, n);
  std::cout << "a: ";
  output(a, maxDistance(a, n));
  std::cout << std::endl;
  minDistance(a, n);
  minRectangle(a, n);
  return 0;
}