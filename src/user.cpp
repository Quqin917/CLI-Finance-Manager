#include "user.h"
#include <nlohmann/json.hpp>
#include <fstream>

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

// Function to store username and password into a json file
void userDatabase::inputUserVal( const std::string& _username, const std::string& _password ) const {
    // Define the data that going to be inserted into a json file
    nlohmann::ordered_json data = {
      {_username, {
          {"password", _password},
          {"active", true}
      }}
    };

    // Open a json file for writing the data
    std::ofstream file("database/user_data.json");

    // Insert data into the json with a 2 space index beautification
    file << data.dump(2);
    file.close();
}