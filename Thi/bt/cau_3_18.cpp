#include <iostream>
#include <string>
#include <list>

class SinhVien {
  private:
    int maSo;
    std::string ten;
    int namSinh;
    std::string gioiTinh;
    double diemToan;
    double diemLy;
    double diemHoa;
    double diemTong;

  public:
    SinhVien(int maSo, std::string ten, int namSinh, std::string gioiTinh, double diemToan, double diemLy, double diemHoa)
      : maSo(maSo), ten(ten), namSinh(namSinh), gioiTinh(gioiTinh), diemToan(diemToan), diemLy(diemLy), diemHoa(diemHoa) {
      diemTong = diemToan + diemLy + diemHoa;
    }

    friend std::istream& operator>>(std::istream &in, SinhVien &sinhVien) {
      std::cout << "Nhap ma so: ";
      in >> sinhVien.maSo;
      std::cout << "Nhap ten: ";
      in.ignore();
      std::getline(in, sinhVien.ten);
      std::cout << "Nhap nam sinh: ";
      in >> sinhVien.namSinh;
      std::cout << "Nhap gioi tinh: ";
      in >> sinhVien.gioiTinh;
      std::cout << "Nhap diem toan: ";
      in >> sinhVien.diemToan;
      std::cout << "Nhap diem ly: ";
      in >> sinhVien.diemLy;
      std::cout << "Nhap diem hoa: ";
      in >> sinhVien.diemHoa;
      sinhVien.diemTong = sinhVien.diemToan + sinhVien.diemLy + sinhVien.diemHoa;
      return in;
    }

    friend std::ostream& operator<<(std::ostream &out, const SinhVien &sinhVien) {
      out << "Ma so: " << sinhVien.maSo << "\n";
      out << "Ten: " << sinhVien.ten << "\n";
      out << "Nam sinh: " << sinhVien.namSinh << "\n";
      out << "Gioi tinh: " << sinhVien.gioiTinh << "\n";
      out << "Diem toan: " << sinhVien.diemToan << "\n";
      out << "Diem ly: " << sinhVien.diemLy << "\n";
      out << "Diem hoa: " << sinhVien.diemHoa << "\n";
      out << "Diem tong: " << sinhVien.diemTong << "\n";
      return out;
    }

    int getMaSo() const { return maSo; }
    double getDiemTong() const { return diemTong; }
};

class QuanLySinhVien {
  private:
    std::list<SinhVien> sinhViens;

  public:
    void themSinhVien(const SinhVien &sinhVien) {
      sinhViens.push_back(sinhVien);
    }

    SinhVien* timSinhVienTheoMaSo(int maSo) {
      for (auto &sinhVien : sinhViens) {
        if (sinhVien.getMaSo() == maSo) {
          return &sinhVien;
        }
      }
      return nullptr;
    }

    void xoaSinhVienTheoMaSo(int maSo) {
      sinhViens.remove_if([maSo](const SinhVien &sinhVien) { return sinhVien.getMaSo() == maSo; });
    }

    void hienThiTatCaSinhVien() const {
      for (const auto &sinhVien : sinhViens) {
        std::cout << sinhVien << "\n";
      }
    }
};

int main() {
  QuanLySinhVien quanLy;

  SinhVien sinhVien1(1, "Nguyen Van A", 2000, "Nam", 8.5, 7.0, 9.0);
  SinhVien sinhVien2(2, "Tran Thi B", 2001, "Nu", 6.0, 8.0, 7.5);
  quanLy.themSinhVien(sinhVien1);
  quanLy.themSinhVien(sinhVien2);

  std::cout << "Tat ca sinh vien:\n";
  quanLy.hienThiTatCaSinhVien();

  SinhVien* sinhVienTimThay = quanLy.timSinhVienTheoMaSo(1);
  if (sinhVienTimThay) {
    std::cout << "Sinh vien tim thay:\n" << *sinhVienTimThay;
  } else {
    std::cout << "Khong tim thay sinh vien.\n";
  }

  quanLy.xoaSinhVienTheoMaSo(1);

  std::cout << "Tat ca sinh vien sau khi xoa:\n";
  quanLy.hienThiTatCaSinhVien();

  return 0;
}