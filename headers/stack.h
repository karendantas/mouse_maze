#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <iostream>

class Stack {
    Node *top;
    public:
      Stack();
      void push(*Node);
      void pop(*Node);

      void peek();
      bool isEmpty();

}


#endif //STACK_H
