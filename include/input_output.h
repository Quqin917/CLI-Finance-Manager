#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

// Check if the machine OS window or linux 
#ifdef _WIN32

#include <windows.h>

#else if __linux__

#include <termios.h>

#endif

#include <iostream>
#include <string>

// Function to get user input with a prompt
std::string getUserInput( const std::string& prompt );

// Function to get password input, hiding characters as they're typed
std::string getPassword( const std::string& prompt );

#endif