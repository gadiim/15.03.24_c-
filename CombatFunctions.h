#pragma once
#include <iostream>
#include <algorithm> // max // sort
#include <vector>

#include "Unit.h"
#include "AuxiliaryFunctions.h"
#include "BattleGround.h"


static size_t armySize();

static bool checkInitiative(const Unit* a_object, const Unit* b_object);

template <typename T>
bool checkOnTarget(const T* attacking_object, const std::vector<T*>& defending_objects);

template <typename T>
bool checkImmunity(const T& attacking_object, const T& defending_object);

template <typename T>
int checkDamage(const T& attacking_object, const T& defending_object);

template <typename T>
void checkHitPointsOneTargetAttack(const T& attacking_object, T& defending_object);

template <typename T>
void checkHitPointsOneTargetHeal(const T& attacking_object, T& defending_object);

template <typename T>
void checkDamageAllEnemies(const T& attacking_object, const std::vector<T*>& defending_objects);

template <typename T>
void checkDrainAllEnemies(T& attacking_object, std::vector<T*>& defending_objects);

template <typename T>
void checkParalizeOneTargetAttack(T& attacking_object, T& defending_object);

template <typename T>
void checkWin(std::vector<T*>& a_objects, std::vector<T*>& b_objects);

