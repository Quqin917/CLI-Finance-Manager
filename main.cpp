#include "input_output.h"
#include "user.h"
#include "option.h"
#include <iostream>

/* 1. User input
 *      1. spending
 *          1. Record today date
 *          2. if user is spending ask the name of item and the price
 *              1. category of spending ex. Groceries, Entertainment, Rent, food, bill, etc 
 *          3. if user is earning ask where the money from
 *  
 *  2. Budgets
 *      1. generate monthly expense ex. Rent, Groceries, Entertainment, and Savings based on earning
 *      2. tell user if 
 * 
 * 
 *  3. Close Program
 *      1. if user choose to make file to be private
 *          1. encrypt user file to keep secret
*/

int main(int argc, char **argv) {

  if (argc > 1) {
    commandOption(argc, argv);
  }

  if (!newUserFlag) {

    std::cout << "Hello Old User\n";
  
  }

  



  return 0;
}