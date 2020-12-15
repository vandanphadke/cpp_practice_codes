#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

class MyHeap {
	public:
		int* heap;
  	int size;
		int init_size;

		MyHeap(int* arr, int size) {
			heap = new int[size];
			for (int i = 0; i < size; i++) {
				heap[i] = arr[i];
			}
			this->size = size;
			this->init_size = size;

		}

		~MyHeap(){
    	delete[] heap;
  	}

		void heap_sort(){
			build_max_heap();
			for (int i = (this->size - 1); i > 0; --i) {
				int temp = heap[0];
				heap[0] = heap[i];
				heap[i] = temp;
				--this->size;
				max_heapify(0);
			}
		}

		void print_arr() {
			for (size_t i = 0; i < this->init_size; i++) {
				cout << heap[i] << endl;
			}
		}

	private:
		int parent(int pos) { return floor((pos - 1) / 2); }

		int left(int pos) { return 2*pos + 1; }

		int right(int pos) { return 2*pos + 2; }

		void max_heapify(int pos) {
			cout << "Heapifying position " << pos << endl;
			if (pos >= this->size) { return; }
			int leftValue = (left(pos) < this->size ? heap[left(pos)] : INT_MIN);
			int rightValue = (right(pos) < this->size ? heap[right(pos)] : INT_MIN);
			int current = heap[pos];
			int maxNum = current;
			maxNum = std::max(current, std::max(leftValue, rightValue));
			if (maxNum == leftValue) {
					int temp = heap[pos];
					heap[pos] = leftValue;
					heap[left(pos)] = temp;
					max_heapify(left(pos));
			}
			else if (maxNum == rightValue) {
				int temp = heap[pos];
				heap[pos] = rightValue;
				heap[right(pos)] = temp;
				max_heapify(right(pos));
			}
		}

		void build_max_heap() {
			for (int i = floor((this->size - 1) / 2); i >= 0; --i) {
				max_heapify(i);
			}
		}
};

int main(int argc, char const *argv[]) {
	int array[7] = {80, 40, 30, 10, 20, 100, 60};
	MyHeap h1(array, 7);
	h1.heap_sort();
	h1.print_arr();
	return 0;
}
