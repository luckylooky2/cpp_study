// 2.5 부동소수점 수 (Floating Point Numbers)

#include <iostream>
#include <iomanip> // 소수점 자리 설정
#include <limits>
#include <cmath>

// 컴퓨터는 소수를 부동소수점을 이용해 표현함
// 결론 : 직접 계산하는 것과 컴퓨터가 실제 내부에서 작동하는 것이 다를 수 있다. 
// 예기치 못한 결과가 나올 수 있다.

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
	using namespace std;
	float		f;
	double		d;
	long double	ld;

	cout << sizeof(f) << endl;	// 4
	cout << sizeof(d) << endl;	// 8
	cout << sizeof(ld) << endl;	// 8

	cout << numeric_limits<float>::max() << endl;			// 3.40282e+38
	cout << numeric_limits<double>::max() << endl;			// 1.79769e+308
	cout << numeric_limits<long double>::max() << endl;		// 1.79769e+308

	// min : 표현할 수 있는 가장 작은 숫자의 절대값(소수점)
	cout << numeric_limits<float>::min() << endl;			// 1.17549e-38
	cout << numeric_limits<double>::min() << endl;			// 2.22507e-308
	cout << numeric_limits<long double>::min() << endl;		// 2.22507e-308

	// lowest : 표현할 수 있는 가장 작은 숫자(음수)
	cout << numeric_limits<float>::lowest() << endl;		// -3.40282e+38
	cout << numeric_limits<double>::lowest() << endl;		// -1.79769e+308
	cout << numeric_limits<long double>::lowest() << endl;	// -1.79769e+308

	// 과학적 표기법
	cout << 3.14 << endl;		// 3.14
	cout << 31.4e-1 << endl;	// 3.14 = 31.4 * 0.1
	cout << 3.14e-2 << endl;	// 0.0314
	cout << 3.14e1 << endl;		// 31.4
	cout << 3.14e3 << endl;		// 3140

	// 해당 수에 가장 가까운 수를 출력
	cout << setprecision(17) << endl;
	cout << 1.0 / 3.0 << endl;					// 0.33333333333333331
	cout << 123456789.0f << endl;				// 123456792
	cout << 123456789.0 << endl;				// 123456789
	cout << 0.1 << endl;						// 0.10000000000000001
	cout << 1.0 << endl;						// 1
	cout << 0.1 + 0.1 + 0.1 + 0.1 + 0.1 \
	+ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 << endl;		// 0.99999999999999989

	double	zero = 0.0;
	double	pos = 5.0 / zero;
	double	neg = -5.0 / zero;
	double	nan = zero / zero;

	cout << pos << endl;				// inf
	cout << neg << endl;				// -inf
	cout << nan << endl;				// nan
	cout << isinf(pos) << endl;			// 1
	cout << isinf(neg) << endl;			// 1
	cout << isnan(nan) << endl;			// 1

	cout << setprecision(10) << endl;	
	cout << 3.141592 << endl;			// 3.141592
	cout << 3.141e1 << endl;			// 31.41
	cout << 0.1000e-2 << endl;			// 0.001
	cout << 1.230002e2 << endl;			// 123.0002
	cout << 0.1e-9 << endl;				// 1e-10
	cout << 2.34560000000e8 << endl;	// 234560000

	return (0);
}
