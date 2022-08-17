// 1.5 함수와의 첫 만남

#include <iostream>

// num_a, num_b : parameter
// parameter 변수를 새로 생성하고 argument 값으로 초기화
int addTwoNumbers(int num_a, int num_b)
{
	// 일괄적으로 모든 행위를 바꿀 수 있음(유지 보수가 쉬움)
	return (num_a + num_b);
}

int	multiplyTwoNumbers(int num_a, int num_b)
{
	return (num_a * num_b);
}

// 함수는 입력(parameter)이 없을수도, 출력(return)이 없을수도 있음
void	printHelloWorld(void)
{
	std::cout << "Hello World" << std::endl;

	// 선택 사항
	return ;
	// return 이후의 문은 실행되지 않음
	std::cout << "Hello World" << std::endl;
}

// 함수가 함수를 부를 수 있음
// 하지만, 중복 함수(함수 안에서 함수를 정의, nested function)는 불가능

void	printInput(void)
{
	int	first;
	int	second;

	while (1)
	{
		std::cout << "\033[39m\n-----Input two integers-----\n";
		std::cout << "\033[39mFirst Integer \t: ";
		std::cin >> first;
		std::cout << "\033[39mSecond Integer \t: ";
		std::cin >> second;
		std::cout << "\033[92mResult \t\t: ";
		std::cout << first + second << "\n";
	}
}

int main()
{
	int	res;

	// 하나의 패턴이 여러 번 나타나면 함수를 사용
	std::cout << 1 + 2 << std::endl;
	std::cout << 3 + 4 << std::endl;
	std::cout << 8 + 13 << std::endl;
	// 함수도 메모리에 저장이 되어있기 때문에 그 메모리에 있는 함수를 mod에서 가져옴
	// 1, 2 : argument
	std::cout << addTwoNumbers(1, 2) << std::endl;
	std::cout << addTwoNumbers(3, 4) << std::endl;
	std::cout << addTwoNumbers(8, 13) << std::endl;
	res = multiplyTwoNumbers(13, 21);

	printHelloWorld();
	printInput();

	return 0;
}