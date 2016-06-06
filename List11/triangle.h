#ifndef TRIANGLE_INCLUDED
#define TRIANGLE_INCLUDED 1

#include "surf.h"
#include <cmath>

struct triangle : public surf
{
   double x1, y1;
   double x2, y2;
   double x3, y3;


   double area( ) const override;
   double circumference( ) const override;
   triangle* clone( ) const & override;
   triangle* clone( ) && override;
   void print( std::ostream& ) const override;

   triangle(const triangle& t)
   : x1{t.x1}, y1{t.y1}, x2{t.x2}, y2{t.y2}, x3{t.x3}, y3{t.y3}
   {}

   triangle(triangle&& t)
   : x1{std::move(t.x1)}, y1{std::move(t.y1)}
   , x2{std::move(t.x2)}, y2{std::move(t.y2)}
   , x3{std::move(t.x3)}, y3{std::move(t.y3)}
   {}
  
   triangle( )
   : x1{0}, y1{0}, x2{1}, y2{0}, x3{0}, y3{1}
   {}

   triangle( double x1, double y1, double x2, double y2, double x3, double y3 )
   : x1{x1}, y1{y1}, x2{x2}, y2{y2}, x3{x3}, y3{y3}
   {}
   ~triangle() {};
};

#endif
