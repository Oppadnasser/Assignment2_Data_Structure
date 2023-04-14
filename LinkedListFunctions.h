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


void combineNodesBetweenZeros(Single_linked_list<int> &list) {
    node<int>* curr = list.get_nth(1);
    int sum = 0;
    int idx = 1 , revers = 0;
    while (curr) {
        if (curr->data == 0) {
            if (curr->next != nullptr) {
                list.RemoveAt(idx); // remove the first zero
                curr = list.get_nth(idx);
                while (curr->data !=0) {
                    sum += curr->data;
                    list.RemoveAt(idx);
                    curr = list.get_nth(idx);
                }
                idx++;
                list.InsertTHead(sum);
                sum = 0;
            }
            else
              break;
        }
        else {
            list.RemoveAt(idx);
            curr = list.get_nth(idx);
        }
    }
    list.reverse();
    if(list.get_nth(1)->data == 0)
      list.RemoveAtHead();
}




#endif //ASSIGNMENT2_DATA_STRUCTURE_LINKEDLISTFUNCTIONS_H
