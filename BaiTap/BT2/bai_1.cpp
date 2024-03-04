/**
 * Updated by thiendev.id.vn's author on August 17 2023
 * Github: https://github.com/@ntdev204
 * "A bit of fragrance clings to the hand that gives flowers!"
 */

#include <iostream>
#include <iomanip>

class Time {
  private:
    int hour;
    int minute;
    int second;

  public:
    void inputTime() {
      std::cout << "Enter hour: ";
      std::cin >> hour;
      std::cout << "Enter minute: ";
      std::cin >> minute;
      std::cout << "Enter second: ";
      std::cin >> second;
      normalizeTime();
    }

    void displayTime() {
      std::cout 
            << std::setfill('0') << std::setw(2) << hour << ":"
            << std::setfill('0') << std::setw(2) << minute << ":"
            << std::setfill('0') << std::setw(2) << second << "\n";
    }

  private:
    void normalizeTime() {
      minute += second / 60;
      second %= 60;
      hour += minute / 60;
      minute %= 60;
      hour %= 24;
    }
};

int main() {
  Time t;
  t.inputTime();
  t.displayTime();
  return 0;
}