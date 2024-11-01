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

userDatabase::userDatabase( const std::string& _hosts, const std::string& _username, const std::string& _password )
  : username { _username }
  , hosts    { _hosts }
  , password { _password } {
    nlohmann::ordered_json data = {
      {_hosts, {
          {"username", _username},
          {"password", _password},
          {"active", true}
      }}
    };

    std::ofstream file("database/user_data.json");
    file << data.dump(2);
    file.close();
}

void userDatabase::changeHost( const std::string& _host ) const { 
  std::string oldHost = getHosts();
}