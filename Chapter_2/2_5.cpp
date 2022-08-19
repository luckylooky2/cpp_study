// 2.5 부동소수점 수 (Floating Point Numbers)

#include <iostream>
#include <iomanip> // 소수점 자리 설정
#include <limits>
#include <cmath>

// 컴퓨터는 소수를 부동소수점을 이용해 표현함
// 결론 : 직접 계산하는 것과 컴퓨터가 실제 내부에서 작동하는 것이 다를 수 있다. 예기치 못한 결과가 나올 수 있다.

// float(4)
// 딥러닝 분야에서는 float 자료형을 사용하는 경우가 많음
// 10진수로 표현하는 것이 아니라 2의 거듭제곱으로 표현하는 것이기 때문에 오차가 발생할 수 있음
// 부호 : 1 bit		=> 0(+), 1(-)
// 지수부 : 8 bits	=> 00000111(7 = 2^0 + 2^1 + 2^2)
// 가수부 : 23 bits	=> 11000000000000000000000(0.75 = 2^-1 + 2^-2)
// 결과 : +(1 + 0.75) * 2^(7 - 127) = +1.316554 * 10^-36

// double(8)

// long double(8) : 8, 12, 16 bytes

int	main()
{
	float		f;
	double		d;
	long double	ld;

	std::cout << sizeof(f) << std::endl;	// 4
	std::cout << sizeof(d) << std::endl;	// 8
	std::cout << sizeof(ld) << std::endl;	// 8

	std::cout << std::numeric_limits<float>::max() << std::endl;			// 3.40282e+38
	std::cout << std::numeric_limits<double>::max() << std::endl;			// 1.79769e+308
	std::cout << std::numeric_limits<long double>::max() << std::endl;		// 1.79769e+308

	// min : 표현할 수 있는 가장 작은 숫자의 절대값(소수점)
	std::cout << std::numeric_limits<float>::min() << std::endl;			// 1.17549e-38
	std::cout << std::numeric_limits<double>::min() << std::endl;			// 2.22507e-308
	std::cout << std::numeric_limits<long double>::min() << std::endl;		// 2.22507e-308

	// lowest : 표현할 수 있는 가장 작은 숫자(음수)
	std::cout << std::numeric_limits<float>::lowest() << std::endl;			// -3.40282e+38
	std::cout << std::numeric_limits<double>::lowest() << std::endl;		// -1.79769e+308
	std::cout << std::numeric_limits<long double>::lowest() << std::endl;	// -1.79769e+308

	// 과학적 표기법
	std::cout << 3.14 << std::endl;		// 3.14
	std::cout << 31.4e-1 << std::endl;	// 3.14 = 31.4 * 0.1
	std::cout << 3.14e-2 << std::endl;	// 0.0314
	std::cout << 3.14e1 << std::endl;	// 31.4
	std::cout << 3.14e3 << std::endl;	// 3140

	// 해당 수에 가장 가까운 수를 출력
	std::cout << std::setprecision(17) << std::endl;
	std::cout << 1.0 / 3.0 << std::endl;				// 0.33333333333333331
	std::cout << 123456789.0f << std::endl;				// 123456792
	std::cout << 123456789.0 << std::endl;				// 123456789
	std::cout << 0.1 << std::endl;						// 0.10000000000000001
	std::cout << 1.0 << std::endl;						// 1
	std::cout << 0.1 + 0.1 + 0.1 + 0.1 + 0.1 \
	+ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 << std::endl;			// 0.99999999999999989

	double	zero = 0.0;
	double	pos = 5.0 / zero;
	double	neg = -5.0 / zero;
	double	nan = zero / zero;

	std::cout << pos << std::endl;				// inf
	std::cout << neg << std::endl;				// -inf
	std::cout << nan << std::endl;				// nan
	std::cout << std::isinf(pos) << std::endl;	// 1
	std::cout << std::isinf(neg) << std::endl;	// 1
	std::cout << std::isnan(nan) << std::endl;	// 1

	std::cout << std::setprecision(10) << std::endl;
	std::cout << 3.141592 << std::endl;
	std::cout << 3.141e1 << std::endl;
	std::cout << 0.1000e-2 << std::endl;
	std::cout << 1.230002e2 << std::endl;
	std::cout << 0.1e-9 << std::endl;
	std::cout << 2.34560000000e8 << std::endl;

	return (0);
}