// 13_6_member_functions.cpp

// 부분적 특수화 멤버 함수화 => 어려움, 상속(overriding)을 이용하는 방법
// why? 템플릿을 통째로 specialization하는 것보다 편하기 때문

#include <iostream>

// 클래스 templatize
template <class T, int size>
// 부모 클래스로 수정
class StaticArray_Base
{
private:
	T	m_array[size];

public:
	T	*getArray() { return m_array; }

	T	&operator[](int index) { return (m_array[index]); }

	// 멤버 함수화 => 공통적으로 해당하는 것이라 어렵지 않음
	void	print()
	{
		for (int i = 0; i < size; ++i)
			std::cout << (*this)[i] << " ";
		std::cout << std::endl;
	}
};

// 자식 클래스
template <class T, int size>
class StaticArray : public StaticArray_Base<T, size>
{
};

// Class T가 char인 경우에만 별도로 한 번 더 상속
template <int size>
class StaticArray<char, size> : public StaticArray_Base<char, size>
{
public:
// 부분적 특수화 멤버 함수화 => overriding을 이용
void	print()
{
	for (int i = 0; i < size; ++i)
		std::cout << (*this)[i];
	std::cout << std::endl;
}
};

int	main()
{
	StaticArray<int, 4>		int4;
	StaticArray<char, 14>	char14;

	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;
	strcpy(char14.getArray(), "Hello, World");
	// before partial specialize
	int4.print();		// 1 2 3 4 
	char14.print();		// H e l l o ,   W o r l d   
	// after partial specialize
	int4.print();		// 1 2 3 4 
	char14.print();		// Hello, World

	return (0);
}