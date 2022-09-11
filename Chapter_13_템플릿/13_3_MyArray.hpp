// 13_3_MyArray.hpp

#ifndef THIRTEEN_THREE_MYARRAY_HPP
#define THIRTEEN_THREE_MYARRAY_HPP

#include <assert.h>
#include <iostream>

// m_length를 대체하는 값을 파라미터로 입력
// T_SIZE는 컴파일타임에 결정
template<typename T, unsigned int T_SIZE>

class MyArray
{
private:
	T	*m_data;
	// T	m_data[T_SIZE];	// stack은 메모리가 적기 때문에 동적 할당

public:
	MyArray()
	{
		m_data = new T[T_SIZE];
		std::cout << "class MyArray constructor" << std::endl;
	}

	~MyArray()
	{
		reset();
		std::cout << "class MyArray destructor" << std::endl;
	}

	void	reset()
	{
		delete[] m_data;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return (m_data[index]);
	}

	int	getLength() { return (T_SIZE); }

	void	print()
	{
		for (int i = 0; i < T_SIZE; i++)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
};

// explicit instanciation
// unsigned int에 해당하는 숫자를 모두 선언해주어야 하기 떄문에 
// 따로 cpp 파일로 하지 않고, 헤더에 다 같이 구현
// template class MyArray<char, 1>;
// template class MyArray<char, 10000000>;

#endif