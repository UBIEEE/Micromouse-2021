#include "Maze.h"

Maze::Maze() {
  _initializeMap();
}

void Maze::_initializeMap() {
  for (int x = 0; x < MAZE_X; x++) {
    for (int y = 0; y < MAZE_Y; y++) {
      map[x][y] = 0b1111;
    }
  }
}


void Maze::movedForward() {
  switch(ori) {
    case NORTH:
      y = y+1;
      break;
    case EAST:
      x = x+1;
      break;
    case SOUTH:
      y = y-1;
      break;
    case WEST:
      x = x-1;
      break;
  }
}
void Maze::turnedLeft() 	{ ori = (ori-1) % 4; }
void Maze::turnedRight()	{ ori = (ori+1) % 4; }
void Maze::turnedAround()	{ ori = (ori+2) % 4; }