/**
 * Updated by thiendev.id.vn's author on August 17 2023
 * Github: https://github.com/@ntdev204
 * "A bit of fragrance clings to the hand that gives flowers!"
 */

#include <iostream>
#include <string>


class Book {
public:
  std::string title;
  std::string author;
  int publishYear;

  void input() {
    std::cout << "Enter title: ";
    std::getline(std::cin >> std::ws, title);
    std::cout << "Enter author: ";
    std::getline(std::cin >> std::ws, author);
    std::cout << "Enter year of publication: ";
    std::cin >> publishYear;
  }
  
  void display() {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Year of publication: " << publishYear << std::endl;
  }
};
                 
int main() {
  int n;
  std::cout << "Enter number of books: ";
  std::cin >> n;
  Book* books = new Book[n];

  for (int i = 0; i < n; i++) {
    std::cout << "Enter details for book " << i + 1 << ":\n";
    books[i].input();
  }

  std::cout << "Books:\n";
  for (int i = 0; i < n; i++) {
    books[i].display();
  }

  std::cout << "Books published between 2000 and 2023:\n";
  for (int i = 0; i < n; i++) {
    if (books[i].publishYear >= 2000 && books[i].publishYear <= 2023) {
      books[i].display();
    }
  }

  delete[] books;
  return 0;
}