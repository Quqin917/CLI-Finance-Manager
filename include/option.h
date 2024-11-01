#ifndef OPTION_H_
#define OPTION_H_

#include "user.h"
#include "input_output.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

// Define a bool for new user
bool newUserFlag = false;

// Function to handle command-line options and arguments
void commandOption(int argc, char **argv);

#endif