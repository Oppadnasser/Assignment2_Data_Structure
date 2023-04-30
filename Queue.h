#ifndef ASSIGNMENT2_DATA_STRUCTURE_QUEUE_H
#define ASSIGNMENT2_DATA_STRUCTURE_QUEUE_H

#include <bits/stdc++.h>
using namespace std;
template<typename T>


class Queue {
private:
    T* data;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int capacity) : front(0), rear(-1), capacity(capacity), size(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(T element) {
        if (isFull()) {
            throw logic_error("Queue is full.");
        }
        rear = (rear + 1) % capacity;
        data[rear] = element;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw logic_error("Queue is empty.");
        }
        T element = data[front];
        front = (front + 1) % capacity;
        size--;
        return element;
    }

    T first() {
        if (isEmpty()) {
            throw logic_error("Queue is empty.");
        }
        return data[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int queueSize() {
        return size;
    }

    void clear() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        do {
            cout << data[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << endl;
    }
};


#endif //ASSIGNMENT2_DATA_STRUCTURE_QUEUE_H
