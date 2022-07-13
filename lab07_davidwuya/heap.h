// heap.h
// Binary heap tree header file for CS 24 lab
// Diba Mirza

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
int left(int idx);
int right(int idx);
int parent(int idx);
class Heap {

public:
  void push(int value); // insert value; //duplicates are allowed
  void pop();           // delete the min element
  int top();
  bool empty();
  void heapifyDown(int idx);
  void heapifyUp(int idx);

private:
  std::vector<int> vdata; // store the binary heap tree as a dynamic array
};

#endif