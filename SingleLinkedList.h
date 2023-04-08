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
  node<T>* get_nth_back(int val){
    int it = 1 + length - val;
    if(it < 0){
      return nullptr;
    }
    return get_nth(it);
  }
  bool list_is_same( Single_linked_list other){
    if(length != other.length)
      return false;
    for(node<T>* node1 = head,  *node2 = other.head;node1;node1 = node1->next , node2 = node2->next){
      if(node1->data != node2->data)
        return false;
    }
    return true;
  }
  Single_linked_list(int a){
    head = new node<T>(a);
  }
  Single_linked_list(){};
};


#endif //ASSIGNMENT2_DATA_STRUCTURE_SINGLELINKEDLIST_H
