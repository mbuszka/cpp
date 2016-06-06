#include <iostream>
#include <vector>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "surface.h"

std::ostream& operator << ( std::ostream& stream,
														const std::vector< surface > & table ) {
	for( size_t i = 0; i < table. size( ); ++ i ) {
		stream << i << "-th element = " << table [i] << "\n";
	}
	return stream;
}

void print_statistics( const std::vector< surface > & table) {
	double total_area = 0.0;
	double total_circumference = 0.0;
	for( const auto& s : table ) {
		std::cout << "adding info about " << s << "\n";
		total_area += s. getsurf( ). area( );
		total_circumference += s. getsurf( ). circumference( );
	}
	std::cout << "total area is " << total_area << "\n";
	std::cout << "total circumference is " << total_circumference << "\n";
}

int main()
{

	rectangle a;

	std::cout << a.area() << "\n";

	a.print(std::cout);
	std::cout << circle{0,0,10};
	std::vector<surface> v{circle{0,0,10}, rectangle{0,0,5,5}, triangle{0,0,2,2,2,0}};
	std::cout << v;
	print_statistics(v);

	return 0;
}
