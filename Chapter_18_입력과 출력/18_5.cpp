// 18.5 정규 표현식 소개

// 유효성 검사를 일일이 구현하는 것은 쉬운 일이 아님 => regex를 사용
// 속도를 잡아먹음 => 다른 언어에 비해서도 매우 느림(파싱, 조건문 등...)

#include <iostream>
#include <regex>

int	main()
{
	// d : 숫자를 의미, \\d == [:digit:]
	// + : 입력 받아야 할 문자가 1개 이상, * : 입력을 안 받아도 괜찮음
	// [ab] : a or b만 true => [[:digit:]] : 숫자만 true
	// {3} : 최소 3개를 받아야 함(3개 단위로 판단)
	// 123123123123 => 123 123 123 123
	// {1,5} : 1개 이상 ~ 5개 이하
	// () : 그룹핑
	// [-]? : -가 있어도 되고 없어도 됨

	// std::regex	re("\\d+");
	// std::regex	re("[[:digit:]]{3}");
	// std::regex	re("[A-Z]*");
	// std::regex	re("[A-Z]{1,5}");
	std::regex	re("([0-9]{1})([-]?)([0-9]{1,4})");	// 0-0, 1-1234, 1234
	std::string	str;

	while (true)
	{
		std::getline(std::cin, str);

		// 입력 받은 string이 형식에 맞는지를 검사
		if (std::regex_match(str, re))
			std::cout << "Match" << std::endl;
		else
			std::cout << "No match" << std::endl;
		
		// print matches
		// 매치되는 부분만 출력
		{
			auto	begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto	end = std::sregex_iterator();

			for (auto itr = begin; itr != end; ++itr)
			{
				std::smatch	match =  *itr;

				std::cout << match.str() << " ";
			}
			std::cout << std::endl;
		}
	}

	// 연습 문제 : 휴대폰 번호 형식 검증하기

	return (0);
}