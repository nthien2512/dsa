// Bubble sort algorithm

// Trình bày ý tưởng thuật toán sắp xếp nổi bọt
// 1. So sánh phần tử thứ i với phần tử thứ i + 1
// 2. Nếu phần tử thứ i lớn hơn phần tử thứ i + 1 thì đổi chỗ 2 phần tử đó
// 3. Lặp lại bước 1 và 2 cho tới khi không còn phần tử nào cần sắp xếp

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}