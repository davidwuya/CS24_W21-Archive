// cards.cpp
// Author: David Zhu
// Implementation of the classes defined in cards.h
#include "cards.h"
#include "utility.h"
#include <cstddef>
#include <string.h>
using namespace std;

BST::BST() : root(NULL){};

BST::~BST() { clear(root); }
void BST::clear(Node *n) {
  if (n) {
    clear(n->left);
    clear(n->right);
    delete n;
  }
}
Node *Node::operator=(Node const &c) {
  this->suit = c.suit;
  this->value = c.value;
  this->left = c.left;
  this->right = c.right;
  this->parent = c.parent;
  return this;
}

bool Node::operator!=(Node const &c) {
  return !(this->suit == c.suit) || !(this->value == c.value);
}
Node* BST::createNode(char suit, int value, Node *left=nullptr, Node *right=nullptr, Node *parent=nullptr){
  Node* returnNode = new Node(suit, value);
  returnNode->left = left;
  returnNode->right = right;
  returnNode->parent = parent;
  return returnNode;
}

bool BST::equals(Node* a, Node* b) const{
  if (nullCard(a)||nullCard(b)){return false;}
  return a->suit == b->suit && a->value == b->value;
}
bool BST::greaterThan(Node* a, Node* b) const{
  if (nullCard(a)||nullCard(b)){return false;}
  int AsuitValue = suitToValue(a->suit);
  int BsuitValue = suitToValue(b->suit);
  return AsuitValue + a->value > BsuitValue + b->value;
}


bool BST::nullCard(Node *a) const{
  return !a? true:!a->suit||!a->value;
}

bool BST::insert(char suit, int value) {
  if (nullCard(root)) {
    root = createNode(suit, value);
    return true;
  }
  return insert(suit, value, root);
}

bool BST::insert(char suit, int value, Node *n) {
  Node *thisNode = new Node(suit, value);
  // handle dupes
  if (equals(thisNode, n)||nullCard(n)){return false;}
  // small -> left
  if (!greaterThan(thisNode, n)) {
    if (n->left) {
      return insert(suit, value, n->left);
    } else {
      n->left = createNode(suit, value, nullptr, nullptr, n);
      // n->left = new Node(suit, value);
      // n->left->parent = n;
      return true;
    }
  }
  // large -> right
  else {
    if (n->right) {
      return insert(suit, value, n->right);
    } else {
      n->right = createNode(suit, value, nullptr, nullptr,n);
      // n->right->parent = n;
      return true;
    }
  }
}

void BST::printInOrder() const {printInOrder(root);}
void BST::printInOrder(Node *n) const {
  if (!n && !n->left && !n->right) {
    return;
  } else {
    if(n->left){printInOrder(n->left);}
    cout << NodetoString(n->suit, n->value) << endl;
    if(n->right){printInOrder(n->right);}
  }
}

Node *BST::getMax(Node *n) const {
  while (n && n->right) {
    n = n->right;
  }
  return n;
}
Node *BST::getMin(Node *n) const {
  while (n && n->left) {
    n = n->left;
  }
  return n;
}
Node *BST::getNodeFor(Node *targetNode, Node *n) const {
  if (nullCard(n)||nullCard(targetNode)){return nullptr;}
  while (n) {
    if (equals(n, targetNode)) {
      return n;
    } else if (greaterThan(targetNode,n)) {
      n = n->right;
    } else {
      n = n->left;
    }
  }
  return nullptr;
}

bool BST::contains(char suit, int value) const {
  return getNodeFor(new Node(suit, value), this->root);
}

bool BST::contains(Node *n) const { return getNodeFor(n, root); }
Node *BST::getRoot() const { return root; }

Node *BST::getSuccessor(char suit, int value) const {
  Node *n = getNodeFor(new Node(suit, value), root);
  return getSuccessorHelper(n) ? getSuccessorHelper(n) : NULL;
}

Node *BST::getSuccessorHelper(Node *n) const {
  if (nullCard(n)) {
    return NULL;
  }
  if (n->right != NULL) {
    return getMin(n->right);
  } else {
    while (n->parent && equals(n->parent->right, n)) {
      n = n->parent;
    }
    if (nullCard(n->parent)) {
      return NULL;
    }
    n = n->parent;
  }
  return n;
}

Node *BST::getPredecessor(char suit, int value) const {
  Node *n = getNodeFor(new Node(suit, value), root);
  return getPredecessorHelper(n);
}

Node *BST::getPredecessorHelper(Node *n) const {
  if (!n) {
    return NULL;
  }
  if (n->left != NULL) {
    return getMax(n->left);
  } else {
    while (n->parent && equals(n->parent->left, n)) {
      n = n->parent;
    }
    if (!n->parent) {
      return NULL;
    }
    n = n->parent;
  }
  return n;
}

bool BST::remove(char suit, int value) {
  Node *n = getNodeFor(new Node(suit, value), root);
  if (!n) {return false;}
  Node *parent = n->parent;
  if (!n->left && !n->right) {
    if (equals(n,root)) {
      root = NULL;
    } else if (equals(n,parent->left)) {
      parent->left = NULL;
    } else if (equals(n,parent->right)) {
      parent->right = NULL;
    }
    delete n;

  } else if (n->left && n->right) {
    int next_value = getSuccessor(suit, value)->value;
    char next_suit = getSuccessor(suit, value)->suit;
    remove(next_suit, next_value);
    n->value = next_value;
    n->suit = next_suit;

  } else {
    Node *child = n->left? n->left : n->right;
    if (equals(n, root)) {
      root = child;
      child->parent = nullptr;
    } else if (!greaterThan(n, parent)) {
      child->parent = parent;
      parent->left = child;
    } else if (greaterThan(n, parent)) {
      child->parent = parent;
      parent->right = child;
    }
    delete n;
  }

  return true;
}