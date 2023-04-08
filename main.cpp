#include "arrayBasedList.h"
<<<<<<< HEAD
#include "SingleLinkedList.h"
int main(){
  Single_linked_list<int> lis;
  lis.InsertTHead(4);
  lis.InsertTHead(3);
  lis.InsertTHead(2);
  lis.InsertTHead(1);
  lis.InsertAt(6,3);
  lis.print();
  lis.swap_(1,2);
  lis.print();
}
=======
#include "CircularLinkedList.h"

>>>>>>> e0b02f55e04b331d01d9c3f07fdd81198202d750
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