int cau1(int n, int p, int u, int x[], int y[]) {
  int f = 0; // 1 phép gán
  for (int i = 0; i<= n - 1; i++) { // 1 phép gán, n + 1 phép so sánh, n phép tăng
    p = 1; // n phép gán
    for (int j = 1; j <= i; j++) { // n phép gán, n(n - 1)/2 + 1 phép so sánh, n(n - 1)/2 phép tăng
      if (i != j) { // n(n - 1)/2 phép so sánh
        p = p * (u - x[j]) / (x[i] - x[j]) + x[i];
      }
    }
    f = f + p * y[i]; // n phép nhân, n phép cộng, n phép gán
  }
  return f; // 1 phép trả về
}

// Tổng phép toán: 3n(n - 1)/2 + 3n + n + n + n + n + 1 + 1 + 1 + 1 + 1 = 3n^2/2 + 11n/2 + 5
// Độ phức tạp thuật toán: O(n^2)