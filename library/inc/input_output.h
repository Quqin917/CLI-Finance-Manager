#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

#include <iostream>
#include <string>
#include <windows.h>

template <typename T>
T getUserInput( const std::string& prompt) {
  std::cout << prompt;

  T input;
  std::cin >> input;
  
  return input;
}


// Function to get password input, hiding characters as they're typed
std::string getPassword( const std::string& prompt );

template <typename T>
T print(T prompt) {
  std::cout << prompt << '\n';
}

#endif