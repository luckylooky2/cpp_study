// 15_1_Resource.hpp

#ifndef FIFTEEN_ONE_RESOURCE_HPP
#define FIFTEEN_ONE_RESOURCE_HPP

#include <iostream>

class Resource
{
private:
	int	m_data[100];
public:
	Resource()
	{
		std::cout << "class Resource construct" << std::endl;
	}

	~Resource()
	{
		std::cout << "class Resource destruct" << std::endl;
	}
};

#endif
