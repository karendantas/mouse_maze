#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
   int x;
   int y;
   Node *next;

   public:
     Node(int x, int y);
     int getX();
     int getY();
     void setX(int x);
     void setY(int y);
     Node *getNext();
     void setNext(Node *next);

 };

#endif //NODE_H
