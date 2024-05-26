#include <iostream>
#include <vector>
#include <string>

class Laptop {
  private:
    std::string nhaSanXuat;
    std::string model;
    std::string cauHinh;
    double gia;
    int soLuong;

  public:
    Laptop(std::string nhaSanXuat, std::string model, std::string cauHinh, double gia, int soLuong)
      : nhaSanXuat(nhaSanXuat), model(model), cauHinh(cauHinh), gia(gia), soLuong(soLuong) {}

    friend std::istream& operator>>(std::istream &in, Laptop &laptop) {
      std::cout << "Nhap nha san xuat: ";
      in >> laptop.nhaSanXuat;
      std::cout << "Nhap model: ";
      in >> laptop.model;
      std::cout << "Nhap cau hinh: ";
      in >> laptop.cauHinh;
      std::cout << "Nhap gia: ";
      in >> laptop.gia;
      std::cout << "Nhap so luong: ";
      in >> laptop.soLuong;
      return in;
    }

    friend std::ostream& operator<<(std::ostream &out, const Laptop &laptop) {
      out << "Nha san xuat: " << laptop.nhaSanXuat << "\n";
      out << "Model: " << laptop.model << "\n";
      out << "Cau hinh: " << laptop.cauHinh << "\n";
      out << "Gia: " << laptop.gia << "\n";
      out << "So luong: " << laptop.soLuong << "\n";
      return out;
    }

    std::string getNhaSanXuat() const { return nhaSanXuat; }
    std::string getModel() const { return model; }
    std::string getCauHinh() const { return cauHinh; }
    double getGia() const { return gia; }
    int getSoLuong() const { return soLuong; }
};

class QuanLyLaptop {
  private:
    std::vector<Laptop> laptops;

  public:
    void themLaptop(const Laptop &laptop) {
      laptops.push_back(laptop);
    }

    double tinhTongGiaTriTheoNhaSanXuat(const std::string &nhaSanXuat) const {
      double tong = 0;
      for (const auto &laptop : laptops) {
        if (laptop.getNhaSanXuat() == nhaSanXuat) {
          tong += laptop.getGia() * laptop.getSoLuong();
        }
      }
      return tong;
    }

    void lietKeLaptopTheoKichThuocManHinh(const std::string &kichThuocManHinh) const {
      for (const auto &laptop : laptops) {
        if (laptop.getCauHinh().find(kichThuocManHinh) != std::string::npos) {
          std::cout << laptop;
        }
      }
    }

    Laptop* timKiemLaptopTheoModel(const std::string &model) {
      int left = 0;
      int right = laptops.size() - 1;

      while (left <= right) {
        int mid = left + (right - left) / 2;
        std::string midModel = laptops[mid].getModel();

        if (midModel == model) {
          return &laptops[mid];
        } else if (midModel < model) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      return nullptr;
    }

    void hienThiTatCaLaptop() const {
      for (const auto &laptop : laptops) {
        std::cout << laptop;
      }
    }
};

int main() {
  QuanLyLaptop quanLy;
  Laptop laptop1("Dell", "XPS13", "Intel i7, 16GB RAM, 512GB SSD, 13 inch", 1200, 10);
  Laptop laptop2("HP", "Spectre x360", "Intel i5, 8GB RAM, 256GB SSD, 13 inch", 1000, 15);
  quanLy.themLaptop(laptop1);
  quanLy.themLaptop(laptop2);

  std::cout << "Tong gia tri cua cac laptop Dell: $" << quanLy.tinhTongGiaTriTheoNhaSanXuat("Dell") << "\n";

  std::cout << "Cac laptop co kich thuoc man hinh 13 inch:\n";
  quanLy.lietKeLaptopTheoKichThuocManHinh("13 inch");

  Laptop* laptopTimThay = quanLy.timKiemLaptopTheoModel("Spectre x360");
  if (laptopTimThay) {
    std::cout << "Tim thay laptop:\n" << *laptopTimThay;
  } else {
    std::cout << "Khong tim thay laptop.\n";
  }

  std::cout << "Tat ca cac Laptop:\n";
  quanLy.hienThiTatCaLaptop();

  return 0;
}