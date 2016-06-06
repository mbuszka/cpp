#include "circle.h"
#include <cmath>

double circle::area( ) const
{
	return PI * radius * radius;
}

double circle::circumference( ) const
{
	return 2 * PI * radius;
}

void circle::print( std::ostream& a ) const
{
	a << "circle:\n";
	a << "x = " << x << "\n";
	a << "y = " << y << "\n";
	a << "radius = " << radius << "\n";
}

circle* circle::clone( ) &&
{
	return new circle( std::move( *this));
}

circle* circle::clone( ) const & {
	return new circle(x, y, radius);
}
