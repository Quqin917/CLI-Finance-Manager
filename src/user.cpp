#include "user.h"

#include <nlohmann/json.hpp>

/*
 * 1. username and password
 *    1. if new user create new file
 *       1. ask user how many there monthly earning is
 *       2. ask user what currency they want to used
 *       3. ask if finance file want to be private
 *          1. if yes then encrypt file
 *          2. if no then don't encrypt file
 * 2. if old user open old file
 *    1. decypher old file
*/

// Function to write data into a json file 
void writeFile(nlohmann::ordered_json data) {
  // Open a json file for writing the data
  std::ofstream file("database/user_data.json");

  // Insert data into the json with a 2 space index beautification, then close file
  file << data.dump(2);
  file.close();
}

nlohmann::json readFile() {
  using json = nlohmann::json;

  std::ifstream file("database/user_data.json");

  json data = json::parse(file);
  return data;
}

// Function to store username and password into a json file 
userDatabase::userDatabase( const std::string& _username, const std::string& _password, bool _newUser )
  : username { _username }
  , password { _password }
  , newUser  { _newUser  } 
  {
    nlohmann::ordered_json data;
    // Check if user is a new user or old user
    if (_newUser) {
      // Define the data that going to be inserted into a json file
      data = {
        {username, {
            {"password", _password},
            {"active", true}
        }}
      };

    writeFile(data);
    } else {
      nlohmann::json data { readFile() };
      std::cout << data << '\n';
    }
}

// Function to handle settings up for new user
void newUserQuestion( userDatabase& database ) {
  userSetup user;
  
  // Ask user what currency want to be used
  user.currency = getUserInput<std::string>("Currency: ");

  // Ask user for monthly earning
  // user.earning = getUserInput<int>("Monthly Earning: ");

  // Ask user if finance file want to be private
  while (user.filePrivate != "yes" || user.filePrivate != "no") {
    user.filePrivate = getUserInput<std::string>("Private File (yes, no): ") ;
  }
}