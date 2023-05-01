#ifndef ASSIGNMENT2_DATA_STRUCTURE_STACK_H
#define ASSIGNMENT2_DATA_STRUCTURE_STACK_H

#include <bits/stdc++.h>
using namespace std;

template<typename elementType>
class Stack {
private:
    int capacity;
    elementType* data;
    int topIndex;
public:
    Stack(int capacity) {
        this->capacity = capacity;
        data = new elementType[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] data;
    }

    void push(elementType element) {
        if (topIndex == capacity - 1) {
            throw out_of_range("Stack is full");
        }
        topIndex++;
        data[topIndex] = element;
    }

    elementType pop() {
        if (topIndex == -1) {
            throw out_of_range("Stack is empty");
        }
        elementType element = data[topIndex];
        topIndex--;
        return element;
    }

    elementType top() {
        if (topIndex == -1) {
            throw out_of_range("Stack is empty");
        }
        return data[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int stackSize() {
        return topIndex + 1;
    }

    void clear() {
        topIndex = -1;
    }

    void print() {
        for (int i = topIndex; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

#endif //ASSIGNMENT2_DATA_STRUCTURE_STACK_H
