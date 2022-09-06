// 5.10 std::cin 더 잘 쓰기

// cin은 콘솔에서 텍스트 입력을 받아들일 때 유용하게 사용
// 하지만 의도하지 않은 입력이 들어왔을 때 어떻게 처리?

#include <iostream>

int	getInt()
{
	while (true)
	{
		std::cout << "Enter an integer number : ";
		int	x;
		// int 범위를 넘는 수 or 문자 등의 입력이 들어오면 무한 루프가 발생
		std::cin >> x;
		// 입력 받는 것을 실패했을 때
		if (std::cin.fail())
		{
			std::cin.clear();
			// 의도하지 않은 입력의 버퍼를 비워줌
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid number, please try again" << std::endl;
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return (x);
		}
	}
}

char	getOperator()
{
	while (true)
	{
		std::cout << "Enter an operator (+, -) : ";
		char op;
		std::cin >> op;
		std::cin.ignore(32767, '\n');
		if (op == '+' || op == '-')
			return (op);
		else
			std::cout << "Invalid operator, please try again" << std::endl;
	}
}

void	printResult(int x, char op, int y)
{
	if (op == '+')
		std::cout << x + y << std::endl;
	else if (op == '-')
		std::cout << x - y << std::endl;
}

int main()
{
	int		x = getInt();
	char	op = getOperator();
	int		y = getInt();

	printResult(x, op, y);

	return (0);
}