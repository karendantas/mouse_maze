#include "node.h"
#include <iostream>

#ifndef STACK_H
#define STACK_H


class Stack {
  public:
   Node *top;
   public:
     Stack();
     void push(int x, int y);
     void pop();

     Node* peek();
     bool isEmpty();

     friend std::ostream& operator<<(std::ostream &os, const Stack &stack);

};


#endif //STACK_H
