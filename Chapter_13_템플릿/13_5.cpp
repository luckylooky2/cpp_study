// 13.5 클래스 템플릿 특수화

#include <iostream>
#include <array>
#include "13_5_Storage8.hpp"

template<typename T>
class A
{
public:
	A(const T& input) {}

	void	Something()
	{
		std::cout << typeid(T).name() << std::endl;
	}

	void	test() {}
};

// char 타입에 대해서만 specialization
// 클래스 템플릿 특수화 => 다른 클래스를 새로 구현하는 것과 비슷
template<>
class A<char>
{
public:
	A(const char &input) {}

	void	Something()
	{
		std::cout << "Char type specialization" << std::endl;
	}
};

int	main()
{
	// 각각 자료형으로 instanciation
	A<int>		a_int(1);
	A<double>	a_double(3.14);
	A<char>		a_char('a');

	// 함수 템플릿과 달리
	// C++ 17 이전에는 생성자 파라미터로 구분할 수 없음(생성자를 추가한 경우)
	// A			a_float(3.14f);

	// before specialization
	a_int.Something();		// i(int)
	a_double.Something();	// d(double)
	a_char.Something();		// c(char)
	a_int.test();
	a_double.test();
	a_char.test();

	// after specialization
	a_int.Something();		// i(int)
	a_double.Something();	// d(double)
	a_char.Something();		// Char type specialization
	a_int.test();
	a_double.test();
	// error: no member named 'test' in 'A<char>'
	// 문법상 다른 클래스와 비슷
	// a_char.test();

	// Storage8
	Storage8<int>	intStorage;

	for (int cnt = 0; cnt < 8; cnt++)
		intStorage.set(cnt, cnt);
	for (int cnt = 0; cnt < 8; cnt++)
		std::cout << intStorage.get(cnt) << " ";
	std::cout << std::endl;		// 0 1 2 3 4 5 6 7 
	std::cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << std::endl;		// Sizeof Storage8<int> 32

	Storage8<bool>	boolStorage;

	// before specialization
	for (int cnt = 0; cnt < 8; cnt++)
		boolStorage.set(cnt, cnt);
	for (int cnt = 0; cnt < 8; cnt++)
		std::cout << boolStorage.get(cnt) << " ";
	std::cout << std::endl;		// 0 1 1 1 1 1 1 1 
	std::cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << std::endl;	// Sizeof Storage8<bool> 8

	// after specialization
	for (int cnt = 0; cnt < 8; cnt++)
		boolStorage.set(cnt, cnt);
	for (int cnt = 0; cnt < 8; cnt++)
		std::cout << boolStorage.get(cnt) << " ";
	std::cout << std::endl;		// 0 1 1 1 1 1 1 1 
	std::cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << std::endl;	// Sizeof Storage8<bool> 1

	return (0);
}