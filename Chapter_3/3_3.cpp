// 3.3 증가/감소 연산자

#include <iostream>

int	add(int a, int b)
{
	return (a + b);
}

int main()
{
	int	x = 5;
	// 전위 증가 연산자
	int y = ++x;
	// 후위 증가 연산자
	int z = x--;

	std::cout << y << std::endl;	// 6
	std::cout << z << std::endl;	// 6

	int a = 6, b = 6;

	std::cout << a << " " << b << std::endl;		// 6 6
	// 코드를 실행시키기 전에 증감
	std::cout << ++a << " " << --b << std::endl;	// 7 5
	// 코드를 실행시킨 후 증감
	std::cout << a++ << " " << b-- << std::endl;	// 7 5
	std::cout << a << " " << b << std::endl;		// 8 4

	x = 1;
	y = 2;

	// warning: unsequenced modification and access to 'x'
	// 컴파일러에 따라 다른 결과가 나올 수 있음(undefined)
	add(x, ++x);
	// 이 경우에는 문제가 없음
	add(x, ++y);

	// warning: multiple unsequenced modifications to 'x'
	x = x++;

	return (0);
}