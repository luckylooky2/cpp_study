// 2.8 리터럴 상수 (Literal Constants)

#include <iostream>
#include "2_8.hpp"

int main()
{
	// 변수와 달리 3.14f는 바꿀 수 없음
	// 글자로 바꿔서 나타내는 것을 리터럴이라고 함
	float	pi = 3.14f;

	// u : unsigned, l : long ...
	// 표현하고자 하는 자료형을 명확히 나타내고자 할 때 사용
	int		i = -1234u;
	long	l = 2147483649l;


	// Decimal : 0 1 2 3 4 5 6 7 8 9 10, 11 12 13
	int	x = 123;
	// Octal : 0 1 2 3 4 5 6 7, 10 11 12
	int	y = 0123;
	// Hexa : 0 1 2 3 4 5 6 7 8 9 A B C D E F, 10 11
	int	z = 0x123;

	std::cout << x << std::endl;	// 123
	std::cout << y << std::endl;	// 89
	std::cout << z << std::endl;	// 291

	// C++ 14 : binary literal
	int	b = 0b1010'1111'0001'0010;
	
	std::cout << b << std::endl;	// 44818

	// C++에서는 C에서와 달리 매크로(#define)를 거의 사용하지 않음
	// 1. 디버깅하기 어려움
	// 2. 전체 파일에 영향을 미칠 가능성
	// 3. 상수를 변수화 해야할 때 편의성
	const int	price_per_item = 10;
	int 		num_items = 123;
	// 리터럴 매직 넘버를 사용하는 것은 좋지 않음
	// 변수를 이용하여 상수로 만드는 편이 좋음
	// int	price = num_items * 10;
	int			price = num_items * price_per_item;

	double	radius;

	std::cin >> radius;
	// namespace를 이용해 상수를 정리하는 방법
	double	circumference = 2.0 * radius * constants::pi;

	return (0);
}
