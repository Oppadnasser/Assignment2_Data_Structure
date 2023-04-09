#ifndef ASSIGNMENT2_DATA_STRUCTURE_LINKEDLISTFUNCTIONS_H
#define ASSIGNMENT2_DATA_STRUCTURE_LINKEDLISTFUNCTIONS_H

#include <bits/stdc++.h>
#include "SingleLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
using namespace std;
template <typename T>
void mergeKLinkedlists(){
  int k ;
  Single_linked_list<T> result;
  cout << "please enter number of arrays you want merge:";
  cin >> k;
  Single_linked_list<T> lists[k];
  int i = k;
  cout << "please enter array size and enter list in single line and separate elements by space:\n";
  while (i--){
    T temp;
    int s;
    cin >> s;
    while(s--){
      cin >> temp;
      lists[k-i-1].InsertAtTail(temp);
    }
  }
  int rm;
  T min;
  bool first = true , all_lists_are_empty = false;
  while(!all_lists_are_empty){
    all_lists_are_empty = true;
    for(int j = 0 ; j < k ; j++) {
      if(!lists[j].isEmpty() && first){
        all_lists_are_empty = false;
        first = false;
        min = lists[j].retrieveATt(1);
        rm = j;
      }
      else if (!lists[j].isEmpty()) {
        all_lists_are_empty = false;
        if (lists[j].retrieveATt(1) < min) {
          min = lists[j].retrieveATt(1);
          rm = j;
        }
      }
      }
    first = true;
    if(!all_lists_are_empty){
      lists[rm].RemoveAtHead();
      result.InsertAtTail(min);
    }
  }
  result.print();
}


#endif //ASSIGNMENT2_DATA_STRUCTURE_LINKEDLISTFUNCTIONS_H
