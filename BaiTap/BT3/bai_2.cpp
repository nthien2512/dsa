#include <iostream>
#include <vector>

int main() {
  int k, x, count, n = 5;
  std::cout << "Nhap x: ";
  std::cin >> x;
  std::vector<int> v;
  std::cout << "Nhap phan tu: ";
  for (int i = 0; i< n; i++) {
    std::cin >> k;
    v.push_back(k);
    if (x == v[i]) {
      count++;
    }
  }
  std::cout << "So lan x xuat hien: " << count;
  return 0;

}