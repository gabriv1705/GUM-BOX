#include "Fighter.h"

//default loaded constructor
Fighter::Fighter(int a, int d, int h, int w, int l){
  attack = a;
  defense = d;
  health = h;
  setRecord(w, l);
}

//setters
void Fighter::setName(string first, string last){fName = first; lName = last;}
void Fighter::setAttack(int a){attack = a;}
void Fighter::setDefense(int d){defense = d;}
void Fighter::setHealth(int h){health = h;}
void Fighter::setRecord(int w,int l){
  wins += w;
  losses += l;
}



//getters
string Fighter::getName(){
  string name = fName + " " + lName;
  return name;
}
int Fighter::getAttack(){return attack;}
int Fighter::getDefense(){return defense;}
int Fighter::getHealth(){return health;}
int Fighter::getLosses(){return losses;}
int Fighter::getWins(){return wins;}

string Fighter::getRecord()
{
  string record = to_string(wins) + "-" + to_string(losses);
  return record;
}