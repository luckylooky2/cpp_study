// 5.8 break, continue

// break => 현재 블록에서 빠져 나감
// switch문 : case마다 break를 써주는 방식 
// while문 : 반복문을 빠져나갈 조건에 써주는 방식 

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

int main()
{
	breakOrReturn();
	for (int i = 0; )
	return (0);
}