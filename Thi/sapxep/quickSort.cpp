// Quick sort algorithm

// Trình bày ý tưởng thuật toán sắp xếp nhanh
// 1. Chọn một phần tử làm phần tử trung tâm
// 2. Xếp các phần tử nhỏ hơn phần tử trung tâm vào bên trái và các phần tử lớn hơn phần tử trung tâm vào bên phải
// 3. Sắp xếp các phần tử bên trái và bên phải phần tử trung tâm
// 4. Lặp lại bước 1, 2, 3 cho tới khi mảng đã sắp xếp

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
      if (arr[j] < pivot) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    int pi = i + 1;

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}