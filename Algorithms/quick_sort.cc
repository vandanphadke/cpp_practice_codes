#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int partition(int* arr, int first, int last) {
  int pivot = arr[last];
  int i = first - 1;
  for (int j = first; j <= last - 1; j++) {
    if (arr[j] <= pivot) {
      ++i;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i+1];
  arr[i+1] = arr[last];
  arr[last] = temp;
  return i + 1;
}

void quick_sort(int* arr, int first, int last) {
    if (first < last) {
      int mid = partition(arr, first, last);
      quick_sort(arr, first, mid - 1);
      quick_sort(arr, mid + 1, last);
    }
}

int main(int argc, char const *argv[]) {
	int array[7] = {80, 40, 30, 10, 20, 100, 60};
	quick_sort(array, 0, 6);
  for (size_t i = 0; i < 7; i++) {
    cout << array[i] << endl;
  }
}
