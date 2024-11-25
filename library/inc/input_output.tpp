#include "input_output.h"

template <typename T>
T getUserInput( const std::string& prompt ) {
  std::cout << prompt;

  std::string input;
  getline(std::cin, input);

  T result;

  std::stringstream inputStream(input);
  inputStream >> result;

  if (inputStream.fail() || !inputStream.eof()) {
    throw std::runtime_error("Error Fail Type");
  }
  
  return result;
}