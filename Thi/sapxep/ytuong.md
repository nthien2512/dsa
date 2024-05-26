# Ý tưởng các thuật toán sắp xếp

## Sắp xếp nổi bọt (Bubble Sort)

[Code cho thuật toán Bubble Sort](bubbleSort.cpp)

**Ý tưởng:**

- **So sánh và hoán đổi:** Duyệt qua mảng từ đầu đến cuối, so sánh từng cặp phần tử liền kề và hoán đổi chúng nếu chúng không theo thứ tự.
- **Lặp lại:** Lặp lại quá trình cho đến khi mảng được sắp xếp hoàn toàn. Sau mỗi lần lặp, phần tử lớn nhất trong đoạn chưa sắp xếp sẽ "nổi" lên cuối mảng.

**Độ phức tạp:**

- Thời gian: O(n²) trong trường hợp xấu nhất và trung bình. O(n) trong trường hợp tốt nhất nếu mảng đã được sắp xếp.
- Bộ nhớ: O(1).

## Sắp xếp chèn (Insertion Sort)

[Code cho thuật toán Insertion Sort](insertionSort.cpp)

**Ý tưởng:**

- **Chèn phần tử vào đúng vị trí:** Duyệt qua mảng từ trái sang phải, tại mỗi phần tử, chèn nó vào đúng vị trí trong đoạn đã được sắp xếp bên trái.
- **Lặp lại:** Lặp lại quá trình cho đến khi tất cả các phần tử được chèn vào đúng vị trí.

**Độ phức tạp:**

- Thời gian: O(n²) trong trường hợp xấu nhất và trung bình. O(n) trong trường hợp tốt nhất nếu mảng đã được sắp xếp.
- Bộ nhớ: O(1).

## Sắp xếp chọn (Selection Sort)

[Code cho thuật toán Selection Sort](selectionSort.cpp)

**Ý tưởng:**

- **Tìm phần tử nhỏ nhất:** Trong mỗi lần duyệt qua mảng, tìm phần tử nhỏ nhất và hoán đổi nó với phần tử đầu tiên của mảng chưa sắp xếp.
- **Lặp lại:** Tiếp tục quá trình này với phần tử thứ hai, thứ ba,... cho đến khi mảng được sắp xếp hoàn toàn.

**Độ phức tạp:**

- Thời gian: O(n²) trong mọi trường hợp.
- Bộ nhớ: O(1).

## Sắp xếp vun đống (Heap Sort)

[Code cho thuật toán Heap Sort](heapSort.cpp)

**Ý tưởng:**

- **Xây dựng Heap:** Chuyển mảng thành một cây nhị phân dạng heap (thường là max-heap) sao cho phần tử lớn nhất là gốc của cây.
- **Sắp xếp:** Hoán đổi phần tử gốc với phần tử cuối cùng của mảng chưa sắp xếp, sau đó giảm kích thước của heap đi 1 và điều chỉnh lại heap để phần tử lớn nhất lại trở thành gốc. Lặp lại quá trình cho đến khi mảng được sắp xếp.

**Độ phức tạp:**

- Thời gian: O(n log n) trong mọi trường hợp.
- Bộ nhớ: O(1).

## Sắp xếp trộn (Merge Sort)

[Code cho thuật toán Merge Sort](mergeSort.cpp)

**Ý tưởng:**

- **Chia nhỏ mảng:** Chia mảng thành hai mảng con bằng cách chia đôi mảng ban đầu.
- **Đệ quy:** Áp dụng đệ quy để tiếp tục chia nhỏ mảng con cho đến khi mỗi mảng con chỉ còn một phần tử.
- **Trộn:** Trộn hai mảng con đã được sắp xếp thành một mảng lớn hơn đã được sắp xếp.

**Độ phức tạp:**

- Thời gian: O(n log n) trong mọi trường hợp.
- Bộ nhớ: O(n) do cần một mảng phụ để trộn.

## Sắp xếp nhanh (Quick Sort)

[Code cho thuật toán Quick Sort](quickSort.cpp)

**Ý tưởng:**

- **Chọn điểm chốt:** Chọn một phần tử làm điểm chốt.
- **Phân chia:** Sắp xếp lại mảng sao cho tất cả các phần tử nhỏ hơn điểm chốt đứng bên trái, và tất cả các phần tử lớn hơn hoặc bằng điểm chốt đứng bên phải.
- **Đệ quy:** Đệ quy áp dụng quá trình trên cho mảng con bên trái và bên phải của điểm chốt cho đến khi mảng con có kích thước 0 hoặc 1.

**Độ phức tạp:**

- Thời gian: O(n log n) trong trường hợp trung bình và tốt nhất. O(n²) trong trường hợp xấu nhất nếu điểm chốt luôn là phần tử lớn nhất hoặc nhỏ nhất.
- Bộ nhớ: O(log n) do sử dụng ngăn xếp đệ quy.

## Tổng kết

| Thuật toán     | Độ phức tạp thời gian (Trung bình) | Độ phức tạp bộ nhớ | Ổn định |
| -------------- | ---------------------------------- | ------------------ | ------- |
| Bubble Sort    | O(n²)                              | O(1)               | Có      |
| Insertion Sort | O(n²)                              | O(1)               | Có      |
| Selection Sort | O(n²)                              | O(1)               | Không   |
| Heap Sort      | O(n log n)                         | O(1)               | Không   |
| Merge Sort     | O(n log n)                         | O(n)               | Có      |
| Quick Sort     | O(n log n)                         | O(log n)           | Không   |

Các thuật toán này có cách tiếp cận và ưu nhược điểm riêng, phù hợp với các tình huống khác nhau trong thực tế.
