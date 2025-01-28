#include "Any_type.h"
#include <iostream>

int main()
{
	Any_type a{ 5.6 }, b{'c'};
	std::cout << "a: " << a.to_double() << " b: " << b.to_char() << std::endl;

	a.swap(b);
	std::cout << "a: " << a.to_char() << " b: " << b.to_double() << std::endl;
}
