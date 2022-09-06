// test.cpp

#include <iostream>
#include "4_2.hpp"

// external linkage
int	test_value;

void	test(void)
{
	std::cout << "hello world" << std::endl;
	std::cout << Constants::pi << std::endl;	// 3.14159
	std::cout << &Constants::pi << std::endl;	// 0x1026b7e08
	std::cout << &Constants::pi << std::endl;	// 0x102ff7ee0
}