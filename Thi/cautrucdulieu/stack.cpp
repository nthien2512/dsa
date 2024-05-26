// Khái niệm ngăn xếp
/*
Ngăn xếp (Stack) là một cấu trúc dữ liệu dạng danh sách mà các phần tử được thêm vào và lấy ra theo nguyên tắc LIFO (Last In First Out).
*/

class StackSl {
  private:
    struct Node {
      int elem;
      Node *next;
    };
    Node *top;
  public: 
    StackSl() {
      top = nullptr;
    }

    ~StackSl() {
      while (top != nullptr) {
        Node *tmp = top;
        top = top->next;
        delete tmp;
      }
    }

    void push(int x) {
      Node *node = new Node;
      node->elem = x;
      node->next = top;
      top = node;
    }

    int pop() {
      Node *tmp = top;
      int x = top->elem;
      top = top->next;
      delete tmp;
      return x;
    }

    int topElement() {
      return top->elem;
    }

    int size() {
      int count = 0;
      Node *tmp = top;
      while (tmp != nullptr) {
        count++;
        tmp = tmp->next;
      }
      return count;
    }

    bool isEmpty() {
      return top == nullptr;
    }
};