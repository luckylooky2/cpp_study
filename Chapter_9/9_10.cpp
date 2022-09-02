// 9.10 변환 생성자, explicit, delete

#include <iostream>

class Fraction
{
private:
	int	m_numerator;
	int	m_denominator;

public:
	// explicit 키워드 : converting construtor를 막음
	explicit Fraction(int num = 0, int den = 1)
	{
		m_numerator = num;
		m_denominator = den;
		std::cout << "class Fraction constructor" << std::endl;
	}

	Fraction(const Fraction &f)
	{
		m_numerator = f.m_numerator;
		m_denominator = f.m_denominator;
		std::cout << "class Fraction copy constructor" << std::endl;
	}

	// delete 키워드
	// 해당 함수를 사용하지 못하게 만듦
	// 버전 업을 하면서 예전에 쓰던 함수들을 쓸까봐 걱정이 되는 경우에 사용
	// 자동 변환 혹은 형 변환이 우려되는 경우에 사용
	Fraction(char c) = delete;

	friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
};

std::ostream& operator<<(std::ostream &out, const Fraction &f)
{
	out << f.m_numerator << " / " << f.m_denominator << std::endl;
	
	return (out);
}

void doSomething(Fraction frac)
{
	std::cout << frac;
}

int main()
{
	Fraction	frac(7);	// class Fraction constructor

	doSomething(frac);	// class Fraction copy constructor 7 / 1
	// converting construtor
	// 어떤 값이 들어왔는데, 받아들일 수 있는게 class 밖에 없다면 자동으로 생성자를 호출
	doSomething(7);		// class Fraction constructor 7 / 1

	// explicit 키워드가 있을 때
	// error: no matching function for call to 'doSomething'
	doSomething(7);

	// delete 키워드
	// error: call to deleted constructor of 'Fraction'
	Fraction	test('c');

	return (0);
}