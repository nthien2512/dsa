class StackArr {
  private:
    int *arr;
    int top;
    int capacity;
  public:
    StackArr(int size = 10001) {
      arr = new int[size];
      capacity = size;
      top = -1;
    }

    ~StackArr() {
      delete[] arr;
    }

    void push(int x) {
      arr[++top] = x;
    }

    int pop() {
      return arr[top--];
    }

    int topElement() {
      return arr[top];
    }

    int size() {
      return top + 1;
    }

    bool isEmpty() {
      return top == -1;
    }
};