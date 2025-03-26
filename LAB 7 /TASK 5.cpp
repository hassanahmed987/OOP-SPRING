#include <iostream>
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;
public:
    Character(int id, string n, int lvl, int hp, string weapon)
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}
    
    void attack() {
        cout << name << " attacks with " << weaponType << "!" << endl;
    }
    
    void defend() {
        cout << name << " defends!" << endl;
    }
    
    void displayStats() {
        cout << "ID: " << characterID << "\nName: " << name << "\nLevel: " << level
             << "\nHP: " << healthPoints << "\nWeapon: " << weaponType << endl;
    }
};

class Warrior : public Character {
    int armorStrength;
    int meleeDamage;
public:
    Warrior(int id, string n, int lvl, int hp, string weapon, int armor, int damage)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}
    
    void attack() {
        cout << name << " swings " << weaponType << " for " << meleeDamage << " damage!" << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;
public:
    Mage(int id, string n, int lvl, int hp, string weapon, int mana, int power)
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(power) {}
    
    void defend() {
        cout << name << " makes a magic shield " << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    int rangedAccuracy;
public:
    Archer(int id, string n, int lvl, int hp, string weapon, int arrows, int accuracy)
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}
    
    void attack() {
        cout << name << " fires an arrow with " << rangedAccuracy << "% accuracy" << endl;
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;
public:
    Rogue(int id, string n, int lvl, int hp, string weapon, int stealth, int agil)
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agil) {}
    
    void displayStats() {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << "\nAgility: " << agility << endl;
    }
};

int main() {
    Warrior w1(1, "Rajveer", 10, 100, "Sword", 50, 20);
    Mage m1(2, "Arjun", 12, 80, "Staff", 100, 30);
    Archer a1(3, "Rohan", 9, 90, "Bow", 20, 85);
    Rogue r1(4, "Kabir", 11, 85, "Dagger", 75, 95);
    
    w1.displayStats();
    w1.attack();
    cout << "\n";
    
    m1.displayStats();
    m1.defend();
    cout << "\n";
    
    a1.displayStats();
    a1.attack();
    cout << "\n";
    
    r1.displayStats();
    
    return 0;
}
