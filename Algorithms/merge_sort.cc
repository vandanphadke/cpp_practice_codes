#include<iostream>
using namespace std;

#define SIZE 10

void merge(int* arr, int l, int mid, int r){
  int n1 = mid - l + 1;
  int n2 = r - mid;
  int left_arr[n1], right_arr[n2];

  for (int i = 0; i < n1; ++i) {
    left_arr[i] = arr[l + i];
  }

  for (int i = 0; i < n2; ++i) {
    right_arr[i] = arr[mid + 1 + i];
  }

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (left_arr[i] <= right_arr[j]) {
      arr[k] = left_arr[i];
      ++i;
    }
    else {
      arr[k] = right_arr[j];
      ++j;
    }
    ++k;
  }

  while (i < n1) {
    arr[k] = left_arr[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = right_arr[j];
    j++;
    k++;
  }
}

void merge_sort(int* arr, int l, int r) {
  if (l >= r) { return; }
  int mid = (l+r-1)/2;
  merge_sort(arr, l, mid);
  merge_sort(arr, mid + 1, r);
  merge(arr, l, mid, r);
}

int main(int argc, char const *argv[]) {
  int arr[10] = {4, 3, 1, 2, 5, 7, 8, 6, 10, 9};
  merge_sort(arr, 0, SIZE - 1);
  for (int i = 0; i < SIZE; i++) {
    cout << arr[i] << " " ;
  }
  return 0;
}
