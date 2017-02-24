//
// Created by zbb on 11/20/15.
//

#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <errno.h>
#include "../include/HangMan.h"

HangMan::HangMan(Man mn, int difficulty) {
    this -> man = mn;
    this -> secretWord = this -> selectWord(difficulty);
    this -> foundChars = new bool[secretWord.size() - 1];
    for (int i = 0; i < secretWord.size() - 1; i++) {
      foundChars[i] = false;
    }
}

void HangMan::displayPlatform() {
    if ((!(this -> man.checkLArm())) && !(this -> man.checkLLeg())) {
        std::cout << "-------------" << std::endl;
        std::cout << "|           |" << std::endl;
        if (this -> man.checkHead())
            std::cout << "O           |" << std::endl;
        if (this -> man.checkTorso())
            std::cout << "|           |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
    }
    else {
        std::cout << " --------------" << std::endl;
        std::cout << " |            |" << std::endl;
        if (this -> man.checkHead())
            std::cout <<" O            |" << std::endl;
        if (this -> man.checkTorso() && this -> man.checkLArm() && this -> man.checkRArm())
            std::cout << "/|\\           |" << std::endl;
        else if (this -> man.checkTorso() && this -> man.checkLArm())
            std::cout << "/|            |" << std::endl;
        else if (this -> man.checkTorso())
            std::cout << " |            |" << std::endl;
        if (this -> man.checkLLeg() && this -> man.checkRLeg())
            std::cout << "/ \\           |" << std::endl;
        else if(this -> man.checkLLeg())
            std::cout << "/             |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
    }
    for (int i = 0; i < this -> secretWord.size() - 1; i++) {
      if (this -> foundChars[i]) {
        std::cout << secretWord[i] << " ";
      } else {
        std::cout << "_ ";
      }
    }
    std::cout << std::endl;

    std::cout << this -> secretWord << std::endl;
    std::cout << this -> secretWord.size() << std::endl; 
}

std::string HangMan::selectWord(int difficulty) {
  std::srand(time(0));
  std::vector<std::string> words;
  std::ifstream file("../../resources/words.txt");
  if (!file) {
    std::cout << "Error reading file!" << std::endl;
    std::cerr << "Error: " << std::strerror(errno);
  } else { 
    std::string line;
    while (std::getline(file, line)) {
      words.push_back(line);
    }
  }
  return words[std::rand() % words.size()]; 
}

std::string HangMan::getSecretWord() {
  return this -> secretWord;
}

void HangMan::guess(char guess) {
  bool success = false;
  if (isGuessValid(guess)) {
    this -> guessesSoFar.push_back(guess);
    for (int i = 0; i < this -> secretWord.size() - 1; i++) {
      if (guess == secretWord[i]) {
        this -> foundChars[i] = true;
        success = true;
      }
    }
    if (!success) {
      this -> man.setNext();
    }
  } else {
    char newGuess;
    std::cout << "You have already guessed that character or it is an invalid character." << std::endl;
    std::cout << "Guess again: ";
    std::cin >> newGuess;
    this -> guess(newGuess);
  }
}

bool HangMan::victory() {
  for (int i = 0; i < this -> secretWord.size() - 1; i++) {
    if (!(this -> foundChars[i])) {
      return false;
    }
  }
  return true;
}

bool HangMan::isGuessValid(char guess) {
  for (int i = 0; i < this -> guessesSoFar.size(); i++) {
    if (guess == guessesSoFar[i]) {
      return false;
    }
  } 
  return true;
}

