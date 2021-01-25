#include<iostream>
#ifndef MAX_ELEMENTS
#define MAX_ELEMENTS 100
#endif

using namespace std;

class ArrStack  {
  public:
    ArrStack() {
      index = 0;
    }


    bool is_stack_empty() {
      return (index == 0);
    }

    void push(int element){
      if (index == MAX_ELEMENTS) {
        cout << "Limit reached" << endl;
        return;
      }

      stackArr[index] = element;
      ++index;
      cout << "Push Index is " << index << endl;
    }

    int pop() {
      if (is_stack_empty()) {
        cout << "Limit reached" << endl;
        return -1;
      }
      --index;
      cout << "Pop Index is " << index << endl;
      return stackArr[index];
    }

    void print_arr(){
      for (size_t i = 0; i < 5; i++) {
        cout << stackArr[i] << endl;
      }
    }

  private:
    int index;
    int stackArr[MAX_ELEMENTS];
};


int main(int argc, char const *argv[]) {
  ArrStack stack;
  stack.push(10);stack.push(20);stack.push(30);
  stack.print_arr();
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  return 0;
}
