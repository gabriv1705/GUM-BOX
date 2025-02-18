#include "Ref.h"
#include "Fighter.h" 
#include "MC.h"

//default constructor
Ref::Ref(){
  stunCount1 =0;
  stunCount2 = 0;
  hitCount1 = 0;
  hitCount2 = 0;
}
  
void Ref::countStun(int c){ //MC is 1, Opponent is 2
  if(c==1){stunCount1++;}
  if(c==2){stunCount2++;}
}
void Ref::countHit(int c){ //MC is 1, Opponent is 2
  if(c==1){hitCount1++;}
  if(c==2){hitCount2++;}
}
void Ref::boxMatchStart(MC m, Fighter* f){ //declare the start of a match
  cout << "\nLadies and gentlemen, welcome to Tonight's Fight!\nIn the challenger corner, with a record of " << m.getRecord()
  << ", we have the dynamic " << m.getName() << "!\nIn the opponents corner, boasting a record of " 
  << f->getRecord() << " we have the formidable, " << f->getName() << "!\n\n!!!!!Get ready for a showdown!!!!!" << endl;
}
int Ref::winnerCalcResult(MC m, Fighter* f){ //calculated match end if nobody gets knocked or health is <=0
  float MC_num = m.getHealth() + (stunCount1*10) + (hitCount1*4.5);
  float Opp_num = f->getHealth() + (stunCount2*10) + (hitCount2*4.5);
  int winner;
  
  if(MC_num > Opp_num){//declares winner of whoever has the highest score
    cout << "TONIGHTS WINNER:  " << m.getName() << "\n";
    m.setRecord(1, 0);
    f->setRecord(0,1);
    winner = 1;
  }
  else {
    cout <<"TONIGHTS WINNER:  " << f->getName() << "\n";
    m.setRecord(0, 1);
    f->setRecord(1,0);
    winner = 2;
  }
  return winner;
}
void Ref::resetHitsandStun(){ //reset the values following the match
  stunCount1 =0;
  stunCount2 = 0;
  hitCount1 = 0;
  hitCount2 = 0;
}
void Ref::fightReward(MC& m, int num){
  if(num == 0){//boxing match
    m.setAttack(m.getAttack()+ 35);
    m.setDefense(m.getDefense()+35);
    m.setHealth(m.getHealth()+25);
    m.coach.money += 10;
  }
  if(num == 1){//practice match
    m.setAttack(m.getAttack()+20);
    m.setDefense(m.getDefense()+20);
    m.setHealth(m.getHealth()+40);
  }
  
}