#include<iostream>
using namespace std;

struct single_node {
  int data;
  single_node *next;
};

struct double_node {
  int data;
  double_node *prev;
  double_node *next;
};

class singly_ll {
private:
  single_node *head;
  single_node *tail;
public:
  singly_ll(){
      head = NULL;
      tail = NULL;
  }

  void add_element_end(int element){
    single_node* tmp = new single_node;
    tmp -> data = element;
    tmp -> next = NULL;

    if (head == NULL) {
      head = tmp;
      tail = tmp;
    }
    else {
      tail -> next = tmp;
      tail = tmp;
    }
  }

  void add_element_middle(int element_before, int element){
    single_node* tmp = head;
    while (tmp != NULL && tmp -> data != element_before){
      tmp = tmp -> next;
    }
    if (tmp == NULL) {
      cout << "Element after insertion should be present." << endl;
      return;
    }
    else {
      single_node* add = new single_node;
      add -> data = element;
      add -> next = tmp -> next;
      tmp -> next = add;
    }
  }

  void remove_element(int element){
    single_node* tmp = head;
    if (tmp -> data == element) {
      head = head -> next;
      return;
    }

    while (tmp -> next != NULL && tmp -> next -> data != element){
      tmp = tmp -> next;
    }
    if (tmp -> next != NULL) {
      tmp -> next = tmp -> next -> next;
    }
  }

  void print_ll(){
    single_node* tmp = head;
    while (tmp != NULL){
      cout << "Node : " << tmp -> data << endl;
      tmp = tmp -> next;
    }
  }

  bool search(int element){
    single_node* tmp = head;
    while (tmp != NULL){
      if (tmp -> data == element) {
        return true;
      }
      tmp = tmp -> next;
    }
    return false;
  }
};

class doubly_ll {
private:
  double_node *head;
  double_node *tail;
public:
  doubly_ll(){
    head = NULL;
    tail = NULL;
  }

  void add_element_end(int element){
    double_node* tmp = new double_node;
    tmp -> data = element;
    tmp -> next = NULL;
    tmp -> prev = NULL;

    if (head == NULL) {
      head = tmp;
      tail = tmp;
    }
    else {
      tail -> next = tmp;
      tmp -> prev = tail;
      tail = tmp;
    }
  }

  void add_element_middle(int element_before, int element){
    double_node* tmp = head;
    while (tmp != NULL && tmp -> data != element_before){
      tmp = tmp -> next;
    }
    if (tmp == NULL) {
      cout << "Element after insertion should be present." << endl;
      return;
    }
    else {
      double_node* next_node = tmp -> next;
      double_node* add = new double_node;
      add -> data = element;
      add -> next = next_node;
      add -> prev = tmp;
      tmp -> next = add;
      next_node -> prev = add;
    }
  }

  void remove_element(int element){
    double_node* tmp = head;
    if (tmp -> data == element) {
      head = head -> next;
      return;
    }

    while (tmp -> next != NULL && tmp -> next -> data != element){
      tmp = tmp -> next;
    }
    if (tmp -> next != NULL) {
      tmp -> next = tmp -> next -> next;
      tmp -> next -> prev = tmp;
    }
  }

  void print_ll(){
    double_node* tmp = head;
    while (tmp != NULL){
      cout << "Node : " << tmp -> data << endl;
      tmp = tmp -> next;
    }
  }

  bool search(int element){
    double_node* tmp = head;
    while (tmp != NULL){
      if (tmp -> data == element) {
        return true;
      }
      tmp = tmp -> next;
    }
    return false;
  }
};

int main() {
  doubly_ll ll;
  ll.add_element_end(1);
  ll.add_element_end(2);
  ll.add_element_end(3);
  ll.add_element_middle(2, 4);
  ll.print_ll();
  // ll.remove_element(2);
  // ll.add_element_middle(3, 7);
  // ll.print_ll();
  // cout << ll.search(2) << endl;
  // cout << ll.search(1) << endl;
}
