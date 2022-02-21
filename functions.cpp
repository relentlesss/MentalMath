#include <cstdlib>
#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <tuple>
#include <chrono>
#include <limits>
#include "functions.hpp"

//function definition file

// inner func
int pseudo_rand_ope(int diff) {

  int res;
  //generate two pseudo random number in range(1,100) inclusive
  srand(time(0));
  int a = 1 + (rand() % 100);
  int b = 1 + (rand() % 100);

  //generate pseudo-random operation
  std::string ope_str;
  int ope = 1 + (rand() % diff);

  if (ope == 1) {
    ope_str = '+';
    res = a + b;
  } else if (ope == 2) {
    ope_str = '-';
    res = a - b;
  } else if (ope == 3) {
    ope_str = '*';
    res = a * b;
  } else if (ope == 4) {
    ope_str = '/';
    // round answer to expect only integer input
    res = round(a / b);
  } else {
    ope_str = '%';
    res = a % b;
  }
  // print out the question to the user
  std::cout << std::to_string(a) + ope_str + std::to_string(b) + "\n";

  return res;

  }

// game loop function
void game_loop(int diff) {
  
  // declare and initialize user's total score var
  int score;
  score = 0;
  
  // start chrono here
  std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
  
  // while chrono under 120 sec game loop continue
  while ((std::chrono::steady_clock::now() - start <= std::chrono::seconds(120))) {
    
    // declare and initialize true answer from pseudo-random operation
    int res;
    res = pseudo_rand_ope(diff);

    int ans;
    
    // while user's input ≠ true answer ==> wait for right ans before moving on to next question
    while (ans != res) {
      while (1) {
        if (std::chrono::steady_clock::now() - start > std::chrono::seconds(120)) {
            break;
          }
        std::cin >> ans;
        //check if last answer was overtime.
        if (std::chrono::steady_clock::now() - start > std::chrono::seconds(121)) {
            score --;
            break;
          }

        // check user's input type i.e. checking for integer input.
        if (std::cin.fail()) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
          // one among many discrete checks in the program to avoid overtime.
          if (std::chrono::steady_clock::now() - start > std::chrono::seconds(120)) {
            break;
          }
          // get user's answer to question
          std::cout << "Enter a valid number please.\n";
          if (std::chrono::steady_clock::now() - start > std::chrono::seconds(120)) {
            break;
          }
        }
        else break;
      }

      if (std::chrono::steady_clock::now() - start > std::chrono::seconds(120)) {
        break;
      }

    }
    // increment total score if question correctly answered
    score ++;
    if (std::chrono::steady_clock::now() - start > std::chrono::seconds(120)) {
      break;
    }

  }
  // 2 minutes passed, time to give this user an idea of his mental arithmetic skill.
  std::cout << "\n";
  std::cout << "You answered " << std::to_string(score) << " correctly under 2 minutes!\n\n\n";

}
