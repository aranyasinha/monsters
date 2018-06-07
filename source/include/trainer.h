#ifndef TRAINER_H
#define TRAINER_H
#include "pokemon.h"

class trainer {
  std::string t_name;
  std::array<pokemon, 6> team;
  std::pair<long, long> wl; // wins & loses
  long total_battles;

public:
  std::string getName() { return t_name; }
  Move getMove(int p_index, int m_index) {
    return team[p_index].getMove(m_index);
  }

  long getTotalBattles() { return total_battles; }

  std::pair<long, long> getRatio() { return wl; }

  void updateBattleResult(bool result) {
    total_battles++;
    if (result) {
      wl.first++;
    } else {
      wl.second++;
    }
  }
};
#endif // TRAINER_H
