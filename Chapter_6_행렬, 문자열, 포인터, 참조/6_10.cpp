// 6.10 C 스타일의 문자열 기호적 상수

#include <iostream>

const char	*getName()
{
	return ("Jack Jack");
}

int	main()
{
	char	name[] = "Jack Jack";
	// error: redefinition of 'name' with a different type: 'char *' vs 'char [10]'
	// l-value는 단순 포인터, r-value는 리터럴
	// 실제로 "Jack Jack"이 담길 메모리를 어디서 만들 것인가는 나와있지 않음
	// 배열에 담는 것도 아니고 변수에 담는 것도 아님 => 포인터에는 담을 수 없음
	// 포인터는 메모리의 주소를 가리키기만 할 수 있음
	char		*name = "Jack Jack";
	// 해결
	const char	*name = "Jack Jack";
	const char	*name2 = getName();
	const char	*name3 = "Jack Jack2";

	std::cout << name << std::endl;
	// 같은 주소를 가지고 있음
	// 컴파일러가 최적화 측면에서 하나의 문자열만 만듦
	std::cout << (uintptr_t)name << std::endl;	// 4362141416
	std::cout << (uintptr_t)name2 << std::endl;	// 4362141416
	std::cout << (uintptr_t)name3 << std::endl;	// 4362141426

	int			int_arr[5] = {1, 2, 3, 4, 5};
	char		char_arr[] = "hello world";
	const char	*name_arr = "Jack Jack";
	char		c = 'Q';

	// std::cout에서 문자열은 특별히 처리함
	// char *가 들어오면 문자열이 아닐까라고 먼저 가정
	// char의 주소를 출력하는 것이 아니라 NULL character까지 출력
	// 구현한 사람이 프로그래머가 편한 방형으로 설계한 것이기 때문에 예외적인 것
	// 원칙 중심으로 이럴 땐 왜 안되지라는 의심을 계속 가질 것
	std::cout << int_arr << std::endl;	// 0x16ba2f470
	std::cout << char_arr << std::endl;	// hello world
	std::cout << name_arr << std::endl;	// Jack Jack
	std::cout << &c << std::endl;		// Q�~'

	return (0);
}