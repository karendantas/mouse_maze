#include <iostream>

#ifndef NODE_H
#define NODE_H

class Node{
   int x;
   int y;
   Node *next;

   public:
     Node(int new_x, int new_y);
     int getX();
     int getY();
     void setX(int new_x);
     void setY(int new_y);

     Node *getNext();
     void setNext(Node *n);

 };

#endif //NODE_H
