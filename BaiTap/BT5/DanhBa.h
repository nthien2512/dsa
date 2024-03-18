#include <iostream>
#include <string>

class DanhBa {
  private:
    struct Node {
      std::string soThueBao;
      std::string hoTen;
      std::string diaChi;
      Node* next;
    };
    Node* head;

    Node* taoNut(std::string soThueBao, std::string hoTen, std::string diaChi) {
      Node* node = new Node;
      node->soThueBao = soThueBao;
      node->hoTen = hoTen;
      node->diaChi = diaChi;
      return node;
    }

    Node* timNut(std::string soThueBao) {
      Node* node = head;
      while (node != nullptr && node->soThueBao != soThueBao) {
        node = node->next;
      }
      return node;
    }

  public:
    DanhBa() {
      head = nullptr;
    };

    ~DanhBa() {
      while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
      }
    };

    void inDanhSach() {
      Node* node = head;
      while (node != nullptr) {
        std::cout << "So thue bao: " << node->soThueBao << std::endl;
        std::cout << "Ho ten: " << node->hoTen << std::endl;
        std::cout << "Dia chi: " << node->diaChi << std::endl;
        node = node->next;
      }
    }

    void themDau(std::string soThueBao, std::string hoTen, std::string diaChi) {
      Node* node = taoNut(soThueBao, hoTen, diaChi);
      node->next = head;
      head = node;
    }

    void themCuoi(std::string soThueBao, std::string hoTen, std::string diaChi) {
      Node* node = taoNut(soThueBao, hoTen, diaChi);
      node->next = nullptr;
      if (head == nullptr) {
        head = node;
      } else {
        Node* newNode = head;
        while (newNode->next != nullptr) {
          newNode = newNode->next;
        }
        newNode->next = node;
      }
    }

    void xoa(std::string soThueBao) {
      Node* node = timNut(soThueBao);
      if (node != nullptr) {
        if (node == head) {
          head = head->next;
        } else {
          Node* prev = head;
          while (prev->next != node) {
            prev = prev->next;
          }
          prev->next = node->next;
        }
        delete node;
      }
    }
    
    void timKiem(std::string soThueBao) {
      Node* node = timNut(soThueBao);
      if (node != nullptr) {
        std::cout << "So thue bao: " << node->soThueBao << std::endl;
        std::cout << "Ho ten: " << node->hoTen << std::endl;
        std::cout << "Dia chi: " << node->diaChi << std::endl;
      } else {
        std::cout << "Khong tim thay so thue bao " << soThueBao << std::endl;
      }
    }
};