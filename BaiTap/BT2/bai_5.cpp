/**
 * Updated by thiendev.id.vn's author on August 17 2023
 * Github: https://github.com/@ntdev204
 * "A bit of fragrance clings to the hand that gives flowers!"
 */

#include <iostream>
#include <string>

class Student {
  public:
    std::string name;
    int age;
    float score;
  public:
    void input() {
      std::cout << "Nhap ten: ";
      std::getline(std::cin >> std::ws, name);
      std::cout << "Nhap tuoi: ";
      std::cin >> age;
      std::cout << "Nhap diem trung binh: ";
      std::cin >> score;
    }
    void display() {
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
    students[i].display();
  }
  // std::cout << "\n";

  std::cout << "Hoc vien do:\n";
  for (int i = 0; i < n; i++) {
    if (students[i].isPass()) {
      students[i].display();
    }
  }

  delete[] students;
  return 0;
}