#include "Movement.h"

Movement::Movement(AF_Stepper *lMotor, AF_Stepper *rMotor, Maze *mazePtr) {
  _lMotor = lMotor;
  _rMotor = rMotor;
  _maze = mazePtr;

  _rMotor->setSpeed(_motorSpeed);
  _lMotor->setSpeed(_motorSpeed);
}

void Movement::moveForward() {
  /*
   *  This group of doubles does math to determine how many counts we need so we can travel one exactly coordinate
   */
  double distancePerCoordinate = 10; // This is a placeholder number, will need to change when we get measurements, it's in cm
  double wheelDiameter = 2.5 * 2.54; // convert's wheel diameter from inches to cm
  double wheelCircumference = PI * (wheelDiameter / 2) * (wheelDiameter / 2);
  double travelDistance = distancePerCoordinate / wheelCircumference;
  double turnCounts = 60 * travelDistance;

  for(uint8_t i = 0; i < (int)turnCounts; ++i) {
    _rMotor->step(1, FORWARD, SINGLE);
    _lMotor->step(1, FORWARD, SINGLE);
  }
  
  _maze->movedForward();
}

void Movement::turnRight() {
  for(uint8_t i = 0; i < 86; ++i) {
    _lMotor->step(1, FORWARD, SINGLE); 
    _rMotor->step(1, BACKWARD, SINGLE);
  }
  _maze->turnedRight();
}

void Movement::turnLeft() {
  for(uint8_t i = 0; i < 86; ++i) {
    _rMotor->step(1, FORWARD, SINGLE); 
    _lMotor->step(1, BACKWARD, SINGLE); 
  }
  _maze->turnedLeft();
}

void Movement::turnAround() {
  for(uint8_t i = 0; i < 170; ++i) {
    _rMotor->step(1, BACKWARD, SINGLE); 
    _lMotor->step(1, FORWARD, SINGLE);
  } 
  _maze->turnedAround();
}

void Movement::moveDirection(uint8_t dir) {
  // Turn towards direction
  switch ((_maze->ori - dir) % 4) {
    case 0:
      // Already facing that direction, do nothing
      break;
    case 1:
      turnLeft();
      break;
    case 2:
      turnAround();
      break;
    case 3:
      turnRight();
      break;
    default:
      // Should not happen
      break;
  }

  moveForward();
}