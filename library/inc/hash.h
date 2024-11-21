#ifndef HASH_H_
#define HASH_H_

#include "input_output.h"
#include <numeric>
#include <vector>
#include <random>
#include <time.h>

// Generating prime value
unsigned int generatePrime();

class key {
private:
  int m_p {};
  int m_q {};
  int m_e { 17 };
  int m_len {};
  int m_tot {};

public:
  // Calculate n value
  void calculateNValue( const int& p, const int& q );

  // Calculate totient(n) value
  void totient();

  void show();

};

#endif