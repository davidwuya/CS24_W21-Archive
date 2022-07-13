// usestack.cpp - for CS 24 lab practice using stacks
// David Zhu, May 25

#include "intstack.h"
#include <iostream>
using namespace std;

int main() {
    Stack s;
    s.push(50);
    s.push(20);
    s.push(30);
    int right = s.top();
    s.pop();
    int left = s.top();
    s.pop();
    s.push(left + right);
    cout << s.top() << endl;
    s.pop();
    s.push(30);
    cout << s.top() << endl;
    return 0;
}
