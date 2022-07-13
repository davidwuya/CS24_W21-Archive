// cards.h
// Author: David Zhu
// All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <cstddef>
#include <string>
#endif
#include <iostream>

using namespace std;

struct Node{
    char suit;
    int value;
    Node *left, *right, *parent;
    Node(char s = '\0', int v = 0): suit(s), value(v), left(0), right(0), parent(0){}
    bool operator ==(const Node& c);
    bool operator !=(const Node& c);
    bool operator <(const Node& c);
    bool operator >(const Node& c);
    Node* operator =(const Node& c);
};


class BST {
    public:
        BST();
        ~BST();
        bool insert(char suit, int value);
        void printInOrder() const;
        int count() const;
        Node* getMax(Node* n) const;
        Node* getMin(Node* n) const;
        bool remove(char suit, int value);
        bool contains(char suit, int value) const;
        bool contains(Node* n) const;
        Node* getPredecessor(char suit, int value) const;
        Node* getSuccessor(char suit, int value) const;
        Node* getNodeFor(Node* targetNode, Node *n) const;
        Node* getRoot() const;
        void inOrderTraversal(Node* root, Node* n, Node** pred, Node** succ) const;
        Node* createNode(char suit, int value, Node* left, Node* right, Node* parent);
        bool equals(Node* a, Node* b) const;
        bool greaterThan(Node* a, Node* b) const;
        bool nullCard(Node* a) const;
    
    private:
        Node* root;
        bool insert(char suit, int value, Node *n);
        void clear(Node *n);
        Node* find(char suit, int value, Node* n) const;
        void printInOrder(Node *n) const;
        int count(Node *n) const;
        Node* getSuccessorHelper(Node* n) const;
        Node* getPredecessorHelper(Node* n) const;
};