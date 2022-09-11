// 13_2_MyArray.hpp

#ifndef THIRTEEN_TWO_MYARRAY_HPP
#define THIRTEEN_TWO_MYARRAY_HPP

#include <assert.h>
#include <iostream>

// 매개변수 T : 함수의 매개변수처럼, 타입에 대한 매개변수라고 생각하면 편함
template<typename T>

class MyArray
{
private:
	int	m_length;
	// double, float, char 등을 한번에 담을 수 있게 일반화
	T	*m_data;

public:
	MyArray()
	{
		m_length = 0;
		m_data = nullptr;
		std::cout << "class MyArray constructor" << std::endl;
	}

	MyArray(int length)
	{
		m_length = length;
		m_data = new T[length];
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
		m_data = nullptr;
		m_length = 0;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return (m_data[index]);
	}

	int	getLength() { return (m_length); }

	// 클래스 밖으로 빼는 경우
	void	print();
};

// print()가 같은 파일 안에 있는 경우는 괜찮지만, 다른 cpp 파일로 옮긴 경우 링킹 에러

#endif