#include "DanhBa.h"


int main() {
  DanhBa danhBa;
  danhBa.themDau("123", "Nguyen Van A", "123 ABC");
  danhBa.themDau("456", "Nguyen Van B", "456 DEF");
  danhBa.themCuoi("789", "Nguyen Van C", "789 GHI");
  danhBa.inDanhSach();
  danhBa.xoa("123");
  danhBa.inDanhSach();
  danhBa.timKiem("789");
  return 0;
}