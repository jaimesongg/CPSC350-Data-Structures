#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <stdexcept> // exception handling
#include <cstdlib> // for dynamic memory allocation

template <typename T>
class MonoStack {
public:
    MonoStack(int iSize, char o);
    ~MonoStack();
    void push(T c); 
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
    int size();

private:
    T* stackArr;  // array for stack elements
    int count;    // current size
    int top;      // index of top element
    int max;      // maximum size
    char order;   // i = increasing, d = decreasing
};

// constructor
template<typename T>
// initializes stack with specified size and order
MonoStack<T>::MonoStack(int iSize, char o) : count(0), top(-1), max(iSize), order(o) {
    stackArr = new T[max];
}

// destructor
template<typename T>
MonoStack<T>::~MonoStack() {
    delete[] stackArr;
}

template<typename T>
void MonoStack<T>::push(T c) {
    // if stack is full it doubles its size
    if (isFull()) {
        T* temp = new T[2 * max]; // creates the new array
        for (int i = 0; i < max; ++i) {
            temp[i] = stackArr[i]; // copies old stack elements to new array
        }
        max *= 2;
        delete[] stackArr;
        stackArr = temp; // points to new array
    }

    if (order == 'i') {  // monotonically increasing
        // removes elements from top until empty (LIFO) or top is smaller than new element
        while (!isEmpty() && peek() > c) {
            pop();
        }
    } else if (order == 'd') {  // monotonically decreasing
        // removes elements from top until empty or top element is larger than new element
        while (!isEmpty() && peek() < c) {
            pop();
        }
    }

    // pushes new element
    stackArr[++top] = c;
    ++count; // increments number of elements
}

template<typename T>
T MonoStack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty"); // exception handling if trying to pop from empty stack
    }
    --count; // decreases element count
    return stackArr[top--]; // return top elemt and moves top index down
}

template<typename T>
T MonoStack<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return stackArr[top];
}

// checks if stack is empty
template<typename T>
bool MonoStack<T>::isEmpty() {
    return count == 0; // stack is empty if count = 0
}

// checks if stack is full
template<typename T>
bool MonoStack<T>::isFull() {
    return count == max; // stack is full when count = max
}

// returns size of stack
template<typename T>
int MonoStack<T>::size() {
    return count;
}

#endif

