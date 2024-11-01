#include "input_output.h"

// Function to get user input with a prompt
std::string getUserInput( const std::string& prompt ) {
  std::cout << prompt; // print a prompt before input

  // Get user input
  std::string input;
  std::cin >> input;
  
  return input;
}

#ifdef _WIN32

// Function to get password input from windows, hiding characters as they're typed
std::string getPassword( const std::string& prompt ) {
  DWORD mode = 0;
  HANDLE inputHandle = GetStdHandle( STD_INPUT_HANDLE );

  // Save current console mode
  GetConsoleMode( inputHandle, &mode );

  // Disable echoing of input 
  SetConsoleMode( inputHandle, mode & (~ENABLE_ECHO_INPUT));

  // Get the password input
  std::string input { getUserInput(prompt) };

  // Restore console mode to previous state
  SetConsoleMode( inputHandle, mode );
  
  return input;
}

#else if __linux__

// Function to ge password input from linux, hiding characters as they're typed
std::string getPassword( const std::string& prompt ) {
  
}

#endif