// 13.6 템플릿을 부분적으로 특수화하기

#include <iostream>

// 클래스 templatize
template <class T, int size>
class StaticArray
{
private:
	T	m_array[size];

public:
	T	*getArray() { return m_array; }

	T	&operator[](int index) { return (m_array[index]); }

	void	print()
	{
		for (int i = 0; i < size; ++i)
			std::cout << (*this)[i] << " ";
		std::cout << std::endl;
	}
};

// 함수도 templatize
template <typename T, int size>
void	print(StaticArray<T, size> &array)
{
	for (int i = 0; i < size; ++i)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

// 문자를 출력할 때는 1칸 공백이 없었으면 좋겠음
// size를 specialization을 해주는 것은 불가능하기 때문에
// typename T만 char에 대해서 specialization
template <int size>
void	print(StaticArray<char, size> &array)
{
	for (int i = 0; i < size; ++i)
		std::cout << array[i];
	std::cout << std::endl;
}

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
	print(int4);		// 1 2 3 4 
	print(char14);		// H e l l o ,   W o r l d   
	// after partial specialize
	print(int4);		// 1 2 3 4 
	print(char14);		// Hello, World

	return (0);
}