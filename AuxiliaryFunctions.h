#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
//#include <cctype>

#include "Unit.h"
//#include "CombatFunctions.h"
#include "BattleGround.h"

void nextScreenClick();

void printUnitInfo(Unit* unit);

void mainMenu();

void sideMenu();

void aboutMenu();

void winScreen(std::string winners, std::string loosers);

void showEarthbornLegion();

void autosave(const std::vector<Unit*>& unitedArmies, const std::vector<Unit*>& Legion, const std::vector<Unit*>& Horde);

void loadGame();
