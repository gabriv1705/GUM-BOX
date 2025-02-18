#include "MC.h"

MC::MC() : Fighter(){level = 0;}

string MC::getNickname() { return nickname; }

string MC::getRep() {
  string popularity = "The People's Champ: " + to_string(reputation.pChamp) +
                      "\n" + "The Hated Heel: " + to_string(reputation.heel) +
                      "\n";
  return popularity;
}

string MC::getName() {
  string n = fName + " \"" + nickname + "\" " + lName;
  return n;
}

void MC::updateRep(int r) { // 2 is whats inputted following a win. 0 is for good response, 1 is a bad response
                        // fighters response
  if (r == 0) {
    reputation.pChamp += 15;
    if (reputation.heel != 0) {
      reputation.heel -= 10;
    }
  }
  if (r == 1) {
    reputation.heel += 15;
    if (reputation.pChamp != 0) {
      reputation.pChamp -= 10;
    }
  }

  if (r == 2) {
    if(reputation.pChamp >= reputation.heel) {
      reputation.pChamp += 5;
    } 
    else {
      reputation.heel += 5;
    }
  }
}