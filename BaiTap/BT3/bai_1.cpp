#include <iostream>
#include <vector>

int main() {
  int x, n = 5, sum = 0;
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    v.push_back(x);
    sum += v[i];
  }
  std::cout << sum;
  return 0;
}