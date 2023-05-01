#include "SingleLinkedList.h"
#include "Stack.h"
#include "CircularLinkedList.h"
#include "LinkedListFunctions.h"
#include "QueueFunctions.h"
#include "StackFunctions.h"


/*    Made By: Abd El-Gafour Nasser    */
/*
int main(){
  generate_bin_nums(3);
}
*/


/*

int main(){
  mergeKLinkedlists<int>();
}
*/



/*
// push
// pop
// top
// isEmpty
// stackSize
// clear
// print


int main(){
  Stack<int> stak ;
  stak.push(3);
  stak.push(2);
  stak.push(1);
  stak.clear();
  cout << stak.StackSize() << endl;
  stak.print();
}
*/

/*
// insertAtHead
// insertAtTail
// insertAt
// removeAtHead
// removeAtTail
// removeAt
// retrieveAt
// replaceAt
// isExist
// isItemAtEqual
// swap
// isEmpty
// linkedListSize
// clear
// print


int main(){
  Single_linked_list<int> lis;
  lis.InsertTHead(4);
  lis.InsertTHead(3);
  lis.InsertTHead(2);
  lis.InsertTHead(1);
  lis.InsertAt(6,3);
  lis.print();
  lis.swap_(1,2);
  lis.clear();
  lis.print();
  cout << boolalpha << lis.isEmpty();
}
 */


/*    Made By: Mostafa Ali    */

/*
int main() {
    ArrayList<int> list(5);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print();   // Output: [1, 2, 3]
    list.insertAt(4, 1);
    list.print();   // Output: [1, 4, 2, 3]
    cout << list.retrieveAt(2) << endl;  // Output: 2
    list.removeAt(0);
    list.print();   // Output: [4, 2, 3]
    list.replaceAt(5, 1);
    list.print();   // Output: [4, 5, 3]
    cout << boolalpha << list.isItemAtEqual(5, 1) << endl;  // Output: true
}
*/

/*
int main() {
    // create a new circular linked list
    CircularLinkedList<int> cll;

    // insert elements at head and end
    cll.insertAtHead(3); // 3
    cll.insertAtHead(2); // 2 3
    cll.insertAtHead(1); // 1 2 3
    cll.insertAtEnd(4); // 1 2 3 4
    cll.insertAtEnd(5); // 1 2 3 4 5

    // insert an element at index 2
    cll.insertAt(10, 2); // 1 2 10 3 4 5

    // remove elements from head and end
    cll.removeAtHead(); // 2 10 3 4 5
    cll.removeAtEnd(); // 2 10 3 4

    // remove an element at index 2
    cll.removeAt(2); // 2 10 4

    // print the list
    cout << "List contents: ";
    cll.print(); // 2 10 4

    // get the element at index 1
    cout << "Element at index 1: " << cll.retrieveAt(1) << endl; // 10

    // replace an element at index 0
    cll.replaceAt(100, 0); // 100 10 4

    // check if an element exists in the list
    cout << "Element 4 exists in list: " << boolalpha << cll.isExist(4) << endl; // true

    // check if an element at index 1 is equal to a value
    cout << "Element at index 1 is equal to 10: " << cll.isItemAtEqual(10, 1) << endl; // true

    // Add new element in head to check the swap
    cll.insertAtHead(1); // 1 100 10 4

    // swap two nodes
    cll.swap(1, 3); // 1 4 10 100

    // print the list after swapping nodes
    cout << "List contents after swapping nodes: ";
    cll.print(); // 1 4 10 100

    // clear the list
    cll.clear(); // 0

    // check if the list is empty
    cout << "List is empty: " << boolalpha << cll.isEmpty() << endl;

}
*/

/*
int main() {
    string s1 = ")()())";
    string s2 = "(()";
    string s3= "";
    string s4= ")()())";

    cout << longestValidParentheses(s1) << endl; // Output: 4
    cout << longestValidParentheses(s2) << endl; // Output: 2
    cout << longestValidParentheses(s3) << endl; // Output: 0
    cout << longestValidParentheses(s4) << endl; // Output: 4
}
 */
/*
int main() {
    Single_linked_list<int> list1;
    list1.InsertAtTail(0);
    list1.InsertAtTail(1);
    list1.InsertAtTail(0);
    list1.InsertAtTail(3);
    list1.InsertAtTail(0);
    list1.InsertAtTail(2);
    list1.InsertAtTail(2);
    list1.InsertAtTail(0);
    combineNodesBetweenZeros(list1);
    list1.print();
}

*/
/*
int main(){
  stack_<int> st;
  st.push(3);
  st.push(6);
  st.push(9);
  st.pop();
  st.pop();
  st.pop();
  st.print();
  return 0;
}
*/

/*
int main() {
    Queue<int> q(4);
    q.enqueue(3);
    q.enqueue(15);
    q.enqueue(2);
    q.enqueue(4);

    sortQueue(q);
    q.print(); // Output: Queue: 2 3 4 15

    q.clear();
    q.enqueue(9);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(1);

    sortQueue(q);
    q.print(); // Output: Queue: 1 1 2 9

    return 0;
}
*/
/*
int main(){
  int a = 16;
  cal_bin(a);

  return 0;
}
 */

/*    Made By: Osama Mamdouh    */

/*
 // Queue
int main() {
    Queue<int> q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print(); // Queue: 10 20 30
    cout << "First element: " << q.first() << endl; // First element: 10
    cout << "Dequeued element: " << q.dequeue() << endl; // Dequeued element: 10
    q.print(); // Queue: 20 30
    cout << "Queue size: " << q.queueSize() << endl; // Queue size: 2
    q.clear();
    q.print(); // Queue is empty.
    return 0;
}
*/

/*
// Double Linked List
int main() {
    DoublyLinkedList<int> list;

    list.insertAtHead(5);
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAt(15, 2);
    list.forwardTraversal();
    list.backwardTraversal();

    //list.removeAtHead();
    //list.removeAtTail();
    //list.forwardTraversal();

    list.replaceAt(30, 3);
    list.forwardTraversal();

    cout << list.isExist(25) << endl;
    cout << list.isExist(15) << endl;
    cout << list.isItemAtEqual(20, 3) << endl;
    cout << list.isItemAtEqual(30, 3) << endl;
    cout << list.isEmpty() << endl;
    cout << list.doubleLinkedListSize() << endl;

    list.reverse();
    list.forwardTraversal();

    list.clear();
    cout << list.doubleLinkedListSize() << endl;

    list.forwardTraversal();
    list.backwardTraversal();
}*/



// Problem 1 In Stack : Convert the infix expression to postfix expression
/*
int main() {
    string infix = "X^Y/(5*Z)+2";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;

    infix = "A+B*C+D";
    postfix = infixToPostfix(infix);
    cout << postfix << endl;

    infix = "(A+B)*(C+D)";
    postfix = infixToPostfix(infix);
    cout << postfix << endl;
}
*/