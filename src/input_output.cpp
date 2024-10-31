#include "input_output.h"

std::string getUserInput(std::string prompt) {
  std::cout << prompt;

  std::string input;
  std::cin >> input;
  return input;
}