#include "arrayBasedList.h"
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