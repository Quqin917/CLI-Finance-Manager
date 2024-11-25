#include "input_output.h"

#ifdef _WIN32

// Function to get password input from windows, hiding characters as they're typed
std::string getPassword( const std::string& prompt ) {
  char censor { '*' };
  DWORD mode = 0;
  HANDLE inputHandle = GetStdHandle( STD_INPUT_HANDLE );

  // Save current console mode
  GetConsoleMode( inputHandle, &mode );

  // Change console mode to disable echo of user input 
  SetConsoleMode( inputHandle, mode & (~ENABLE_ECHO_INPUT));

  // Get the password input
  std::string input { getUserInput<std::string>(prompt) };

  // Restore console mode to old state
  SetConsoleMode( inputHandle, mode );
  
  return input;
}

#elif __linux__

// Function to get password input from windows, hiding characters as they're typed
std::string getPassword( const std::string& prompt ) {
  termios oldt;

  // Save current console mode
  tcgetattr(STDIN_FILENO, &oldt);
  termios newt = oldt;

  // Change console mode to disable echo of user input
  newt.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  // Get password input
  std::string input { getUserInput<std::string>(prompt) };

  // Restore console to old state
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return input;
}

#endif