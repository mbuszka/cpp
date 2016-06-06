#ifndef CIRCLE_INCLUDED
#define CIRCLE_INCLUDED 1

#include "surf.h"
#include <cmath>

const double PI = 3.141592653589793238462643383279502884197;

struct circle : public surf
{
   double x;
   double y;
   double radius;


   double area( ) const override;
   double circumference( ) const override;
   circle* clone( ) const & override;
   circle* clone( ) && override;
   void print( std::ostream& ) const override;

   circle(const circle& c)
   : x{c.x}, y{c.y}, radius{c.radius}
   {}

   circle(circle&& c)
   : x{std::move(c.x)}, y{std::move(c.y)}, radius{std::move(c.radius)}
   {}

   circle( )
   : x{0}, y{0}, radius{1}
   {}

   circle( double x, double y, double radius )
   : x{x}, y{y}, radius{radius}
   {}

   ~circle() {};
};

#endif
