// 3.2 산술 연산자

#include <iostream>

int main()
{
	int x = 7;
	// unary operator, 꼭 붙여서 쓸 것
	int y = 3;
	int z = -x;

	std::cout << x + y << std::endl;			// 0
	std::cout << x - y << std::endl;			// 14
	std::cout << x * y << std::endl;			// -49
	// 몫 연산자
	std::cout << x / y << std::endl;			// 1
	// 둘 중에 하나만 실수면 실수로 나옴
	std::cout << x / float(y) << std::endl; 	// 2.33333
	// 나머지 연산자
	std::cout << x % y << std::endl;			// 0

	// 음의 정수를 나누는 경우
	// C99 : -2.5 => -2? -3?
	// C11 : -2.5 => -2(절삭)
	std::cout << -5 / 2 << std::endl;			// -2
	// 나누는 정수의 부호에 따라 값이 결정됨
	std::cout << -5 % 2 << std::endl;			// -1

	int	a = x;

	// 1. 코드의 양을 줄여줌
	// 2. 오타의 가능성을 줄여줌
	a += y;	// a = a + y;
	a -= y; // a = a - y;
	a *= y; // a = a * y;
	a /= y; // a = a / y;

	return (0);
}