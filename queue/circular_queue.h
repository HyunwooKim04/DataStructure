// circular_queue.h

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <iostream>

template <class T>
class CircularQueue {
public:
    CircularQueue(int capacity = 10);
    ~CircularQueue();

    void Push(const T& item);
    void Pop();
    const T& Front() const;

    bool IsEmpty() const;
    bool IsFull() const;

    friend std::ostream& operator<<(std::ostream& os, const CircularQueue<T>& q) {
        if (q.IsEmpty()) {
            os << "[empty]";
            return os;
        }

        int i = q.front;
        while (true) {
            os << "[" << q.queue[i] << "] ";
            if (i == q.rear) break;
            i = (i + 1) % q.capacity;
        }
        return os;
    }

private:
    T* queue;
    int front;
    int rear;
    int size;
    int capacity;
};

template <class T>
CircularQueue<T>::CircularQueue(int cap) : capacity(cap), front(0), rear(capacity - 1), size(0) {
    if (capacity < 1) throw "Queue capacity must be > 0";
    queue = new T[capacity];
}

template <class T>
CircularQueue<T>::~CircularQueue() {
    delete[] queue;
}

template <class T>
bool CircularQueue<T>::IsEmpty() const {
    return size == 0;
}

template <class T>
bool CircularQueue<T>::IsFull() const {
    return size == capacity;
}

template <class T>
void CircularQueue<T>::Push(const T& item) {
    if (IsFull()) throw "Queue is full";
    rear = (rear + 1) % capacity;
    queue[rear] = item;
    size++;
}

template <class T>
void CircularQueue<T>::Pop() {
    if (IsEmpty()) throw "Queue is empty";
    front = (front + 1) % capacity;
    size--;
}

template <class T>
const T& CircularQueue<T>::Front() const {
    if (IsEmpty()) throw "Queue is empty";
    return queue[front];
}

#endif
