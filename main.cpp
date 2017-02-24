#include <iostream>
#include "../include/Man.h"             //links files main.cpp and Man.cpp together
#include "../include/HangMan.h"         // links files main.cpp and HangMan.cpp together

int main() {
    Man mn;                             //mn will be stored as man in Hangman.cpp
    HangMan hm(mn, 1);                  //calls the function Hangman in Hangman.cpp that selects difficulty level and picks the word to guess
                                        // if the player has not won the game yet or run out of guesses then continue in this loop
    while (!mn.isDead() && !hm.victory()) {
      hm.displayPlatform();             //function in HangMan.cpp that displays the gallows
      char guess;                       //this will be the players guess taken from line 14
      std::cout << "Enter a guess: ";   //prompts the user to guess a letter
      std::cin >> guess;                //takes the players guess as char guess   
      hm.guess(guess);                  //function in Hangman.cpp that stores guess and keeps track of guesses
    }
                                        //if the player has won the game by guessing the correct word than enter into this if statement
    if (hm.victory()) {
      hm.displayPlatform();             //function in HanMan.cpp that displays the gallows
      std::cout << "Congratulations! You Win!" << std::endl;  //tells the user that they won
                                        //if they have not won and they ran out of guesses than enter this if statement
                                        //this loop will let the user know what the word was and wish them better luck
    } else {
      hm.displayPlatform();             //function in HangMan.cpp that displays the gallows
      std::cout << "Better luck next time!" << std::endl;
      std::cout << "The secret word was: " << hm.getSecretWord() << std::endl; //prins answer from function in Hangman.cpp

    }
    return 0;
}
