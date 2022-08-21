// 2.9 심볼릭 상수 (Symbolic Constants)

#include <iostream>

// 함수에서도 많이 쓰임
// 파라미터를 함수 내에서 바꾸는 것은 지양
void	printNumber(const int my_number)
{
	// 바꾸려고 한다면 새로운 변수에 복사하여 사용
	int	new_my_number = my_number;

	std::cout << new_my_number << std::endl;
}

int	main()
{
	// 둘 다 의미는 동일하나, 보통 앞에 붙임
	// 포인터 레퍼런스?에서 의미가 달라지는 경우가 발생하기도 함

	// 값을 변경하지 못하기 때문에 선언과 동시에 초기화가 반드시 필요
	const double	gravity = 9.8;
	double const 	new_gravity = 9.8;

	// const 키워드를 붙인 변수의 값을 변경할 수 없음
	// 다른 사람이 변경하지 못하도록 막거나, 실수로 바꾸는 것을 방지
	// gravity = 1.2;

	printNumber(123);

	int	number;
	std::cin >> number;

	// 런타임 상수
	// 실행을 해야 runtime_1의 값이 결정이 됨
	const int	runtime_1(number);

	// 컴파일타임 상수
	// 컴파일 단계에서 compiletime_1는 값이 결정이 됨
	const int	compiletime_1(123);

	// 두 상수를 문법상 구분할 수 없는 문제점 => constexpr 키워드
	constexpr int	runtime_2(number);
	constexpr int	compiletime_2(123);


	return (0);
}