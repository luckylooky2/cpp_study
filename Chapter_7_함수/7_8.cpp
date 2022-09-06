// 7.8 매개변수의 기본값

#include <iostream>
#include <string>

// 매개변수 기본값을 지정하는 경우에는 선언과 정의 둘 다에 기본값을 지정하지 않는다.
// why? 컴파일러가 기본값을 헷갈리지 않게 하기 위해
// 1. 선언에 지정하는 경우 => header file을 먼저 탐색하곤 함
// 2. 정의에 지정하는 경우
void	foo(int x = 10, int y = 20, int z = 30); // in header file
void	foo(int x, int y, int z) {}

// 함수 오버로딩
void	bar(int x) { std::cout << "no default argument" << std::endl; }
void	bar(int x = 1) {std::cout << "default argument" << std::endl; }

void	print1(int x)
{
	std::cout << x << std::endl;
}

void	print2(int x = 0)
{
	std::cout << x << std::endl;
}

// error: missing default argument on parameter 'y'
// 가장 마지막 매개변수는 default argument이어야 함
void	print3(int x = 0, int y)
{
	std::cout << x << " " << y << std::endl;
}

void	print4(int x, int y = 0)
{
	std::cout << x << " " << y << std::endl;
}

int	main()
{
	print1(10);			// 10
	// error: no matching function for call to 'print1'
	// note: candidate function not viable: requires single argument 'x', but no arguments were provided
	// 매개변수 초기화가 없으면 반드시 입력해야 함
	print1();

	print2(10);			// 10
	print2();			// 0
	
	print4(100);		// 100 0
	print4(100, 200);	// 100 200
	// error: no matching function for call to 'print4'
	// note: candidate function not viable: requires at least argument 'x', but no arguments were provided
	print4();

	// 함수 오버로딩
	// 입력값이 없는 경우 매개변수 기본값이 있는 함수를 먼저 찾음
	bar();				// default argument

	return (0);
}