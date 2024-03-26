#include <iostream>
#include <string>

template <class T>
class SList {
  private:

    struct Node {
      T elem;
      Node* next;

      Node(T elem, Node* next = nullptr) : elem(elem), next(next) {}
    };

    Node* head;
    Node* tail;

  public:

    SList() : head(nullptr), tail(nullptr) {}

    ~SList() {
      while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
      }
    }

    void printList() {
      for (Node* p = head; p != nullptr; p = p->next) {
        std::cout << p->elem << std::endl;
      }
    }

    void push_front(T x) {
      Node* node = new Node(x, head);
      head = node;
      if (tail == nullptr) {
        tail = node;
      }
    }

    void push_back(T x) {
      Node* node = new Node(x);
      if (head == nullptr) {
        head = tail = node;
      } else {
        tail = tail->next = node;
      }
    }

    void erase(T x) {
      Node* p = head;
      Node* prev = nullptr;
      while (p != nullptr && p->elem != x) {
        prev = p;
        p = p->next;
      }
      if (p != nullptr) {
        if (prev == nullptr) {
          head = p->next;
        } else {
          prev->next = p->next;
        }
        delete p;
      }
    }

    void search(T x) {
      Node* p = head;
      Node* prev = nullptr;
      while (p != nullptr && p->elem != x) {
        prev = p;
        p = p->next;
      }
      std::cout << p->elem;
    }
};

class DocGia {
  public:
    int maDocGia;
    std::string tenDocGia, namSinh, diaChi;

    DocGia(int maDocGia = 0, std::string tenDocGia = "", std::string namSinh = "", std::string diaChi = "")
    : maDocGia(maDocGia), tenDocGia(tenDocGia), namSinh(namSinh), diaChi(diaChi) {}

    DocGia themDocGia() {
      DocGia dg;
      std::cout << "Nhap thong tin doc gia:\n";
      std::cout << "Nhap ma doc gia: ";
      std::cin >> dg.maDocGia;
      std::cout << "Nhap ten doc gia: ";
      std::cin.ignore();
      getline(std::cin, dg.tenDocGia);
      std::cout << "Nhap nam sinh: ";
      std::cin >> dg.namSinh;
      std::cout << "Nhap dia chi: ";
      std::cin >> dg.diaChi;
      return dg;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const DocGia& dg) {
      return os << "----------------------------------------"
                << "\nMa doc gia: " << dg.maDocGia
                << "\nTen doc gia: " << dg.tenDocGia
                << "\nNam sinh:" << dg.namSinh
                << "\nDia chi: " << dg.diaChi
                << "\n----------------------------------------\n";
    }

    bool operator!=(const DocGia& other) const {
      return maDocGia != other.maDocGia;
    }
};

void menu() {
  std::cout << "--------------------- Menu ---------------------\n";
  std::cout << "1. In danh sach doc gia\n";
  std::cout << "2. Them mot doc gia\n";
  std::cout << "3. Xoa mot doc gia theo ma\n";
  std::cout << "4. Tim kiem doc gia theo ma\n";
  std::cout << "0. Thoat\n";
  std::cout << "------------------------------------------------\n";
  std::cout << "Lua chon: ";
}

int main() {
  SList<DocGia> listDocGia;
  DocGia dg;

  listDocGia.push_back(DocGia(123, "TH", "203", "DC"));



  int choice;

  do {
    menu();
    std::cin >> choice;
    switch (choice) {
      case 1:
        listDocGia.printList();
        break;
      case 2: {
        listDocGia.push_back(
          dg.themDocGia()
        );
        break;
      }
      case 3: {
        int maDocGia;
        std::cout << "Nhap ma doc gia can xoa";
        std::cin >> maDocGia;
        listDocGia.erase(maDocGia);
        break;
      }
      case 4:{
        int maDocGia;
        std::cout << "Nhap ma doc gia can tim";
        std::cin >> maDocGia;
        listDocGia.search(maDocGia);
        break;
      }
      case 0:
        std::cout << "Da thoat chuong trinh!";
        break;
      default:
        std::cout << "Lua chon khong hop le\n";
    }
  } while (choice != 0);
  
  return 0;
}