#ifndef Pathfinding_h
#define Pathfinding_h

#include <Arduino.h>
#include <Movement.h>
#include <main.ino>


class Pathfinding
{
    public:
        Pathfinding(uint8_t *mazePtr, int mazeX, int mazeY);
        enum determineDirection(Movement *movPtr);
        void storePath();
    private:
        uint8_t * mazePtr;
        int mazeX;
        int mazeY;
        //Movement::Movement *movPtr;
        //std::vector<int, int> path;

    


};
#endif // Pathfinding_h