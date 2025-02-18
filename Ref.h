#pragma once
#include "Fighter.h" 
#include "MC.h"


//make ref class
class Ref : public MC{
public: 
  Ref();
  void countStun(int); // 1 is for mc, 2 if for fighter
  void countHit(int); // 1 is for mc, 2 if for fighter
  void boxMatchStart(MC main, Fighter* extra); 

  //only if nobodies health is <= 0 and nobody is knocked out. 
  int winnerCalcResult(MC, Fighter*); //calculation for who wins a match
//reset the number of stuns and hits counted for in a match. 
  void resetHitsandStun();
  void fightReward(MC&, int); //return 0 if boxing match and 1 if practice, give them 10 dollars per fight. 

private:
  float stunCount1;
  float stunCount2;
  float hitCount1;
  float hitCount2;

};





