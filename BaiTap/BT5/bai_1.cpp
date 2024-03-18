#include <windows.h>
#include "DanhBa.h"

using namespace std;

struct ThongTin {
  string soThueBao;
  string hoTen;
  string diaChi;
};

void nhapThongTin(ThongTin& thongTin) {
  cout << "Nhap so thue bao: ";
  cin >> thongTin.soThueBao;
  cin.ignore();
  cout << "Nhap ho ten: ";
  getline(cin, thongTin.hoTen);
  cout << "Nhap dia chi: ";
  getline(cin, thongTin.diaChi);
}

int main() {
  DanhBa danhBa;
  ThongTin thongtin;
  int choice;

  danhBa.themDau("123", "Nguyen Van A", "123 ABC");

  do {
    cout << "----------------" << endl;
    cout << "0. Thoat" << endl;
    cout << "1. In danh sach" << endl;
    cout << "2. Them vao dau" << endl;
    cout << "3. Them vao cuoi" << endl;
    cout << "4. Xoa" << endl;
    cout << "5. Tim kiem" << endl;
    cout << "----------------" << endl;

    cout << "Nhap lua chon: ";
    cin >> choice;
    switch (choice) {
      case 1:
        danhBa.inDanhSach();
        break;
      case 2:
        nhapThongTin(thongtin);
        danhBa.themDau(thongtin.soThueBao, thongtin.hoTen, thongtin.diaChi);
        break;
      case 3:
        nhapThongTin(thongtin);
        danhBa.themCuoi(thongtin.soThueBao, thongtin.hoTen, thongtin.diaChi);
        break;
      case 4:
        cout << "Nhap so thue bao can xoa: ";
        cin >> thongtin.soThueBao;
        danhBa.xoa(thongtin.soThueBao);
        break;
      case 5: 
        cout << "Nhap so thue bao can tim: ";
        cin >> thongtin.soThueBao;
        danhBa.timKiem(thongtin.soThueBao);
        break;
      default:
        break;
    }
  } while (choice != 0);
  
  
  return 0;
}