#include "input_output.h"

std::string getUserInput( const std::string& prompt ) {
  std::cout << prompt;

  std::string input;
  std::cin >> input;
  return input;
}

#ifdef _WIN32

std::string getPassword( const std::string& prompt ) {
  std::cout << prompt;

  DWORD mode = 0;
  HANDLE inputHandle = GetStdHandle( STD_INPUT_HANDLE );

  GetConsoleMode( inputHandle, &mode );

  SetConsoleMode( inputHandle, mode & (~ENABLE_ECHO_INPUT));

  std::string input;
  std::cin >> input;

  SetConsoleMode( inputHandle, mode );

  std::cout << '\n';
  return input;
}

#endif