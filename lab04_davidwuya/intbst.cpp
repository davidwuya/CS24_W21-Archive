// intbst.cpp
// Implements class IntBST
// David Zhu, Apr 28 2022

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST():root(0) { 

}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if (!root){
        root = new Node(value);
        return true;
    }
    else {
        return insert(value, root);
    }
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info){
        return false;
    }
    if (value < n->info){
        if (n->left){
            return insert(value,n->left);
        }
        else {
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
    }
    else{
        if (n->right){
            return insert(value,n->right);
        }
        else {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n){
        cout<< n->info << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
   if (!n){
       return;
   }
   else{
       if (n->left){
           printInOrder(n->left);
       }
        cout << n->info << " ";
        if (n->right) {
            printInOrder(n->right);
        }
   }
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
       if (!n){
       return;
   }
   else{
       if (n->left){
           printInOrder(n->left);
       }
        
        if (n->right) {
            printInOrder(n->right);
        }
    cout << n->info << " ";
   }
}


// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (!n){
        return 0;
    }
    return n->info + sum(n->left) + sum(n->right);
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    int thisCount = 0;
    if (!n){
        return thisCount;
    }
    else{
        if (n->left){
            thisCount = thisCount + count(n->left);
        }
        if (n->right){
            thisCount = thisCount + count(n->right);
        }
    }
    return thisCount + 1; //account for root node
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (!n){
        return NULL;
    }
    if (n->info == value){
        return n;
    }
    if (n->info < value){
        return getNodeFor(value, n->right);
    }
    else{
        return getNodeFor(value, n->left);
    }
    return NULL;
}


// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return getNodeFor(value, root);
}
IntBST::Node* IntBST::getMax(Node *n) const{
    while (!n->right){
        n = n->right;
    }
    return n;
}
// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
//  Node* thisNode = getNodeFor(value, root);
//  Node* predecessor = NULL;
//  if (!thisNode){
//      return NULL;
//  }
//  if (thisNode->left){
//      return getMax(thisNode->left);
//  }
//  else{
//      predecessor = thisNode->parent;
//      while (!predecessor && thisNode == predecessor->left){
//          thisNode = predecessor;
//          predecessor = predecessor->parent;
//      }
//  return predecessor;
//  }
    return NULL;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    return 0;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    return NULL;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    return -1;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
//  Node* thisNode = getNodeFor(value, root);
    return true;
}
