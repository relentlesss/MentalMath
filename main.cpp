#include <iostream>
#include <string>
#include <random>
#include "functions.hpp"


int main() {

  std::cout << "\n";
  std::cout << "*********************** *************************************\n";
  std::cout << "Welcome to SigmaSquare, the best mental arithmetic game ever!\n";
  std::cout << "*********************** *************************************\n\n";
  std::cout << "Rules:\n";
  std::cout << "-Try to answer the maximum number of arithmetic questions in 2 minutes.\n";
  std::cout << "-Only whole numbers are accepted. Round your guess if necessary.\n\n";

  int usr_diff;
  usr_diff = 0;
  
  // set initial conditions of the game
  while (usr_diff < 1 || usr_diff > 5) {

    std::cout << "Difficulty: \n";
    std::cout << "  Level 1: + - *\n";
    std::cout << "  Level 2: + - * /\n";
    std::cout << "  Level 3: + - * / %\n\n";

    std::cout << "Please, enter the number indicating the desired level of difficulty.\n";
    std::cout << "The game will start right after, good luck!\n";

    std::cin >> usr_diff;
    usr_diff += 2;

    }

  // call the game loop
  game_loop(usr_diff);

}
