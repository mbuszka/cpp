
#include "fifteen.h"

using position = std::pair< size_t, size_t > ;

fifteen::fifteen(): {
  for (size_t i = 0; i < dimension * dimension - 1; i++) {
    table[i%dimension][i/dimension] = i + 1;
  }
  open_i = open_j = dimension-1;
  table[open_i][open_j] = 0;
}

fifteen::fifteen(std::initializer_list< std::initializer_list< size_t >> init) {
  size_t j = 0;
  for (auto l : init) {
    size_t i = 0;
    for (auto n : l) {
      table[i][j] = n;
      if (n == 0) {
         open_i = i;
         open_j = j;
       }
      i++;
    }
    j++;
  }
}

bool fifteen::equals( const fifteen& other ) const {
  for (size_t i = 0; i < dimension * dimension; i++) {
    if (table[i%dimension][i/dimension] != other.table[i%dimension][i/dimension])
      return false;
  }
  return true;
}

position fifteen::solvedposition( size_t val ) {
  if (val == 0) return position(dimension-1, dimension-1);
  else return position((val-1)%dimension, (val-1)/dimension);
}

size_t fifteen::distance( ) const {
  size_t dist = 0;
  for (size_t j = 0; j < dimension; j++)
    for (size_t i = 0; i < dimension; i++)
      dist += distance(solvedposition(table[i][j]), position(i, j));
  return dist;
}

void fifteen::makemove( move m ) {
  switch(m) {
  case move::up :
    if (open_j == 0) throw illegalmove(m);
    std::swap(table[open_i][open_j], table[open_i][open_j-1]);
    open_j--;
    break;
  case move::down :
    if (open_j == dimension-1) throw illegalmove(m);
    std::swap(table[open_i][open_j], table[open_i][open_j+1]);
    open_j++;
    break;
  case move::left :
    if (open_i == 0) throw illegalmove(m);
    std::swap(table[open_i][open_j], table[open_i-1][open_j]);
    open_i--;
    break;
  case move::right  :
    if (open_i == dimension-1) throw illegalmove(m);
    std::swap(table[open_i][open_j], table[open_i+1][open_j]);\
    open_i++;
    break;
  }
}

size_t fifteen::hashvalue( ) const {
  size_t t = 1;
  for (size_t i = 0; i < dimension * dimension; i++) {
    t += table[i%dimension][i/dimension] * i * 1654231;
    t = t % 60687810173;
  }
  return std::hash<size_t>()(t);
}

bool fifteen::issolved( ) const {
  for (size_t i = 0; i < dimension * dimension - 1; i++) {
    if (table[i%dimension][i/dimension] != i + 1) return false;
  }
  return true;
}


std::ostream& operator<< ( std::ostream& stream, const fifteen& f ) {
  int n = f.dimension * f.dimension;
  int width = 0;
  while (n > 0) {
    width++;
    n /= 10;
  }
  for (size_t i = 0; i < f.dimension; i++) {
    for (size_t j = 0; j< f.dimension; j++) {
      stream << std::setw(width) << f.table[j][i]
             << (j == f.dimension-1 ? '\n' : ' ');
    }
  }
  return stream;
}
