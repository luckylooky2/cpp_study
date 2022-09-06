// 9.9 복사 생성자, 복사 초기화, RVO(Return Value Optimization)

#include <iostream>

class Fraction
{
private:
	int	m_numerator;
	int	m_denominator;

public:
	Fraction(int num = 0, int den = 1)
	{
		m_numerator = num;
		m_denominator = den;
		std::cout << "class Fraction constructor" << std::endl;
	}

	// copy constructor
	// 자신하고 똑같은 class의 인스턴스가 파라미터로 들어올 때
	// 어떻게 복사하는가?(깊은 복사, 얕은 복사)에 따라 많이 다름
	// 복사 생성자가 얼마나 많이 호출되는가에 따라
	// 복사 생성자가 호출되지 않게 하려면 => private 영역으로 옮김
	Fraction(const Fraction &f)
	{
		m_numerator = f.m_numerator;
		m_denominator = f.m_denominator;
		std::cout << "class Fraction copy constructor" << std::endl;
	}

	friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
};

std::ostream& operator<<(std::ostream &out, const Fraction &f)
{
	out << f.m_numerator << " / " << f.m_denominator << std::endl;
	
	return (out);
}

Fraction doSomething()
{
	Fraction temp(1, 2);

	std::cout << &temp << std::endl;	// 0x16eeff464

	return (temp);
}

int main()
{
	// 생성자 호출
	Fraction frac(3, 5);								// class Fraction constructor
	// 복사 생성자 호출
	Fraction fr_copy1(frac);							// class Fraction copy constructor
	// copy initialization : 복사 생성자 호출, 같은 결과
	Fraction fr_copy2 = frac;							// class Fraction copy constructor
	// 생성자 호출 => 컴파일러가 필요없다고 싶으면 생략
	// Fraction fr_copy3(3, 10)와 같음
	// 이것도 RVO?
	Fraction fr_copy3(Fraction(3, 10));					// class Fraction constructor

	std::cout << frac;			// 3 / 5
	std::cout << fr_copy1;		// 3 / 5
	std::cout << fr_copy2;		// 3 / 5
	std::cout << fr_copy3;		// 3 / 10

	// Return Value Optimization
	// 복사 생성자는 경우에 따라서 호출이 될수도 있고, 컴파일러가 최적화를 위해 생략을 해줄 수 있음
	// debug mode => copy initialization : 복사 생성자 호출
	// release mode => 생성자 호출
	// MacOS에서는 자동으로 RVO?
	// 서로 다르기 때문에 복사를 했어야만 했는데 복사하지 않음
	Fraction result = doSomething();

	std::cout << result;				// 1 / 2
	std::cout << &result << std::endl;	// 0x16eeff464

	return (0);
}