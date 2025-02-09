#include "IntDList.hpp"

// Constructor
IntDLList::IntDLList() : head(nullptr), tail(nullptr) {}

// Destructor
IntDLList::~IntDLList() {
    while (head != nullptr) {
        deleteFromHead();
    }
}

// Add to head
void IntDLList::addToHead(int value) {
    Node* newNode = new Node{value, nullptr, head};
    if (head) head->prev = newNode;
    head = newNode;
    if (!tail) tail = head;
}

// Add to tail
void IntDLList::addToTail(int value) {
    Node* newNode = new Node{value, tail, nullptr};
    if (tail) tail->next = newNode;
    tail = newNode;
    if (!head) head = tail;
}

// Insert in order
void IntDLList::insertInOrder(int value) {
    if (!head || value <= head->data) {
        addToHead(value);
        return;
    }
    if (value >= tail->data) {
        addToTail(value);
        return;
    }
    Node* current = head;
    while (current && current->data < value) {
        current = current->next;
    }
    Node* newNode = new Node{value, current->prev, current};
    current->prev->next = newNode;
    current->prev = newNode;
}

// Delete from head
int IntDLList::deleteFromHead() {
    if (!head) throw std::runtime_error("List is empty");
    int value = head->data;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    return value;
}

// Delete from tail
int IntDLList::deleteFromTail() {
    if (!tail) throw std::runtime_error("List is empty");
    int value = tail->data;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    return value;
}

// Delete a specific node
void IntDLList::deleteNode(int value) {
    Node* current = head;
    while (current && current->data != value) {
        current = current->next;
    }
    if (!current) return;
    if (current == head) deleteFromHead();
    else if (current == tail) deleteFromTail();
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

// Check if value is in list
bool IntDLList::isInList(int value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

// Print all values
void IntDLList::printAll() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Convert list to string
std::string IntDLList::addToString() const {
    std::ostringstream oss;
    Node* current = head;
    while (current) {
        oss << current->data;
        current = current->next;
    }
    return oss.str();
}