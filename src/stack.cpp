#include "../include/stack.h"
#include "../include/node.h"
#include <iostream>
using namespace std;
Stack::Stack(){
    top = NULL;
}
//Stack::~Stack(){}

bool Stack::isEmpty(){
  return top == NULL;
}

//como é uma pilha, os Nodes sempre irão entrar no "começo"
//ou seja, eles sempre serão um topo;
void Stack::push(int x, int y){
    Node *newNode = new Node(x,y);

    newNode->setNext(top);
    top = newNode;
}

void Stack::pop(){
  if(isEmpty()) return;

  Node *current = top;

  top = current->getNext();
  delete current;
  free(current);

}

Node* Stack::peek(){
    if(isEmpty()) return NULL;

    cout << top->getX() << " " << top->getY() << endl;
    Node *current = top;
    return current;
}

std::ostream& operator<<(std::ostream &os, const Stack &stack){
    Node *current = stack.top;
    while(current != NULL){
      os << current->getX() << " " << current->getY() << endl;
      current = current->getNext();
    }
}