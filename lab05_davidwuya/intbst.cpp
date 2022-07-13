// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
template <class T>
IntBST<T>::IntBST() : root(nullptr) {}

// destructor deletes all nodes
template <class T>
IntBST<T>::~IntBST()
{
  clear(root);
}

// recursive helper for destructor
template <class T>
void IntBST<T>::clear(Node *n)
{
  if (n)
  {
    clear(n->left);
    clear(n->right);
    delete n;
  }
}

// insert value in tree; return false if duplicate
template <class T>
bool IntBST<T>::insert(T value)
{
  if (!root)
  {
    root = new Node(value);
    return true;
  }
  else
  {
    return insert(value, root);
  }
}

// recursive helper for insert (assumes n is never 0)
template <class T>
bool IntBST<T>::insert(T value, Node *n)
{
  if (value == n->info)
  {
    return false;
  }
  if (value < n->info)
  {
    if (n->left)
    {
      return insert(value, n->left);
    }
    else
    {
      n->left = new Node(value);
      n->left->parent = n;
      return true;
    }
  }
  else
  {
    if (n->right)
    {
      return insert(value, n->right);
    }
    else
    {
      n->right = new Node(value);
      n->right->parent = n;
      return true;
    }
  }
}

// print tree data pre-order
template <class T>
void IntBST<T>::printPreOrder() const
{
  printPreOrder(root);
}

// recursive helper for printPreOrder()
template <class T>
void IntBST<T>::printPreOrder(Node *n) const
{
  if (n)
  {
    cout << n->info << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
  }
}

// print tree data in-order, with helper
template <class T>
void IntBST<T>::printInOrder() const
{
  printInOrder(root);
}

template <class T>
void IntBST<T>::printInOrder(Node *n) const
{
  if (!n)
  {
    return;
  }
  else
  {
    if (n->left)
    {
      printInOrder(n->left);
    }
    cout << n->info << " ";
    if (n->right)
    {
      printInOrder(n->right);
    }
  }
}

template <class T>
void IntBST<T>::printPostOrder() const

{
  printPostOrder(root);
}
template <class T>
void IntBST<T>::printPostOrder(Node *n) const
{
  if (!n)
  {
    return;
  }
  else
  {
    if (n->left)
    {
      printPostOrder(n->left);
    }

    if (n->right)
    {
      printPostOrder(n->right);
    }
    cout << n->info << " ";
  }
}

template <class T>
T IntBST<T>::sum() const
{
  return sum(root);
}

template <class T>
T IntBST<T>::sum(Node *n) const
{
  if (!n)
  {
    return 0;
  }
  return n->info + sum(n->left) + sum(n->right);
}

template <class T>
int IntBST<T>::count() const
{
  return count(root);
}

template <class T>
int IntBST<T>::count(Node *n) const
{
  int thisCount = 0;
  if (!n)
  {
    return thisCount;
  }
  else
  {
    if (n->left)
    {
      thisCount = thisCount + count(n->left);
    }
    if (n->right)
    {
      thisCount = thisCount + count(n->right);
    }
  }
  return thisCount + 1; // account for root node
}

template <class T>
typename IntBST<T>::Node *IntBST<T>::getNodeFor(T value, Node *n) const
{
  if (!n)
  {
    return NULL;
  }
  if (n->info == value)
  {
    return n;
  }
  if (n->info < value)
  {
    return getNodeFor(value, n->right);
  }
  else
  {
    return getNodeFor(value, n->left);
  }
  return NULL;
}

template <class T>
bool IntBST<T>::contains(T value) const
{
  return getNodeFor(value, root);
}

template <class T>
typename IntBST<T>::Node *IntBST<T>::getPredecessorNode(T value) const

{
  Node *n = getNodeFor(value, root);
  if (!n)
  {
    return nullptr;
  }

  if (n->left)
  {
    n = n->left;
    while (n->right)
    {
      n = n->right;
    }
  }
  else
  {
    while (n->parent && n->parent->left == n)
    {
      n = n->parent;
    }
    if (!n->parent)
      return nullptr;

    n = n->parent;
  }
  return n;
}

template <class T>
T IntBST<T>::getPredecessor(T value) const
{
  return getPredecessorNode(value) ? getPredecessorNode(value)->info : T();
}

template <class T>
typename IntBST<T>::Node *IntBST<T>::getSuccessorNode(T value) const
{
  Node *n = getNodeFor(value, root);
  if (!n)
  {
    return nullptr;
  }
  if (n->right)
  {
    n = n->right;
    while (n->left)
    {
      n = n->left;
    }
  }
  else
  {
    while (n->parent && n->parent->right == n)
    {
      n = n->parent;
    }
    if (!n->parent)
      return nullptr;

    n = n->parent;
  }
  return n;
}

template <class T>
T IntBST<T>::getSuccessor(T value) const
{
  return getSuccessorNode(value) ? getSuccessorNode(value)->info : T();
}

template <class T>
bool IntBST<T>::remove(T value)
{
  Node *n = getNodeFor(value, root);
  if (!n)
  {
    return false;
  }
  Node *parent = n->parent;
  if (!n->left && !n->right)
  {
    if (n == root)
    {
      root = nullptr;
    }
    else if (n == parent->left)
    {
      parent->left = nullptr;
    }
    else if (n == parent->right)
    {
      parent->right = nullptr;
    }
    else
    {
      return false;
    }
    delete n;
    return true;
  }
  else if (n->left && n->right)
  {
    T next = getSuccessor(value);
    remove(next);
    n->info = next;
    return true;
  }
  else
  {
    Node *child = n->left ? n->left : n->right;
    if (n->info == parent->info)
    {
      root = child;
      child->parent = nullptr;
    }
    else if (n->info < parent->info)
    {
      child->parent = parent;
      parent->left = child;
    }
    else if (n->info > parent->info)
    {
      child->parent = parent;
      parent->right = child;
    }
    else
    {
      return false;
    }
    delete n;
    return true;
  }
  return false;
}
