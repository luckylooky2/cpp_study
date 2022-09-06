// 7.9 함수 포인터

#include <iostream>
#include <array>
// C++ 11
#include <functional>

typedef	bool(*check_func_t)(const int &);
using	check_func_t = bool(*)(const int &);

int	func()
{
	return (5);
}

int	goo()
{
	return (10);
}

bool	isEven(const int &number)
{
	if (number % 2 == 0)
		return (true);
	return (false);
}

bool	isOdd(const int &number)
{
	if (number % 2 == 1)
		return (true);
	return (false);
}

void	printNumbers(std::array<int, 10> &my_array, bool (*check_func)(const int &number) = isEven)
{
	for (const int &elem : my_array)
	{
		if (check_func(elem))
			std::cout << elem << " ";
		else if (check_func(elem))
			std::cout << elem << " ";
	}
	std::cout << std::endl;
}

int	main()
{
	// warning: address of function 'func' will always evaluate to 'true' 
	// note: prefix with the address-of operator to silence this warning => &func
	// 함수도 주소를 가지고 있음
	std::cout << func << std::endl;			// 1

	// 함수 포인터의 () : 가리키는 함수의 파라미터
	// 함수의 () :  붙이면 실행시킨 값을 가져온다는 의미
	// 리턴 타입과 파라미터가 정확히 일치해야 사용할 수 있음
	int	(*funcptr)() = func;
	// C++ 11
	std::function<bool (const int &)>	fp = isEven;

	funcptr = goo;
	std::cout << funcptr() << std::endl;	// 10

	std::array<int, 10> my_array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// 파라미터로 함수 포인터를 넘겨 주는 경우 => 다형성을 이해할 때 도움이 됨
	printNumbers(my_array, isEven);			// 0 2 4 6 8
	printNumbers(my_array, isOdd);			// 1 3 5 7 9
	// default argument
	printNumbers(my_array);					// 0 2 4 6 8

	return (0);
}