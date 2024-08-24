#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>

#include "Unit.h"
#include "AuxiliaryFunctions.h"

class BattleGround {
private:
    int gridSize;
    std::string** grid;
    std::string groundSymbol;
    std::string obstacleSymbol;
    int obstacle;
    int* obstaclePositionX;
    int* obstaclePositionY;

public:
    BattleGround();
    ~BattleGround();

    int getGridSize() const;
    std::string getGrid() const;    
    std::string getGroundSymbol() const;
    std::string getObstacleSymbol() const;
    int getObstacle() const;
    const int* getObstaclePositionX() const;
    const int* getObstaclePositionY() const;


    void displayPlaceUnit() const;
    void display() const;
    void generateObstacles();
    void placeUnit(Unit* unit);
    void moveUnit(Unit* unit, const std::vector<Unit*>& combinedArmies);
};