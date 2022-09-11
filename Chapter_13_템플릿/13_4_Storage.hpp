// 13_4_Storage.hpp

#ifndef THIRTEEN_FOUR_STORAGE_HPP
#define THIRTEEN_FOUR_STORAGE_HPP

#include <iostream>

template<class T>
class Storage
{
private:
	T	m_value;

public:
	Storage(T value)
	{
		m_value = value;
		std::cout << "class Storage constuctor" << std::endl;
	}

	~Storage()
	{
		std::cout << "class Storage destuctor" << std::endl;
	}

	void	print()
	{
		std::cout << m_value << std::endl;
	}
};

// double 타입일 떄, scientific notation 방식으로 출력하고 싶음
// cpp 파일로 옮기면 적용이 안 됨
// why? 컴파일러가 specialization에 대해 알지 못하는 상황(선언이 없어서)
// 방법 1. header only => 헤더 파일에 구현
// 방법 2. cpp 파일 include => 아래 정의해놓은 것과 같은 상황
template<>
void	Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << std::endl;
}


#endif