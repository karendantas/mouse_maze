#include "include/node.h"
#include "include/stack.h"
#include <iostream>
using namespace std;


int main (){
  Stack stack1;

  stack1.push(10, 2);
  stack1.push(3, 4);
  stack1.push(5, 6);
  cout << stack1;
    stack1.pop();
  cout << endl;
  cout << stack1;

  return 0;
  }