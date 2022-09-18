// 15_6_Resource.hpp

#include <iostream>

#ifndef FIFTEEN_SIX_RESOURCE_HPP
#define FIFTEEN_SIX_RESOURCE_HPP

class Resource
{
public:
	int			*m_data = nullptr;
	unsigned	m_length = 0;

public:
	Resource()
	{
		std::cout << "class Resource default constructor" << std::endl;
	}

	Resource(unsigned length)
	{
		std::cout << "class Resource length constructor" << std::endl;
		this->m_data = new int[length];
		this->m_length = length;
	}

	Resource(const Resource &res)
	{
		std::cout << "class Resource copy constructor" << std::endl;
		Resource(res.m_length);
		// deep copy : 복사하는데 시간이 소요됨
		for (unsigned i = 0; i < m_length; i++)
			m_data[i] = res.m_data[i];
	}

	~Resource()
	{
		std::cout << "class Resource destructor" << std::endl;
		// 할당 해제
		if (m_data != nullptr) delete[] m_data;
	}

	// copy assignment
	Resource& operator=(Resource& res)
	{
		std::cout << "class Resource copy assignment" << std::endl;
		// 자신을 인자로 받을 경우 => 그냥 내보냄
		if (&res == this) return (*this);
		// 복사 당하는 입장에서 leak이 나지 않게 할당 해제
		if (this->m_data != nullptr) delete[] m_data;
		m_length = res.m_length;
		m_data = new int[m_length];
		// deep copy
		for (unsigned i = 0; i < m_length; i++)
			m_data[i] = res.m_data[i];

		return (*this);
	}

	void	print()
	{
		for (unsigned i = 0; i < m_length; i++)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	// 값 초기화
	void	setAll(const int& v)
	{
		for (unsigned i = 0; i < m_length; i++)
			m_data[i] = v;
	}
};

#endif