#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

#include <iostream>
#include <string>

std::string getUserInput( const std::string& prompt );

#ifdef _WIN32

#include <windows.h>
#include <stdexcept>

std::string getPassword( const std::string& prompt );

#endif

#endif