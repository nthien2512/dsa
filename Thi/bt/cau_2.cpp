#include <iostream>
#include <vector>
#include <queue>

void bubbleSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j] < arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> heights(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> heights[i];
  }

  bubbleSort(heights);

  std::queue<int> q;
  for (int height : heights) {
    if (!q.empty() && q.front() - height >= 3) {
      q.pop();
    }
    q.push(height);
  }

  std::cout << q.size() << std::endl;

  return 0;
}