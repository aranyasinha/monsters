
#ifndef POKEMON_H
#define POKEMON_H
#include "monster.h"

class pokemon : private Monster {
private:
  uint16_t p_hp, p_attack, p_defence, p_speed;
  std::array<Move, 4> moveset;
  // std::string nature_name; std::pair<std::string,std::string> stat_name;
  // std::multimap<std::pair<std::string,std::string>, std::string> nature;
public:
  // No Setters, use from monster class
  void calcStats() {
    float tmp;
    // HP = (( (IV=31) + 2 * BaseStat + ( (EV=124) /4) ) * (Level=50) /100 ) +
    // 10 + (Level=50)
    tmp = ((62 + (2 * Monster::getHP())) * 0.5) + 60;
    p_hp = (uint16_t)tmp;
    // Stat = ((( (IV=31) + 2 * BaseStat + ( (EV=124) /4) ) * (Level=50) /100 )
    // + 5) * (Nature Value=1)
    tmp = ((62 + (2 * Monster::getAttack())) * 0.5) + 5;
    p_attack = (uint16_t)tmp;
    tmp = ((62 + (2 * Monster::getDefence())) * 0.5) + 5;
    p_defence = (uint16_t)tmp;
    tmp = ((62 + (2 * Monster::getSpeed())) * 0.5) + 5;
    p_speed = (uint16_t)tmp;
  }
  uint16_t updateHP(uint16_t dmg) {
    if (dmg > p_hp) { // For 1HKO
      p_hp = 0;
    } else if ((dmg * (-1)) > p_hp) { // For Healing
      p_hp = ((62 + (2 * Monster::getHP())) * 0.5) + 60;
    } else {
      p_hp -= dmg;
    }
    return p_hp;
  }
  uint16_t getHP() { return (p_hp); }
  uint16_t getAttack() { return (p_attack); }
  uint16_t getDefence() { return (p_defence); }
  uint16_t getSpeed() { return (p_speed); }

  float getStab(int i) {
    if ((moveset[i].getType() == (Monster::getType()).first) ||
        (moveset[i].getType() == (Monster::getType()).second)) {
      return (1.5);
    }
    return (1.0);
  }

  double getPower(int i) {
    //(2 * (Level=50) / 5 + 2) * AttackStat * AttackPower
    return ((this->getAttack()) * moveset[i].getPower() * 22);
  }

  Move getMove(int i) { return moveset[i]; }
};
#endif // POKEMON_H
