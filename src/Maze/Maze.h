#ifndef Maze_h
#define Maze_h

#include <inttypes.h>

/* 
 * Class of functions and variables related to the maze and our position in it
 */
class Maze
{
	public:
		Maze(/* args */);

		// Fills the current tile with given wall pattern
		void fillNode(uint8_t wallNum);

		void movedForward();	// Updates the data for the robot moving forward
		void turnedLeft();		// Updates the data for the robot turning left
		void turnedRight();		// Updates the data for the robot turning right
		void turnedAround();	// Updates the data for the robot turning around
		
		/* 
		 * Each node is an 8 bit int, representing the state of the walls.
		 * 
		 * The 4 least significant bits are binary representation of the walls, 
		 * (1  = wall, 0 = no wall).
		 * 
		 * 0b1111 (15) signifies that the tile hasn't been explored yet.
		 * 
		 * The top 4 bits are unused, so the bit pattern is: ---- NESW
		 */
		uint8_t map[16][16];

		uint8_t x = 0;     // X position of the robot
		uint8_t y = 0;     // Y position of the robot
		uint8_t ori = 0;   // Orientation of the robot

		// Constants for orientation. N=0, E=1, S=2, W=3
		enum directions { NORTH, EAST, SOUTH, WEST };
	
	private:
		// Fills the map array with unexplored cells
		void _initializeMap();

		#define MAZE_X 16
		#define MAZE_Y 16
};

#endif //Maze_h
