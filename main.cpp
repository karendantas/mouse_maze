#include "include/node.h"
#include "include/stack.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


int main (){
  ifstream maze_file("src/maze.txt");
  string line;

  // -- pegando linha  e coluna
  int rows, cols;

  string dimension_line;
  getline(maze_file, dimension_line);
  stringstream ss(dimension_line);
  char x_separator;

  ss >> rows >> x_separator >> cols;
  cout << rows << " " << x_separator << " " << cols << endl;
  // --

  // -- pegando a matriz

  char maze[rows][cols];

  string paths_inline;
  while (getline(maze_file, line)) {
    paths_inline += line;

  }
  cout << paths_inline << endl;
  stringstream maze_lines(paths_inline);

  char num;
  int row = 0, col = 0;
  while (maze_lines >> num) {
    maze[row][col] = num;
    row++;
    if (row == 4) {
      row = 0;
      col++;
    }
  }

  cout << "Maze:"<<endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << maze[i][j];
    }
    cout << "" << endl;
  }
  // --

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

//1 pilha - armazena os caminhos disponiveis
//
// 1, 3
// 1, 2
// 2, 2
// 2, 1
// 3, 1
//
// 2 pilha - armazrna as posições que o rato percorreu


#include <iostream>
#include <sstream>  // Para usar stringstream

// int main() {
//   std::string data = "10 20 30 40";
//   std::stringstream ss(data);  // Inicializa o stringstream com a string
//
//   int num;
//   while (ss >> num) {  // Lê os números até o final da string
//     std::cout << num << std::endl;
//   }
//
//   return 0;
// }
