
#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>

void listtest::sort_assign(std::list<std::string>& v) {
  for (auto j = v.begin(); j != v.end(); j++)
    for (auto i = v.begin(); i != j; i++) {
      if (*i > *j) {
        std::string s = *i;
        *i = *j;
        *j = s;
      }
    }
}

void listtest::sort_move( std::list< std::string > & v ) {
  for (auto j = v.begin(); j != v.end(); j++)
    for (auto i = v.begin(); i != v.end(); i++) {
      if (*i > *j)
        std::swap(*i, *j);
    }
}

std::list<std::string> listtest::convert(const std::vector<std::string>& vec) {
  std::list<std::string> l;
  for (const auto& s : vec) {
    l.push_back(s);
  }
  return l;
}
