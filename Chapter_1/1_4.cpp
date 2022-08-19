// 1.4 입출력 스트림과의 첫 만남 cin, cout

// 입출력 스트림을 사용하기 위해서는
#include <iostream> // cout, cin, endl, ...
#include <cstdio> // printf

int main()
{
	// 함수 블록 안에서 std::를 생략할 수 있음
	// 명령어 PATH를 찾아주듯이 컴파일러가 namespace를 자동으로 찾아줌
	using namespace std;

	int	x = 1024;
	int	y = 2147483649;
	int	z = 2.5;
	double pi = 3.141592;

	// std::이 붙는 이유?
	// cout은 std라는 이름의 namespace 안에 정의가 되어있고, 이것을 사용하기 위해 ::를 사용

	// <<의 의미? : output operator
	// stream을 따라서 cout으로 들어간다고 생각하자?
	std::cout << "I love this lecture!" << std::endl;
	std::cout << "I love this lecture!\n";
	std::cout << "x is " << x << std::endl; 	// x is 1024
	std::cout << "y is " << y << std::endl;		// y is -2147483647
	std::cout << "z is " << z << std::endl; 	// z is 2
	// 소수점이 잘리는 이유?
	std::cout << "pi is " << pi << std::endl; 	// pi is 3.14159

	std::cout << "abc" << "\t" << "def" << std::endl;
	std::cout << "ab" << "\t" << "cdef" << std::endl;

	cout << "\a";

	// printf("I love this lecture!\n");

	int		a = 1;
	char	str[3];

	std::cout << "Before your input, a was " << a << std::endl;
	std::cin >> a; // if 100000000000000 => a = 2147483647
	std::cout << "Your input is " << a << std::endl;
	std::cin >> str;
	std::cout << str << std::endl;

	// cin, cout은 스트림의 일부에 불과
	// C언어에서 printf, scanf와의 차이점?
	// 나중에 operator overloading을 배운 후에는 file I/O, network에도 다시 사용할 수 있음

	return (0);
}