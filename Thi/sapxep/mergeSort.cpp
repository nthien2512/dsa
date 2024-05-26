// Merge sort algorithm

// Trình bày ý tưởng thuật toán sắp xếp trộn
// 1. Chia mảng thành 2 mảng con
// 2. Sắp xếp 2 mảng con
// 3. Trộn 2 mảng con đã sắp xếp thành mảng lớn
// 4. Lặp lại bước 1, 2, 3 cho tới khi mảng đã sắp xếp

void mergeSort(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }

  for (int j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}