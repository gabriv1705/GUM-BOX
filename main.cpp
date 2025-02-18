#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Fighter.h"
#include "MC.h"
#include "Ref.h"

using namespace std;

// function prototypes
int menuOptions();
int fightSimulation(MC, Fighter*, Ref&); //the fight, attack & defense
void loadInStats(Fighter* M[], int , ifstream& fin); //load info for fighters we're fighting
bool endSaveGame(MC &v, Fighter* f[], int quant);
bool loadGame(MC&); 
void store(MC&); //buy drinks
void cornerHelp(MC&); //get drinks between rounds to up performance
void introText();
void introText2();//intro text
void endOfFightDividend(int, MC& , Fighter* Enemy, Ref&); //dividens for tournament fights
int Interview(MC&); //interviews every odd fight, only if they win as well


int main(){

  const int MAX_FIGHTERS = 6; 
  int user = 2;
  char mChoice;
  int fightResult;
  bool progress;
  
  MC Gummy;
  Fighter* Enemy[MAX_FIGHTERS];
  Ref Stevie;
  
  cout << "░██████╗░██╗░░░██╗███╗░░░███╗  ██████╗░░█████╗░██╗░░██╗" << endl;
  cout << "██╔════╝░██║░░░██║████╗░████║  ██╔══██╗██╔══██╗╚██╗██╔╝" << endl;
  cout << "██║░░██╗░██║░░░██║██╔████╔██║  ██████╦╝██║░░██║░╚███╔╝░" << endl;
  cout << "██║░░╚██╗██║░░░██║██║╚██╔╝██║  ██╔══██╗██║░░██║░██╔██╗░" << endl;
  cout << "╚██████╔╝╚██████╔╝██║░╚═╝░██║  ██████╦╝╚█████╔╝██╔╝╚██╗" << endl;
  cout << "░╚═════╝░░╚═════╝░╚═╝░░░░░╚═╝  ╚═════╝░░╚════╝░╚═╝░░╚═╝" << endl;
  cout << "    ,--,--'.        ,---.               "<< endl;
  cout << "    `- |   |-. ,-.  |  -'  ,-. ,-,-. ,-."<< endl;
  cout << "     , |   | | |-'  |  ,-' ,-| | | | |-'"<< endl;
  cout << "     `-'   ' ' `-'  `---|  `-^ ' ' ' `-'"<< endl;

  cout << "                          ⠀⠀⣠⣶⣿⣿⣿⡿⠓⢀⣠⣴⣶⣿⣿⣿⣶⣄" << endl;
  cout << "                          ⢀⣼⣿⣿⣿⠟⠋⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇" << endl;
  cout << "Would you like to:       ⠀⣾⣿⣿⣿⣇⣠⣾⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⠇⢰⣶⣶⣤⣀" << endl;
  cout << "(press a number)        ⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢀⣼⣿⣿⣿⣿⣿⡟⢀⣾⣿⣿⣿⣿⣷⡄" << endl;
  cout << "                        ⠀⢸⣿⣿⠛⣿⣿⣿⣿⣿⡟⢠⣾⣿⣿⣿⣿⣿⡟⢀⣾⣿⣿⣿⣿⣿⣿⣿⡄" << endl;
  cout << "Start a new Game (1)    ⠀⠀⠙⠋⠀⣿⣿⣿⣿⣿⠃⢸⣿⣿⣿⣿⡿⠋⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷" << endl;
  cout << "                        ⠀⠀⠀⠀⠀⢻⣿⣿⣿⡿⠀⠘⠿⠿⠟⠋⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿" << endl;
  cout << "OR                       ⠀⠀⠀⠀⠀⠙⢿⣿⡇⢸⣷⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇" << endl;
  cout << "                          ⠀⠀⠀⠀⠀⠀⠙⠇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏" << endl;
  cout << "Load a Game(2)           ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏" << endl;
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                         ⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁" << endl;
  cout << "                         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⡿⠟⠉" << endl;
  cout << "⠀                        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠛⠛⠉⠁\n" << endl;

  while(user == 2){
    cin >> user;
    if(user == 2){
      if(loadGame(Gummy) == false) {
        cout << "No saved games to load. Please select to start a new game\nOr try a different name by pressing '2' again." << endl;
      }
      else {break;}
    }
    else if(user == 1){
      break;
    }
    else {cout << "Please enter a valid number" << endl;}
  }
  
  ifstream fin("InfoFighters.txt");
  loadInStats(Enemy, MAX_FIGHTERS, fin);
  
  introText();
  if(user == 1){
    cout << "But what's your real name? (input first and last name)" << endl;
    cin >> Gummy.fName >> Gummy.lName;
    cout << "\nYou shall be known as " << Gummy.getName() << endl;
  }
  introText2();

  
  cout << "\nWould you like to do a quick training session? (y/n)" << endl;
  cin >> mChoice;
  cout << "Throw left and right hook and block these as well in order to win the match.\n" << 
    "If you're lucky enough you might land a stun or even a knockout!"<< endl;
  if(mChoice == 'y' || mChoice == 'Y'){
    fightResult = fightSimulation(Gummy, Enemy[5], Stevie);
    if(fightResult == 4 || fightResult == 2 || fightResult == 3){
      cout << "Coach: Why you lose like that! You can't be quitting like that!" << endl;
      Stevie.resetHitsandStun();
    }
    if(fightResult == 1){
      cout << "!!!!" << Gummy.getName() << " WINS!!!!" << endl;
      //update boxing fight winnings with 0, practice winnings with 1
      Stevie.fightReward(Gummy, 1);
      cout << "\nNew Profile Stats!" << endl;
      cout << "\n" << Gummy.getName() << ":\n    Attack: " << Gummy.getAttack() << "  Defense: " << Gummy.getDefense()
        << "  Health: " << Gummy.getHealth() << endl;
     Stevie.resetHitsandStun();
    }
  }
  
  while(user != 5){
    user = menuOptions();
    if(user == 1){
      Stevie.boxMatchStart(Gummy, Enemy[Gummy.level]);
      fightResult = fightSimulation(Gummy, Enemy[Gummy.level], Stevie);
      endOfFightDividend(fightResult, Gummy, Enemy[Gummy.level], Stevie);
      
    }
    if(user == 2){
      store(Gummy);
    }
    if(user == 3){
      fightResult = fightSimulation(Gummy, Enemy[5], Stevie);
      if(fightResult == 4 || fightResult == 3){
        cout << "You can't be quitting like that man! You gotta do better!" << endl;
      }
      if(fightResult == 1){
        cout << "!!!!" << Gummy.getName() << " WINS!!!!" << endl;
        //update boxing fight winnings with 0, practice winnings with 1
        Stevie.fightReward(Gummy, 1);
        cout << "New Profile Stats!" << endl;
        cout << "\n" << Gummy.getName() << ":\n    Attack: " << Gummy.getAttack() << "  Defense: " << Gummy.getDefense()
          << "  Health: " << Gummy.getHealth() << endl;
      }
    }
    if(user == 4){
      cout << "STATS" << endl;
      cout << "\n" << Gummy.getName() << "\nRecord: "<< Gummy.getRecord() << ":\n    Attack: " << Gummy.getAttack() << "  Defense: " << Gummy.getDefense()
        << "  Health: " << Gummy.getHealth() << endl;
      cout << "ACCOUNT BALANCE: $" << Gummy.coach.money << endl;
      cout << "\nDRINKS:" << endl;
      cout << "     Gatorade: " << Gummy.coach.attackR << endl;
      cout << "     Powerade: " << Gummy.coach.defenseR << endl;
      cout << "     Water: " << Gummy.coach.healthR << endl;
      cout << "REPUTATION:" 
        << "\n  Peoples Campion: " << Gummy.reputation.pChamp << "\n  Hated Heel: " << Gummy.reputation.heel << endl;
    }
    if(user == 5){
      progress = endSaveGame(Gummy, Enemy, MAX_FIGHTERS);
      if(progress != true){
        user = 0;
        cout << "Error Saving Game. Please try again." << endl;
      }
      else {break;}
    }
  }
  
  cout << "Thanks for Playing!\n" << endl;
  cout << "░██████╗░██╗░░░██╗███╗░░░███╗  ██████╗░░█████╗░██╗░░██╗" << endl;
  cout << "██╔════╝░██║░░░██║████╗░████║  ██╔══██╗██╔══██╗╚██╗██╔╝" << endl;
  cout << "██║░░██╗░██║░░░██║██╔████╔██║  ██████╦╝██║░░██║░╚███╔╝░" << endl;
  cout << "██║░░╚██╗██║░░░██║██║╚██╔╝██║  ██╔══██╗██║░░██║░██╔██╗░" << endl;
  cout << "╚██████╔╝╚██████╔╝██║░╚═╝░██║  ██████╦╝╚█████╔╝██╔╝╚██╗" << endl;
  cout << "░╚═════╝░░╚═════╝░╚═╝░░░░░╚═╝  ╚═════╝░░╚════╝░╚═╝░░╚═╝" << endl;


}

int menuOptions(){
  int userChoice;
  cout << "\n\n███╗   ███╗███████╗███╗   ██╗██╗   ██╗" << endl;
  cout << "████╗ ████║██╔════╝████╗  ██║██║   ██║" << endl;
  cout << "██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║" << endl;
  cout << "██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║" << endl;
  cout << "██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝" << endl;
  
  cout << "Would you like to (select a number): \n1. Fight in Tournament\n2. Go to the Store\n3. Train\n4. See My Stats\n5. Quit & Save\n" << endl;
  cin >> userChoice;
  return userChoice;
}





//boxing match reward
void endOfFightDividend(int fightResult, MC& Gummy, Fighter* Enemy, Ref& Stevie){
  if(fightResult == 1){
    cout << "!!!! " << Gummy.getName() << " WINS!!!!" << endl;
    Gummy.level++;
    Gummy.setRecord(1, 0); // increase number of wins
    if(Gummy.level%2 == 1){Gummy.updateRep(Interview(Gummy));}      
    cout << "+++++++++++++++++++++++++" << endl;
    cout << "You have leveled up to Level " << Gummy.level << endl;
    cout << "Your Reward: " << endl;
    Stevie.fightReward(Gummy, 0); //below it outputs the profile of player with post-fight winnings
    cout << "\n" << Gummy.getName() << ":\n    Attack: " << Gummy.getAttack() <<      "  Defense: " << Gummy.getDefense() << "  Health: " << Gummy.getHealth() << endl;
    }
    if(fightResult == 2){
      cout << "********YOU LOSE********" << endl;
      Enemy->getName();
      Gummy.setRecord(0, 1); // increase number of losses
    }
    if(fightResult == 3){
      fightResult = Stevie.winnerCalcResult(Gummy, Enemy);
      if(fightResult == 1){
        Gummy.level++;
        Gummy.setRecord(1, 0); // increase number of wins
        if(Gummy.level%2 == 1){Gummy.updateRep(Interview(Gummy));} 
        cout << "+++++++++++++++++++++++++" << endl;
        cout << "You have leveled up to Level " << Gummy.level << endl;
        cout << "New Profile Stats!" << endl;
        //update boxing fight winnings with 0, practice winnings with 1
        Stevie.fightReward(Gummy, 0); //below it outputs the profile of player with post-fight winnings
        cout << "\n" << Gummy.getName() << ":\n    Attack: " << Gummy.getAttack() << "  Defense: " << Gummy.getDefense()
          << "  Health: " << Gummy.getHealth() << endl;
      }
    }
    if(fightResult == 4){
      cout << "You're a loser" << endl;
    }
  Stevie.resetHitsandStun();
}

int Interview(MC& Gummy){
  int speech, rep;
  char choice;
  cout << "++++++++++++++++++++++++++" << endl;

  cout << "Someone's looking to interview you, would you like to? (y/n)" << endl;
  cin >> choice;
  if(choice != 'y' && choice != 'Y'){
    return 2;
  }
  if(Gummy.level == 1){
    cout << "Hi! Im Jessica Sparks with Scotch Sports\n" 
      << "We just wanted to ask, how did you get into boxing?\n\n" << endl;
    cout << "Choose an answer: \n1) I used to watch videos of the great like Ali\n" << "2) I never did, I just like whooping people." << endl;
    
    cin >> speech;
    if(speech != 1 && speech != 2){
      cout << "\nSparks: Alright, I guess being rude is your thing." << endl;
      return 2;
    }
    if(speech == 1){rep = 0;}
    if(speech == 2){rep = 1;}
    
  }
  if(Gummy.level == 3){
    cout << "Hi! Im Liam Dank with GUM Sports\n" 
      << "How was your confidence going into this match?\n\n" << endl;
    cout << "Choose an answer: \n1) I believe in myself but I want to thank others for believing in me.\n" << "2) I don't need confidence to destroy my opponent." << endl;

    cin >> speech;
    if(speech != 1 && speech != 2){
      cout << "\nDank: You must love talking with walls." << endl;
      return 2;
    }
    if(speech == 1){rep = 0;}
    if(speech == 2){rep = 1;}

  }
  
  if(Gummy.level == 5){
    cout << "Hi! Im Skip with Yahoo! Sports\n" 
      << "You beat the big monster, what's next?\n\n" << endl;
    cout << "Choose an answer: \n1) Put my foot down and show everyone I'm here to stay.\n" << "2) Forget all of you annoying people." << endl;

    cin >> speech;
    if(speech != 1 && speech != 2){
      cout << "\nSkip: If I was 30 years younger I'd slap you!\n" << endl;
      return 2;
    }
    if(speech == 1){rep = 0;}
    if(speech == 2){rep = 1;}

  }
  return rep;
}



//fight simulation function
int fightSimulation(MC v, Fighter* f, Ref& r){

  char decision;
  bool knockout1 = false;
  bool knockout2 = false;
  int MCTotalHealth = v.getHealth();
  int opponentTotalHealth = f->getHealth();
  int direction1, direction2, damage, damageDealt;
  int tradedBlows = 0;
  
  cout << "\nCoach: You got this, give them all you got!\n" << endl;
  
  for(int i = 0; i < 3; i++){
    cout << "\n" << v.getName() << ":\n    Attack: " << v.getAttack() << "  Defense: " << v.getDefense()
      << "  Health: " << v.getHealth() << endl;
    cout << f->getName() << ":\n    Attack: " << f->getAttack() << "  Defense: " << f->getDefense()
    << "  Health: " << f->getHealth() << endl;
    cout << "\n\n           ROUND " << i+1 << ", FIGHT!"<< endl;
    
    while(tradedBlows < 3){
      //opponent defense
      srand(time(0));
      direction2 = (rand() % 2+1);
      
      srand(time(0));
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
      cout << "\nATTACK:\n      Left Hook(1) or Right Hook(2)" << endl;
      cin >> direction1;
      //MC throws a hook & damage in punch, theres a range of +-7
      damage = (rand() % 14 + 1) + v.getAttack() - 7;
      //check the block & decide according outcome
      if(direction1 == direction2){
        if(damage > f->getDefense()){
          //define the ammount of damage a punch packed
          damageDealt = damage - f->getDefense();
          
          cout << "\nPARTIAL BLOCK! Hook landed for " << damageDealt << endl;
          f->setHealth(f->getHealth() - damageDealt);
          //check opponents health
          r.countHit(1);
          if(f->getHealth() <= 0){break;}
        }
        else {
          if(direction1 == 1){cout << "BLOCKED!" << endl;}
          if(direction1 == 2){cout << "WEAVED AND DODGED!" << endl;}
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
      }
      else{
          cout << "\nBAM! Hook landed for " << damage << endl;
          f->setHealth(f->getHealth() - damage);
          r.countHit(1); //count the hit
          if(damage == v.getAttack() + 7){
            r.countStun(1);
            cout << "\n~~~~~~~~~*STUN HIT TRIGGER*~~~~~~~~\n" << endl;
            srand(time(0));
            damage = (rand() % 14 + 1) + v.getAttack(); 
            cout << "ATTACK:\n      Left Hook(1) or Right Hook(2)" << endl;
            cin >> direction1;
            //Example: MC damage is 20, regular range is 13-27, in stun it will be 20-34
            cout << "STUN-STRIKE LANDED FOR " << damage << endl; //check for potential games
            f->setHealth(f->getHealth() - damage);
            //check for a potential knockout that can only ocurr under these circumstances
            if(f->getHealth() < (opponentTotalHealth/2) && damage > v.getAttack() + 7){
              knockout1 = true;
              break;
            }
            //check opponents health
            if(f->getHealth() <= 0){break;}
          }
        }
        cout << "-----------------------------------------" << endl;
        //ENEMY BLOW
        //choose the hook to defend
        cout << "\nDEFEND:\n     Left Hook(1) or Right Hook(2)" << endl;
        cin >> direction1;
        srand(time(0));
        //hook to throw
        direction2 = (rand() % 2+1);
        srand(time(0));
        //damage of the hook
        damage = (rand() % 14 + 1) + f->getAttack() - 7;
        //test the hook/block
        if(direction1 == direction2){
          if(damage > v.getDefense()){
            //define the ammount of damage a punch packed
            damageDealt = damage - v.getDefense();
  
            cout << "\nYOU TOOK A PARTIAL HIT for " << damageDealt << endl;
            v.setHealth(v.getHealth() - damageDealt);
            //check opponents health & count hit
            r.countHit(2);
            if(v.getHealth() <= 0){break;}
          }
          else {
            if(direction1 == 1){cout << "YOU WEAVED AND DODGED!\n" << endl;}
            if(direction1 == 2){cout << "YOU BLOCKED SUCCESSFULLY!\n" << endl;}
          }
          cout << "----------------------------------------" << endl;
        }
        else{
        cout << "\nYOU GOT HIT FOR " << damage << endl;
        v.setHealth(v.getHealth() - damage);
        r.countHit(2); //count the hit
        if(damage == f->getAttack() + 7){
          r.countStun(2);
          cout << "\n~~~~~~~~~*STUN HIT TRIGGER*~~~~~~~~\n" << endl;
          srand(time(0));
          damage = (rand() % 14 + 1) + f->getAttack(); 
          //Example: MC damage is 20, regular range is 13-27, in stun it will be 20-34
          cout << "YOU GOT HIT WITH A STUN-STRIKE FOR " << damage << endl; //check for potential games
          v.setHealth(v.getHealth() - damage);
          //check for a potential knockout that can only ocurr under these circumstances
          if(v.getHealth() < (MCTotalHealth/2) && damage > f->getAttack() + 7){
            cout << "=========== OH! ITS A KNOCKOUT! ============" << endl;
            knockout2 = true;
            break;
          }
          //check opponents health
          if(v.getHealth() <= 0){break;}
        } 
      }
        tradedBlows++;
    }
    cout << "\n++++++++++++++END OF ROUND+++++++++++++\n" << endl;
    tradedBlows = 0; //reset traded blows, 4 blows per round for 3 rounds total
      //end the match if a knockout ocurrs, or if the player has no health left
    if(knockout1 == true || knockout2 == true|| f->getHealth() <= 0 || v.getHealth() <= 0){
      break;
    }
    else if(i != 2){
      cornerHelp(v); //give them drinks to improve their performance
      cout << "\nWould you like to forfeit the match? (y/n)" << endl;
      cin >> decision;
      if(decision == 'y' || decision == 'Y'){return 4;} //automatic loss, forfeited
    }
    
  }
  if(knockout1 == true || f->getHealth() <= 0){ //check if user MC won
    return 1;
  }
  else if(knockout2 == true || v.getHealth() <= 0){ //check if user MC lost
    return 2;
  }
  else { //if theres no knockout and no players health <= 0. Call for winning calc
    return 3;
  }
  
}


//both end and save the game, free dynamic Fighters array
bool endSaveGame(MC &v, Fighter* f[], int quant){
  string saveFile;
  string input2;
  bool fileOpen = true;

    cout << "Would you like to save your game? (y/n)" << endl;
    cin >> input2;
    if(input2.at(0) == 'y' || input2.at(0) == 'Y'){
      cout << "Under what username would you like to save your game?" << endl;
      cin>>saveFile;
      ofstream fout;
      fout.open(saveFile);
      if(fout.is_open()){
        fout << v.level << endl;
        fout << v.fName << endl << v.lName << endl;
        fout << v.getAttack() << endl << v.getDefense() << endl << v.getHealth() << endl;
        fout << v.coach.attackR << endl << v.coach.defenseR << endl << v.coach.healthR << endl << v.coach.money << endl;
        fout << v.reputation.pChamp << endl << v.reputation.heel << endl << v.getWins() << endl << v.getLosses();
        fout.close();
        
        for(int i = 0; i < quant; ++i){
          delete f[i];
        }
      }
      else {
        cout << "Error opening save file" << endl;
        fileOpen = false;
        fout.clear();
      }
    }
  return fileOpen;
}


//load a game

bool loadGame(MC& v){
  string loadFile;
  bool fileSuccess = true;

  cout << "\nWhat's the username of the saved game to load?" << endl;
  cin >> loadFile;
  
  string space;
  
  ifstream fin(loadFile);
  fin >> space;
  if(fin.is_open() && space != "")
  {
    v.level = stoi(space);
    int x;
    fin >> v.fName >> v.lName;      
    fin >> x;
    v.setAttack(x);
    fin >> x;
    v.setDefense(x);
    fin >> x;
    v.setHealth(x);

    fin >> v.coach.attackR >> v.coach.defenseR >> v.coach.healthR >> v.coach.money;
    fin >> v.reputation.pChamp >> v.reputation.heel;
    fin >> x;
    v.setRecord(x,0);
    fin >> x;
    v.setRecord(0, x);
      cout << "\nProfile Loaded!" << endl;
      cout << "Stats for " << v.getName() << " Record: " << v.getRecord() << "\nLevel: " << v.level << "\n" << "Attack: " << v.getAttack() << "\n" <<
        "Defense: " << v.getDefense() << "\n" << "Health: " << v.getHealth() << endl;
      fin.close();
  } //be surre to make sure they dont fight fighters that do not exist
    //else if(space == "6"){cout << "You already completed this story! Make a new one!!" << endl;}
  else{
    cout << "\nThere's been an error loading your profile..." << endl;
    fileSuccess = false;
  }
  return fileSuccess;
}

//updates the Coach structure the MC class has
//for enhancement drinks to be used in between rounds during matches
//bought with money from matches
void store(MC &v){

  int rAttack = 100;
  int rDefense = 100;
  int rHealth = 100;

  int e = 0;
  cout << "\nI'm Mr.Li; this my store. I don't have time to waste.\nIf you want something click the number!" << endl;
  cout << "1. Gatorade (increase attack by 25; costs 5 dollars)" << endl;
  cout << "2. Powerade (increase defense by 25; costs 5 dollars)" << endl;
  cout << "3. Water (increase health by 10; costs 5 dollars)" << endl << endl;
  cout << "Leave Store (4)" << endl;

  while(e != 4){
    cin >> e;
    if(v.coach.money >= 5){
       if(e == 1){
         v.coach.attackR += 5;
         rAttack--;
         v.coach.money -=5;
         cout << "Haha! Thanks for your money!" << endl;
       }
       else if(e == 2){
         v.coach.defenseR++;
         rDefense--;
          v.coach.money -=5;
          cout << "Haha! Thanks for your money!" << endl;
       }
       else if(e == 3){
         v.coach.healthR++;
         rHealth--;
         v.coach.money -=5;
          cout << "Haha! Thanks for your money!" << endl;
       }
      else {cout << "You hooligan! We dont have that, buy something or leave!\n" << endl;}
     }
     else {
       cout << "No money! Out my store!" << endl;
       e=4;
     }
    cout << "Balance: " << v.coach.money << endl;
  }
}
//Give MC chance to drink in between rounds. 
void cornerHelp(MC &v){
  int e = 0;
  cout << "\nCoach: I think we have drinks, pick something (number) before the next round!" << endl;
   cout << "1. Gatorade (increase attack by 25)" << endl;
   cout << "2. Powerade (increase defense by 25)" << endl;
   cout << "3. Water (increase health by 100)" << endl;
    cout << "4. No Drinks (skip)" << endl << endl;

  for(int i = 0; i < 3; ++i){
  cin >> e;
    if(e == 4){break;}
    if(e == 1){
      if(v.coach.attackR > 0){
         v.coach.attackR--;
        v.setAttack(v.getAttack() + 5);
        }
      else{cout << "No Gatorade!" << endl;}
       }
       if(e == 2){
        if(v.coach.defenseR > 0){
         v.coach.defenseR--;
         v.setDefense(v.getDefense() + 5);
        }
         else{cout << "No Powerade!" << endl;}
       }
       if(e == 3){
         if(v.coach.healthR > 0){
          v.coach.healthR++;
           v.setHealth(v.getHealth() + 10);;
        }
         else {cout << "No water!" << endl;}
       }
  }

  cout << "Coach: Get Up!!" 
  << "\nCoach: The rounds about to start!" << endl << endl;

}

//laod the stats for the fighters array which the user faces
void loadInStats(Fighter* M[], int quant, ifstream& fin){
  int num, num2;
  string fname, lname;

  for(int i = 0; i < quant; ++i){
    M[i] = new Fighter();
    fin >> fname >> lname;
    M[i]->setName(fname, lname);
    fin >> num;
    M[i]->setAttack(num);
    fin >> num;
    M[i]->setDefense(num);
    fin >> num;
    M[i]->setHealth(num);
    fin >> num >> num2;
    M[i]->setRecord(num, num2);
  }
  
}
//introduction text
void introText(){
  cout << "\nLong time rival bear cliques, GUM and SOURS are fighting for\nthe yearly right to sell gummy bear candy or sour bear candy in the schools cafeteria. \n";
  cout << "Last year, GUM lost all of their boxers during the tournament due to injury." << endl;
  cout << "In particular.. to that man.... Mike... But anyways...\n" << endl;
  cout << "You got tricked into signing up for the tournament\nthey desperately needed a boxer to not be disqualified." << endl;
  cout << "The entire school nicknamed you Gummy.\nBecause you got tricked and by GUM and it rhymes with Dummy... yeah...\n" << endl;

}

void introText2(){
  cout << ".\nYou're being helped by the rather useless gym coach.\nHe's so useless we only call him Coach, we don't even his real name.\nThe store owner, Mr.Li, will sell you drinks for the fight so you can improve your performance.\nHe's a bit rude so beware. \n\nYou will need to train to win this tournament and also, watch your reputation!\n";  
}
