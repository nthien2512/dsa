#include "Fraction.h"

int main() {
  #include <algorithm> // Include the necessary header file

  int n = 10;

  Fraction f1(1, 2), f2(3, 4);
  Fraction f[n];

  std::cout << f1 << " + " << f2 << " = " << f1 + f2 << '\n';
  std::cout << f1 << " - " << f2 << " = " << f1 - f2 << '\n';
  std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n';
  std::cout << f1 << " / " << f2 << " = " << f1 / f2 << '\n';

  std::cout << f1 << " + " << 5 << " = " << f1 + 5 << '\n';
  std::cout << f1 << " * " << 5 << " = " << f1 * 5 << '\n';
  return 0;
}