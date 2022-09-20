// 17.4 std::string 문자 접근하기와 배열로의 변환

#include <string>
#include <iostream>
#include <vector>

int	main()
{
	// 설명할 많은 부분이 vector와 유사
	std::string	my_str("abcdefg");

	std::cout << my_str[0] << std::endl;	// a
	std::cout << my_str[3] << std::endl;	// d
	my_str[3] = 'Z';
	std::cout << my_str << std::endl;		// abZdefg

	// 런타임 에러가 발생할 가능성
	// 1. assert
	// 2. try, catch
	try
	{
		// [] operator overloading
		// 내부적으로 예외 처리를 해주지 않음(throw)
		// my_str[100] = 'X';
		// 예외 처리가 있는 버전 => 안정성이 더 중요할 때
		my_str.at(100) = 'X';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';	// basic_string
	}

	// C style array => '\0'를 붙여서 생성
	// .c_str과 .data는 동의어
	const char	*arr = my_str.c_str();

	std::cout << arr << std::endl;		// abcZefg
	std::cout << arr[6] << std::endl;	// g

	char	buf[20];

	// '\0'을 넣어주지 않음
	my_str.copy(buf, 5, 0);
	buf[5] = '\0';
	std::cout << buf << std::endl;		// abcZe

	return (0);
}