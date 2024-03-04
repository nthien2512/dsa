#include <iostream>
#include <vector>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
} 

void increase(std::vector<int>& v, int n) {
  for (int i = 0; i < n - 1; i++) {
    int idx = i;
    for (int j = i + 1; j < n; j++) {
      if (v[j] < v[idx]) {
        idx = j;
      }
    }
    if (idx != i) {
      swap(v[i], v[idx]);
    }
  }
}

void decrease(std::vector<int>& v, int n) {
  for (int i = 0; i < n - 1; i++) {
    int idx = i;
    for (int j = i + 1; j < n; j++) {
      if (v[j] > v[idx]) {
        idx = j;
      }
    }
    if (idx != i) {
      swap(v[i], v[idx]);
    }
  }
}

int main() {
  int x, n = 5;
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    v.push_back(x);
  }

  int select;
  std::cout << "Chon phuong thuc sap xep (1 - Tang, 2- Giam): \n";
  std::cin >> select;
  switch (select) {
    case 1:
      increase(v, n);
      break;
    case 2:
      decrease(v, n);
      break;
    default:
      break;
  }
  
  for (int i = 0; i < n; i++) {
    std::cout << v[i] << " ";
  }
  return 0;
}