#ifndef Navigation_h
#define Navigation_h

#include <inttypes.h>
#include <Arduino.h>
#include "Maze.h"

/* 
 * Class of functions and variables related to determining how to move through
 * the maze. This does NOT include determining WHERE to go (that's Routing).
 */
class Navigation
{
	public:
		Navigation(/* args */);

		/*
		 * General decision making function upon enering a cell
		 *
		 * If there is only one way to go, go there. If there are multiple
		 * options, call the Pathfinding function
		 * 
		 * Params:
		 *   uint8_t curWallNum - The binary wall state number of the current cell
		 *   uint8_t lastWallNum - The binary wall state number of the previous cell (the cell behind the robot)
		 * 
		 * Returns:
		 *   uint8_t - An entry from the Maze.directions enum for where we should go
		 */
		uint8_t cellDecision(Maze *mazePtr);

	private:
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
		uint8_t getOpeningsFromWallNumber(uint8_t wallNum);

}

#endif //Navigation_h
