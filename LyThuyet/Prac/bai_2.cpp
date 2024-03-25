#include <windows.h>
#include "Tivi.h"

void menu() {
  std::cout << "----------- Menu -----------\n";
  std::cout << "1. Them tivi\n";
  std::cout << "2. Xoa tivi\n";
  std::cout << "3. Hien thi danh sach tivi\n";
  std::cout << "0. Thoat\n";
  std::cout << "-----------------------------\n";
  std::cout << "Lua chon: ";
}

int main() {
  Tivi tivi;
  int choice;
  system("cls");
  do {
    menu();
    std::cin >> choice;
    switch (choice) {
      case 1:
        system("cls");
        tivi.them();
        break;
      case 2: {
        system("cls");
        std::string maHang;
        std::cout << "Nhap ma hang tivi can xoa: ";
        std::cin >> maHang;
        tivi.xoa(maHang);
        std::cout << "Da xoa tivi co ma hang " << maHang << std::endl;
        break;
      }
      case 3:
        system("cls");
        tivi.display();
        break;
      default:
        std::cout << "Lua chon khong hop le\n";
    }
  } while (choice != 0);
  return 0;
}