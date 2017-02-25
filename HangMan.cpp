

#include <ctime>                                //this allows you to access functions to manipulate date and time information
#include <cstdlib>                              //allows access to functions in the general utilities library
#include <cstring>                              //allows access to functions in the string library
#include <iostream>                             //allows access to input/output functions
#include <fstream>                              //allows access to input/output functions on files
#include <vector>                               //allows access to functions that involve vectors
#include <errno.h>                              //allows access to functions that deal with error calls
#include "../include/HangMan.h"                 // links with the rest of the project

                                                //the function HangMan finds a word based off of a difficulty level and sets
                                                //all the characters in the word to false so that they do not get printed of
                                                //until they are guessed correctly
HangMan::HangMan(Man mn, int difficulty) {
    this -> man = mn;                                       //declares man as type Man
    this -> secretWord = this -> selectWord(difficulty);   //finds a word with the correct difficulty level         
    this -> foundChars = new bool[secretWord.size() - 1]; //finds the size of the secret word and sets them to bool values so
    for (int i = 0; i < secretWord.size() - 1; i++) {     //that they can be set to false here so that they are not printed
      foundChars[i] = false;
    }
}
                                                           //the function displayPlatform prints out the gallows and parts of
                                                           //the man depending on how many guesses they have incorrectly taken
void HangMan::displayPlatform() {
    if ((!(this -> man.checkLArm())) && !(this -> man.checkLLeg())) { //if the left leg and arm have not been put to true
        std::cout << "-------------" << std::endl;                  //print part of the gallows
        std::cout << "|           |" << std::endl;                  //print the rope
        if (this -> man.checkHead())                                //if the head has been put to true in Man.cpp 
            std::cout << "O           |" << std::endl;              //then print the head
        if (this -> man.checkTorso())                               //if the torso has been put to true in Man.cpp      
            std::cout << "|           |" << std::endl;              //then print the torso
        std::cout << "            |" << std::endl;                  //prints gallows automatically
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
    }                                                               //if the left leg and arm have been put to true in
    else {                                                          //Man.cpp then print out the following
        std::cout << " --------------" << std::endl;                //print part of the gallows
        std::cout << " |            |" << std::endl;                //print the rope
        if (this -> man.checkHead())                                //the head condition should be true but it still checks it
            std::cout <<" O            |" << std::endl;             //prints the head
        if (this -> man.checkTorso() && this -> man.checkLArm() && this -> man.checkRArm()) //if all these conditions are true
            std::cout << "/|\\           |" << std::endl;                                   //then print torso, left and right arm
        else if (this -> man.checkTorso() && this -> man.checkLArm()) //if only two of the conditions are correct then
            std::cout << "/|            |" << std::endl;              //print out left arm and torso
        else if (this -> man.checkTorso())                            //if only the torso is set to true in Man.cpp then
            std::cout << " |            |" << std::endl;              //print the torso
        if (this -> man.checkLLeg() && this -> man.checkRLeg())      //checks if left and right leg are set to true
            std::cout << "/ \\           |" << std::endl;           //prints them out if they are set to true
        else if(this -> man.checkLLeg())                            //if just the left leg is set to true then
            std::cout << "/             |" << std::endl;            //print out just the left leg
        std::cout << "              |" << std::endl;                //prints out the gallows
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
        std::cout << "              |" << std::endl;
    }                                                           //this loop will print out the length of the word in underscores
                                                                //where the user has correctly guessed the letter, that letter 
                                                                //will replace the underscore in the word
    for (int i = 0; i < this -> secretWord.size() - 1; i++) {   //loops through the size of the word
      if (this -> foundChars[i]) {                              //if the user has correctly guessed that letter
        std::cout << secretWord[i] << " ";                      //print out that letter
      } else {
        std::cout << "_ ";                                      //otherwise print out an underscore
      }
    }
    std::cout << std::endl;                                     //prints out a new line

    std::cout << this -> secretWord << std::endl;               //prints out the word to guess
    std::cout << this -> secretWord.size() << std::endl;        //prints out the size of the word to guess 
}
                                                            //the function selectWord() will pick out a word from a list of words
                                                            //in a text file based off of the level of difficutly selected
std::string HangMan::selectWord(int difficulty) {
  std::srand(time(0));
  std::vector<std::string> words;                           //creates a vector called words to store the word from the file in
  std::ifstream file("../../resources/words.txt");          //opens the file to read from
  if (!file) {                                              //if the progrram cannot find the file to read from
    std::cout << "Error reading file!" << std::endl;        //let the user know that there is an error in reading that file
    std::cerr << "Error: " << std::strerror(errno);         //handle that error
  } else {                                                  //if the program found the file
    std::string line;                                       // the loop reads through the entire file line by line
    while (std::getline(file, line)) {                      // and copies it into the vector called words
      words.push_back(line);                                //the vector words now has all the words in that file
    }
  }
  return words[std::rand() % words.size()];                 //randomly chooses one of the words in the file to use
}

std::string HangMan::getSecretWord() {                  //the function getSecretWord() returns the word selected from the
  return this -> secretWord;                            //program that the user has to guess
}
                                                        //the function guess keeps track of all the guesses the user has 
                                                        //taken so far and decides wether or not the guess was correct by
                                                        //setting foundChars to true. It also prints out the guesses already made
void HangMan::guess(char guess) {
  bool success = false;                                 //sets success to false so program knows user has not guessed correctly yet
  if (isGuessValid(guess)) {                            //checks to see if guess is valid by calling function below
    this -> guessesSoFar.push_back(guess);              //stores users guess to keep track of all past guesses
    for (int i = 0; i < this -> secretWord.size() - 1; i++) {   //loops through the entire word to check if guess is there
      if (guess == secretWord[i]) {                         //if the user correctly guessed a letter
        this -> foundChars[i] = true;                       //set foundChars to true so that it can be printed
        success = true;                                     //set success to true so that no more limbs are printed in the 
                                                            //function displayPlatform()
      }
    }
    if (!success) {                                     //if the user did not correctly guess a letter than
      this -> man.setNext();                            //print out the next limb in displayPlatform()
    }
  } else {                                               //if the user guesses a letter that has already been guessed than
    char newGuess;                                      //they have to guess again
    std::cout << "You have already guessed that character or it is an invalid character." << std::endl;
    std::cout << "Guess again: ";
    std::cin >> newGuess;
    this -> guess(newGuess);
  }
}                                                       //this function will check the entire length of the word and if every
                                                        //charcter from foundChars is true than the user won
bool HangMan::victory() {
  for (int i = 0; i < this -> secretWord.size() - 1; i++) { //loops through the entire word
    if (!(this -> foundChars[i])) {                         //if one of the characters is not guessed yet than return false
      return false;
    }
  }                                                         //if all the characters are true than the user won so return true
  return true;                                              
}
                                                        //this function checks if the users guess is valid by looping through
                                                        //the entire list that the user has guessed so far and if any match 
                                                        //with the current guess than it is not a valid guess
bool HangMan::isGuessValid(char guess) {
  for (int i = 0; i < this -> guessesSoFar.size(); i++) {  //loops through the entire guess list
    if (guess == guessesSoFar[i]) {                         //if any of the guesses from before match the current guess
      return false;                                     //guess is not valid
    }
  } 
  return true;                                      //otherwise the guess is valid
}

