#include "Navigation.h"

Navigation::Navigation() {

}

uint8_t Navigation::cellDecision(Maze *mazePtr) {
	uint8_t curWallNum = mazePtr
}

/*
 * Returns the number of openings based on the wall number,
 * which is a count of the 0s in the binary representation number
 * 
 * Params:
 *   uint8_t wallNum - The binary wall state number of the current cell
 *
 * Returns:
 *   uint8_t - The number of openings in the current cell
 */
uint8_t Navigation::getOpeningsFromWallNumber(uint8_t wallNum) {
  uint8_t numOpenings = 0;
  
  for(uint8_t bit = 0; bit < 4; bit++){
    if(bitRead(wallNum, bit) == 0){
      numOpenings++;
    }
  }

  return numOpenings;
}