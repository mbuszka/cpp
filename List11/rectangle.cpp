#include "rectangle.h"


double rectangle::area( ) const
{
	return abs( x1 - x2 ) * abs( y1 - y2 );
}

double rectangle::circumference( ) const
{
	return 2 * abs( x1 - x2 ) + 2 * abs( y1 - y2 );
}

void rectangle::print( std::ostream& a ) const
{
	a << "rectangle:\n";
	a << "x1 = " << x1 << " y1 = " << y1 << "\n";
	a << "x2 = " << x2 << " y2 = " << y2 << "\n";
}

rectangle* rectangle::clone( ) const &
{
	return new rectangle(x1, y1, x2, y2);
}

rectangle* rectangle::clone( ) &&
{
	return new rectangle( std::move( *this));
}
