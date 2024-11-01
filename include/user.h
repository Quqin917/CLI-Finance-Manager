#ifndef USER_H_
#define USER_H_

#include <iostream>

class userDatabase {
private:
  std::string username;
  std::string password;
  std::string hosts;

public:
  userDatabase( const std::string& _hosts,  const std::string& _username,  const std::string& _password);

  void changeHost( const std::string& _host ) const;

  std::string getUsername() const { return this->username; }
  std::string getHosts() const { return this->hosts; }

};

#endif