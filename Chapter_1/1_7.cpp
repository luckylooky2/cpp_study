// 1.7 지역 범위(local scope)

#include <iostream>

// 블록 {} 안에 선언된 변수는 블록 {} 밖에서는 사라짐

int test()
{
	int x = 0;
	// error: redefinition of 'x'
	// int x = 1;

	std::cout << x << "  " << &x << std::endl; 		// 0x7ffeed42fa38

	// if, function 등과 같이 쓰이지 않을 수 있음
	{
		int	x = 1;

		std::cout << x << "  " << &x << std::endl; 	// 0x7ffeed42fa34
	}

	{
		// int	x = 2;

		// Javascript에서의 스코프 체인과 비슷?
		std::cout << x << "  " << &x << std::endl; 	// 0x7ffeed42fa38
	}

	{
		x = 3;
		std::cout << x << "  " << &x << std::endl; 	// 0x7ffeed42fa38
	}

	return (0);
}

void	doSomething(int x)
{
	// int x = 123; 할 수 없음 why? parameter가 있기 때문에 redefinition
	x = 123;

	std::cout << x << std::endl;
}

int	main()
{
	test();

	int	x = 0;

	std::cout << x << std::endl;
	// return을 한다면? 포인터를 가지고 간다면?
	doSomething(x);
	std::cout << x << std::endl;

	return (0);
}
