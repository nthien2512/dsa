#include <iostream>
#include <string>
#include <vector>


class Tivi {
  private:
    std::vector<Tivi> tivis;
    std::string maHang;
    std::string hangSX;
    std::string tenTivi;
    long long donGia;
    int soLuong;

  public:
    Tivi() : maHang(""), hangSX(""), tenTivi(""), donGia(0), soLuong(0) {}

    Tivi(const std::string& maHang, const std::string& hangSX, const std::string& tenTivi, int donGia, int soLuong) 
      : maHang(maHang), hangSX(hangSX), tenTivi(tenTivi), donGia(donGia), soLuong(soLuong) {}

    void display() {
      std::cout << "Danh sach tivi:\n";
      for (auto& tivi : tivis) {
        std::cout << "-------------------------------\n";
        std::cout << "Ma hang: " << tivi.maHang 
                  << "\nHang SX: " << tivi.hangSX 
                  << "\nTen tivi: " << tivi.tenTivi 
                  << "\nDon gia: " << tivi.donGia 
                  << "\nSo luong: " << tivi.soLuong;
        std::cout << "\n-------------------------------\n";
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
        std::cout << "Nhap hang SX: ";
        std::cin >> tivi.hangSX;
        for (auto& existingTivi : tivis) {
          if (existingTivi.maHang == tivi.maHang) {
            isUnique = false;
            std::cout << "Ma hang da ton tai. Vui long nhap lai.\n";
            break;
          }
        }
      } while (!isUnique);
      std::cin.ignore();
      std::cout << "Nhap ten tivi: ";
      getline(std::cin, tivi.tenTivi);
      std::cout << "Nhap don gia: ";
      std::cin >> tivi.donGia;
      std::cout << "Nhap so luong: ";
      std::cin >> tivi.soLuong;
      tivis.push_back(tivi);
    }

    void xoa(std::string& maHang) {
      for (auto it = tivis.begin(); it != tivis.end(); ++it) {
        if (it->maHang == maHang) {
          tivis.erase(it);
        }
      }
      std::cout << "Khong tim thay tivi voi ma hang: " << maHang << "\n";
    }

    long long sum(std::string& hangSX) {
      long long sum = 0;
      for (auto& tivi : tivis) {
        if (tivi.hangSX == hangSX && tivi.soLuong > 0) {
          sum += tivi.donGia * tivi.soLuong;
        }
      }
      return sum;
    }
};