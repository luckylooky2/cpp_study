// 18.4 흐름 상태와 입력 유효성 검증

#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

// ios는 부모 클래스
// istream, ostream을 공통적으로 사용할 수 있다는 의미 => 상속
void	printStates(const std::ios& stream)
{
	std::cout << std::boolalpha;
	std::cout << "good()=" << stream.good() << std::endl;
	// 파일을 다 읽었는지?
	std::cout << "eof()=" << stream.eof() << std::endl;
	// read를 실패했는지?
	std::cout << "fail()=" << stream.fail() << std::endl;
	std::cout << "bad()=" << stream.bad() << std::endl;
}

void	printCharacterClassification(const int& i)
{
	std::cout << std::boolalpha;
	std::cout << "isalnum : " << bool(std::isalnum(i)) << std::endl;
	std::cout << "isblank : " << bool(std::isblank(i)) << std::endl;
	std::cout << "isdigit : " << bool(std::isdigit(i)) << std::endl;
	std::cout << "islower : " << bool(std::islower(i)) << std::endl;
	std::cout << "isupper : " << bool(std::isupper(i)) << std::endl;
}

bool	isAllDigit(const std::string& str)
{
	bool	ok_flag = true;

	for (auto e : str)
	{
		if (!std::isdigit(e))
		{
			ok_flag = false;
			break;	
		}
	}
	return (ok_flag);
}

int	main()
{
	while(true)
	{
		// int		i;
		char	ch;

		// 숫자가 아니라 문자가 들어올 경우 문제가 발생
		// 스트림의 잘못된 상태임을 알 수 있는 함수
		// std::cin >> i;
		std::cin >> ch;
		printStates(std::cin);
		std::cout << std::boolalpha;
		// 비트 플래그 형태로 return => fail인지 아닌지 check
		std::cout << std::bitset<8>(std::cin.rdstate()) << std::endl;		
		// 비트 마스크
		// goodbit는 0000 0000이기 때문에 & 연산에 의해 오류 bit가 추출되지 않음
		// failbit로 추출하고 검사 후 결과를 출력
		std::cout << std::bitset<8>(std::istream::goodbit) << std::endl;	// 0000 0000
		std::cout << std::bitset<8>(std::istream::failbit) << std::endl;	// 0000 0100
		// 현재 상태를 비트 마스크를 이용해 추출
		std::cout << !bool((std::cin.rdstate() & std::istream::failbit) != 0) << std::endl;

		// 원하는 문자인가를 검증하는 함수
		printCharacterClassification(ch);

		// 버퍼를 비우는 작업
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cout << std::endl;

		// int	i;

		// cin : 123
		// good()=true
		// eof()=false
		// fail()=false
		// bad()=false

		// cin : abc => 가장 문제가 되는 경우
		// good()=false
		// eof()=false
		// fail()=true
		// bad()=false

		// cin : 123.456 => 데이터 절삭이 발생함
		// good()=true
		// eof()=false
		// fail()=false
		// bad()=false

		// char	ch;

		// cin : a
		// isalnum : true
		// isblank : false
		// isdigit : false
		// islower : true
		// isupper : false

		// cin : A
		// isalnum : true
		// isblank : false
		// isdigit : false
		// islower : false
		// isupper : true

		// cin : 1024
		// isalnum : true
		// isblank : false
		// isdigit : true
		// islower : false
		// isupper : false

		// cin :    abc => 공백, 개행문자 단위로 cin이 read를 하기 때문에 isblank를 사용하지 못함
		// isalnum : true
		// isblank : false
		// isdigit : false
		// islower : true
		// isupper : false
	}

	{
		std::cout << std::boolalpha;
		// 정규표현식을 사용하지 않고 한 글자씩 비교하는 방식
		// 정규표현식을 사용하면 훨씬 편함
		std::cout << isAllDigit("1234") << std::endl;	// true
		std::cout << isAllDigit("a1234") << std::endl;	// false
	}

	return (0);
}