#include "triangle.h"
#include <cmath>

double triangle::area( ) const
{
	return abs( x1*y2 + x2*y3 + x3*y1 - x3*y2 - x1*y3 - x2*y1 ) / 2;
}

double triangle::circumference( ) const
{
	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) +
		   sqrt( (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) ) +
		   sqrt( (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1) );
}


void triangle::print( std::ostream& a ) const
{
	a << "triangle:\n";
	a << "x1 = " << x1 << " y1 = " << y1 << "\n";
	a << "x2 = " << x2 << " y2 = " << y2 << "\n";
	a << "x3 = " << x3 << " y3 = " << y3 << "\n";
}

triangle* triangle::clone( ) &&
{
	return new triangle (std::move ( *this));
}

triangle* triangle::clone( ) const &
{
	return new triangle(x1, y1, x2, y2, x3, y3);
}
