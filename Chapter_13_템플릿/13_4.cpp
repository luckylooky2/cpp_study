// 13.4 함수 템플릿 특수화

// 템플릿 프로그래밍을 하다보면 특정한 자료형에 대해 다른 기능을 구현하고 싶을 떄가 있음
// 함수를 기준으로 먼저 설명

#include <iostream>
#include "13_4_Storage.hpp"

template<typename T>
T	getMax(T x, T y)
{
	return ((x > y) ? x : y);
}

// specialization
// 특수한 타입에 대해 적용하는 것이 때문에 템플릿의 목적과 반대되는 방식
template<>
char	getMax(char x, char y)
{
	std::cout << "Warning : comparing chars" << std::endl;
	return ((x > y) ? x : y);
}

int	main()
{
	std::cout << getMax(1, 2) << std::endl;				// 2
	// 내부적으로 동일
	std::cout << getMax<int>(1, 2) << std::endl;		// 2
	// 강제 instanciatoin
	std::cout << getMax<double>(1, 2) << std::endl;		// 2

	// 문자에 대해서 instanciation할 때는 사용자에게 문자끼리 비교하는 것을 알려주고 싶음
	std::cout << getMax('a', 'b') << std::endl;			// Warning : comparing chars b
	// 방법 1. if문으로 char 타입일 때 처리하기 => 컴파일타임에 처리해야 하기 떄문에 불가
	// 방법 2. specialization

	Storage<int>	nValue(5);			// 5
	Storage<double>	dValue(6.7);		// Double Type 6.700000e+00

	nValue.print();
	dValue.print();

	return (0);
}