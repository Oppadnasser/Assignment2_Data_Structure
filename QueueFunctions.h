#ifndef ASSIGNMENT2_DATA_STRUCTURE_QUEUEFUNCTIONS_H
#define ASSIGNMENT2_DATA_STRUCTURE_QUEUEFUNCTIONS_H

#include <bits/stdc++.h>
#include "Queue.h"
using namespace std;

/*
string cal_bin(int n){
  string result = "";
  while(n){
    result= to_string(n%2) + result;
    n/=2;
  }
  cout << result << ' ';
}
void generate_bin_nums(int n){
  Queue<string> nums;
  for (int i = 1; i <= n ; ++i) {
    nums.enqueue(cal_bin(i));
  }
  nums.print();
}
*/

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
