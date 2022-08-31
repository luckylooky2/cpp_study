#include <iostream>

struct aaa
{
	int			x;
	static int	y;
};

void foo()
{
	static int	a = 123;
}

int	main()
{
	std::cout << aaa::y << std::endl;
	// std::cout << a << std::endl;
	foo();
	// std::cout << a << std::endl;
	return (0);
}

// 함수 안에 있는 static 변수
// 함수 안에서 밖에 접근하지 못함 => 밖에서 사용할 경우 값을 return을 해줘야 함