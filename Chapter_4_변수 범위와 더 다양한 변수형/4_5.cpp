// 4.5 암시적 형변환과 명시적 형변환

// 컴파일러가 형 변환을 할 때, 비트단위로 단순히 데이터가 복붙되는 것이 아니라
// 부호, 부동소수점, 자리수를 고려하여 변환이 진행됨 => 주의 필요

// implicit type conversion(coersion)
// 프로그래머가 요구하지 않아도 컴파일러가 형변환을 진행

// explicit type conversion(casting)
// 프로그래머가 직접 형 변환을 진행

#include <iostream>
#include <typeinfo>
#include <iomanip>

int main()
{
	int	a = 123;

	// 사용하고 있는 변수, 리터럴의 자료형을 확인할 때 사용
	std::cout << typeid(4.0).name() << std::endl;	// d
	std::cout << typeid(a).name() << std::endl;		// i

	// coersion
	// 승급(promotion) => 크게 문제될 것이 없음
	double	x = 123.0f;
	// 강등(demotion), numeric conversion
	float	y = 123.0;
	char	z = 30000;

	std::cout << z << std::endl;					// '0'
	// casting
	std::cout << static_cast<int>(z) << std::endl;	// 48

	double	i = 0.123456789;
	float	j = i;

	std::cout << std::setprecision(12) << i << std::endl;	// 0.123456789
	std::cout << std::setprecision(12) << j << std::endl;	// 0.123456791043

	float	f = 3.14;
	int		g = f;

	// 버림(floor)
	std::cout << g << std::endl;		// 3
	
	// 형 변환 우선순위
	// 4 byte보다 작은 것 => int
	// int, unsigned int, long, unsigned long, long long, unsigned long long, float, double, long double
	// int는 unsinged int로 변환되지 않기 때문
	std::cout << 5u - 10 << std::endl;	// 4294967291
	std::cout << 5 - 10u << std::endl;	// 4294967291
	std::cout << 5 - 10 << std::endl;	// -5

	// casting
	// C style
	int	b = (int)4.0;
	// C++ style
	int	c = int(4.0);
	int	d = static_cast<int>(4.0);

	return (0);
}