#include "include/stack.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <regex>

using namespace std;
const int limit  = 20;

//sfml depois eu vejo
class Position {
  public:
  int x;
  int y;
  Position(int x, int y): x(x), y(y) {}
};

void showMaze(char maze[limit][limit],const int rows, const int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << maze[i][j] << " ";
    }
    cout << endl;
  }
}

int main (){
  ifstream maze_file("src/maze.txt");

  // -- pegando linha  e coluna
  int rows, cols;


  // -- pegando tamanho da matriz
  string dimension_line;
  getline(maze_file, dimension_line);
  stringstream ss(dimension_line);
  char x_separator;

  ss >> rows >> x_separator >> cols;
  cout << rows << " " << x_separator << " " << cols << endl;


  // -- Criando a matriz com base no arquivo

  char maze[limit][limit];
  string line;
  string path_inline;

  while (getline(maze_file, line)) {
    path_inline += line;
  }

  // -- removendo espaços
  regex space_regex("\\s+");
  path_inline = regex_replace(path_inline,space_regex ,"");
  cout << path_inline << endl;

  int index = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (index < path_inline.size()) {
        maze[i][j] = path_inline[index++];
      }
    }
  }

  cout << "Maze:"<<endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << maze[i][j];
    }
    cout << "" << endl;
  }

  // - pegando posições do mouse
  Position mousePosition(0, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (maze[i][j] == 'q') {
        mousePosition.x = i;
        mousePosition.y = j;
      }
    }
  }

  // -- percorrendo labirinto
  Stack backTrack;
  int IAnterior = 0, JAnterior = 0;
  int x = mousePosition.x, y = mousePosition.y;

  do {
    if (maze[x][y-1] == 'q' || maze[x][y+1] == 'q' || maze[x - 1][y] == 'q' || maze[x + 1][y] == 'q') {
      cout << "O Rato achou o queijo!";
      break;
    }

    if (maze[x][y-1] == '0') {
      JAnterior = y;
      IAnterior = x;
      backTrack.push(x, y);
      y--;
    } else if (maze[x][y+1] == '0') {
      JAnterior = y;
      IAnterior = x;
      backTrack.push(x, y);
      y++;
    }else if (maze[x-1][y] == '0') {
      IAnterior = x;
      JAnterior = y;
      backTrack.push(x, y);
      x--;
    } else if (maze[x+1][y] == '0') {
      IAnterior = x;
      JAnterior = y;
      backTrack.push(x, y);
      x++;
    } else if (!backTrack.isEmpty()) {
      IAnterior = x;
      JAnterior = y;
      Node* top = backTrack.pop();
      x = top->getX();
      y = top->getY();
    } else {
      cout << "Nao foi possivel encontrar uma saída!";
      break;
    }
    sleep(1);
    system("cls");
    showMaze(maze, rows, cols);
    maze[IAnterior][JAnterior] = '.';

  } while (maze[x][y] != 'q');

  return 0;
  }

