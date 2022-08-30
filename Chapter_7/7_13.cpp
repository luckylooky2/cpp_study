// 7.13 방어적 프로그래밍의 개념

// 많은 사람이 어떻게 사용하든지 정상적으로 작동하게 만드는 것
// 방어적 프로그래밍은 손이 많이가지만, 안전 장치가 되어 있어야 함

#include <iostream>

int	main()
{
	// syntax error : ;을 빼먹었을 때
	int x;

	// semantic error : 논리적 오류, 5 이상? 초과?, 찾기 어려움
	std::cin >> x;
	std::cin.ignore(32767, '\n');
	if (x >= 5)
		std::cout << "x is greater than 5" << std::endl;

	// violoated assumption : 사용자가 의도하지 않은대로 행동
	int			i;
	std::string	hello = "hello, my name is Jack Jack";

	// 만약 i가 엄청 큰 수라면, 오류가 발생할 가능성
	// 방법 1 : 안내 문구 => 근본적 해결 방법이 아님
	std::cout << "Input from 0 to " << hello.size() - 1 << std::endl;
	std::cin >> i;
	std::cout << hello[i] << std::endl;
	// 방법 2
	while (true)
	{
		int	i;
		std::cin >> i;
		if (i >= 0 && i <= hello.size() - 1)
		{
			std::cout << hello[i] << std::endl;
			break ;
		}
		else
			std::cout << "Please try again...";
	}

	return (0);
}