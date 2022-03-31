#include "Maze.h"

Maze::Maze(int size) {
  _initializeMap();
}

void Maze::fillNode(uint8_t wallNum) {
  fillNode(wallNum, x, y);
}

void Maze::fillNode(uint8_t wallNum, uint8_t x, uint8_t y) {
  map[x][y] = wallNum;
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

void Maze::_initializeMap() {
  for (int x = 0; x < MAZE_SIZE; x++) {
    for (int y = 0; y < MAZE_SIZE; y++) {
      map[x][y] = 0b1111;
    }
  }
}
