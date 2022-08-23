// 4.6 문자열 std::string

#include <iostream>
#include <string>

int main()
{
	// 문자를 나열하는 방식으로 사용
	const char			*my_strs = "hello world";
	// 사용자 정의 자료형 => 문자열과 관련된 기능을 추가
	const std::string	my_hello = "hello world";
	// 기본 자료형을 사용자 정의 자료형으로 암시적 형 변환을 해주는 방법이 없기 때문
	// 바꿀 수는 있음
	// std::string	my_ID = 123;

	std::cout << "hello world" << std::endl;	// hello world
	std::cout << my_hello << std::endl;			// hello world

	std::cout << "Your age ? : ";
	int	age;
	// 문자열이 아닐 때는 cin으로 받음
	std::cin >> age;
	// std::getline(std::cin, age);
	// 버퍼 비우기 : 개행 문자가 나올때까지 최대 32767개의 문자를 무시하라
	std::cin.ignore(32767, '\n');
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Your name ? : ";
	std::string	name;
	// std::cin >> name;
	std::getline(std::cin, name);


	// chanhyle 29 vs. chanhyle\n 29\n => 결과가 다름
	// why?
	// cin은 빈칸이 있으면 입력을 다 받았다고 인식
	// 빈칸 이후의 문자를 버퍼에 보관했다가 cin에 넘겨줌
	// std::getline(std::cin, name)을 사용 => 개행 문자가 나올 때까지 인식
	std::cout << age << " " << name << std::endl;

	std::string	a("hello ");
	std::string	b("world ");
	// operator overriding
	std::string	c = a + b;

	c += "I'm good";

	std::cout << c << std::endl;
	std::cout << a.length() << std::endl;

	return (0);
}

// C와 C++ 문자열의 차이점?