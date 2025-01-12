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

void createMaze(char maze[limit][limit], int &rows, int &cols);
void showMaze(char maze[limit][limit], int rows, int cols);

class Position {
  public:
  int x;
  int y;
  Position(int x, int y): x(x), y(y) {}
};



int main (){
  int rows, cols;
  char maze[limit][limit];
  createMaze(maze, rows, cols);


  // -- pegando posições do gabiru
  Position mousePosition(0, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (maze[i][j] == 'm') {
        mousePosition.x = i;
        mousePosition.y = j;
      }
    }
  }

  Position cheesePosition(0, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (maze[i][j] == 'q') {
        cheesePosition.x = i;
        cheesePosition.y = j;
      }
    }
  }

  // -- percorrendo labirinto
  Stack backTrack, currentPosition;
  int x = mousePosition.x, y = mousePosition.y;

  currentPosition.push(x,y);
  do {
    maze[x][y] = 'm';
    if (maze[x][y] == 'q' ) {
      cout << "Achou o queijo";
      break;
    }
    if (maze[x][y+1] == '0' ) {

      backTrack.push(x, y);
      currentPosition.push(x,y);
      y++;
    } else if (maze[x+1][y] == '0'   ) {

      backTrack.push(x, y);
      currentPosition.push(x,y);
      x++;
    }else if (maze[x][y-1] == '0'   ) {
      backTrack.push(x, y);
      currentPosition.push(x,y);
      y--;
    } else if (maze[x-1][y] == '0' ) {
      backTrack.push(x, y);
      currentPosition.push(x,y);
      x--;
    } else {
      if (!backTrack.isEmpty()) {
        currentPosition.push(x, y);
        Node* top = backTrack.pop();
        x = top->getX();
        y = top->getY();
      }else {
        cout << "Nao foi possivel encontrar uma saida!";
        break;

      }
    }
    sleep(1);
    system("cls");
    showMaze(maze, rows, cols);

    maze[currentPosition.top->getX()][currentPosition.top->getY()] = '.';

    currentPosition.peek();
  } while (maze[x][y] != 'q');

  return 0;
  }

void createMaze(char maze[limit][limit], int &rows, int &cols) {
  ifstream maze_file("src/maze.txt");

  // -- pegando tamanho da matriz
  string dimension_line;
  getline(maze_file, dimension_line);
  stringstream ss(dimension_line);
  char x_separator;

  ss >> rows >> x_separator >> cols;
  cout << rows << " " << x_separator << " " << cols << endl;


  // -- Criando a matriz com base no arquivo

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

}

void showMaze(char maze[limit][limit],const int rows, const int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << maze[i][j] << " ";
    }
    cout << endl;
  }
}