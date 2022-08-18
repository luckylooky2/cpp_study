// 1.8 연산자와의 첫 만남

#include <iostream>

int	main()
{
	// x is a variable, 2 is a literal.
	// 변수 : 메모리 주소를 가지고 있음
	// 리터럴 : 2라는 의미를 전달하기 위한 존재
	int	x = 2;

	// 문자열 또한 리터럴
	std::cout << "Hello, World" << std::endl;
	// 1 + 2 : 표현식
	std::cout << 1 + 2 << std::endl;

	// 단항 연산자
	std::cout << -2 << std::endl;
	// 이항 연산자
	std::cout << 1 + 2 << std::endl;
	// 삼항 연산자
	int	y = ( x > 0 ) ? 1 : 2;
	std::cout << y << std::endl;

	return (0);
}