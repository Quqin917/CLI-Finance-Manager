#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

#include <iostream>
#include <string>
#include <sstream>

#ifdef _WIN32
  #include <windows.h>

#elif __linux__
  #include <termios.h>
  #include <unistd.h>

#endif

// Function to get password input, hiding characters as they're typed
std::string getPassword( const std::string& prompt );

// Function to get user input 
template <typename T>
T getUserInput( const std::string& prompt );

#include "input_output.tpp"

#endif