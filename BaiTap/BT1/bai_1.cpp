#include <iostream>

bool isRightTriangle(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) {
    if (a + b <= c || b + c <= a || c + a <= b) {
      if (a * a + b * b != c * c || a * a + c * c != b * b || b * b + c * c != a * a) {
        return false;
      }
      return false;
    }
    return false;
  }
  return true;
}

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (isRightTriangle(a, b, c)) {
    std::cout << "Day la 3 canh tam giac vuong" << std::endl;
  } else {
    std::cout << "Day khong phai la 3 canh tam giac vuong" << std::endl;
  }
  return 0;
}