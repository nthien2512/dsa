// Heap sort algorithm

// Trình bày ý tưởng thuật toán sắp xếp heap
// 1. Xây dựng heap từ mảng đầu vào
// 2. Lấy ra phần tử lớn nhất từ heap và đưa vào cuối mảng
// 3. Giảm kích thước heap đi 1 và heapify lại
// 4. Lặp lại bước 2 và 3 cho tới khi heap rỗng

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);
  }
}