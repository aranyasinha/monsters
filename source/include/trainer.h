#ifndef TRAINER_H
#define TRAINER_H
#include "pokemon.h"

class trainer {
  std::string t_name;
  std::array<pokemon, 6> t_team;
  std::pair<long, long> t_wl; // wins & loses
  long t_battles;

public:
  // setters
  void setName(std::string name) { t_name = name; }
  void setTeam(std::array<pokemon, 6> team) { t_team = team; }

  // getters
  std::string getName() { return t_name; }
  Move getMove(int p_index, int m_index) {
    return t_team[p_index].getMove(m_index);
  }

  long getTotalBattles() { return t_battles; }

  std::pair<long, long> getRatio() { return t_wl; }

  void updateBattleResult(bool result) {
    t_battles++;
    if (result) {
      t_wl.first++;
    } else {
      t_wl.second++;
    }
  }

  // init
  trainer() {
    t_name = "Grey";
    // Decide on a default team for default initilization
    // t_team = {};
    t_wl = std::make_pair(0, 0);
    t_battles = 0;
  }
  trainer(std::string name, std::array<pokemon, 6> team) {
    t_name = name;
    t_team = team;
    t_wl = std::make_pair(0, 0);
    t_battles = 0;
  }
  // Appends player state, ie; name, team & stats are saved in a binary file
  bool record() {
    std::string filename = "trainer.data";
    // Check for exceptions here
    std::ofstream ofo(filename, std::ios::binary | std::ios::app);
    if (ofo.is_open()) {
      ofo.write(reinterpret_cast<char *>(this), sizeof(*this));
      // ofo.flush();
      ofo.close();
      return true;
    } else {
      std::cout << "Failed to open" << filename << std::endl;
      return false;
    }
  }
  // trainer retrieve(long index){}
};
#endif // TRAINER_H
