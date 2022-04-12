#ifndef Movement_h
#define Movement_h

#include <Arduino.h>
#include <AFMotor.h>
#include <inttypes.h>

#include "Maze.h"

// Class of functions and variables related to physically moving the robot
class Movement
{
	public:
		Movement(AF_Stepper *lMotor, AF_Stepper *rMotor, Maze *mazePtr);

		// Moves the robot forward one grid tile and updates Maze instance
		void moveForward();
		// Rotates the robot in place, 90 deg left, and updates Maze instance
		void turnLeft();
		// Rotates the robot in place, 90 deg right, and updates Maze instance
		void turnRight();
		// Rotates the robot in place, 180 deg around, and updates Maze instance
		void turnAround();
		// Turns and moves the robot one grid tile in the given direction, based on the Maze.directions enums, and updates the Maze instance
		void moveDirection(uint8_t dir);

	private:
		AF_Stepper *_lMotor;
		AF_Stepper *_rMotor;
		uint16_t _stepsPerRev = 60;
		uint8_t _motorSpeed = 160;
		Maze *_maze;
};

#endif //Movement_h
