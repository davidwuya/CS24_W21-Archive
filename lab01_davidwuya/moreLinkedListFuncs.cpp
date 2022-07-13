#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"



void addIntToEndOfList(LinkedList *list, int value) {
  assert(list!=nullptr); // if list is nullptr, we can do nothing.

  // TODO:
  // (1) Allocate a new node.  p will point to it.
  Node* p = new Node;
  p->data = value;
  p->next = nullptr;

  // (2) Set p's data field to the value passed in
  
  // (3) Set p's next field to nullptr


  if (list->head == nullptr) {
    list->head = p;
    list->tail = p;
    // (4) Make both head and tail of this list point to p
    
  } else {
    
    Node* temp = list->head;
   while(temp->next != nullptr)
      temp = temp->next;
    temp->next = p;
    // Add p at the end of the list.   

    // (5) The current node at the tail? Make it point to p instead of nullptr

    // (6) Make the tail of the list be p now.

  }

}

void addIntToStartOfList(LinkedList *list, int value) {
  assert(list!=nullptr); // if list is nullptr, we can do nothing.
  // Add code for this.  
  // HINTS:
  //  You will need to allocate a new Node.
  Node* p = new Node;
  p->data=value;
  p->next = nullptr;
  //  You will need two cases just as in addIntToEndOfList,
  //  one for when list->head is nullptr and another for when it is not.
  if (list->head == nullptr) {
    list->tail = p->next;
    list->head = p;
    // (4) Make both head and tail of this list point to p
  }
  else{
    p->next = list->head;
    list->head = p;
  }
  // You need to consider how to make sure that list->head changes to point to the new node
  // that you allocated.  And you will need to make sure that when you are done, 
  // that if the new node is now the ONLY thing on the list, that tail points to it also,
  // and that the new node is pointing to nullptr.
  // Otherwise, you'll need to be sure that 
  // if it is the only node on the list, or to the "old" head if there 

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element  
// If more than one element has largest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node * pointerToMax(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list!=nullptr);
  assert(list->head != nullptr);
  // Assign first value to max
  int max = list->head->data;
  Node* maxHead = list->head;
  Node* head = list->head;
  // TODO: Insert code here to calculate and return
  // value of pointer to max element (first one if ties.)
  while (head != nullptr) {
        if (max < head->data){
            max = head->data;
            maxHead = head;
        }
      head = head->next;
    }
  return maxHead;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the smallest value.  
// You may assume list has at least one element
// If more than one element has smallest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head


Node * pointerToMin(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=nullptr);
  assert(list->head != nullptr);

  int min = list->head->data;
  Node* minHead = list->head;
  Node* head = list->head;
  // TODO: Insert code here to calculate and return
  // value of pointer to max element (first one if ties.)
  while (head != nullptr) {
        if (min > head->data){
            min = head->data;
            minHead = head;
        }
      head = head->next;
    }
  return minHead;


}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=nullptr);
  assert(list->head != nullptr);

  // TODO: Insert code here to calculate and return
  //   largest value in list (which may not be unique).

  return pointerToMax(list)->data;

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=nullptr);
  assert(list->head != nullptr);

  // TODO: Insert code here to calculate and return
  //   smallest value in list (which may not be unique).

  return pointerToMin(list)->data;

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not nullptr
// However, the list may be empty (i.e. list->head may be nullptr)
//  in which case your code should return 0.

int sum(LinkedList * list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=nullptr);
  int sum = 0;
  Node* head = list->head;
  while (head != nullptr) {
    sum = sum + head->data;
    head = head->next;
    }
  return sum;

}

