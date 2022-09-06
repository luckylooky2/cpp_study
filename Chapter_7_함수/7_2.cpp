// 7.2 값에 의한 인수 전달 call by value

// call by value
// 함수가 호출될 때 값이 복사됨
// 함수 밖에 영향을 끼치지 않음

#include <iostream>

// 1. int y 선언
// 2. 변수 y 메모리에 전달 받은 인자 값이 초기화
void	doSomething(int y)
{
	std::cout << "In func " << y << " " << &y << std::endl;
}

int	main()
{
	// 매개변수로 5라는 값이 전달되어야 하는 상황
	doSomething(5);											// In func 5 0x7ffee01037fc

	int	x = 6;

	std::cout << "In main " << x << " " << &x << std::endl;	// In main 6 0x7ffee0103818
	// 실제로 매개변수로 전달되는 것은 변수가 아니라 변수의 값(value)
	// 다른 언어를 먼저 배웠다면 헷갈릴 수 있음
	doSomething(x);											// In func 6 0x7ffee01037fc	
	doSomething(x + 1);										// In func 7 0x7ffee01037fc

	return (0);
}