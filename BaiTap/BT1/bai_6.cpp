#include <iostream>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void moveToEnd(int arr[], int n, int k) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == k) {
      for (int j = i; j < n - 1; j++) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

int main() {
  int n, k;
  std::cin >> n >> k;
  int arr[n] = {1, 2, 3 ,4};
  moveToEnd(arr, n, k);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}