// 7.15 명령줄 인수

// command line argument
// 프로그램을 실행할 때, 넘겨줄 수 있는 변수

// Boost 라이브러리 : 준표준
// Boost.Program_options : command line argument를 다룰 때 유용

#include <iostream>
#include <string>

// 들어오는 인자가 문자열임에 주의
int	main(int argc, char *argv[])
{
	for (int cnt; cnt < argc; cnt++)
	{
		std::string	argv_single = argv[cnt];

		if (cnt == 1)
		{
			// 숫자로 사용하려면 변환하는 과정이 필요
			int	number = std::stoi(argv_single);
			std::cout << number + 1 << std::endl;
		}
		else
			std::cout << argv_single << std::endl;
	}

	return (0);
}