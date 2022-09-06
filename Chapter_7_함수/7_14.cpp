// 7.14 단언하기 assert

// assert()
// 런타임에 사용자가 지정해준 범위 외 행동을 하는지 체크
// 결과값이 true이면 넘어가고, false이면 에러 발생
// release 모드에서는 작동하지 않음
// 어디서 오류가 발생했는지도 알려주기 때문에 유용
// 코드를 남겨두어도 상관없음

// static_assert()
// 컴파일타임에 사용자가 지정해준 범위 외 행동을 하는지 체크

#include <iostream>
#include <cassert>	// assert.h
#include <array>

void	printValue(const std::array<int, 5> &my_array, const int &i)
{
	assert(i >= 0);
	assert(i <= my_array.size() - 1);
	std::cout << my_array[i] << std::endl;
}

int	main()
{
	// Assertion failed: (false), function main, file 7_14.cpp, line 22.
	// assert(false);

	int			number_1 = 5;
	const int	number_2 = 10;

	// ...
	// debug 모드에서 number가 5가 아니면 이후로 실행시키지 않음
	assert(number_1 == 5);

	std::array<int, 5> my_array{1, 2, 3, 4, 5};

	// Assertion failed: (i <= my_array.size() - 1), function printValue, file 7_14.cpp, line 15.
	// printValue(my_array, 100);

	// error: static_assert expression is not an integral constant expression
	static_assert(number_1 == 5, "x should be 5");
	// error: static_assert failed due to requirement 'number_2 == 5' "x should be 5"
	static_assert(number_2 == 5, "x should be 5");
	
	return (0);
}