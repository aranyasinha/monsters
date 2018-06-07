#ifndef _BATTLE_H
#define _BATTLE_H 1

class Battle {
private:
  static Battle *b_instance;

  Battle() {}
  Battle(Battle const &) = delete;
  void operator=(Battle const &) = delete;

public:
  static Battle *getInstance() {
    if (b_instance == NULL) {
      b_instance = new Battle();
    }
    return b_instance;
  }
  // setters
  // getters

  // signed int is used in future consideration of using as a healing move as
  // well

  // calculated for defending monster
  // pre_dmg is calculated using above function (getpre_dmg) and returned here
  // as argument pre_dmg is calculated for attacking monster dmgcalc is
  // calculated for defending monster stab is damage constant dependant on
  // attacking monster's type and attack move's type matching =1.5, else =1
  int dmgcalc(int pre_dmg, attack move, float st = 1.0) {
    // check for accuracy here, again using random number generation from 0 to
    // 50, if < move.accuracy then return(0);
    // <-- insert code here -->
    // else the below code gets executed
    float eff = effect(move.T, t1) * effect(move.T, t2);
    float dmg = (((pre_dmg / def) / 50) + 2) * st * eff;
    // Insert a random multiplier (random_number/100) to dmg, where
    // random_number is [85 to 100]
    // <-- insert code here -->
    return (int(dmg));
  }
};
#endif
