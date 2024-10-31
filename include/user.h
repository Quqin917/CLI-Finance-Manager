#pragma once

#include <iostream>

class userDatabase {
private:
  std::string d_username;
  std::string d_password;

public:
  userDatabase(std::string username, std::string password);

  std::string getUsername() const { return d_username; }
};