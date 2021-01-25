#include<iostream>

using namespace std;

void counting_sort(int* arr, int* output, int size, int limit){
  int count_arr[limit + 1];
  memset(count_arr, 0, (limit+1)*sizeof(int));
  for (int i = 0; i < size; i++) {
    ++count_arr[arr[i]];
  }
  for (int i = 1; i <= limit; i++) {
    count_arr[i] = count_arr[i] + count_arr[i-1];
  }
  for (int i = 0; i < size; i++) {
    output[count_arr[arr[i]]] = arr[i];
    --count_arr[arr[i]];
  }
}

int main() {
  int arr[8] = {2, 5, 3, 0, 2, 3, 0, 3};
  int output[8] = {0};
  counting_sort(arr, output, 8, 5);
  for (int i = 0; i < 8; i++) {
    cout << output[i] << endl;
  }

  return 0;
}
