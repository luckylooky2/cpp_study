// 5.8 break, continue

// break => 현재 블록에서 빠져 나감 + 조건문과 같이 많이 사용
// switch문 : case마다 break를 써주는 방식 
// while문 : 반복문을 빠져나갈 조건에 써주는 방식 

// continue

#include <iostream>

void	breakOrReturn()
{
	while (true)
	{
		char	ch;
		std::cin >> ch;

		// "Hello" 출력
		if (ch == 'b')
			break;
		// "Hello" 출력 x
		else if (ch == 'r')
			return ;
	}
	std::cout << "Hello" << std::endl;
}

void	breakIfX()
{
	bool	escape_flag = false;

	while (escape_flag)
	{
		char	ch;

		std::cin >> ch;
		std::cout << ch << " " << std::endl;
		if (ch == 'x')
			escape_flag = true;
	}
}

int main()
{
	int cnt = 0;

	breakOrReturn();
	breakIfX();

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << std::endl;
		if (i == 5)
			break ;
	}

	// 홀수 출력하기
	for (int i = 0; i < 10; ++i)
	{
		// 방법 1
		if (i % 2 == 1)
			std::cout << i << std::endl;

		// 방법 2
		// 조건을 만족하는 경우에는 continue를 실행
		if (i % 2 == 0)
			continue ;
		// 아래 코드를 실행시키지 않고, 증감 연산으로 이동
		std::cout << i << std::endl;
	}

	// (do) while문에서의 continue
	do
	{
		if (cnt == 5)
			continue ;
		std::cout << cnt << std::endl;
		// 무한 루프에 빠짐
		// cnt를 continue 이후에 증가시키기 때문에 증감 연산 수행없이 루프
		cnt++;
	// 조건문에 증감을 포함시켜주어야 함
	} while (cnt < 10);
	
	return (0);
}