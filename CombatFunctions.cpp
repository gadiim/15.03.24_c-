#include <algorithm>
#include "Unit.h"
#include "CombatFunctions.h"


static size_t armySize() {
    return 3;
}

static bool checkInitiative(const Unit* a_object, const Unit* b_object) {
    return a_object->getInitiative() > b_object->getInitiative();
}

template <typename T>
bool checkOnTarget(const T* attacking_object, const std::vector<T*>& defending_objects) {
    bool hasValidTarget = false;

    for (const auto& otherUnit : defending_objects) {
        if (attacking_object->getRace() != otherUnit->getRace()) {
            int deltaX = attacking_object->getPositionX() - otherUnit->getPositionX();
            int deltaY = attacking_object->getPositionY() - otherUnit->getPositionY();
            int distanceSquared = deltaX * deltaX + deltaY * deltaY;
            int attackRange = attacking_object->getAttackRange();

            if (distanceSquared <= attackRange * attackRange) {
                hasValidTarget = true;

                //std::cout << attacking_object->getType() << " can attack " << otherUnit->getType() << " at position ("
                //    << otherUnit->getPositionX() << ", " << otherUnit->getPositionY() << ")" << std::endl;

                std::cout << attacking_object->getType() << " can attack " << otherUnit->getType() << std::endl;
            }
        }
    }

    if (!hasValidTarget) {

        std::cout << attacking_object->getType() << " has no target to attack." << std::endl;
    }

    return hasValidTarget;
}

template <typename T>
bool checkImmunity(const T& attacking_object, const T& defending_object) {
    bool isImmunity = (attacking_object.getSource() == defending_object.getImmunity()); 
    return isImmunity;
}

template <typename T>
int checkDamage(const T& attacking_object, const T& defending_object) {
    int strengthHit = attacking_object.checkStrengthHit(); 

    if (!strengthHit) {
        std::cout << attacking_object.getType() << " missed!" << std::endl; 
        return 0;
    }
    else {
        bool isImmunity = checkImmunity(attacking_object, defending_object);

        if (isImmunity) {
            std::cout << attacking_object.getType() << " hit " << defending_object.getType() << " with the "
                << attacking_object.getSource() << ": " << strengthHit << " HP" << std::endl;
            std::cout << defending_object.getType() << " has immunity to " + attacking_object.getSource() << std::endl;
            return 0;
        }
        else {
            int damage = std::max(strengthHit - defending_object.getArmor(), 0);
            std::cout << attacking_object.getType() << " hit " << defending_object.getType() << " with the "
                << attacking_object.getSource() << ": " << strengthHit << " HP" << std::endl;

            if (defending_object.getArmor() > 0) {
                std::cout << defending_object.getType() << " has armor " << defending_object.getArmor() << " HP" << std::endl;
            }

            std::cout << defending_object.getType() << " damaged by the " << attacking_object.getSource() << ": " << damage << " HP" << std::endl;

            return damage;
        }
    }
}

template <typename T>
void checkHitPointsOneTargetAttack(const T& attacking_object, T& defending_object) {
    if (defending_object.isAlive()) {
        int remainingHP = (defending_object.hitPoints) - checkDamage(attacking_object, defending_object);
        //defending_object.setHitPoints(remainingHP);
        defending_object.setHitPoints(std::max(remainingHP, 0));  
    }
}

template <typename T>
void checkHitPointsOneTargetHeal(const T& attacking_object, T& defending_object) {   
    if (defending_object.isAlive()) {
        int heal = attacking_object.checkHeal();
        int remainingHP = std::min(defending_object.hitPoints + heal, defending_object.previousHitPoints);
        std::cout << defending_object.getType() << " got " << heal << " extra HP" << std::endl;
        defending_object.setHitPoints(remainingHP);
    }
}

template <typename T>
void checkDamageAllEnemies(const T& attacking_object, const std::vector<T*>& defending_objects) {
    int index = 0;
    std::cout << attacking_object.getType() << " attack all targets:" << std::endl;
    nextScreenClick();
    for (const auto* unit : defending_objects) {
        checkHitPointsOneTargetAttack(attacking_object, *defending_objects[index]);
        index++;
    }   
}

template <typename T>
void checkDrainAllEnemies(T& attacking_object, std::vector<T*>& defending_objects) {
    int totalHeal = 0;
    int index = 0;
    int attack;
    std::cout << attacking_object.getType() << " attacks all targets:" << std::endl;
    nextScreenClick();

    for (const auto* unit : defending_objects) {
        attack = checkDamage(attacking_object, *defending_objects[index]);
        int remainingHP = (defending_objects[index]->hitPoints) - attack;
        defending_objects[index]->setHitPoints(std::max(remainingHP, 0));
        index++;
        totalHeal += attack / 3;
    }
    attacking_object.setHitPoints(std::min(attacking_object.hitPoints + totalHeal, attacking_object.previousHitPoints));
    std::cout << attacking_object.getType() << " got " << totalHeal << " extra HP" << std::endl;
};

template <typename T>
void checkParalizeOneTargetAttack(T& attacking_object, T& defending_object) {

        bool isImmunity = checkImmunity(attacking_object, defending_object);

        if (isImmunity) {
            std::cout << attacking_object.getType() << " hit " << defending_object.getType() << " with the " << attacking_object.getSource() <<  std::endl;
            std::cout << defending_object.getType() << " has immunity to " + attacking_object.getSource() << std::endl;   
        }
        else {
            std::cout << attacking_object.getType() << " hit " << defending_object.getType() << " with the " << attacking_object.getSource() << std::endl;
            defending_object.moveRange = 0;
            defending_object.duration = 1;
            std::cout << defending_object.getType() << " get " << attacking_object.getTypeEffect() << " for 1 turn."  << std::endl;
        };
    
}

template <typename T>
void checkWin(std::vector<T*>& a_objects, std::vector<T*>& b_objects) {
    //std::cout << "...the battle continues...    " << std::endl;
    int totalA_objectsHitPoints = 0;
    for (const auto* a_object : a_objects) {
        totalA_objectsHitPoints += a_object->hitPoints;
    };
    int totalB_objectsHitPoints = 0;
    for (const auto* b_object : b_objects) {
        totalB_objectsHitPoints += b_object->hitPoints;
    };
    if (totalA_objectsHitPoints == 0) {
        std::string loosers = a_objects[0]->race;
        std::string winners = b_objects[0]->race;
        winScreen(winners, loosers);
        for (const auto* unit : a_objects) {
            std::cout << "delete unit attacking_objects" << std::endl;
            delete unit;
        }
        for (const auto* unit : b_objects) {
            std::cout << "delete unit defending_objects" << std::endl;
            delete unit;
        }
        nextScreenClick();
        mainMenu();
    }
    else if (totalB_objectsHitPoints == 0) {
        std::string loosers = b_objects[0]->race;
        std::string winners = a_objects[0]->race;
        winScreen(winners, loosers);
        for (const auto* unit : b_objects) {
            //std::cout << "delete unit defending_objects" << std::endl;
            delete unit;
        }
        for (const auto* unit : a_objects) {
           //std::cout << "delete unit attacking_objects" << std::endl;
            delete unit;
        }
        nextScreenClick();
        mainMenu();
    };
};