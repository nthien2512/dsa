#include <iostream>
#include <string>
#include <vector>

class Tivi {
  private:
    std::vector<Tivi> tivis;
    std::string maHang;
    std::string tenTivi;
    int donGia;
    int soLuong;

    const std::string& layMaHang() const {
      return maHang;
    }

  public:
    Tivi() : maHang(""), tenTivi(""), donGia(0), soLuong(0) {}

    Tivi(const std::string& maHang, const std::string& tenTivi, int donGia, int soLuong) 
      : maHang(maHang), tenTivi(tenTivi), donGia(donGia), soLuong(soLuong) {}

    friend std::istream& operator>>(std::istream& is, Tivi& tivi) {
      return is >> tivi.maHang >> tivi.tenTivi >> tivi.donGia >> tivi.soLuong;
    }

    friend std::ostream& operator<<(std::ostream& os, const Tivi& tivi) {
      return os << "Ma hang: " << tivi.maHang << "\nTen tivi: " << tivi.tenTivi 
                << "\nDon gia: " << tivi.donGia << "\nSo luong: " << tivi.soLuong;
    }

    void display() const {
      std::cout << "Danh sach tivi:\n";
      for (const auto& tivi : tivis) {
        std::cout << "------------------\n";
        std::cout << tivi << std::endl;
        std::cout << "------------------\n";
      }
    }

    void them() {
      Tivi tivi;
      bool isUnique;
      do {
        isUnique = true;
        std::cout << "Nhap thong tin tivi:\n";
        std::cout << "Nhap ma hang: ";
        std::cin >> tivi.maHang;
        for (const auto& existingTivi : tivis) {
          if (existingTivi.layMaHang() == tivi.maHang) {
            isUnique = false;
            std::cout << "Ma hang da ton tai. Vui long nhap lai.\n";
            break;
          }
        }
      } while (!isUnique);
      std::cout << "Nhap ten tivi: ";
      std::cin >> tivi.tenTivi;
      std::cout << "Nhap don gia: ";
      std::cin >> tivi.donGia;
      std::cout << "Nhap so luong: ";
      std::cin >> tivi.soLuong;
      tivis.push_back(tivi);
    }

    void xoa(const std::string& maHang) {
      for (auto it = tivis.begin(); it != tivis.end(); ++it) {
        if (it->layMaHang() == maHang) {
          tivis.erase(it);
          return;
        }
      }
      std::cout << "Khong tim thay tivi voi ma hang: " << maHang << std::endl;
    }
};