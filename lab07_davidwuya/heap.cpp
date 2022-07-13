// heap.cpp
// Diba Mirza
// Author: David Zhu

#include "heap.h"
#include <iostream>
using namespace std;

int parent(int idx) { return (idx - 1) / 2; }
int left(int idx) { return 2 * idx + 1; }
int right(int idx) { return 2 * idx + 2; }

void Heap::heapifyUp(int idx) {
  while (idx > 0) {
    if (vdata[idx] >= vdata[parent(idx)]) {
      return;
    } else {
      int temp = vdata[idx];
      vdata[idx] = vdata[parent(idx)];
      vdata[parent(idx)] = temp;
      idx = parent(idx);
    }
  }
}

void Heap::heapifyDown(int idx) {
  while (left(idx) < vdata.size()) {
    int min = vdata[idx];
    int s = -1;
    int i = 0;
    while (i < 2 && i + left(idx) < vdata.size()) {
      if (vdata[i + left(idx)] < min) {
        min = vdata[i + left(idx)];
        s = i + left(idx);
      }
      i++;
    }
    if (min == vdata[idx]) {
      return;
    } else {
      int temp = vdata[idx];
      vdata[idx] = vdata[s];
      vdata[s] = temp;
      idx = s;
    }
  }
}

void Heap::push(int value) {
  vdata.push_back(value);
  heapifyUp(vdata.size() - 1);
}

void Heap::pop() {
  vdata[0] = vdata[vdata.size() - 1];
  vdata.pop_back();
  heapifyDown(0);
}

// Returns the minimum element in the heap
int Heap::top() { return vdata[0]; }

// Returns true if the heap is empty, false otherwise
bool Heap::empty() { return vdata.size() == 0; }