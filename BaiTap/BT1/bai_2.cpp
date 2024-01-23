#include <iostream>
#include <string>

void upper(std::string &s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] -= 32;
    }
  }
}

void lower(std::string &s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] += 32;
    }
  }
}

int main() {
  std::string s;
  std::cout << "Nhap chuoi: ";
  std::getline(std::cin, s);
  upper(s);
  std::cout << "Chuoi chuyen thanh chu hoa: " << s << std::endl;
  lower(s);
  std::cout << "Chuoi chuyen thanh chu thuong: " << s << std::endl;
  return 0;
}