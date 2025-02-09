#ifndef INT_DLIST_HPP
#define INT_DLIST_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "IntDList_node.hpp"

class IntDLList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    // Constructor & Destructor
    IntDLList();
    ~IntDLList();

    // Member functions
    void addToHead(int value);
    void addToTail(int value);
    void insertInOrder(int value);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int value);
    bool isInList(int value) const;
    void printAll() const;
    std::string addToString() const;
};

#endif // INT_DLIST_HPP
