#ifndef RECTANGLE_INCLUDED
#define RECTANGLE_INCLUDED 1

#include "surf.h"
#include <cmath>

struct rectangle : public surf
{
   double x1, y1;
   double x2, y2;


   double area( ) const override;
   double circumference( ) const override;
   rectangle* clone( ) const & override;
   rectangle* clone( ) && override;
   void print( std::ostream& ) const override;

   rectangle(const rectangle& r)
   : x1{r.x1}, y1{r.y1}, x2{r.x2}, y2{r.y2}
   {}

   rectangle(rectangle&& r)
   : x1{std::move(r.x1)}, y1{std::move(r.y1)}
   , x2{std::move(r.x2)}, y2{std::move(r.y2)}
   {}

   rectangle( )
   : x1{1}, y1{1}, x2{0}, y2{0}
   {}

   rectangle( double x1, double y1, double x2, double y2 )
   : x1{x1}, y1{y1}, x2{x2}, y2{y2}
   {}

   ~rectangle() {}
};

#endif
