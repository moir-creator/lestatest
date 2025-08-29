#include <iostream>
#include <string>

using std::cout;
using std::endl;

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
    lvl(1)
    currentWeapon
    {}
    void takeDamage(short damage) {
        this->health -= damage;
    }
    bool isALive() const {
        return health > 0;
    }
};

int main() {

    return 0;
}