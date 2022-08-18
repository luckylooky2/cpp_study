// 1.9 선언과 정의의 분리

#include <iostream>

// 선언(Declaration) : 전방 선언(Forward Declaration)
// 함수에 대해 알기 위한 최소 조건 : 입력이 어떤 것이고, 출력이 어떤 것이다.
// 프로토타입을 위에 선언

int add(int a, int b);
int	multiply(int a, int b);
int	subtract(int a, int b);

// main 함수가 전방 선언 없이 제일 위에 정의될 경우
// error: use of undeclared identifier 'add'

int main()
{
	std::cout << add(1, 2) << std::endl;
	std::cout << multiply(1, 2) << std::endl;
	std::cout << subtract(1, 2) << std::endl;

	return (0);
}

// 정의(Definition)

int add(int a, int b)
{
	return (a + b);
}

int	multiply(int a, int b)
{
	return (a * b);
}

int	subtract(int a, int b)
{
	return (a - b);
}
