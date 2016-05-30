
#include "varchain.h"
#include <algorithm>

bool operator < (const powvar& l, const powvar& r) {
  if (l.v > r.v) {
    return false;
  } else if (r.v == l.v) {
    return l.n < r.n;
  } else {
    return true;
  }
}

std::ostream& operator << ( std::ostream& out, const powvar & p )
{
   if( p.n == 0 )
   {
      out << "1"; // Should not happen, but we still have to print something.
      return out;
   }

   out << p.v;
   if( p.n == 1 )
      return out;

   if( p.n > 0 )
      out << "^" << p.n;
   else
      out << "^{" << p.n << "}";
   return out;
}


std::ostream& operator << ( std::ostream& out, const varchain& c )
{
   if( c. isunit( ))
   {
      out << "1";
      return out;
   }

   for( auto p = c. repr. begin( ); p != c. repr. end( ); ++ p )
   {
      if( p != c. repr. begin( ))
         out << ".";
      out << *p;
   }

   return out;
}


int varchain::power( ) const
{
   int p = 0;
   for( auto pv : repr )
      p += pv. n;
   return p;
}

varchain operator * ( varchain c1, const varchain& c2 ) {
  c1.repr.reserve(c1.size() + c2.size());
  for (auto e : c2.repr) c1.repr.push_back(e);
  c1.normalize();
  return c1;
}

int varchain::compare(const varchain& l, const varchain& r) {
  size_t n = l.size() < r.size() ? l.size() : r.size();
  for (size_t i=0; i<n; i++) {
    if (l.repr[i] < r.repr[i]) {
      return -1;
    }
    if (r.repr[i] < l.repr[i]) {
      return 1;
    }
  }
  if (l.size() < r.size()) return -1;
  if (l.size() == r.size()) return 0;
  return 1;
}

void varchain::normalize() {
  if (repr.size() == 0) return;
  std::sort(repr.begin(), repr.end());
  std::vector<powvar> newRepr;
  std::string v = repr[0].v;
  int n = 0;
  for ( auto pow : repr) {
    if (pow.v == v) {
      n += pow.n;
    } else {
      if (n != 0) newRepr.push_back({v, n});
      v = pow.v;
      n = pow.n;
    }
  }
  if (n != 0) newRepr.push_back({v, n});
  repr = newRepr;
}
