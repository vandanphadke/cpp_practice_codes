#include<iostream>
using namespace std;

#define SIZE 5

void insertion_sort(int* arr) {
  for (int i = 1; i < SIZE; i++) {
    int key = arr[i];
    int j = i-1;
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      --j;
    }
    arr[j+1] = key;
  }
}

int main() {
  int arr[5] = {5, 2, 1, 3, 4};

  insertion_sort(arr);

  for (int i = 0; i < SIZE; i++) {
    cout << arr[i] << " " ;
  }
}
