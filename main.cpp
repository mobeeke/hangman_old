#include <iostream>
#include "../include/Man.h"
#include "../include/HangMan.h"

int main() {
    Man mn;
    HangMan hm(mn, 1);
    while (!mn.isDead() && !hm.victory()) {
      hm.displayPlatform();
      char guess;
      std::cout << "Enter a guess: ";
      std::cin >> guess;
      hm.guess(guess);
    }
    if (hm.victory()) {
      hm.displayPlatform();
      std::cout << "Congratulations! You Win!" << std::endl;
    } else {
      hm.displayPlatform();
      std::cout << "Better luck next time!" << std::endl;
      std::cout << "The secret word was: " << hm.getSecretWord() << std::endl;

    }
    return 0;
}
