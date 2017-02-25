//
// Created by zbb on 11/20/15.
//

#include "../include/Man.h"

Man::Man() {
    bodyParts = new bool[6];
    for (int i = 0; i < 6; i++) {
        this -> bodyParts[i] = false;
    }
}

bool Man::checkHead() const {
    return this -> bodyParts[0];
}

bool Man::checkTorso() const {
    return this -> bodyParts[1];
}

bool Man::checkRArm() const {
    return this -> bodyParts[3];
}

bool Man::checkLArm() const {
    return this -> bodyParts[2];
}

bool Man::checkRLeg() const {
    return this -> bodyParts[5];
}

bool Man::checkLLeg() const {
    return this -> bodyParts[4];
}

bool Man::isDead() const {
  for (int i = 0; i < 6; i++) {
    if (this -> bodyParts[i] == false) {
      return false;
    }
  }
  return true;
}

void Man::setNext() {
  for (int i = 0; i < 6; i++) {
    if (this -> bodyParts[i] == false) {
      this -> bodyParts[i] = true;
      break;
    }
  }
}

void Man::setHead() {
    this -> bodyParts[0] = true;
}

void Man::setTorso() {
    this -> bodyParts[1] = true;
}

void Man::setRArm() {
    this -> bodyParts[2] = true;
}

void Man::setLArm() {
    this -> bodyParts[3] = true;
}

void Man::setRLeg() {
    this -> bodyParts[4] = true;
}

void Man::setLLeg() {
    this -> bodyParts[5] = true;
}
