// 5.7 반복문 for

// 가장 많이 쓰이는 반복문
// do-while : 먼저 한 번 실행
// while : 일단 돌리고 보자
// for : 반복 횟수가 정해져 있을 때
// for <=> while 상호 변환 가능

#include <iostream>

int	pow(int base, int exponent)
{
	int	result = 1;

	for (int cnt = 0; cnt < exponent; ++cnt)
		result *= base;
	return (result);
}

int main()
{
	// 마찬가지로, for문 이하가 한 줄이라면 중괄호 생략
	// i : iteration
	// 1. cnt 선언 및 초기화
	// 2. 조건 검사
	// 3. 코드 실행
	// 4. 증감 수행
	// 5. 2 ~ 4 반복 수행
	for (int cnt = 0; cnt < 10; cnt++)
		std::cout << cnt;
	std::cout << std::endl;	// 0123456789
	// for문 안에서 선언했기 때문
	std::cout << cnt << std::endl;

	int	cnt;

	// infinite loop
	for (;; ++cnt)
	{
		std::cout << cnt;
	}

	std::cout << pow(2, 4) << std::endl;	// 16

	// unsigned 자료형이면 문제가 발생할 수 있음
	for (unsigned int cnt = 9; cnt >= 0; cnt -= 2)
		std::cout << cnt;

	// 변수 2개 이상도 가능
	for (int i = 0, j = 0; (i + j) < 10; ++i, j += 2)
		std::cout << i << " " << j << std::endl;

	// 다중 for문
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			std::cout << i << " " << j << std::endl;


	return (0);
}