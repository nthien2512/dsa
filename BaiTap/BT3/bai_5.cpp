#include <iostream>
#include <vector>

int main() {
  int k, n = 5;
  std::vector<int> v;

  std::cout << "Nhap danh sach: ";
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    v.push_back(x);
  }

  std::cout << "Truoc khi xoa: ";
  for (int i : v) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  std::cout << "Phan tu can xoa: ";
  std::cin >> k;

  for (std::vector<int>::iterator it = v.begin(); it != v.end();) {
    *it == k ? it = v.erase(it) : ++it; 
  }

  std::cout << "Sau khi xoa: ";
  for (int i : v) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}