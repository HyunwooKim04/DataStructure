// stack.h

#include <iostream>

template <class T>
class Stack {
public:
    Stack(int stackCapacity = 10);
    bool IsEmpty() const;
    const T& Top() const;
    void Push(const T& item);
    void Pop();

    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& st) {
        for (int i = 0; i <= st.top; i++) {
            os << '[' << st.stack[i] << "] ";
        }
        return os;
    }

private:
    T* stack;
    int top;
    int capacity;
};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity) {
    if(capacity < 1) throw "Stack capacity must be > 0";
    stack = new T[capacity];
    top = -1;
}

template <class T>
bool Stack<T>::IsEmpty() const {
    return top == -1;
}

template <class T>
const T& Stack<T>::Top() const {
    if (IsEmpty()) throw "Stack is empty";
    return stack[top];
}

template <class T>
void Stack<T>::Push(const T& item) {
    if (top == capacity - 1) throw "Stack is full";
    stack[++top] = item;
}

template <class T>
void Stack<T>::Pop() {
    if (IsEmpty()) throw "Stack is empty";
    top--;
}
