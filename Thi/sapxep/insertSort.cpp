// Insert sort Algorithm

// Trình bày ý tưởng thuật toán sắp xếp chèn
// 1. Chia mảng thành 2 phần: một phần đã sắp xếp và một phần chưa sắp xếp
// 2. Chọn phần tử đầu tiên của phần chưa sắp xếp và chèn vào phần đã sắp xếp
// 3. Lặp lại bước 2 cho tới khi không còn phần tử nào trong phần chưa sắp xếp

void insertSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}