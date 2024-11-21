#include "user.h"

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
void writeFile(nlohmann::ordered_json data, std::string& address) {
  // Open a json file for writing the data
  std::ofstream file(address);

  // Insert data into the json with a 2 space index beautification, then close file
  file << data.dump(2);
  file.close();
}

nlohmann::json readFile(std::string& address) {
  using json = nlohmann::json;

  std::ifstream file(address);

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
    std::string fileAddress = "${workspaceFolder}/database/user_data.json";

    // Check if user is a new user or old user
    if (_newUser) {
      // Define the data that going to be inserted into a json file
      data = {
        {username, {
            {"password", _password},
            {"active", true}
        }}
      };

    writeFile(data, fileAddress);
    } else {
      nlohmann::json data { readFile(fileAddress) };
      std::cout << data << '\n';
    }
}

// Function to handle settings up for new user
void newUserQuestion( userDatabase& database ) {
  userSetup user;
  
  // Ask user what currency want to be used
  user.currency = getUserInput<std::string>("Currency: ");

  // Ask user for monthly earning
  user.earning = getUserInput<int>("Monthly Earning: ");

  // Ask user if finance file want to be private
  int stop = 0;
  do {
    std::string trueFalse { getUserInput<std::string>("File Private(yes, no): ") };

    for ( auto& c : trueFalse ) {
      c = tolower(c);
    }

    if ( trueFalse.compare("y") == 0 || trueFalse.compare("yes") == 0 ) {
      user.filePrivate = true;
      stop = 1;
    } else if ( trueFalse.compare("n") == 0 || trueFalse.compare("no") == 0 ){
      user.filePrivate = false;
      stop = 1;
    }

  } while ( stop == 0 );

  // std::cout << user.currency << '\n';
  // std::cout << user.earning << '\n';
  // std::cout << user.filePrivate << '\n';
}