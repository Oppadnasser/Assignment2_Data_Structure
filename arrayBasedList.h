#ifndef ASSIGNMENT2_DATA_STRUCTURE_ARRAYBASEDLIST_H
#define ASSIGNMENT2_DATA_STRUCTURE_ARRAYBASEDLIST_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class ArrayList {
private:
    T* data;
    int capacity;
    int size;

public:
    ArrayList(int capacity) : capacity(capacity), size(0) {
        data = new T[capacity];
    }

    ~ArrayList() {
        delete[] data;
    }

    void insert(T element) {
        if (isFull()) {
            throw overflow_error("List is full");
        }
        data[size] = element;
        size++;
    }

    void insertAt(T element, int index) {
        if (index < 0 || index > size) {
            throw out_of_range("Invalid index");
        }
        if (isFull()) {
            throw overflow_error("List is full");
        }
        for (int i = size; i > index; i--) {
            data[i] = data[i-1];
        }
        data[index] = element;
        size++;
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }
        return data[index];
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }
        for (int i = index; i < size-1; i++) {
            data[i] = data[i+1];
        }
        size--;
    }

    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }
        data[index] = newElement;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }
        return data[index] == element;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int listSize() {
        return size;
    }

    int maxListSize() {
        return capacity;
    }

    void clear() {
        size = 0;
    }

    void print() {
        cout << "[";
        for (int i = 0; i < size; i++) {
            std::cout << data[i];
            if (i < size-1) {
                std::cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};


#endif //ASSIGNMENT2_DATA_STRUCTURE_ARRAYBASEDLIST_H
