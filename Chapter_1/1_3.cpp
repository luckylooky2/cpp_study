// 1.3 변수와의 첫 만남

#include <iostream>

// 객체(objects)
// 컴퓨터 안에서 실제로 존재한다와 존재하지 않는다를 어떻게 구분?
// "메모리에 저장된 정보가 객체로서 존재"

// 변수(variables)
// 객체는 메모리에 존재할 뿐, 사용(접근)하기 위해서는 이름(식별자)가 필요
// 변수 : 식별자(메모리를 숫자로 기억하기에는 한계가 있음)

// l-values
// 주소 값을 가진 변수 그 자체
// 기준 : 메모리 주소를 프로그래머가 직접적으로 접근할 수 있음

// r-values
// 해당 변수의 값으로 치환됨
// 기준 : 메모리 주소를 프로그래머가 직접적으로 접근할 수 없음

int test(void)
{
	// initialization : 변수가 메모리에 할당될 때 바로 값을 복사해 넣음
	// assignment와 반드시 구분할 것
	// 객체지향 생성자/소멸자, assignment operator overloading할 때
	int	x = 123;
	int	y(123);

	// 왼쪽 x : l-value, 주소 값을 가진 변수 그 자체
	// 오른쪽 x : r-value, 변수 x의 값으로 치환됨
	// assignment opeator(대입 연산자), 같다라는 뜻이 아님
	x = x + 2;
	std::cout << x << std::endl; // 0
	std::cout << &x << std::endl; // 0x16d74b7a8
	return (0);
}

// 변수 초기화를 진행하지 않았을 때

// debug mode
// warning
// 실행파일 실행 : runtime error 발생

// release mode
// warning
// 실행파일 실행 : 실행은 일단 됨(0으로 초기화)
// 컴파일러 단에서 해결, 다른 환경에서는?
// 하지만 까먹고 초기화를 안 해줄 경우, 의도대로 코드가 동작하지 않을 가능성
// debug 모드에서 완벽하게 할 것

int	main(void)
{
	test();
	int	x = 1;
	x = x + 2;
	std::cout << x << std::endl; 		// 3?

	int	y = x;
	std::cout << y << std::endl; 		// 3?

	// is (x + y) l-value or r-value? r-value
	std::cout << x + y << std::endl; 	// 6?

	std::cout << x << std::endl; 		// 3?

	int	z;
	std::cout << z << std::endl; 		// uninitialized

	return (0);
}