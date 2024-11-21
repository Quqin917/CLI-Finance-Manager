#include "input_output.h"

// Function to get password input from windows, hiding characters as they're typed
std::string getPassword( const std::string& prompt ) {
  char censor { '*' };
  DWORD mode = 0;
  HANDLE inputHandle = GetStdHandle( STD_INPUT_HANDLE );

  // Save current console mode
  GetConsoleMode( inputHandle, &mode );

  // Change console mode to disable echo user input 
  SetConsoleMode( inputHandle, mode & (~ENABLE_ECHO_INPUT));

  // Get the password input
  std::string input { getUserInput<std::string>(prompt) };

  // Restore console mode to previous state
  SetConsoleMode( inputHandle, mode );
  
  return input;
}

// Function to print
// template