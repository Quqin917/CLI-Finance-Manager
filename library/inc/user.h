#ifndef USER_H_
#define USER_H_

#include "hash.h"
#include "input_output.h"
#include "commandOption.h"
#include <fstream>
#include <nlohmann/json.hpp>

// Class that taking care of user information
class userDatabase {
private:
  std::string m_username; // Stores the username of the user
  std::string m_password; // Stores the password of the user
  bool m_newUser;

public:
  // Constructor to initialize the username and password. newUser is set to true by default
  userDatabase( const std::string& _username,  const std::string& _password, bool _newUser = true );
  
  // Get username of current user
  std::string getUsername() const { return m_username; };
};

struct userSetup {
  std::string currency;
  int earning;
  std::string filePrivate;
};

// Function to handle settings up for new user
void newUserQuestion( userDatabase& database );

#endif