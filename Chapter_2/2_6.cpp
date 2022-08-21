// 2.6 불리언 자료형과 조건문 if

#include <iostream>

// true(1), false(0)

bool	isEqual(int a, int b)
{
	return (a == b);
}

int test()
{
	bool	b1 = true; // copy initialization
	bool	b2(false); // direct initialization
	// bool	b3{ true }; // uniform initialization
	// b3 = false;

	std::cout << std::boolalpha;
	std::cout << b1 << std::endl;	// true
	std::cout << b2 << std::endl;	// false
	std::cout << std::noboolalpha;
	std::cout << b1 << std::endl;	// 1
	std::cout << b2 << std::endl;	// 0

	// not operator : 단항 연산자
	// 직관적이지 않기 때문에, 디버깅할 때 헷갈릴 가능성 => 자주 쓰지는 않음
	std::cout << !b1 << std::endl;	// 0
	std::cout << !b2 << std::endl;	// 1

	// 논리 연산자
	// if문을 대체하기도 함
	// && : 앞 조건이 true이면 뒤 조건을 실행
	// || : 앞 조건이 false이면 뒤 조건을 실행
	std::cout << ( true && true ) << std::endl;		// 1
	std::cout << ( true && false ) << std::endl;	// 0
	std::cout << ( false && true ) << std::endl;	// 0
	std::cout << ( false && false ) << std::endl;	// 0
	std::cout << ( true || true ) << std::endl;		// 1
	std::cout << ( true || false ) << std::endl;	// 1
	std::cout << ( false || true ) << std::endl;	// 1
	std::cout << ( false || false ) << std::endl;	// 0
	std::cout << isEqual(2, 2) << std::endl;		// 1

	// 조건문에서는 결과값이 0이 아니면 true
	if ("s")
		std::cout << "This is true " << std::endl;	// This is true
	else
		std::cout << "This is false " << std::endl;	// This is false

	// cin에서는 입력값이 0이 아니고 && 숫자이면 true
	// true, false 문자열로 입력하면 안 됨 => 환경마다 다른 결과가 발생할 수
	// 굳이 0, 1 숫자가 아닌 다른 문자를 넣어서 오류가 생길 수 있는 여지를 만드는 것은 좋지 못함
	bool	b;

	std::cin >> b;
	std::cout << std::boolalpha;
	std::cout << "Your input : " << b << std::endl;
	std::cin.clear();

	return (0);
}

int main()
{
	test();

	int			num;
	const char	*res;

	std::cin >> num;
	res = (num % 2) ? "odd number." : "even number.";
	std::cout << num << " is " << res << std::endl;
}