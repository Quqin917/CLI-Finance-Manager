#include "input_output.h"

// Function to get user input with return value that can be determined
template <typename T>
T getUserInput( const std::string& prompt ) {
  T result;
  std::cout << prompt;

  std::string input;
  std::getline(std::cin, input);

  std::stringstream inputStream(input);
  inputStream >> result;

  // Check if input type is valid
  if ( inputStream.fail() || !inputStream.eof() ) {
    throw std::runtime_error("Error Invalid Type.");
  }

  return result;
}
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