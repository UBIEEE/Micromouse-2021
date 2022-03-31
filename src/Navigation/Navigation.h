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

		/*
		 * General decision making function upon enering a cell
		 *
		 * If there is only one way to go, go there. If there are multiple
		 * options, call the Pathfinding function
		 */
		void cellDecision();

	
};

#endif //Navigation_h
