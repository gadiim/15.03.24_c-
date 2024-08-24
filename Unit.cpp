#include "Unit.h"
#include "CombatFunctions.h"

std::string Unit::getHitPoints() const {
    float balanceHP = static_cast<float>(hitPoints) / previousHitPoints;
    if (balanceHP > 0.9)//fullHP
    {
        return ("\x1B[36m" + std::to_string(hitPoints) + " HP" + "\033[0m");
    }
    else if ((balanceHP < 0.9) && (balanceHP > 0.5))//normalHP
    {
        return ("\x1B[32m" + std::to_string(hitPoints) + " HP" + "\033[0m");
    }
    else if ((balanceHP < 0.5) && (balanceHP > 0.1)) //lowHP
    {
        return ("\x1B[33m" + std::to_string(hitPoints) + " HP" + "\033[0m");
    }
    else if ((balanceHP < 0.1) && (balanceHP > 0)) //criticalHP
    {
        return ("\x1B[35m" + std::to_string(hitPoints) + " HP" + "\033[0m");
    }
    else if (balanceHP <= 0) //emptyHP
    {
        return ("\x1B[93m0 HP\033[0m");
    }
    else {
        return "fog on the field - it is impossible to see the wound...";
    }
}
//int Unit::getHitPoints() const {
//    std::cout << type << " has hitpoints:\t" << hitPoints << std::endl;
//    return hitPoints;
//}

int Unit::getDamage() const {
    //std::cout << type << "\tdamage:\t" << damage << std::endl;
    return damage;
}

int Unit::getArmor() const {
    //std::cout << type << "\tarmor:\t" << armor << std::endl;
    return armor;
}

int Unit::getAttackRange() const {
    return attackRange;
}

int Unit::getActionEffect() const {
    //std::cout << type << "\tarmor:\t" << actionEffect << std::endl;
    return actionEffect;
}

int Unit::getInitiative() const {
    //std::cout << type << "\tinitiative:\t" << initiative << std::endl;
    return initiative;
}

int Unit::getDuration() const {
    //std::cout << type << "\moveRange:\t" << initiative << std::endl;
    return duration;
}

int Unit::getMoveRange() const {
    //std::cout << type << "\moveRange:\t" << initiative << std::endl;
    return moveRange;
}

int Unit::getPositionX() const {
    return positionX;
}

int Unit::getPositionY() const {
    return positionY;
}

std::string Unit::getTypeEffect() const {
    //std::cout << type << "\trace:\t" << typeEffect << std::endl;
    return typeEffect;
}

std::string Unit::getSource() const {
    return source;
}

std::string Unit::getImmunity() const {
    return immunity;
}

std::string Unit::getRace() const {
    return race;
}

std::string Unit::getType() const {
    return type;
}

std::string Unit::getSymbol() const {
    return symbol;
}


//void Unit::move(char direction) {
//    switch (direction) {
//    case 'A':
//        if (positionY -1 >= 0)
//            positionY -=1;
//        break;
//    case 'D':
//        if (positionY +1 < 5)
//            positionY +=1;
//        break;
//    case 'W':
//        if (positionX -1 >= 0)
//            positionX -=1;
//        break;
//    case 'S':
//        if (positionX +1 < 5)
//            positionX +=1;
//        break;
//
//    default:
//        std::cout << "Invalid direction!" << std::endl;
//    }
//}

void Unit::move(char direction) {
    switch (direction) {
    case 'A':
        positionY -= 1;
        break;
    case 'D':
        positionY += 1;
        break;
    case 'W':
        positionX -= 1;
        break;
    case 'S':
        positionX += 1;
        break;
    case 'X':
        
        break;

    default:
        std::cout << "Invalid direction!" << std::endl;
    }
}

void Unit::setHitPoints(int newHitPoints) {
    hitPoints = newHitPoints;
    //std::cout << type << "\tset hit points to:\t" << hitPoints << std::endl;
}

//initiative sorting
bool Unit::operator < (const Unit& other) const {
    return initiative < other.initiative;
}

//bool Unit::operator > (const Unit& other) const {
//    return initiative > other.initiative;
//}

bool Unit::isAlive() const {
    if (hitPoints > 0) {
        return true;
    }
    else { 
        return false; 
    }
}

int Unit::checkMissHit() const {
    srand(static_cast<unsigned>(time(nullptr)));
    int chance = 0 + rand() % 101;
    //std::cout << type << "\tcheckMissHit\t" << chance << std::endl;
    return chance > chancesToHit ? false : true;
}

int Unit::checkStrengthHit() const {
    int attackStrength = damage * checkMissHit(); 
    return attackStrength;
}

int Unit::checkHeal() const { 
    int heal = actionEffect * checkMissHit(); 
    return heal;
}

std::string Paladin::getType() const {
    return "\x1B[34m" + type + "\033[0m";
}

std::string Paladin::getSymbol() const {
    return "\x1B[34m" + symbol + "\033[0m";
}

std::string Barbarian::getType() const {
    return "\x1B[34m" + type + "\033[0m";
}

std::string Barbarian::getSymbol() const {
    return "\x1B[34m" + symbol + "\033[0m";
}

std::string Archer::getType() const {
    return "\x1B[34m" + type + "\033[0m";
}

std::string Archer::getSymbol() const {
    return "\x1B[34m" + symbol + "\033[0m";
}

std::string Crossbowman::getType() const {
    return "\x1B[34m" + type + "\033[0m";
}

std::string Crossbowman::getSymbol() const {
    return "\x1B[34m" + symbol + "\033[0m";
}

std::string Wizard::getType() const {
    return "\x1B[34m" + type + "\033[0m";
}

std::string Wizard::getSymbol() const {
    return "\x1B[34m" + symbol + "\033[0m";
}

std::string Priest::getType() const {
    return "\x1B[34m" + type + "\033[0m";
}

std::string Priest::getSymbol() const {
    return "\x1B[34m" + symbol + "\033[0m";
}

std::string DarkWarrior::getType() const {
    return "\x1B[33m" + type + "\033[0m";
}

std::string DarkWarrior::getSymbol() const {
    return "\x1B[33m" + symbol + "\033[0m";
}

std::string Skeleton::getType() const {
    return "\x1B[33m" + type + "\033[0m";
}

std::string Skeleton::getSymbol() const {
    return "\x1B[33m" + symbol + "\033[0m";
}

std::string DarkHunter::getType() const {
    return "\x1B[33m" + type + "\033[0m";
}

std::string DarkHunter::getSymbol() const {
    return "\x1B[33m" + symbol + "\033[0m";
}

std::string Witch::getType() const {
    return "\x1B[33m" + type + "\033[0m";
}

std::string Witch::getSymbol() const {
    return "\x1B[33m" + symbol + "\033[0m";
}

std::string Occultist::getType() const {
    return "\x1B[33m" + type + "\033[0m";
}

std::string Occultist::getSymbol() const {
    return "\x1B[33m" + symbol + "\033[0m";
}

std::string Shadow::getType() const {
    return "\x1B[33m" + type + "\033[0m";
}

std::string Shadow::getSymbol() const {
    return "\x1B[33m" + symbol + "\033[0m";
}