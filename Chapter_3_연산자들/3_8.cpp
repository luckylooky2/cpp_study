// 3.8 비트단위 연산자

#include <iostream>
#include <bitset>

// 지금까지 해왔던 것은 타입단위 연산자
// 비트단위 연산자는 비트단위 자리끼리 연산하는 방법

// 메모리의 주소를 줄 수 있는 단위 : 1 byte => 주소를 줄 수 있는 단위는 안방, 화장실이 아닌 집 단위
// 비트단위 연산자를 제공하는 이유?
// 1.
// 256가지 표현이 가능한데 bool은 0 또는 1만 나타냄 => 낭비
// 메모리를 아끼고 전부 계산에 사용하기 위해 비트단위 연산자를 제공
// 2.
// 계산 속도가 훨씬 빠름

// bitwise operator(vs. logical operator)
// << : left shift
// >> : right shift
// ~ : not
// & : and
// | : or
// ^ : xor

// cin, cout과 똑같이 생겼지만, 서로 다름 => operator overloading
// 기본은 비트단위 연산자가 기본
// 기호의 개수가 제한적이기 때문
// 비트단위 연산은 기본적으로 unsigned

int main()
{
	unsigned int a = 1;
	unsigned int b = 2;
	unsigned int c = 3;
	unsigned int d = 1024;

	// <4> : template
	std::cout << std::bitset<4>(a) << std::endl;	// 0001
	std::cout << std::bitset<4>(b) << std::endl;	// 0010

	// << : 왼쪽으로 밀고, 남은 자리는 0으로 채움
	// 의미 : 2^n을 곱한 값과 같음
	// 언제 쓰이나? 2^n을 곱하는 것보다 훨씬 빠름
	std::cout << std::bitset<8>(c) << std::endl;		// 0000 0011(3)
	std::cout << std::bitset<8>(c << 1) << std::endl;	// 0000 0110(6)
	std::cout << std::bitset<8>(c << 2) << std::endl;	// 0000 1100(12)
	std::cout << std::bitset<8>(c << 3) << std::endl;	// 0001 1000(24)
	std::cout << std::bitset<8>(c << 4) << std::endl;	// 0011 0000(48)

	// >> : 오른쪽으로 밀고, 남은 자리는 0으로 채움
	// 의미 : 2^n을 나눈 값과 같음
	// 언제 쓰이나? 2^n을 나누는 것보다 훨씬 빠름
	std::cout << std::bitset<16>(d) << std::endl;		// 0000 0100 0000 0000(1024)
	std::cout << std::bitset<16>(d >> 1) << std::endl;	// 0000 0010 0000 0000(512)
	std::cout << std::bitset<16>(d >> 2) << std::endl;	// 0000 0001 0000 0000(256)
	std::cout << std::bitset<16>(d >> 3) << std::endl;	// 0000 0000 1000 0000(128)
	std::cout << std::bitset<16>(d >> 4) << std::endl;	// 0000 0000 0100 0000(64)

	// ~ :  비트를 반전함
	// 직관적인 관계를 찾기 어려움
	std::cout << std::bitset<16>(d) << std::endl;		// 0000 0100 0000 0000(1024)
	std::cout << std::bitset<16>(~d) << std::endl;		// 1111 1011 1111 1111(4294966271)

	unsigned int e = 0b1100;	// 12
	unsigned int f = 0b0110;	// 6

	// & : 둘 다 1이어야 1
	std::cout << std::bitset<4>(e & f) << std::endl;	// 0100

	// | : 둘 중 하나만 1이어도 1
	std::cout << std::bitset<4>(e | f) << std::endl;	// 1110

	// ^ : 둘이 다르면 0, 같으면 1
	std::cout << std::bitset<4>(e ^ f) << std::endl;	// 1010

	// 연습 문제 => 10진수로 표현하면?
	std::cout << (0100 >> 2) << std::endl;	// 0001(1)
	std::cout << (5 | 12) << std::endl;		// 0101 | 1100 => 1101(13)
	std::cout << (5 & 12) << std::endl;		// 0101 & 1100 => 0100(4)
	std::cout << (5 ^ 12) << std::endl;		// 0101 ^ 1100 => 1001(9)

	return (0);
}