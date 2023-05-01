#ifndef ASSIGNMENT2_DATA_STRUCTURE_QUEUEFUNCTIONS_H
#define ASSIGNMENT2_DATA_STRUCTURE_QUEUEFUNCTIONS_H

#include <bits/stdc++.h>
#include "Queue.h"
using namespace std;


string cal_bin(int n){
  string result = "";
  while(n){
    result= to_string(n%2) + result;
    n/=2;
  }
  cout << result << ' ';
}
void generate_bin_nums(int n){
  int size = log(n);
  Queue<string> nums(size);
  for (int i = 1; i <= n ; ++i) {
    nums.enqueue(cal_bin(i));
  }
  nums.print();
}

template <typename T>
struct stack_{
 private:
    Queue<T> data{2};
    int capacity = 2;
    int size {0};
 public:
  stack_(){}
  void push(T val){
    int ncapacity = capacity;
    if(size == capacity)
    {
      ncapacity*=2;
    }
      if(data.isEmpty()){
        data.enqueue(val);
        return;
      }
      Queue<T> newdata(ncapacity);
      newdata.enqueue(val);
      size = 1;
      while(!data.isEmpty()){
        newdata.enqueue(data.dequeue());
        size++;
      }
      data = newdata;
  }
  void pop(){
    if(size == 0){
      cout << "can not pop from empty stack";
      return;
    }
    data.dequeue();
    size--;
    if(size < (capacity/2))
      capacity/=2;
  }
  void print(){
    if(size == 0)
      return;
    data.print();
  }
};

template <typename T>
void sortQueue(Queue<T>& q) {
    if (q.isEmpty()) {
        return;
    }

    Queue<T> temp(q.queueSize());

    while (!q.isEmpty()) {
        T min = q.first();
        int n = q.queueSize();

        // find minimum element in queue
        for (int i = 0; i < n; i++) {
            T curr = q.dequeue();
            if (curr < min) {
                min = curr;
            }
            q.enqueue(curr);
        }

        // remove minimum element from queue
        for (int i = 0; i < n; i++) {
            T curr = q.dequeue();
            if (curr != min) {
                q.enqueue(curr);
            }
        }

        // add minimum element to temporary queue
        temp.enqueue(min);
    }

    // copy elements from temporary queue back to original queue
    while (!temp.isEmpty()) {
        q.enqueue(temp.dequeue());
    }
}


#endif //ASSIGNMENT2_DATA_STRUCTURE_QUEUEFUNCTIONS_H
