// Selection sort algorithm

// Trình bày ý tưởng thuật toán sắp xếp chọn
// 1. Tìm phần tử nhỏ nhất trong mảng và đổi chỗ nó với phần tử đầu tiên
// 2. Tìm phần tử nhỏ nhất trong mảng còn lại và đổi chỗ nó với phần tử thứ 2
// 3. Lặp lại bước 2 cho tới khi mảng được sắp xếp

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

// Trình bày ý tưởng chi tiết sắp xếp mảng 31, 41, 59, 26, 41, 58
// 1. 31 là phần tử nhỏ nhất, đổi chỗ với 31
// 2. 41 là phần tử nhỏ nhất, đổi chỗ với 41
// 3. 59 là phần tử nhỏ nhất, đổi chỗ với 59
// 4. 26 là phần tử nhỏ nhất, đổi chỗ với 26
// 5. 41 là phần tử nhỏ nhất, đổi chỗ với 41
// 6. 58 là phần tử nhỏ nhất, đổi chỗ với 58
