#include<iostream>
#ifndef MAX_ELEMENTS
#define MAX_ELEMENTS 100
#endif

using namespace std;

class ArrQueue {
  public:
    ArrQueue() {
      front_index = 0;
      rear_index = 0;
    }

    bool is_stack_empty() {
      return (front_index == rear_index);
    }

    bool is_stack_full() {
      return (rear_index + 1 == front_index);
    }

    void add(int element) {
      if (is_stack_full()) {
        cout << "Queue is full." << endl;
        return;
      }
      queue_arr[rear_index] = element;
      rear_index = ( rear_index + 1 ) % MAX_ELEMENTS;
    }

    int poll() {
      if (is_stack_empty()) {
        cout << "Queue is empty." << endl;
        return -1;
      }
      front_index = ( front_index + 1 ) % MAX_ELEMENTS;
      return queue_arr[(( front_index - 1 ) % MAX_ELEMENTS)];
    }

  private:
    int front_index;
    int rear_index;
    int queue_arr[MAX_ELEMENTS];
};


int main(int argc, char const *argv[]) {
  ArrQueue queue;
  cout << queue.poll() << endl;
  queue.add(1);
  queue.add(2);
  queue.add(3);
  cout << queue.poll() << endl;
  cout << queue.poll() << endl;
  cout << queue.poll() << endl;
  cout << queue.poll() << endl;
  return 0;
}
