#ifndef ASSIGNMENT2_DATA_STRUCTURE_DOUBLYLINKEDLIST_H
#define ASSIGNMENT2_DATA_STRUCTURE_DOUBLYLINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;
template<typename T>


class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node *prev;
        Node *next;

        Node(T element, Node *p = nullptr, Node *n = nullptr) : data(element), prev(p), next(n) {}
    };

    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertAtHead(T element) {
        Node *newNode = new Node(element, nullptr, head);
        if (head == nullptr) {
            tail = newNode;
        } else {
            head->prev = newNode;
        }
        head = newNode;
        size++;
    }

    void insertAtTail(T element) {
        Node *newNode = new Node(element, tail, nullptr);
        if (tail == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        size++;
    }

    void insertAt(T element, int index) {
        if (index < 0 || index > size) {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }
        if (index == 0) {
            insertAtHead(element);
            return;
        }
        if (index == size) {
            insertAtTail(element);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node *newNode = new Node(element, temp, temp->next);
        temp->next->prev = newNode;
        temp->next = newNode;
        size++;
    }

    void insertAfter(Node *prev_node, T element) {
        if (prev_node == nullptr) {
            std::cout << "Previous node cannot be null!" << std::endl;
            return;
        }
        if (prev_node == tail) {
            insertAtTail(element);
            return;
        }
        Node *newNode = new Node(element, prev_node, prev_node->next);
        prev_node->next->prev = newNode;
        prev_node->next = newNode;
        size++;
    }

    void removeAtHead() {
        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void removeAtTail() {
        if (tail == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }
        if (index == 0) {
            removeAtHead();
            return;
        }
        if (index == size - 1) {
            removeAtTail();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }


    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds!" << std::endl;
            return T();
        }
        Node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = newElement;
    }

    bool isExist(T element) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->data == element) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds!" << std::endl;
            return false;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data == element;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size) {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        Node *temp = head;
        Node *firstNode = nullptr;
        Node *secondNode = nullptr;
        for (int i = 0; i < size; i++) {
            if (i == firstItemIdx) {
                firstNode = temp;
            }
            if (i == secondItemIdx) {
                secondNode = temp;
            }
            if (firstNode != nullptr && secondNode != nullptr) {
                break;
            }
            temp = temp->next;
        }
        firstNode->next->prev = secondNode;
        secondNode->next->prev = firstNode;
        std::swap(firstNode->next, secondNode->next);
        std::swap(firstNode->prev, secondNode->prev);
    }

    void reverse() {
        Node *temp = nullptr;
        Node *current = head;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    int doubleLinkedListSize() {
        return size;
    }

    void clear() {
        while (head != nullptr) {
            removeAtHead();
        }
    }

    void forwardTraversal() {
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void backwardTraversal() {
        Node *temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
};



                #endif //ASSIGNMENT2_DATA_STRUCTURE_DOUBLYLINKEDLIST_H
