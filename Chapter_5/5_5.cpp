// 5.5 반복문 while

// for문을 더 많이 사용하는 것은 사실이나, while이 반드시 필요한 경우가 있음
// 1. 반복 횟수를 정확히 확신하지 못할 때 사용
// 2. 전통적으로 사용
// 3. 조금 더 간결하기 때문에 사용
// 사용에 주의가 필요 => 무한 루프에 빠질 가능성

#include <iostream>

int main()
{
	std::cout << 1 << std::endl;
	std::cout << 2 << std::endl;
	// ...
	// 반복적인 작업을 줄일 수 있음

	// for문의 1번 요소 : 선언 및 초기화
	int	cnt = 0;

	while (cnt < 10)
	{
		// for문의 2번 요소 : 최대 카운터
		if (cnt > 5)
			break ;
		std::cout << cnt;
		// for문의 3번 요소 : 증감
		cnt++;
	}
	std::cout << std::endl; // 012345

	int				count = 10;	// 문제가 발생하지 않음
	// unsigned가 필요한 상황이 존재하기 때문에, 이 경우 overflow를 생각해야 함		
	// unsigned int	count = 10;	// infinite loop => overflow

	while (count >= 0)
	{
		if (count == 0)
			std::cout << "zero";
		else
			std::cout << count << " ";
		count--;
	}
	std::cout << std::endl; // 10 9 8 7 6 5 4 3 2 1 zero

	int	i = 1, j = 1;

	while (i <= 5)
	{
		j = 1;
		while (j <= i)
			std::cout << j++ << " ";
		std::cout << std::endl;
		i++;
	}

	return (0);

	// 연습 문제
	// 1. 구구단
	// 2. while문 => goto문
	// 3. 역피라미드
}