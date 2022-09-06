// 8.3 생성자

// 생성자(constructor)
// 리턴 타입이 없고 class 이름을 메서드 이름으로 함
// error: constructor cannot have a return type
// 의도적으로 호출하지 않아도 생성시 호출됨
// 생성자가 없을 때는 default 생성자가 숨어있음 => Fraction() {}
// constructor가 class를 생성하는 것이 아니고, class가 생성될 때 호출되는 함수
// 생성자를 하나라도 정의하게 되면, default 생성자는 사라짐
// 생성자에 출력하는 습관을 들여도 좋을 듯
// 생성자를 private으로 만드는 경우도 있음 => 생성자를 호출하지 못함
// => 특별한 경우에 이 성질을 이용하는 프로그래밍 기법

#include <iostream>

class Fraction
{
	// encapsulation
	// 방법 3 : C++ 11
private:
	int	m_numerator = 0;
	int	m_denominator = 1;

public:

	Fraction(const int &num_in, const int &den_in = 1)
	{
		m_numerator = num_in;
		m_denominator = den_in;
		std::cout << "Fraction constructor" << std::endl;
	}

	// error: call to constructor of 'Fraction' is ambiguous
	// default argument에 의해 발생한 에러 => 중복되는 생성자 제거
	Fraction()
	{
		m_numerator = 0;
		m_denominator = 1;
		std::cout << "Fraction constructor" << std::endl;
	}

	void	print()
	{
		std::cout << m_numerator << " / " << m_denominator << std::endl;
	}
};


class Second
{
public:
	Second()
	{
		std::cout << "class Second constructor" << std::endl;
	}
};

class First
{
	Second	sec;
public:
	First()
	{
		std::cout << "class First constructor" << std::endl;
	}
};

int main()
{
	// error: no matching constructor for initialization of 'Fraction'
	// 매개변수를 받는 생성자 밖에 없어서 발생하는 에러 => 매개변수 없는 생성자를 추가 or default argument 설정
	Fraction	frac;
	// warning: empty parentheses interpreted as a function declaration [-Wvexing-parse]
	// cf> 생성자인데 매개변수가 없을 때는 ()를 생략
	Fraction	frac2();

	// 초기화가 되어있지 않음
	frac.print();
	// 방법 1 : 멤버 변수를 public으로 만들고 main()에서 할당
	// frac.m_numerator = 0;
	// frac.m_denominator = 1;
	// 방법 2 : uniform init. => 여전히 public

	// 만약 인스턴스를 만들 때마다 새로운 값으로 초기화하고 싶다면? => 생성자
	Fraction	frac3(1, 100);

	// copy init.
	// 1 / 3으로 초기화된 인스턴스 하나가 frac4로 복사
	// operator overloading을 하지 않으면, 자동으로 있는 것을 줌
	Fraction	frac4 = Fraction{1, 3};
	// 줄여 쓰는 것을 권장
	// uniform init.은 private에는 사용 불가
	// cf> 하지만, 생성자가 있다면 생성자를 호출
	// 타입 변환을 허용하지 않음 => 더 엄격
	Fraction	frac5{1, 3};
	// warning: implicit conversion from 'double' to 'int' changes value from 1.5 to 1 [-Wliteral-conversion]
	Fraction	frac6{1.5, 3};

	// class가 멤버 변수일 경우
	First		fir;
	// class Second constructor
	// class First constructor
	// 멤버를 초기화해줘야 상위 class를 사용할 수 있음

	return (0);
}