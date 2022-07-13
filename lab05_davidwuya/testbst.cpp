#include <iostream>
#include "intbst.h"
#include <vector>
#include <queue>
using std::cout;

int main(){
IntBST<float> bst1;

    bst1.insert(-7.3);
    bst1.insert(18.3);
    bst1.insert(-12.3);
    bst1.insert(0.3);
    bst1.insert(-4.3);
    bst1.insert(9.3);
    bst1.insert(7.3);
    bst1.insert(13.3);
    cout << bst1.getPredecessor(-7.3) << endl;
    cout << bst1.getPredecessor(18.3)<< endl;
    cout << bst1.getPredecessor(0.3)<< endl;
    cout << bst1.getPredecessor(7.3)<< endl;
    bst1.remove(-12.3);
    bst1.remove(18.3);
}