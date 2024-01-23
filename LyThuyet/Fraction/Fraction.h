#include <iostream>

class Fraction {
  private:
    int ts_, ms_;
  public:
    // Hàm khởi tạo mặc định
    Fraction(int ts = 0, int ms = 1) : ts_(ts), ms_(ms) {}

    // Hàm sao chép
    Fraction(const Fraction& f) : ts_(f.ts_), ms_(f.ms_) {}

    // Hàm rút gọn phân số
    Fraction compact() {
      int a = ts_, b = ms_;
      while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
      }
      Fraction res(ts_ / a, ms_ / a);
      return res;
    }

    // Hàm hủy
    Fraction& operator=(const Fraction& f) {
      ts_ = f.ts_;
      ms_ = f.ms_;
      return *this;
    }

    // Phép cộng 2 phân số
    Fraction operator+(const Fraction& f) {
      Fraction res;
      res.ts_ = ts_ * f.ms_ + f.ts_ * ms_;
      res.ms_ = ms_ * f.ms_;
      return res;
    }

    // Phép trừ 2 phân số
    Fraction operator-(const Fraction& f) {
      Fraction res;
      res.ts_ = ts_ * f.ms_ - f.ts_ * ms_;
      res.ms_ = ms_ * f.ms_;
      return res;
    }

    // Phép nhân 2 phân số
    Fraction operator*(const Fraction& f) {
      Fraction res;
      res.ts_ = ts_ * f.ts_;
      res.ms_ = ms_ * f.ms_;
      return res;
    }

    // Phép chia 2 phân số
    Fraction operator/(const Fraction& f) {
      Fraction res;
      res.ts_ = ts_ * f.ms_;
      res.ms_ = ms_ * f.ts_;
      return res;
    }

    // Phép cộng 1 phân số với 1 số nguyên
    Fraction operator+(int x) {
      Fraction res;
      res.ts_ = ts_ + x * ms_;
      res.ms_ = ms_;
      return res;
    }

    // Phép nhân 1 phân số với 1 số nguyên
    Fraction operator*(int x) {
      Fraction res;
      res.ts_ = ts_ * x;
      res.ms_ = ms_;
      return res;
    }

    // Phân số lũy thừa
    Fraction operator^(int n) {
      Fraction res(1, 1);
      for (int i = 0; i < n; ++i) {
        res = res * (*this);
      }
      return res;
    }

    // Phân số nghịch đảo
    Fraction operator!() {
      Fraction res(ms_, ts_);
      return res;
    }

    // Phân số đối
    Fraction operator-() {
      Fraction res(-ts_, ms_);
      return res;
    }

    // Tổng các phân số trong mảng
    static Fraction sum(Fraction* arr, int n) {
      Fraction res;
      for (int i = 0; i < n; ++i) {
        res = res + arr[i];
      }
      return res;
    }

    // Phân số lớn nhất trong mảng
    static Fraction max(Fraction* arr, int n) {
      Fraction res = arr[0];
      for (int i = 1; i < n; ++i) {
        if (res.ts_ * arr[i].ms_ < res.ms_ * arr[i].ts_) {
          res = arr[i];
        }
      }
      return res;
    }

    // Phân số nhỏ nhất trong mảng
    static Fraction min(Fraction* arr, int n) {
      Fraction res = arr[0];
      for (int i = 1; i < n; ++i) {
        if (res.ts_ * arr[i].ms_ > res.ms_ * arr[i].ts_) {
          res = arr[i];
        }
      }
      return res;
    }

    // Hàm so sánh 2 phân số
    bool operator<(const Fraction& f) {
      return ts_ * f.ms_ < ms_ * f.ts_;
    }
    bool operator>(const Fraction& f) {
      return ts_ * f.ms_ > ms_ * f.ts_;
    }
    bool operator==(const Fraction& f) {
      return ts_ * f.ms_ == ms_ * f.ts_;
    } 

    // Hàm in ra phân số
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
      os << f.ts_ << "/" << f.ms_;
      return os;
    }
    // Hàm nhập phân số
    friend std::istream& operator>>(std::istream& is, Fraction& f) {
      is >> f.ts_ >> f.ms_;
      return is;
    }
};