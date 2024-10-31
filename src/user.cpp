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

userDatabase::userDatabase(std::string username, std::string password)
  : d_username { username }
  , d_password { password } {
    nlohmann::json userData = {
      {"username", username},
      {"password", password}
    };

    std::ofstream file("database/user_data.json");
    file << userData;
  }