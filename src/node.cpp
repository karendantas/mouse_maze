#include "../include/node.h"
#include <iostream>
using namespace std;

Node::Node(int new_x, int new_y){
    x = new_x;
    y = new_y;
    next = NULL;
}

//Node::~Node(){}

int Node::getX(){
  return x;
}
int Node::getY(){
  return y;
}
void Node::setX(int new_x){
   x = new_x;
}
void Node::setY(int new_y){
   y = new_y;
}
Node* Node::getNext(){
  return next;
}
void Node::setNext(Node *n){
  next = n;
}