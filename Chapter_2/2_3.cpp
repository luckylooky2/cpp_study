// 2.3 고정 너비 정수 (Fixed-width Integers)

// 자료형은 최소 크기만 규정 : 플랫폼, 컴파일러마다 구현된 size는 다를 수 있음 => 불확실성, 문제가 생길 수 있음
// C++ 11부터는 어떤 플랫폼이든지 똑같은 data size를 사용하는 자료형을 규정

// 멀티 플랫폼 프로그래밍을 할 때 많이 사용

#include <iostream>
// #include <cstdint>

int main()
{
	// 해당 플랫폼에서 16 bits 자료형으로 바꿔줌
	std::int16_t	i(5);
	std::int8_t		myint = 65;

	std::cout << myint << std::endl;	// A

	// 8 bits size 중에서 가장 빠른 자료형 
	std::int_fast8_t	fi(5);
	// 최소 64 bits (8 bytes)를 갖는 자료형
	std::int_least64_t	fl(5);

	return (0);
}