#include "BattleGround.h"

BattleGround::BattleGround() {
    gridSize = 5;
    groundSymbol = " - ";
    obstacleSymbol = " # ";
    obstacle = 3;

    grid = new std::string * [gridSize];
    for (int i = 0; i < gridSize; ++i) {
        grid[i] = new std::string[gridSize];
    }

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            grid[i][j] = groundSymbol;
        }
    }

    srand(static_cast<unsigned>(time(nullptr)));

    obstaclePositionX = new int[obstacle];
    obstaclePositionY = new int[obstacle];

    generateObstacles();
}

BattleGround::~BattleGround() {
    for (int i = 0; i < gridSize; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
    delete[] obstaclePositionX;
    delete[] obstaclePositionY;
}

int BattleGround::getGridSize() const {
    return gridSize;
}

std::string BattleGround::getGrid() const {
    std::string gridString;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            gridString += grid[i][j] + " ";
        }
        gridString += "\n";
    }
    return gridString;
}

std::string BattleGround::getGroundSymbol() const {
    return groundSymbol;
}

std::string BattleGround::getObstacleSymbol() const {
    return obstacleSymbol;
}

int BattleGround::getObstacle() const {
    return obstacle;
}

const int* BattleGround::getObstaclePositionX() const {
    return obstaclePositionX;
}

const int* BattleGround::getObstaclePositionY() const {
    return obstaclePositionY;
}

void BattleGround::displayPlaceUnit() const {
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void BattleGround::display() const {
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "<<    TRIBUTE TO HEROES    >>" << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
}

void BattleGround::generateObstacles() {
    for (int i = 0; i < obstacle; ++i) {
        int x = rand() % gridSize;
        int y = rand() % gridSize;

        while (grid[x][y] != groundSymbol) {
            x = rand() % gridSize;
            y = rand() % gridSize;
        }

        grid[x][y] = obstacleSymbol; //obstacle
        obstaclePositionX[i] = x;
        obstaclePositionY[i] = y;
    }
}

void BattleGround::placeUnit(Unit* unit) {
    std::cout << "# on battleground is obstacle." << std::endl;
    std::cout << "- free space on the battlefield." << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "Legion can be placed in columns 0 or 1." << std::endl;
    std::cout << "Horde can be placed in columns " << gridSize-2 << " or " << gridSize - 1 << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;

    int row, column;

    while (true) {
        std::cout << "Enter the row for " << unit->getType() << ": ";
        std::cin >> row;
        std::cout << "Enter the column for " << unit->getType() << ": ";
        std::cin >> column;

        bool isValid = true;
        if (unit->race == "earthborn") {// for Legion  
            isValid = (column == 0 || column == 1) && (row >= 0 && row < gridSize);
        }
        else if (unit->race == "undead") {// for Horde   
            isValid = (column == gridSize-2 || column == gridSize-1) && (row >= 0 && row < gridSize);
        }

        if (isValid) {
            for (int i = 0; i < obstacle; ++i) {
                if (row == obstaclePositionX[i] && column == obstaclePositionY[i]) {
                    std::cout << "Cannot place unit. Obstacle at the ground." << std::endl;
                    isValid = false;
                    break;
                }
            }

            if (isValid && grid[row][column] != groundSymbol) {
                std::cout << "Cannot place unit. Position is occupied." << std::endl;
                isValid = false;
            }

            if (isValid) {
                grid[row][column] = unit->getSymbol();
                unit->positionX = row;
                unit->positionY = column;
                break;
            }
        }
        else {
            std::cout << "Invalid position!" << std::endl;
        }
    }
}

void BattleGround::moveUnit(Unit* unit, const std::vector<Unit*>& combinedArmies) {

    char direction;

    int movesLeft = unit->getMoveRange();

    while (movesLeft > 0) {
        bool isValid = true;
        std::cout << "Move " << unit->getType() << " (A|S|W|D| X ):\t";
        std::cin >> direction;
        direction = std::toupper(direction);

        int tempPosX = unit->positionX;
        int tempPosY = unit->positionY;

        unit->move(direction); // change position

        if (unit->positionX < 0 || unit->positionX >= gridSize || unit->positionY < 0 || unit->positionY >= gridSize) {
            std::cout << "Your courage does not allow you to leave the battlefield." << std::endl;
            isValid = false;
        };

        for (int i = 0; i < obstacle; ++i) {
            if (unit->positionX == obstaclePositionX[i] && unit->positionY == obstaclePositionY[i]) {
                std::cout << "Obstacle in your way." << std::endl;
                isValid = false;
            };
        };

        for (const auto& otherUnit : combinedArmies) {
            if (unit != otherUnit && unit->positionX == otherUnit->positionX && unit->positionY == otherUnit->positionY) {
                if (otherUnit->race != unit->race) {
                    std::cout << "To take the place you have to kill him." << std::endl;
                }
                else if (otherUnit->race == unit->race) {
                    std::cout << "To take this place, it is not necessary to kill him." << std::endl;
                };
                isValid = false;
            };
        };

        if (isValid) {
            grid[tempPosX][tempPosY] = groundSymbol;
            grid[unit->positionX][unit->positionY] = unit->getSymbol();

            nextScreenClick();
            display();

            movesLeft--;
        }
        else {
            unit->positionX = tempPosX;
            unit->positionY = tempPosY;
            nextScreenClick();
            display();
        }
    }
}
            


