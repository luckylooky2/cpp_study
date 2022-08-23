// 4.4 auto 키워드와 자료형 추론

#include <iostream>

// 함수 리턴 타입으로도 사용 가능
// 파라미터는 auto 키워드를 쓸 수 없음
// trailing : 코드를 정리할 때 보기가 좋다.(indentation, 리턴 타입)
auto	add(int a, int b) -> int
{
	return (a + double(b));
}

// 다양한 자료형에 대해서 add()가 파라미터 자료형을 추론하는 것은 불가
// 다양한 자료형에 대해서 add()가 자동으로 만들어 줌 => template을 이용

// C++ 17 : 여러 변수를 return 하는 것이 쉬워짐

int main()
{
	// 가장 일반적인 방식
	// 중복된 정보가 존재 : int와 123(int)
	int		a = 123;		// int
	// 형 추론
	// 당연하지만, 초기화가 반드시 필요
	auto	b = 456;		// int
	auto	c = 123.0;		// double
	auto	d = 1 + 2.0f;	// float
	// 함수의 리턴 타입을 알고 있을 필요가 없음
	auto	e = add(1, 2);	// int

	return (0);
}