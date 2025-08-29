#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
//задаю enum для типов героев, чтобы игрок мог их выбрать
enum class CharecterClass {
    Warrior,
    Rogue,
    Barbarian
};
//задаю тип урона, т.к. есть монстры не воспринимающие определенный типы урона
enum class DamageType {
    Slashing, //рубящий
    Bludgeoning, //дробящий
    Piercing //колющий
};
//создаю для оружия структуру, получающую 1,2,3 из enum
//не вижу смысла создавать для него целый класс
struct weapon {
    std::string name;
    short damage;
    DamageType type;
};

class fighter {
public:
    std::string name;
    short health;
    short maxHealth;
    short strength;
    short agility;
    short endurance;
    short lvl;
    weapon* currentWeapon;

    fighter(const std::string& n, short hp, short maxh, short str, short agl, short edr, weapon w) :
    name(n),
    health(hp),
    maxHealth(maxh),
    strength(str),
    agility(agl),
    endurance(edr),
    lvl(1),
    currentWeapon (new weapon(w))
    {}
    void takeDamage(short damage) {
        this->health -= damage;
    }
    bool isALive() const {
        return health > 0;
    }
};

int main() {
    //генератор случайных чисел для статов
    srand(time(0));
    //создание случайных статов героя
    short randomStrenght = 1 + rand() % 3;
    short randomAgility = 1 + rand() % 3;
    short randomEndurance = 1 + rand() % 3;

    cout << "Your starting stats: " << endl;
    cout << "Strenght: " << randomStrenght << endl;
    cout << "Agility: " << randomAgility << endl;
    cout << "Endurance: " << randomEndurance << endl;

    return 0;
}