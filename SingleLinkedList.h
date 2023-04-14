#ifndef ASSIGNMENT2_DATA_STRUCTURE_SINGLELINKEDLIST_H
#define ASSIGNMENT2_DATA_STRUCTURE_SINGLELINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node{
 public:
  T data;
  node* next = nullptr;
  node(T data) : data(data){}
  node();
  ~node(){
    delete this;
  }
};
template <typename T>
class Single_linked_list{
  node<T>* head{ } ;
  node<T>* tail{ };
  int length = 0;
 public:
  void print(){
    node<T>* data = head;
    if(!head){
      cout << '\n';
      return;
    }
    cout << data->data << ' ';
    while(data->next != nullptr){
      data = data->next;
      cout << data->data << ' ';
    }
    cout << '\n';
  }
  void InsertTHead(T num){
    node<T>* temp = new node<T>(num);
    if(!head){
      head = tail = temp;
      length++;
      return;
    }
    temp->next = head;
    head = temp;
    length++;
  }
  void InsertAtTail(T num){
    node<T>* item = new node<T>(num);
    if(!head){
      head = tail = item;
      length++;
      return;
    }
    tail->next = item;
    tail = item;
    length++;
  }
  void InsertAt(T valu , int indx){
    node<T>* temp = new node<T> (valu);
    temp->next = get_nth(indx);
    get_nth(indx-1)->next = temp;
    length++;
    return;
  }
  void RemoveAtHead(){
    node<T>* temp = head;
    head = move(temp->next);
    move(temp);
    length--;
  }
  void RemoveAt(int indx){
    if(indx == 1){
      RemoveAtHead();
      return;
    }
    node<T> * temp = get_nth(indx);
    node<T>* previous = get_nth(indx-1);
    previous->next = temp->next;
    move(temp);
  }
  void RemoveAtTail(){
    node<T>* temp = get_nth(length-1);
    temp->next = nullptr;
    tail = move(temp);
    length--;
  }
  T retrieveATt(int ind){
    return get_nth(ind)->data;
  }
  void ReplaceAt(T new_element , int idx){
    get_nth(idx)->data = new_element;
  }
  bool isExist(T val){
    for(node<T>* temp = head ; temp;temp = temp->next)
      if(temp->data == val)
        return true;
    return false;
  }
  bool isItemAtEqual(T val, int idx){
    if(get_nth(idx)->data == val)
      return true;
    return false;
  }
  void swap_ (int firstItemIdx, int secondItemIdx){
    node<T> * first = new node<T> (get_nth(firstItemIdx)->data);
    first->next = get_nth(firstItemIdx+1);
    node<T> * second = new node<T> (get_nth(secondItemIdx)->data);
    second->next = get_nth(firstItemIdx + 1);
    if(get_nth(secondItemIdx)->next) {
      first->next = get_nth(secondItemIdx + 1);
    }
    else{
      first->next = nullptr;
    }
    if(firstItemIdx > 1)
      get_nth(firstItemIdx-1)->next = second;
    else
      head = second;
    get_nth(secondItemIdx-1)->next = first;
  }

  node<T>* get_nth(int a){
    if(a > length){
      cout << "error";
      return nullptr;
    }
    a--;
    node<T>* temp = head;
    for(;a; temp = temp->next,a--){
    }
    return temp;
  }

  void reverse() {
    if (length <= 1) { // list is empty or contains only one element
      return;
    }
    node<T>* prev = nullptr;
    node<T>* curr = head;
    node<T>* next = nullptr;
    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    tail = head; // update the tail to the previous head
    head = prev; // update the head to the previous tail (new head)
  }

  bool isEmpty(){
    return length==0;
  }
  int linkedlistsize(){
    return length;
  }
  void clear(){
    head = tail = { };
    length = 0;
  }
  Single_linked_list(int a){
    head = new node<T>(a);
  }
  Single_linked_list(){};
};


#endif //ASSIGNMENT2_DATA_STRUCTURE_SINGLELINKEDLIST_H
