#ifndef USER_H_
#define USER_H_

#include <iostream>

class userDatabase {
private:
  std::string username; // Stores the username of the user
  std::string password; // Stores the password of the user

public:
  // Constructor to initialize the username and password
  userDatabase( const std::string& _username,  const std::string& _password);
  
  // Getter username
  std::string getUsername() const { return this->username; }
};

#endif