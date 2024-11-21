#include "hash.h"

void key::calculateNValue( const int& _p, const int& _q ) {
  m_p = _p;
  m_q = _q;
  m_len = _p * _q;
}

void key::totient() {
  // lcm(p-1, q-1)

  int p = m_p - 1;
  int q = m_q - 1;
  std::vector<int> divisionTable;

  while ( p % 2 == 0 && q % 2 == 0 ) {
    p = p / 2;
    q = q / 2;

    divisionTable.push_back(2);
  }
  
  int i = 3;
  while ( i <= p && i <= q ) {
    while ( p % i == 0 && q % i == 0 ) {
      p = p / i;
      q = q / i;

      divisionTable.push_back(i);
    }
    i += 2;
  }

  int result = 1;
  for ( auto& e : divisionTable ) {
    result = result * e;
  }
  result = p * q * result;

  m_tot = result;
}

void key::show() {
  std::cout << m_p << '\t' << m_q << '\t' << m_len << '\n';
  std::cout << m_tot;
}

// unsigned int generatePrime() {
// }