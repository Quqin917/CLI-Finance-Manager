#include "input_output.h"

// Function to get user input with a prompt
std::string getUserInput( const std::string& prompt ) {
  std::cout << prompt; // print a prompt before input

  // Get user input
  std::string input;
  std::cin >> input;
  
  return input;
}


// Function to get password input from windows, hiding characters as they're typed
std::string getPassword( const std::string& prompt ) {
}