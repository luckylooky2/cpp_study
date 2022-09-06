// 5.6 반복문 do-while

// while문 보다 많이 쓰이지는 않음
// while문과 다른 점
// 먼저 do 블록을 한 번 실행한 후, 조건을 평가
// 특정한 수학 알고리즘에서 반드시 필요한 경우가 있음

#include <iostream>

int main()
{
	int	selection;

	do
	{
		std::cout << "1. add" << std::endl;
		std::cout << "2. sub" << std::endl;
		std::cout << "3. mult" << std::endl;
		std::cout << "4. div" << std::endl;
		std::cin >> selection;
	} while (selection <= 0 || selection >= 5);	// semicolon을 반드시 붙여줘야 함
	std::cout << "You selected " << selection << std::endl;

	return (0);
}