#ifndef MC_H
#define MC_H

#include "Fighter.h"
struct rep { //counts the reputation of the MC according to post game fights
  int pChamp = 0;
  int heel = 0;
};
struct Coach { //holds the money and performance drinks for MC
  int attackR = 0, defenseR = 0, healthR = 0;
  int money = 0;
};

class MC : public Fighter {

public:
  MC();
  string getNickname();
  string getRep();
  string getName();

  void updateRep(int r); // 2 is whats inputed when a fight win, 1 and 0 are fighters response
                        
  int level;
  rep reputation;
  Coach coach;

private:
  string nickname = "Gummy";
};

#endif