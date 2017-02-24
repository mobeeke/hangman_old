//
// Created by zbb on 11/20/15.
//

#include "../include/Man.h"                 //connects Man.cpp to all the other files
                                            //the function man loops through all of the parts of the hangman body and sets them
                                            //to false so that in HangMan.cpp the function displayPlatform() does not print them
                                            // out initially
Man::Man() {
    bodyParts = new bool[6];                //creates an array for all 6 of the body parts
    for (int i = 0; i < 6; i++) {           // loops through all of the body parts and sets them to false so they are not printed
        this -> bodyParts[i] = false;       // because the function displayPlatform() will not print them unless they are true
    }
}
                                            //the next 6 function are used to check the boolean condition of each body part to
                                            // see if they can be printed or not
bool Man::checkHead() const {
    return this -> bodyParts[0];            //returns the boolean value of the head
}

bool Man::checkTorso() const {
    return this -> bodyParts[1];            //returns the boolean value of the torso
}

bool Man::checkRArm() const {               //returns the boolean value of the right arm
    return this -> bodyParts[3];
}

bool Man::checkLArm() const {               //returns the boolean value of the left arm
    return this -> bodyParts[2];
}

bool Man::checkRLeg() const {               //returns the boolean value of the right leg
    return this -> bodyParts[5];
}

bool Man::checkLLeg() const {               //returns the boolean value of the left leg
    return this -> bodyParts[4];
}

                                            // if the game is over and the man is completely shown all boolean values for
                                            //the body will be true so this sets them all back to false
bool Man::isDead() const {
  for (int i = 0; i < 6; i++) {
    if (this -> bodyParts[i] == false) {
      return false;
    }
  }
  return true;
}
                                            // if the player has an incorrect guess the next body part must be shown this
                                            // function setNext() will make the next body part true so that it can be printed
void Man::setNext() {
  for (int i = 0; i < 6; i++) {
    if (this -> bodyParts[i] == false) {    //finds the next body part on the list that has not been printed yet
      this -> bodyParts[i] = true;          //sets it to true so that it can be printed
      break;
    }
  }
}
                                            // the next 6 functions set the boolean values for the body parts of the hangman
                                            //to true so that they can be printed in HangMan.cpp in the function 
                                            //displayPlatform()
void Man::setHead() {
    this -> bodyParts[0] = true;            // sets the boolean value of head to true
}

void Man::setTorso() {
    this -> bodyParts[1] = true;            // sets the boolean value of torso to true
}

void Man::setRArm() {
    this -> bodyParts[2] = true;            // sets the boolean value of right arm to true
}

void Man::setLArm() {                       // sets the boolean value of left arm to true
    this -> bodyParts[3] = true;
}

void Man::setRLeg() {                       // sets the boolean value of right leg to true
    this -> bodyParts[4] = true;
}

void Man::setLLeg() {                       // sets the boolean value of left leg to true
    this -> bodyParts[5] = true;
}
