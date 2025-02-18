#ifndef FIGHTER_H
#define FIGHTER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fighter {

public:
  Fighter(int a=60, int d=60, int h=500, int w=0, int l=0);
  void setName(string, string);
  void setAttack(int);
  void setDefense(int);
  void setHealth(int);

  int getAttack();
  int getDefense();
  int getHealth();
  string getName();
  int getLosses();
  int getWins();

  void setRecord(int w, int l);
  string getRecord();
  string fName, lName;

private:
  int attack;
  int defense;
  int health;
  int wins = 0;
  int losses = 0;
};

#endif