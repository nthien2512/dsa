// Khái niệm hàng đợi
/*
Hàng đợi (Queue) là một cấu trúc dữ liệu dạng danh sách mà các phần tử được thêm vào ở cuối và lấy ra ở đầu theo nguyên tắc FIFO (First In First Out).
*/

// Cấu trúc lớp của hàng đợi

template <class N>
class Node {
  public:
    N data;
    Node* next;

    Node(N data, Node* next = nullptr) : data(data), next(next) {}
};

template <class Q>
class Queue {
  private:
    Node<Q>* front;
    Node<Q>* rear;

  public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
      Node<Q>* node;
      while (front != nullptr) {
        node = front;
        front = front->next;
        delete node;
      }
    }

    void printQueue() const {
      for (Node<Q>* p = front; p != nullptr; p = p->next) {
        std::cout << p->data << std::endl;
      }
    }

    void enqueue(Q x) {
      Node<Q>* node = new Node<Q>(x);
      if (front == nullptr) {
        front = node;
      } else {
        rear->next = node;
      }
      rear = node;
    }

    Q dequeue() {
      Node<Q>* tmp = front;
      Q x = front->data;
      front = front->next;
      delete tmp;
      return x;
    }

    Q frontElement() {
      return front->data;
    }

    Q rearElement() {
      return rear->data;
    }

    int size() {
      int count = 0;
      Node<Q>* tmp = front;
      while (tmp != nullptr) {
        count++;
        tmp = tmp->next;
      }
      return count;
    }

    bool isEmpty() {
      return front == nullptr;
    }
};
