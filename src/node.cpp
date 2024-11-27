#inlcude "node."
#include <iostream>
using namespace std;

Node::Node(int x, int y){
    this->x = x;
    this->y = y;
    this->next = NULL;
}

Node::~Node(){}

int Node::getx(){
  return this->x;
}
int Node::gety(){
  return this->y;
}
void Node::setx(int x){
  this->x = x;
}
void Node::sety(int y){
  this->y = y;
}
Node* Node::getnext(){
  return this->next;
}
void Node::setnext(Node *n){
  this->next = n;
}