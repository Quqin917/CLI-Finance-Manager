#include "input_output.h"
#include "user.h"
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
 *  3. Close Programj
 *      1. if user choose to make file to be private
 *          1. encrypt user file to keep secret
*/

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "for new user, close program then type 'finman.exe --new ${username} ${password}'\n";
  } else if (argc != 4) {
    std::cout << "Wrong commnad, type 'finman.exe --new ${username} ${password}'\n";
    return 1;
  }

  const userDatabase database{ getUserInput("Username: "), getUserInput("Password: ")};

  return 0;
}