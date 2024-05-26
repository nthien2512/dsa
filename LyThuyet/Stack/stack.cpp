#include <iostream>
#include "StackArr.h"


void menu() {
  std::cout << "---------------\n";
  std::cout << "1. Push\n";
  std::cout << "2. Pop\n";
  std::cout << "3. Top\n";
  std::cout << "4. Size\n";
  std::cout << "5. Is empty\n";
  std::cout << "---------------\n";
}

int main() {
  StackArr s;
  int choice;
  do {
    menu();
    std::cin >> choice;
    switch (choice) {
      case 1:
        int x;
        std::cout << "Enter x: ";
        std::cin >> x;
        s.push(x);
        break;
      case 2:
        s.pop();
        std::cout << "Da xoa\n";
        break;
      case 3:
        std::cout << s.topElement() << std::endl;
        break;
      case 4:
        std::cout << s.size() << std::endl;
        break;
      case 5:
        std::cout << (s.isEmpty() ? "Empty" : "Not empty") << std::endl;
        break;
      default:
        break;
    }
  } while (choice != 0);
  return 0;
}