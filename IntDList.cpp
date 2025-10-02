#include "IntDList.hpp"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor
IntDLList::IntDLList() {
    head = tail = nullptr;
}

// Destructor
IntDLList::~IntDLList() {
    while (head) {
        deleteFromHead();
    }
}

// Add to head
void IntDLList::addToHead(int val) {
    IntDLLNode *newNode = new IntDLLNode(val, head, nullptr);
    if (!head) {
        tail = newNode;
    } else {
        head->prev = newNode;
    }
    head = newNode;
}

// Add to tail
void IntDLList::addToTail(int val) {
    IntDLLNode *newNode = new IntDLLNode(val, nullptr, tail);
    if (!tail) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
}

// Insert in order
void IntDLList::insertInOrder(int val) {
    if (!head || val <= head->info) {
        addToHead(val);
        return;
    }
    if (val >= tail->info) {
        addToTail(val);
        return;
    }

    IntDLLNode *current = head;
    while (current && current->info < val) {
        current = current->next;
    }

    IntDLLNode *newNode = new IntDLLNode(val, current, current->prev);
    current->prev->next = newNode;
    current->prev = newNode;
}

// Delete from head
int IntDLList::deleteFromHead() {
    if (!head) throw runtime_error("Cannot delete from an empty list.");
    int val = head->info;
    IntDLLNode *temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    return val;
}
 // Delete from tail 
int IntDLList::deleteFromTail() {
    if (!tail) throw runtime_error("Cannot delete from an empty list.");
    int val = tail->info;
    IntDLLNode *temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    return val;
}


// Delete specific node
void IntDLList::deleteNode(int val) {
    if (!head) return;
    if (head->info == val) {
        deleteFromHead();
        return;
    }
    if (tail->info == val) {
        deleteFromTail();
        return;
    }

    IntDLLNode *current = head->next;
    while (current && current->info != val) {
        current = current->next;
    }

    if (!current) return;

    current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;
    delete current;
}

// Check if value is in list
bool IntDLList::isInList(int val) const {
    IntDLLNode *current = head;
    while (current) {
        if (current->info == val) return true;
        current = current->next;
    }
    return false;
}

// Print all elements
void IntDLList::printAll() const {
    IntDLLNode *current = head;
    while (current) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

// Convert list to string
string IntDLList::addToString() const {
    ostringstream oss;
    IntDLLNode *current = head;
    while (current) {
        oss << current->info;
        current = current->next;
    }
    return oss.str();
}


