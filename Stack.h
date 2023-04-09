#ifndef ASSIGNMENT2_DATA_STRUCTURE_STACK_H
#define ASSIGNMENT2_DATA_STRUCTURE_STACK_H

#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Stack{
 private:
  struct nod{
      int data{ };
      nod* next { };
  };
  nod* head { };
  int size {0};
 public:
  bool is_empty(){
    return head;
  }
  void push(int x){
    size++;
    if(!head){
      head = new nod{x};
      return;
    }
    nod* temp = new nod{x};
    temp->next = head;
    head = temp;
  }
  T pop(){
    nod* temp = new nod{head->data};
    head = move(head->next);
    size--;
    return temp->data;
  }
  T top(){
    return head->data;
  }
  int StackSize(){
    return size;
  }
  void clear(){
    nod* temp = new nod{} ;
    head = temp->next;
    size = 0;
  }
  void print(){
    nod* temp = head;
    while(temp){
      cout << temp->data << ' ';
      temp = temp->next;
    }
    cout << '\n';
  }
};
//bool is_higher(char a , Stack<char> st){
//  if(st.is_empty())
//    return true;
//  if((a == '*' || a == '/') && (st.peek() != '*' || st.peek() != '/') && st.peek() != '^')
//    return true;
//  if(st.peek() == '(')
//    return true;
//  if(a == '^' && (st.peek() != '^' || st.peek() == '^'))
//    return true;
//  return false;
//}
//string postfix(string x){
//  string output = "";
//  Stack<char> operators(20);
//  for(char a : x){
//    if(isdigit(a))
//      output+=a;
//    else{
//      if(a == ')'){
//        while(operators.peek() != '('){
//          output += operators.pop();
//        }
//        operators.pop();
//      }
//      else if(a == '('){
//        operators.push_(a);
//      }
//      else {
//        while (!is_higher(a, operators) && !operators.is_empty())
//          output += operators.pop();
//        operators.push_(a);
//      }
//    }
//  }
//  while(!operators.is_empty())
//    output+=operators.pop();
//  return output;
//}
//void calculate(char a , Stack<float> &s){
//  double second = s.pop();
//  double first = s.pop();
//  if(a == '+'){
//    s.push_(first+second);
//  } else if(a == '-'){
//    s.push_(first-second);
//  } else if(a == '*'){
//    s.push_(first*second);
//  } else if(a == '/'){
//    s.push_(first/second);
//  } else{
//    s.push_(pow(first, second));
//  }
//}
//float evaluate_postfix(string post){
//  Stack<float> nums(10);
//  for(char a : post){
//    if(isdigit(a)){
//      string c = "";
//      c+=a;
//      nums.push_(stod(c));
//    }
//    else{
//      calculate(a , nums);
//    }
//  }
//  return nums.pop();
//
//}


#endif //ASSIGNMENT2_DATA_STRUCTURE_STACK_H
