// GAME.cpp
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <queue>
#include <algorithm>  // max // sort
#include <vector>
#include <fstream>

#include "Unit.h"

#include "CombatFunctions.h"
#include "CombatFunctions.cpp"
#include "AuxiliaryFunctions.h"
//#include "AuxiliaryFunctions.cpp"
#include "BattleGround.h"


//Оголошення функцій
static std::vector<Unit*> recruitmentLegion();
static std::vector<Unit*> recruitmentHorde();
static std::vector<Unit*> combinedArmies(std::vector<Unit*> Legion, std::vector<Unit*> Horde);

//Функція вибору юнітів до Легіону 
static std::vector<Unit*> recruitmentLegion() {
    std::vector<Unit*> Legion;
    Unit* unitLegion;
    enum earthbornLegion
    {
        PALADIN = 1, BARBARIAN, ARCHER, CROSSBOWMAN, WIZARD, PRIEST = 6
    };

    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "<<    EARTHBORN LEGION     >>" << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "Choose " << armySize() << " earthborn to Legion" << std::endl;
    std::cout << " 1    Paladin                " << std::endl;
    std::cout << " 2    Barbarian              " << std::endl;
    std::cout << " 3    Archer                 " << std::endl;
    std::cout << " 4    Crossbowman            " << std::endl;
    std::cout << " 5    Wizard                 " << std::endl;
    std::cout << " 6    Priest                 " << std::endl;
    std::cout << " 0    Enough                 " << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;

    int countLegionMember = 0;
    do {
        int choice;
        std::cin >> choice;
        switch (choice) {
        case PALADIN:
            unitLegion = new Paladin();
            Legion.push_back(unitLegion);
            countLegionMember++;
            std::cout << unitLegion->type << " preparing for battle!" << std::endl;
            break;
        case BARBARIAN:
            unitLegion = new Barbarian();
            Legion.push_back(unitLegion);
            countLegionMember++;
            std::cout << unitLegion->type << " preparing for battle!" << std::endl;
            break;
        case ARCHER:
            unitLegion = new Archer();
            Legion.push_back(unitLegion);
            countLegionMember++;
            std::cout << unitLegion->type << " preparing for battle!" << std::endl;
            break;
        case CROSSBOWMAN:
            unitLegion = new Crossbowman();
            Legion.push_back(unitLegion);
            countLegionMember++;
            std::cout << unitLegion->type << " preparing for battle!" << std::endl;
            break;
        case WIZARD:
            unitLegion = new Wizard();
            Legion.push_back(unitLegion);
            countLegionMember++;
            std::cout << unitLegion->type << " preparing for battle!" << std::endl;
            break;
        case PRIEST:
            unitLegion = new Priest();
            Legion.push_back(unitLegion);
            countLegionMember++;
            std::cout << unitLegion->type << " preparing for battle!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
        if (choice == 0) {
            break;
        }

    } while (countLegionMember < armySize());
    nextScreenClick();
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "<<    TRIBUTE TO HEROES    >>" << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "The earthborn legion is ready:" << std::endl;
    for (const auto& earthbornUnit : Legion) {
        std::cout << earthbornUnit->getType() << ": " << earthbornUnit->getHitPoints() << std::endl;
    };
    //// free the memory
    //for (auto& earthbornUnit : Legion) {
    //    delete earthbornUnit;
    //};
    nextScreenClick();
    return Legion;
};
//Функція вибору юнітів до Орди 
static std::vector<Unit*> recruitmentHorde() {
std::vector<Unit*> Horde;
Unit* unitHorde;
enum undeadHorde
{
    DARK_WARRIOR = 1, SKELETON, DARK_HUNTER, WITCH, OCCULTIST, SHADOW = 6
};
std::cout << "* * * * * * * * * * * * * * *" << std::endl;
std::cout << "<<      UNDEAD HORDE       >>" << std::endl;
std::cout << "* * * * * * * * * * * * * * *" << std::endl;
std::cout << "Choose " << armySize() << " undead to Horde" << std::endl;
std::cout << " 1    Dark Warrior           " << std::endl;
std::cout << " 2    Skeleton               " << std::endl;
std::cout << " 3    Dark Hunter            " << std::endl;
std::cout << " 4    Witch                  " << std::endl;
std::cout << " 5    Occultist              " << std::endl;
std::cout << " 6    Shadow                 " << std::endl;
std::cout << " 0    Enough                 " << std::endl;
std::cout << "* * * * * * * * * * * * * * *" << std::endl;

int countHordeMember = 0;
do {
    int choice;
    std::cin >> choice;

    switch (choice) {
    case DARK_WARRIOR:
        unitHorde = new DarkWarrior();
        Horde.push_back(unitHorde);
        countHordeMember++;
        std::cout << unitHorde->type << " preparing for battle!" << std::endl;
        break;
    case SKELETON:
        unitHorde = new Skeleton();
        Horde.push_back(unitHorde);
        countHordeMember++;
        std::cout << unitHorde->type << " preparing for battle!" << std::endl;
        break;
    case DARK_HUNTER:
        unitHorde = new DarkHunter();
        Horde.push_back(unitHorde);
        countHordeMember++;
        std::cout << unitHorde->type << " preparing for battle!" << std::endl;
        break;
    case WITCH:
        unitHorde = new Witch();
        Horde.push_back(unitHorde);
        countHordeMember++;
        std::cout << unitHorde->type << " preparing for battle!" << std::endl;
        break;
    case OCCULTIST:
        unitHorde = new Occultist();
        Horde.push_back(unitHorde);
        countHordeMember++;
        std::cout << unitHorde->type << " preparing for battlee!" << std::endl;
        break;
    case SHADOW:
        unitHorde = new Shadow();
        Horde.push_back(unitHorde);
        countHordeMember++;
        std::cout << unitHorde->type << " preparing for battle!" << std::endl;
        break;
    case 0:
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
    };
    if (choice == 0) {
        break;
    }
} while (countHordeMember < armySize());
nextScreenClick();
std::cout << "* * * * * * * * * * * * * * *" << std::endl;
std::cout << "<<    TRIBUTE TO HEROES    >>" << std::endl;
std::cout << "* * * * * * * * * * * * * * *" << std::endl;
std::cout << " The undead horde is ready:  " << std::endl;
for (const auto& undeadUnit : Horde) {
    std::cout << undeadUnit->getType() << ": " << undeadUnit->getHitPoints() << std::endl;
};

//for (auto& undeadUnit : Horde) {
//    delete undeadUnit;
//};

nextScreenClick();
return Horde;
};
//Функція об'єднання сформованих Лкгіону та Орди 
// визначає чергу ходу юнітів // сортування за змінною Unit::int initiative; 
static std::vector<Unit*> combinedArmies(std::vector<Unit*> Legion, std::vector<Unit*> Horde) {
    std::vector<Unit*> unitedArmies;
    unitedArmies.insert(unitedArmies.end(), Legion.begin(), Legion.end());
    unitedArmies.insert(unitedArmies.end(), Horde.begin(), Horde.end());

    std::sort(unitedArmies.begin(), unitedArmies.end(), checkInitiative);
    return unitedArmies;
};  


int main() {

    mainMenu();
   
    // формуємо Легіон
    std::vector<Unit*> Legion = recruitmentLegion();
    // формуємо Орду
    std::vector<Unit*> Horde = recruitmentHorde();
    // формуємо об'єднану армію
    std::vector<Unit*> unitedArmies = combinedArmies(Legion, Horde);

    //Створення поля бою
    BattleGround battleGround;
    //place Legion // розміщення юнітів Легіону на полі бою
    for (const auto& unit : Legion) {
        battleGround.display();
        battleGround.placeUnit(unit);
        nextScreenClick();
    }

    //place Horde // розміщення юнітів Орди на полі бою
    for (const auto& unit : Horde) {
        battleGround.display();
        battleGround.placeUnit(unit);
        nextScreenClick();
    }
    
    //Процес  бою
    int turn = 0;
    while (true) {
        turn++;
        std::cout << "turn " << turn << std::endl;
        for (const auto& unit : unitedArmies) {

            //перевірка на переможну команду
            checkWin(Legion, Horde);
            // вивід поля бою на екран
            battleGround.display();
            // рух юніта
            battleGround.moveUnit(unit, unitedArmies);
            // дії юніта, якщо є доступна ціль (недороблено, але процює:) )
            if (checkOnTarget(unit, unitedArmies))

            {
                int attackChoice;
                int indexUnitLegion = 1;
                int indexUnitHorde = 1;

                // якщо хід паладина
                if (unit->race == "earthborn" && unit->type == "paladin") {
                    std::cout << unit->getType() << " selects a target to attack:" << std::endl;
                    // цикл виводить ворожих юнітів з номерами, за якими їх можна атакувати
                    for (const auto& unitHorde : Horde) {
                        std::cout << indexUnitHorde++ << ". " << unitHorde->getType() << ": " << unitHorde->getHitPoints() << std::endl;
                    };
                    std::cin >> attackChoice;
                    // розрахунок атаки + зміна HP жертви атаки // передається посилання на того хто атакує і кого атакують
                    checkHitPointsOneTargetAttack(*unit, *Horde[attackChoice - 1]);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід варвара
                else if (unit->race == "earthborn" && unit->type == "barbarian") {
                    std::cout << unit->getType() << " selects a target to first attack:" << std::endl;
                    // цикл виводить ворожих юнітів з номерами, за якими їх можна атакувати
                    for (const auto& unitHorde : Horde) {
                        std::cout << indexUnitHorde++ << ". " << unitHorde->getType() << ": " << unitHorde->getHitPoints() << std::endl;
                    };
                    std::cin >> attackChoice;
                    // розрахунок атаки + зміна HP жертви атаки
                    checkHitPointsOneTargetAttack(*unit, *Horde[attackChoice - 1]);
                    // оновлення екрана
                    nextScreenClick();
                    // варвар має особоивість подвійної атаки
                    std::cout << unit->getType() << " selects a target to second attack:" << std::endl;
                    // цикл виводить ворожих юнітів з номерами, за якими їх можна атакувати
                    indexUnitHorde = 1;
                    for (const auto& unitHorde : Horde) {
                        std::cout << indexUnitHorde++ << ". " << unitHorde->getType() << ": " << unitHorde->getHitPoints() << std::endl;
                    };
                    std::cin >> attackChoice;
                    // розрахунок атаки + зміна HP жертви атаки
                    checkHitPointsOneTargetAttack(*unit, *Horde[attackChoice - 1]);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід лучника
                else if (unit->race == "earthborn" && unit->type == "archer") {
                    std::cout << unit->getType() << " selects a target to attack:" << std::endl;
                    // цикл виводить ворожих юнітів з номерами, за якими їх можна атакувати
                    for (const auto& unitHorde : Horde) {
                        std::cout << indexUnitHorde++ << ". " << unitHorde->getType() << ": " << unitHorde->getHitPoints() << std::endl;
                    };
                    std::cin >> attackChoice;
                    // розрахунок атаки + зміна HP жертви атаки
                    checkHitPointsOneTargetAttack(*unit, *Horde[attackChoice - 1]);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід арбалетника
                else if (unit->race == "earthborn" && unit->type == "crossbowman") {
                    std::cout << unit->getType() << " selects a target to attack:" << std::endl;
                    // цикл виводить ворожих юнітів з номерами, за якими їх можна атакувати
                    for (const auto& unitHorde : Horde) {
                        std::cout << indexUnitHorde++ << ". " << unitHorde->getType() << ": " << unitHorde->getHitPoints() << std::endl;
                    };
                    std::cin >> attackChoice;
                    // розрахунок атаки + зміна HP жертви атаки
                    checkHitPointsOneTargetAttack(*unit, *Horde[attackChoice - 1]);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід чарівника
                else if (unit->race == "earthborn" && unit->type == "wizard") {
                    // розрахунок атаки на всіх ворожих юнітів + зміна HP всіх жертв атаки
                    checkDamageAllEnemies(*unit, Horde);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід священника
                else if (unit->race == "earthborn" && unit->type == "priest") {
                    std::cout << unit->getType() << " selects a target to heal:" << std::endl;
                    // цикл виводить дружніхх юнітів з номерами, за якими їх можна лікувати
                    for (const auto& unitLegion : Legion) {
                        std::cout << indexUnitLegion++ << ". " << unitLegion->getType() << ": " << unitLegion->getHitPoints() << std::endl;
                    };
                    std::cin >> attackChoice;
                    // зміна HP дружнього об'єкта
                    checkHitPointsOneTargetHeal(*unit, *Legion[attackChoice - 1]);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід темного воїна
                else if (unit->race == "undead" && unit->type == "dark warrior") {
                    // цикл виводить ворожих юнітів з номерами, за якими їх можна атакувати
                    std::cout << unit->getType() << " selects a target to attack:" << std::endl;
                    for (const auto& unitLegion : Legion) {
                        std::cout << indexUnitLegion++ << ". " << unitLegion->getType() << ": " << unitLegion->getHitPoints() << std::endl;
                    };
                    std::cin >> attackChoice;
                    // розрахунок атаки + зміна HP жертви атаки
                    checkHitPointsOneTargetAttack(*unit, *Legion[attackChoice - 1]);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід скелета
                else if (unit->race == "undead" && unit->type == "skeleton") {
                    std::cout << unit->getType() << " selects a target to attack:" << std::endl;
                    // цикл виводить ворожих юнітів з номерами, за якими їх можна атакувати
                    for (const auto& unitLegion : Legion) {
                        std::cout << indexUnitLegion++ << ". " << unitLegion->getType() << ": " << unitLegion->getHitPoints() << std::endl;
                    };
                    std::cin >> attackChoice;
                    // розрахунок атаки + зміна HP жертви атаки
                    checkHitPointsOneTargetAttack(*unit, *Legion[attackChoice - 1]);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід темного мисливця
                else if (unit->race == "undead" && unit->type == "dark hunter") {
                    std::cout << unit->getType() << " selects a target to attack:" << std::endl;
                    // цикл виводить ворожих юнітів з номерами, за якими їх можна атакувати
                    for (const auto& unitLegion : Legion) {
                        std::cout << indexUnitLegion++ << ". " << unitLegion->getType() << ": " << unitLegion->getHitPoints() << std::endl;
                    };
                    std::cin >> attackChoice;
                    // розрахунок атаки + зміна HP жертви атаки
                    checkHitPointsOneTargetAttack(*unit, *Legion[attackChoice - 1]);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід відьми
                else if (unit->race == "undead" && unit->type == "witch") {
                    // розрахунок атаки на всіх ворожих юнітів + зміна HP всіх жертв атаки
                    checkDamageAllEnemies(*unit, Legion);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід окультиста
                else if (unit->race == "undead" && unit->type == "occultist") {
                    // розрахунок атаки на всіх ворожих юнітів + зміна HP всіх жертв атаки + зміна HP окультиста
                    checkDrainAllEnemies(*unit, Legion);
                    // оновлення екрана
                    nextScreenClick();
                }
                // якщо хід тіні
                else if (unit->race == "undead" && unit->type == "shadow") {
                    std::cout << unit->getType() << " selects a target to attack:" << std::endl;
                    // цикл виводить ворожих юнітів з номерами, за якими їх можна атакувати
                    for (const auto& unitLegion : Legion) {
                        std::cout << indexUnitLegion++ << ". " << unitLegion->getType() << ": " << unitLegion->getHitPoints() << std::endl;
                    };
                    std::cin >> attackChoice;
                    // розрахунок атаки + зміна Unit::int moveRange жертви атаки // не реалізовано
                    checkParalizeOneTargetAttack(*unit, *Legion[attackChoice - 1]);
                    // оновлення екрана
                    nextScreenClick();
                }
                
                // зберігання даних бою у файл
                autosave(unitedArmies, Legion, Horde);
            }
            
            // оновлення екрана
            nextScreenClick();
        };        
    };
    
    return 0;
};
