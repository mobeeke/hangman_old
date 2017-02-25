//
// Created by zbb on 11/20/15.
//

#ifndef HANGMAN_MAN_H
#define HANGMAN_MAN_H

class Man {
public:
    Man();
    bool checkHead() const;
    bool checkTorso() const;
    bool checkRArm() const;
    bool checkLArm() const;
    bool checkRLeg() const;
    bool checkLLeg() const;
    bool isDead() const;
    void setNext();
    void setHead();
    void setTorso();
    void setRArm();
    void setLArm();
    void setRLeg();
    void setLLeg();
private:
    bool* bodyParts;

};

#endif //HANGMAN_MAN_H
