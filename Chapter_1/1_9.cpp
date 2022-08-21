// 1.9 기본적인 서식 맞추기

#include <iostream>

// 모두가 따라야 하는 규칙이 있는 것은 아님
// 결국 사람이 볼 때, 얼마나 편안한가의 문제
// 코드를 정리하는 것 : 여백을 어떻게 만들 것인가의 문제
// => 컴파일러는 여백을 상관하지 않음, 프로그래머 관점의 문제

// BSD 스타일
int add(int x, int y)
{
	// indenting
	return (x + y);
}

// K&R 스타일
int	multiply(int x, int y) {
	return (x * y);
}

int	main()
{
	// 코드가 한 눈에 보이게끔 적절한 줄바꿈
	// 한 줄을 넘어갈 경우, 줄 끝에 연산자를 넣는 방법
	std::cout << "Hello, World" << "abcdefg" <<
	std::endl;

	// tab 키을 통해 정렬할 수 있음
	int	my_v 		= 1;
	int	x 			= 4;
	int num_apples 	= 123;

	return (0);
}
