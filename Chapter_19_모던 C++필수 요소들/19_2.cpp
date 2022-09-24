// 19.2 함수에서 여러 개의 리턴값 반환하기

// C++ 17

#include <iostream>
#include <tuple>

int	my_func()
{
	// return (0, 1, 2, "string");
	return (0);
}

// 해결 방법
// 1. 리턴 타입을 구조체, 클래스를 만들어 사용 => 정의하는데 불편함
// 2. 튜플을 사용하는 방법
std::tuple<int, int>	my_func2()
{
	return (std::tuple<int, int>(123, 456));
}

// 더 간단하게 사용
auto	my_func3()
{
	return (std::tuple<int, int>(123, 456));
}

auto	my_func4()
{
	// C++ 17 : 더 간단하게 사용
	return (std::tuple(123, 456));
}

int	main()
{
	std::tuple<int, int>	result2 = my_func2();
	auto					result3 = my_func3();
	auto					result4 = my_func4();
	// 다른 방법 => 파이썬과 비슷한 방법?
	auto					[a, b] = my_func4();

	std::cout << std::get<0>(result2) << " " << std::get<1>(result2) << std::endl;	// 123 456
	std::cout << std::get<0>(result3) << " " << std::get<1>(result3) << std::endl;	// 123 456
	std::cout << std::get<0>(result4) << " " << std::get<1>(result4) << std::endl;	// 123 456
	std::cout << a << " " << b << std::endl;										// 123 456

	return (0);
}