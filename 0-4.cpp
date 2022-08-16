#include <iostream>

int	main(void)
{
	// 0-4.cpp:5:17: warning: conversion from string literal to 'char *' is deprecated [-Wc++11-compat-deprecated-writable-strings]
    // char    *string = "Hello, World!";                      ^
	// 1 warning generated.
	const char	*string = "Hello, World!";


	std::cout << string << std::endl;
	return 0;
}