#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

//#include "CombatFunctions.h"
//#include "BattleGround.h"

class Unit abstract {
public:

    int previousHitPoints;
    int hitPoints;
    int damage;
    int armor;
    int chancesToHit;
    int target;
    int attackRange;
    int actionEffect;
    int initiative;
    int moveRange;
    int duration;
    int positionX;
    int positionY;
    std::string typeEffect;
    std::string source;
    std::string immunity;
    std::string race;
    std::string type;
    std::string symbol;

    Unit(
        int previousHitPoints,
        int hitPoints,
        int damage,
        int armor,
        int chancesToHit,
        int target,
        int attackRange,
        int actionEffect,
        int initiative,
        int moveRange,
        int duration,
        int positionX,
        int positionY,
        const std::string& typeEffect,
        const std::string& source,
        const std::string& immunity,
        const std::string& race,
        const std::string& type,
        const std::string& symbol)
        : previousHitPoints(previousHitPoints), hitPoints(hitPoints), damage(damage), armor(armor), chancesToHit(chancesToHit),
        target(target), attackRange(attackRange), actionEffect(actionEffect), initiative(initiative), moveRange(moveRange),
        duration(duration), positionX(positionX), positionY(positionY),
        typeEffect(typeEffect), source(source), immunity(immunity), race(race), type(type), symbol(symbol){}

    Unit() : Unit(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", "", "", "", "", "U") {}

    virtual std::string getHitPoints() const;
    virtual int getDamage() const;
    virtual int getArmor() const;
    virtual int getAttackRange() const;
    virtual int getActionEffect() const;
    virtual int getInitiative() const;
    virtual int getMoveRange() const;
    virtual int getDuration() const;
    virtual int getPositionX() const;
    virtual int getPositionY() const;

    virtual std::string getTypeEffect() const;
    virtual std::string getSource() const;
    virtual std::string getImmunity() const;
    virtual std::string getRace() const;
    virtual std::string getType() const;
    virtual std::string getSymbol() const;

    void move(char direction);

    virtual void setHitPoints(int newHitPoints);
    virtual bool operator < (const Unit& other) const;
    //virtual bool operator > (const Unit& other) const;
    virtual bool isAlive() const;
    virtual int checkMissHit() const;
    virtual int checkStrengthHit() const;
    virtual int checkHeal() const;

    virtual ~Unit() {}
};

class Paladin : public Unit {
public:
    Paladin() : Unit(100, 100, 20, 5, 75, 1, 1, 10, 70, 1, 0, 0, 0, "shield", "weapon", "no", "earthborn", "paladin", " P ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class Barbarian : public Unit {
public:
    Barbarian() : Unit(100, 100, 10, 0, 65, 1, 1, 0, 85, 2, 0, 0, 0, "no", "weapon", "no", "earthborn", "barbarian", " B ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class Archer : public Unit {
public:
    Archer() : Unit(90, 90, 15, 0, 75, 1, 3, 85, 0, 1, 0, 0, 0, "no", "weapon", "no", "earthborn", "archer", " A ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class Crossbowman : public Unit {
public:
    Crossbowman() : Unit(80, 80, 20, 5, 60, 1, 2, 0, 60, 1, 0, 0, 0, "no", "weapon", "no", "earthborn", "crossbowman", " C ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class Wizard : public Unit {
public:
    Wizard() : Unit(70, 70, 10, 0, 60, 6, 10, 0, 60, 1, 0, 0, 0, "no", "magic", "no", "earthborn", "wizard", " W ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class Priest : public Unit {
public:
    Priest() : Unit(75, 75, 0, 0, 95, 1, 10, 10, 50, 1, 0, 0, 0, "heal", "magic", "magic", "earthborn", "priest", " P ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class DarkWarrior : public Unit {
public:
    DarkWarrior() : Unit(90, 90, 20, 0, 80, 1, 1, 0, 75, 1, 0, 0, 0, "no", "weapon", "no", "undead", "dark warrior", " D ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class Skeleton : public Unit {
public:
    Skeleton() : Unit(65, 65, 15, 0, 65, 1, 1, 0, 80, 2, 0, 0, 0, "no", "weapon", "magic", "undead", "skeleton", " K ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class DarkHunter : public Unit {
public:
    DarkHunter() : Unit(90, 90, 10, 0, 75, 1, 3, -5, 90, 1, 0, 0, 0, "poison", "weapon", "no", "undead", "dark hunter", " H ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class Witch : public Unit {
public:
    Witch() : Unit(65, 65, 15, 0, 65, 1, 10, -10, 65, 1, 0, 0, 0, "curse", "magic", "no", "undead", "witch", " W ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class Occultist : public Unit {
public:
    Occultist() : Unit(65, 65, 10, 0, 60, 6, 10, 0, 60, 1, 0, 0, 0, "drain", "magic", "no", "undead", "occultist", " O ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};

class Shadow : public Unit {
public:
    Shadow() : Unit(50, 50, 5, 0, 35, 1, 10, 0, 50, 1, 0, 0, 0, "paralyze", "magic", "weapon", "undead", "shadow", " S ") {}
    std::string getType() const override;
    std::string getSymbol() const override;
};