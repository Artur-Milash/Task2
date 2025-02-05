#include "Any_type.h"
#include <iostream>

int main()
{
	Any_type a{ 5.6 }, b{'c'};
	std::cout << "a: " << a.to_double() << " b: " << b.to_char() << std::endl;

	a.swap(b);
	std::cout << "a: " << a.to_char() << " b: " << b.to_double() << std::endl;

	Any_type c;
	int ia = 5;
	void* ptr = &ia;
	c = ptr;
	std::cout << c.to_int();
}
