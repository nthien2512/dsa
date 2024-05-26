#include <iostream>
#include <list>

using namespace std;

class NhanVien {
private:
  int maNV;
  string hoTen;
  int namSinh;
  double luong;

public:
  NhanVien() {}
  NhanVien(int maNV, string hoTen, int namSinh, double luong) {
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->namSinh = namSinh;
    this->luong = luong;
  }

  friend istream& operator>>(istream& is, NhanVien& nv) {
    cout << "Nhap ma nhan vien: ";
    is >> nv.maNV;
    cout << "Nhap ho ten: ";
    is.ignore();
    getline(is, nv.hoTen);
    cout << "Nhap nam sinh: ";
    is >> nv.namSinh;
    cout << "Nhap luong: ";
    is >> nv.luong;
    return is;
  }

  friend ostream& operator<<(ostream& os, NhanVien& nv) {
    os << "Ma nhan vien: " << nv.maNV << endl;
    os << "Ho ten: " << nv.hoTen << endl;
    os << "Nam sinh: " << nv.namSinh << endl;
    os << "Luong: " << nv.luong << endl;
    return os;
  }

  int getMaNV() const {
    return maNV;
  }
};

class QuanLyNhanVien {
private:
  list<NhanVien> dsNhanVien;

public:
  void themNhanVien(NhanVien nv) {
    dsNhanVien.push_back(nv);
  }

  void xoaNhanVienTheoMa(int maNV) {
    for (auto it = dsNhanVien.begin(); it != dsNhanVien.end(); ++it) {
      if ((*it).getMaNV() == maNV) {
        it = dsNhanVien.erase(it);
        break;
      }
    }
  }

  void inDanhSachNhanVien() {
    for (auto nv : dsNhanVien) {
      cout << nv << endl;
    }
  }

  NhanVien timKiemNhanVienTheoMa(int maNV) {
    for (auto nv : dsNhanVien) {
      if (nv.getMaNV() == maNV) {
        return nv;
      }
    }
    return NhanVien();
  }
};

int main() {
  QuanLyNhanVien qlnv;
  NhanVien nv1(1, "Nguyen Van A", 1990, 1000);
  NhanVien nv2(2, "Nguyen Van B", 1991, 2000);
  NhanVien nv3(3, "Nguyen Van C", 1992, 3000);
  qlnv.themNhanVien(nv1);
  qlnv.themNhanVien(nv2);
  qlnv.themNhanVien(nv3);

  qlnv.inDanhSachNhanVien();

  cout << "Nhap ma nhan vien can xoa: ";
  int maNV;
  cin >> maNV;
  qlnv.xoaNhanVienTheoMa(maNV);

  qlnv.inDanhSachNhanVien();

  cout << "Nhap ma nhan vien can tim: ";
  cin >> maNV;
  NhanVien nv = qlnv.timKiemNhanVienTheoMa(maNV);
  if (nv.getMaNV() != 0) {
    cout << nv << endl;
  } else {
    cout << "Khong tim thay nhan vien" << endl;
  }

  return 0;
}