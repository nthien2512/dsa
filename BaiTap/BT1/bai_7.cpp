#include <iostream>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  float x, s = 0, sum = 0;
  std::cin >> x;
  for (int i = 1; i <= n; i++) {
    sum += 1.0 / i;
    s += pow(-1, i - 1) * (pow(x, i) / sum);
  }
  std::cout << s;
  return 0;
}