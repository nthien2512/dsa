#include <iostream>
#include <cmath>

int main() {
  long long gt;
  int n;
  std::cin >> n;
  float x, s = 0;
  std::cin >> x;
  for (int i = 0; i <= n; i++) {
    gt = 1;
    for (int j = 1; j <= i; j++) {
      gt *= j;
    }
    s += (pow(x, i) / gt);
  }
  std::cout << s;
}