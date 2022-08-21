// windows.cpp

#include <iostream>

void	printIfWindows()
{
#ifdef WINDOWS
	std::cout << "Windows" << std::endl;
#else
	std::cout << "MacOS" << std::endl;
#endif
}
