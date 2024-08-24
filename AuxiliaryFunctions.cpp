//#include "Unit.h"
#include "AuxiliaryFunctions.h"
#include "BattleGround.h"


void nextScreenClick() {
    system("pause");
    system("cls");
}

void printUnitInfo(Unit* unit) {
    std::cout << "race:\t" << unit->race << std::endl;
    std::cout << "type:\t" << unit->type << std::endl;
    std::cout << "immunity:\t" << unit->immunity << std::endl;
    std::cout << "source:\t" << unit->source << std::endl;
    std::cout << "previous hit points:\t" << unit->previousHitPoints << std::endl;
    std::cout << "hit points:\t" << unit->hitPoints << std::endl;
    std::cout << "damage:\t" << unit->damage << std::endl;
    std::cout << "armor:\t" << unit->armor << std::endl;
    std::cout << "chances to hit:\t" << unit->chancesToHit << std::endl;
    std::cout << "target:\t" << unit->target << std::endl;
    std::cout << "attack range:\t" << unit->attackRange << std::endl;
    std::cout << "initiative:\t" << unit->initiative << std::endl;
    std::cout << std::endl;
}

void mainMenu() {
    char gameMode;
    while (true) {
        std::cout << "* * * * * * * * * * * * * * *" << std::endl;
        std::cout << "<<    TRIBUTE TO HEROES    >>" << std::endl;
        std::cout << "* * * * * * * * * * * * * * *" << std::endl;
        std::cout << "          GAME MODE          " << std::endl;
        std::cout << "* * * * * * * * * * * * * * *" << std::endl;
        std::cout << " 1    PLAY vs CPU            " << std::endl;
        std::cout << " 2    PLAY vs PLAYER         " << std::endl;
        std::cout << " L    LOAD GAME              " << std::endl;
        std::cout << " Q    QUIT GAME              " << std::endl;
        std::cout << "* * * * * * * * * * * * * * *" << std::endl;
        std::cout << " ENTER YOUR CHOICE: ";
        std::cin >> gameMode;
        gameMode = std::toupper(gameMode);
        switch (gameMode) {
        case '1':
            nextScreenClick();
            sideMenu();
            break;
        case '2':
            nextScreenClick();
            sideMenu();
            break;
        case 'L':
            std::cout << "NO FILES TO LOAD!" << std::endl;
            nextScreenClick();
            break;
        case 'Q':
            std::cout << "YOU`VE LEFT THE GAME!" << std::endl;
            exit(0);
        default:
            std::cout << "INCORRECT!" << std::endl;
            nextScreenClick();
        }
        if (gameMode == '1' || gameMode == '2' || gameMode == 'L' || gameMode == 'Q') {
            break;
        }
        else {
            //std::cout << "INCORRECT!" << std::endl;
            //nextScreenClick();
        }
        //return gameMode;
    }
}

void sideMenu() {
    char sideMode;
    while (true) {
        std::cout << "* * * * * * * * * * * * * * *" << std::endl;
        std::cout << "<<    TRIBUTE TO HEROES    >>" << std::endl;
        std::cout << "* * * * * * * * * * * * * * *" << std::endl;;
        std::cout << "       CHOOSE the SIDE       " << std::endl;
        std::cout << "* * * * * * * * * * * * * * *" << std::endl;
        std::cout << " 1    EARTHBORN LEGION       " << std::endl;
        std::cout << " 2    UNDEAD HORDE           " << std::endl;
        std::cout << " A    ABOUT                  " << std::endl;
        std::cout << " Q    TO MAIN MENU           " << std::endl;
        std::cout << "* * * * * * * * * * * * * * *" << std::endl;
        std::cout << " ENTER YOUR CHOICE: ";
        std::cin >> sideMode;
        sideMode = std::toupper(sideMode);
        switch (sideMode) {
        case '1':
            nextScreenClick();
            break;
        case '2':
            nextScreenClick();
            break;
        case 'A':
            nextScreenClick();
            aboutMenu();
            break;
        case 'Q':
            nextScreenClick();
            mainMenu();
            break;
        default:
            std::cout << "INCORRECT!" << std::endl;
            nextScreenClick();
        }
        if (sideMode == '1' || sideMode == '2' || sideMode == 'A' || sideMode == 'Q') {
            break;
        }
        else {
            /*std::cout << "INCORRECT!" << std::endl;
            nextScreenClick();*/
        }
        //return sideMode;
    }
}

void aboutMenu() {
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "<<    EARTHBORN LEGION     >>" << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "In the rays of the mighty sun, the Earthborn Legion,\na heroic alliance of great warriors, stands before the world.\nTheir shining armors and warming colors, like fires,\nreflect sparkling flashes in the air, creating a stunning image." << std::endl;
    std::cout << "The heart of this legendary army is the Paladin,\nradiating nobility and dedication.Behind him stand the Barbarian,\nsteadfast as a rock, the Archer with the steady gaze\nof a marksman who always hits the target, the Wizard with charms\nunfolding like a magical flame, and the Priest, a devoted healer\ncarrying the light of hope." << std::endl;
    std::cout << "Their union creates a picturesque and resilient\npalette that delves into the soul, like a testament to true heroism." << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    nextScreenClick();
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "<<      UNDEAD HORDE       >>" << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "In the infernal silence, the darkness disperses,\nreleasing its rulers - the Undead Horde. Emerging from the depths\nof the underworld, they carry eternal curses\nand a desire for destruction. " << std::endl;
    std::cout << "Dark warriors like the Dark Warrior take the forefront,\narmed with enchanted weapons and clad in dark armor.\nMagic-created skeletons move silently, being impervious\nand ready to serve their master. Dark Hunter and Witch, masters\nof deception and dark magic, march to war, making\nenemies feel fear and despair. The founder, Occultist,\nwields powerful magical forces, summoning dark energies\nto support their ruler. The gray shadowy world of the\nShadow unfolds, sweeping away enemies into a vortex of darkness." << std::endl;
    std::cout << "In this chaos and horror, the Undead Horde carves\nits path, conquering the hearts and souls of enemies,\nenchanting them with eternal nightmares." << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    nextScreenClick();
    sideMenu();
}

void winScreen(std::string winners, std::string loosers) {
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "<<     " << winners << " WINS!     >>" << std::endl;
    std::cout << "<< " << loosers << " army is defeated! >>" << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "                             " << std::endl;
    std::cout << "    glory to the victors,    " << std::endl;
    std::cout << "    woe to the vanquished    " << std::endl;
    std::cout << "                             " << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
}

void showEarthbornLegion() {
    enum earthbornLegion
    {
        PALADIN = 1, BARBARIAN, ARCHER, CROSSBOWMAN, WIZARD, PRIEST = 6, BACK = 0
    };

    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << "<<    EARTHBORN LEGION     >>" << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    std::cout << " 1    Paladin                " << std::endl;
    std::cout << " 2    Barbarian              " << std::endl;
    std::cout << " 3    Archer                 " << std::endl;
    std::cout << " 4    Crossbowman            " << std::endl;
    std::cout << " 5    Wizard                 " << std::endl;
    std::cout << " 6    Priest                 " << std::endl;
    std::cout << " 0    BACK                   " << std::endl;
    std::cout << "* * * * * * * * * * * * * * *" << std::endl;
    int choice;
    do {
        std::cin >> choice;
        choice = std::toupper(choice);
        Unit* unit;
        switch (choice) {
        case PALADIN:
            unit = new Paladin();
            printUnitInfo(unit);
            nextScreenClick();
            delete unit;
            showEarthbornLegion();
            break;
        case BARBARIAN:
            unit = new Barbarian();
            printUnitInfo(unit);
            nextScreenClick();
            delete unit;
            showEarthbornLegion();
            break;
        case ARCHER:
            unit = new Archer();
            printUnitInfo(unit);
            nextScreenClick();
            delete unit;
            showEarthbornLegion();
            break;
        case CROSSBOWMAN:
            unit = new Crossbowman();
            printUnitInfo(unit);
            nextScreenClick();
            delete unit;
            showEarthbornLegion();
            break;
        case WIZARD:
            unit = new Wizard();
            printUnitInfo(unit);
            nextScreenClick();
            delete unit;
            showEarthbornLegion();
            break;
        case PRIEST:
            unit = new Priest();
            printUnitInfo(unit);
            nextScreenClick();
            delete unit;
            showEarthbornLegion();
            break;
        case BACK:
            nextScreenClick();
            sideMenu();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            nextScreenClick();
            showEarthbornLegion();
            break;
        };

    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '0');
}

void autosave(const std::vector<Unit*>& unitedArmies, const std::vector<Unit*>& Legion, const std::vector<Unit*>& Horde) {
    std::ofstream outFile("autosave.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open the file autosave.txt" << std::endl;
        return;
    }

    outFile << "United Armies:\n";
    for (const auto& unit : unitedArmies) {
        outFile << unit->type << ": " << unit->hitPoints << " " << unit->positionX << " " << unit->positionY << std::endl;
    }
    outFile << std::endl;

    outFile << "Legion:\n";
    for (const auto& unitLegion : Legion) {
        outFile << unitLegion->type << ": " << unitLegion->hitPoints << " " << unitLegion->positionX << " " << unitLegion->positionY << std::endl;
    }
    outFile << std::endl;

    outFile << "Horde:\n";
    for (const auto& unitHorde : Horde) {
        outFile << unitHorde->type << ": " << unitHorde->hitPoints << " " << unitHorde->positionX << " " << unitHorde->positionY << std::endl;
    }

    outFile.close();
}
//LOAD
void loadGame() {

}