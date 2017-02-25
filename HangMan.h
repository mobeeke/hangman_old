//
// Created by zbb on 11/20/15.
//

#ifndef HANGMAN_HANGMANGRAPHICS_H
#define HANGMAN_HANGMANGRAPHICS_H


#include "Man.h"
#include <string>
#include <vector>

class HangMan {
public:
   HangMan(Man mn, int difficulty);
  void displayPlatform();
  std::string getSecretWord();
  void guess(char guess);
  bool victory();
    
private:
    Man man;
    std::string secretWord;
    bool* foundChars;
    std::vector<char> guessesSoFar;
    std::string selectWord(int difficulty);
    bool isGuessValid(char guess);
};


#endif //HANGMAN_HANGMANGRAPHICS_H
