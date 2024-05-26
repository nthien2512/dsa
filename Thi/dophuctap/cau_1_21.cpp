void cau1(int n, int a[]) {
  int k = 0; // 1 phép gán
  for (int i = 2; i <= n; i++) { // 1 phép gán, n - 1 + 1 = n phép so sánh, n - 1 phép tăng
    int ok = 1; // n - 1 phép gán
    for (int j = 1; j <= k; j++) { // n - 1 phép gán, n(n - 1)/2 + 1 phép so sánh, n(n - 1)/2 phép tăng
      if (a[i] == a[j]) { // n(n - 1)/2 phép so sánh
        ok = 0;
        break;
      }
    }
    if (ok) {
      a[++k] = a[i]; // n - 1 phép tăng, n - 1 phép gán -> 2n - 2
    }
  }
  n = k; // 1 phép gán
}

// Tổng phép toán: 3n^2/2 + 9n/2 + - 1
// Độ phức tạp thuật toán: O(n^2)