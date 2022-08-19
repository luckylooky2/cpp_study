// 2.2 정수형 (Integers)

#include <iostream>
#include <limits>

int main()
{
	short			s = 1; // 2 bytes = 2 * 8 bits = 16 bits (max : 2^(16-1) - 1)
	int				i = 1; // 00000000 00000000 00000000 00000001, signed int : 처음 1 bit는 부호에 사용
	long			l = 1;
	long long		ll = 1;
	unsigned int	ui;

	std::cout << sizeof(short) << std::endl;		// 2
	std::cout << sizeof(int) << std::endl;			// 4
	std::cout << sizeof(long) << std::endl;			// 8
	std::cout << sizeof(long long) << std::endl;	// 8
	
	std::cout << std::numeric_limits<short>::max() << std::endl;	// 32767
	std::cout << std::numeric_limits<short>::min() << std::endl;	// -32768
	// float 자료형에서 min()과 lowest()는 차이가 존재
	std::cout << std::numeric_limits<short>::lowest() << std::endl;	// -32768

	// overflow
	// 표현할 수 있는 가장 큰 수에 1을 더하면, 표현할 수 있는 가장 작은 수가 됨
	s = 32767 + 1;
	std::cout << s << std::endl; // -32768

	// 대입할 때는 overflow를 적용하여 대입
	ui = -1;
	std::cout << ui << std::endl; // 4294967295

	// 정수와 정수의 나눗셈은 정수로 반환
	i = 22 / 4;
	std::cout << i << std::endl; 				// 5
	std::cout << 22 / 4 << std::endl;			// 5
	// 실수와 정수의 나눗셈은 실수로 반환
	i = (float)22 / 4;
	std::cout << i << std::endl; 				// 5
	std::cout << (float)22 / 4 << std::endl;	// 5.5

	return (0);
}
