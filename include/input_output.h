#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

// Function to get user input with return value that can be determined
template <typename T>
T getUserInput( const std::string& prompt );

// Function to get password input, hiding characters as they're typed
std::string getPassword( const std::string& prompt );

#endif