#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
#include "utility.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
  
  BST alice;
  BST bob;
  char suit;
  int value;

  while (getline (cardFile1, line) && (line.length() > 0)){
    suit = line[0];
    value = valueToInt(line.substr(2));
    alice.insert(suit, value);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    suit = line[0];
    value = valueToInt(line.substr(2));
    bob.insert(suit, value); 
  }
  cardFile2.close();

bool AGame = true;
bool BGame = false;

while(true) {
  Node* aMin = alice.getMin(alice.getRoot());
  Node* bMax = bob.getMax(bob.getRoot());
  bool aMatch = false;
  bool bMatch = false;
  while(aMin) {
    Node* nextNode = alice.getSuccessor(aMin->suit, aMin->value);
    char thisSuit = aMin->suit;
    int thisValue = aMin->value;
    aMin = nextNode;
    BGame = true;
    if(bob.contains(thisSuit, thisValue) && AGame) {
      cout << "Alice picked matching card " << NodetoString(thisSuit, thisValue) << endl;
      bob.remove(thisSuit, thisValue);
      alice.remove(thisSuit, thisValue);
      aMatch = true;
      AGame = false;
      break;//go to bob's turn
    }
  }
  while(bMax) {
    Node* prevNode = bob.getPredecessor(bMax->suit, bMax->value);
    char thisSuit = bMax->suit;
    int thisValue = bMax->value;
    bMax = prevNode;
    AGame = true;
    if(alice.contains(thisSuit, thisValue) && BGame) {
      cout << "Bob picked matching card " << NodetoString(thisSuit, thisValue) << endl;
      alice.remove(thisSuit, thisValue);
      bob.remove(thisSuit, thisValue);
      bMatch = true;
      BGame = false;
      break; //go to alice's turn
    }
  }
  //all matched cards found
  if(!aMatch && !bMatch) {
    break;
  }
}
//inorder print cards
  cout << endl<< "Alice's cards:" << endl;
  alice.printInOrder();
  cout << endl << "Bob's cards:" << endl;
  bob.printInOrder();
}
