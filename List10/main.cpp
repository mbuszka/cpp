
#include <vector>
#include <algorithm>
#include "varchain.h"
#include "polynomial.h"
#include "bigint.h"
#include "rational.h"


template< typename N >
polynomial< N > exptaylor( unsigned int n )
{
   varchain v;

   N fact = 1;

   polynomial< N > result;
   for( unsigned int i = 0; i < n; ++ i )
   {
      result[v] += fact;
      v = v * powvar( "x" );
      fact = fact / (i+1);
   }

   return result;
}

int main( int argc, char* argv [] )
{
   #if 1
   std::cout << "hello\n";

   polynomial< rational > pol;

   int N = 50;

   pol[ { } ] = 1;
   pol[ { "x" } ] = rational( 1, N );

   polynomial< rational > res = 1;

   for( int i = 0; i < N; ++ i )
      res = res * pol;

   std::cout << "rsult = " << res << "\n\n";

   std::cout << " taylor expansion = " << exptaylor<rational>(20) << "\n\n";

   std::cout << "difference = " ;
   std::cout << res - exptaylor<rational> ( 40 ) << "\n\n\n";
   #endif
   std::vector<powvar> vec{{"x", 5}, {"y", 7}, {"x", 6}};
   std::sort(vec.begin(), vec.end());
   std::cout << (vec[0] < vec[1]) << " " << (vec[0] < vec[2]) << "\n";
   varchain c{{"x", 5}, {"y", 7}, {"x", 6}};
   varchain d{{"z", 2}, {"y", -1}, {"z", 5}};
   std::cout << (c * d) << "\n";
   return 0;
}
