#ifndef INTDLLIST_H
#define INTDLLIST_H
#include "IntDList_node.hpp"
#include <string>
using namespace std;

class IntDLList {
private:
    IntDLLNode *head, *tail;

public:
    IntDLList();                 // Constructor
    ~IntDLList();                // Destructor

    void addToHead(int);
    void insertInOrder(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;
    string addToString() const;
};

#endif /* INTDLLIST_H */
