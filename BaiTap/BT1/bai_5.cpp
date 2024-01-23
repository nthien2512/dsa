#include <iostream>

void swap(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  swap(&a, &b);
  std::cout << a << " " << b << std::endl;
  return 0;
}