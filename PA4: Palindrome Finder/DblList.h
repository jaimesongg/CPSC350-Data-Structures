#ifndef DBLLIST_H
#define DBLLIST_H

#include <iostream>

template <typename T>
class DblList {
public:
    // nested node structure to represent each element in the list
    struct Node {
        T data;        
        Node* next;    
        Node* prev;    
        // constructor for node
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };

    DblList();  
    ~DblList(); 

    void insertBack(T value); // inserts new node at end of the list
    void deleteNode(Node* node); // deletes specific node in the list
    Node* getHead() const; 
    Node* getTail() const; 
    void clear(); 

private:
    Node* head; 
    Node* tail; 
    int size;   
};

template <typename T>
DblList<T>::DblList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DblList<T>::~DblList() { 
    clear(); 
}

template <typename T>
void DblList<T>::insertBack(T value) {
    Node* newNode = new Node(value); // creates new node with given value

    if (!head) { // if list is empty set head/tail to new node
        head = newNode;
        tail = newNode;
    } else { // if list has elements add new node at the end
        tail->next = newNode; 
        newNode->prev = tail; 
        tail = newNode; 
    }
    ++size; 
}

template <typename T>
void DblList<T>::deleteNode(Node* node) {
    if (!node) return; // if node is nullptr = do nothing

    // if node is head = update head to next node
    if (node == head) {
        head = head->next;
        if (head) head->prev = nullptr; 
    }
    // if node is the tail = update tail to previous node
    else if (node == tail) {
        tail = tail->prev;
        if (tail) tail->next = nullptr;
    }
    // for middle node link previous and next nodes to bypass it
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    delete node; 
    --size;
}

template <typename T>
typename DblList<T>::Node* DblList<T>::getHead() const {
    return head;
}

template <typename T> 
typename DblList<T>::Node* DblList<T>::getTail() const {
    return tail;
}

// clears entire list and frees memory for each node
template <typename T> 
void DblList<T>::clear() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    // resets everything to nullptr
    head = nullptr;
    tail = nullptr;
    size = 0;   
}

#endif 
