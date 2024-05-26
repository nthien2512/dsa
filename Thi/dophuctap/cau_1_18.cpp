int cau2(int n, int a[]) {
  int k = 0; // 1 phép gán
  for (int i = 1; i <= n; i++) { // 1 phép gán, n + 1 phép so sánh, n phép tăng
    for (int j = i + 1; j <= n; j++) { // n phép gán, n(n - 1)/2 + 1 phép so sánh, n(n - 1)/2 phép tăng
      if ((a[i] + a[j]) % 2 == 0 && a[i] > a[j]) { // n(n - 1)/2 phép cộng, n(n - 1)/2 phép chia, n(n - 1)/2 phép so sánh
        k++;
      }
    }
  }
  return k; // 1 phép trả về
}

// Tổng phép toán: 5n^2/2 + n/2 + 5
// Độ phức tạp thuật toán: O(n^2)