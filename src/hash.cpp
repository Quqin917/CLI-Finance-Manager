#include "hash.h"

void key::calculateNValue( const int& _p, const int& _q ) {
  m_p = _p;
  m_q = _q;
  m_len = _p * _q;
}

void key::totient() {
  // lcm(p-1, q-1)

  std::vector<int> divisionValue {m_p - 1, m_q - 1};
  std::vector<int> divisionTable;

  while ( divisionValue[0] % 2 == 0 && divisionValue[1] % 2 == 0) {
    divisionValue[0] = divisionValue[0] / 2;
    divisionValue[1] = divisionValue[1] / 2;

    divisionTable.push_back(2);
  }
  
  int i = 3;
  while ( i <= divisionValue[0] && i <= divisionValue[1] ) {
    while ( divisionValue[0] % i == 0 && divisionValue[1] % i == 0 ) {
      divisionValue[0] = divisionValue[0] / i;
      divisionValue[1] = divisionValue[1] / i;

      divisionTable.push_back(i);
    }
    i += 2;
  }

  int result = 1;
  for ( int e : divisionTable ) {
    result = result * e;
  }
  result = divisionValue[0] * divisionValue[1] * result;

  m_tot = result;
}

void key::show() {
  std::cout << m_p << '\t' << m_q << '\t' << m_len << '\n';
  std::cout << m_tot;
}

// unsigned int generatePrime() {
// }