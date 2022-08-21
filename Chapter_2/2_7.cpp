// 2.7 문자형 (char)

#include <iostream>

// 컴퓨터 내부에서는 모두 숫자로 처리
// 그럼 문자를 어떻게 숫자로 나타내는가?
// ASCII TABLE(문자와 숫자를 대응)

// 문자열을 표현
// 1. ""(double quote)
// 2. std::string 자료형

int main()
{
	char	c1(65);
	// 한 글자를 표현할 때는 ''(single quote)
	char	c2('A');

	std::cout << c1 << " " << c2 << " " << \
	int(c1) << " " << int(c2) << std::endl;	// A A 65 65

	// 강제 형변환(데이터 손실 가능성)
	// C style casting
	std::cout << (char)65 << std::endl;	// A
	std::cout << (int)'A' << std::endl;	// 65
	// C++ style casting
	std::cout << char(65) << std::endl;	// A
	std::cout << int('A') << std::endl;	// 65

	// static_cast
	// 1. 컴파일 타임에 fundamental type간에 문제없이 형변환이 가능한지 확인할 수 있음
	// 2. casting을 다른 프로그래머가 인지하지 못할 경우를 대비 => 확실히 나타낼 수 있음
	std::cout << static_cast<char>(65) << std::endl;	// A
	std::cout << static_cast<int>('A') << std::endl;	// 65

	char	ch(97);

	// 변수도 static_cast가 가능
	std::cout << static_cast<int>(ch) << std::endl;		// 97
	// static_cast를 해도 변수의 값은 변하지 않음
	std::cout << ch << std::endl;						// a

	int		i1(130);

	std::cout << static_cast<char>(i1) << std::endl;	// {
	std::cout << char(i1) << std::endl;	// {
	
	// 하나의 문자만 받을 수 있기 떄문에 여러 문자를 입력하더라도 하나만 읽음
	// 나머지는 버퍼에 저장
	std::cin >> ch;	// abc
	std::cout << ch << " " << static_cast<int>(ch) << std::endl;  // a 97
	std::cin >> ch;
	std::cout << ch << " " << static_cast<int>(ch) << std::endl;  // b 98

	wchar_t		test;	// windows용 프로그램 자료형
	char32_t	test1;

	return (0);
}
