#ifndef Navigation_h
#define Navigation_h

#include <inttypes.h>

/* 
 * Class of functions and variables related to determining how to move through
 * the maze. This does NOT include determining WHERE to go (that's Routing).
 */
class Navigation
{
	public:
		Navigation(/* args */);

		
		uint8_t x = 0;     // X position of the robot
		uint8_t y = 0;     // Y position of the robot
		// Constants for orientation. N=0, E=1, S=2, W=3
		enum directions { NORTH, EAST, SOUTH, WEST };
	
};

#endif //Navigation_h
