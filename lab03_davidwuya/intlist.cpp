// intlist.cpp
// Implements class IntList
// David Zhu, Apr 27 2022

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    first = 0;
    Node* t = source.first;
    while(t){
        append(t->info);
        t = t->next;
    }
    
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* t = first;
    
    while(t){
        t = t->next;
        delete first;
        first = t;
    }
    delete t;
    delete first;

}


// return sum of values in list
int IntList::sum() const {
    int thisSum = 0;
    Node* t = first;
    
    while(t){
        thisSum = thisSum + t->info;
        t = t->next;
    }

    return thisSum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* t = first;
    
    while(t){
        if(t->info == value){
            return true;
        }
        t = t->next;
        
    }
    
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = 0;
    Node* t = first;
    if (!t){
        return 0;
    }
    while(t){
        if(t->info > max){
            max = t->info;
            
        }
        t = t->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    Node* t = first;
    if(!t){
        return 0.0;
    }
    double thisSum = sum();
    double thisCount = count();
    double avg = thisSum/thisCount;
    return avg;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = first;
    first = newNode;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    Node* t1 = first;
    Node* t2 = source.first;
    
    while(t1){
        t1 = t1->next;
        delete first;
        first = t1;
    }
    delete t1;
    delete first;
    while(t2){
        append(t2->info);
        t2 = t2->next;
    }

    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
