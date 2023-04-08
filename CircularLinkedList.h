#ifndef ASSIGNMENT2_DATA_STRUCTURE_CIRCULARLINKEDLIST_H
#define ASSIGNMENT2_DATA_STRUCTURE_CIRCULARLINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;


template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T element): data(element), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;

public:
    CircularLinkedList(): head(nullptr), tail(nullptr), size(0) {}

    void insertAtHead(T element) {
        Node* newNode = new Node(element);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        size++;
    }

    void insertAtEnd(T element) {
        Node* newNode = new Node(element);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        size++;
    }

    void insertAt(T element, int index) {
        if(index < 0 || index > size) {
            cout << "Invalid index!" << endl;
            return;
        }
        if(index == 0) {
            insertAtHead(element);
            return;
        }
        if(index == size) {
            insertAtEnd(element);
            return;
        }
        Node* newNode = new Node(element);
        Node* temp = head;
        for(int i = 0; i < index-1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void removeAtHead() {
        if(head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if(size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        size--;
    }

    void removeAtEnd() {
        if(head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if(size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* temp = head;
            while(temp->next != tail) {
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
        }
        size--;
    }

    void removeAt(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        if(index == 0) {
            removeAtHead();
            return;
        }
        if(index == size-1) {
            removeAtEnd();
            return;
        }
        Node* temp = head;
        for(int i = 0; i < index-1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        size--;
    }


    T retrieveAt(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return T();
        }
        Node* temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void replaceAt(T newElement, int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        Node* temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = newElement;
    }

    bool isExist(T element) {
        if(head == nullptr) {
            return false;
        }
        Node* temp = head;
        do {
            if(temp->data == element) {
                return true;
            }
            temp = temp->next;
        } while(temp != head);
        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return false;
        }
        Node* temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data == element;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if(firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size || firstItemIdx == secondItemIdx) {
            cout << "Invalid indices!" << endl;
            return;
        }
        Node* firstItem = head;
        for(int i = 0; i < firstItemIdx; i++) {
            firstItem = firstItem->next;
        }
        Node* secondItem = head;
        for(int i = 0; i < secondItemIdx; i++) {
            secondItem = secondItem->next;
        }
        Node* temp = firstItem->next;
        firstItem->next = secondItem->next;
        secondItem->next = temp;
        temp = firstItem->next->next;
        firstItem->next->next = secondItem->next->next;
        secondItem->next->next = temp;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int circularLinkedListSize() {
        return size;
    }

    void clear() {
        while(!isEmpty()) {
            removeAtEnd();
        }
    }

    void print() {
        if(head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
        cout << endl;
    }
};


#endif //ASSIGNMENT2_DATA_STRUCTURE_CIRCULARLINKEDLIST_H
