// Quản lý Học Viên
// Xây dựng một lớp Student để mô tả thông tin về học viên bao gồm họ tên, tuổi, và điểm trung
// bình.
// Các phương thức gồm: - nhập thông tin của học viên từ bàn phím, in thông tin sách lên màn
// hình.
// Xây dựng hàm main nhập vào n học viên từ bàn phím, in thông tin các học viên vừa nhập lên
// màn hình.
// Thêm một phương thức để kiểm tra xem học viên có đỗ hay không (nếu điểm trung bình lớn hơn
// hoặc bằng 5.0).
// Lọc ra các học viên đỗ trong danh sách.
// Không dùng using namespace std;

#include <iostream>
#include <string>

class Student {
  private:
    std::string name;
    int age;
    float score;
  public:
    void input() {
      std::cout << "Nhap ten: ";
      std::cin >> name;
      std::cout << "Nhap tuoi: ";
      std::cin >> age;
      std::cout << "Nhap diem trung binh: ";
      std::cin >> score;
    }
    void output() {
      std::cout << "Ten: " << name << "\n";
      std::cout << "Tuoi: " << age << "\n";
      std::cout << "Diem trung binh: " << score << "\n";
    }
    bool isPass() {
      return score >= 5.0;
    }
};

int main() {
  int n;
  std::cout << "Nhap so hoc vien: ";
  std::cin >> n;
  Student* students = new Student[n];

  for (int i = 0; i < n; i++) {
    std::cout << "Nhap thong tin hoc vien " << i + 1 << ":\n";
    students[i].input();
  }
  std::cout << "\n";

  std::cout << "Danh sach hoc vien:\n";
  for (int i = 0; i < n; i++) {
    students[i].output();
  }
  std::cout << "\n";

  std::cout << "Hoc vien do:\n";
  for (int i = 0; i < n; i++) {
    if (students[i].isPass()) {
      students[i].output();
    }
  }

  delete[] students;
  return 0;
}