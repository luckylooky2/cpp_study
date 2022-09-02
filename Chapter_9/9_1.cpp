// 9.1 산술 연산자 오버로딩하기

// 연산자 오버로딩
// C++에서는 기존의 C 언어에서 제공하고 있는 연산자에 대하여 
// 그 의미를 다시 부여하는 것을 "연산자 오버로딩" 또는 "연산자 중복(재정의)"라 함
// 연산자 오버로딩은 기본적으로 함수의 오버로딩과 같이 연산자도 하나의 함수라는 개념을 사용하여 중복 정의
// 중복되는 연산자 함수는 클래스의 멤버함수나 프렌드 함수로 정의
// 함수 이름 대신에 operator 키워드를 사용하고 다음에 연산자를 기술
// 컴파일러가 연산자를 함수로 변경하여 호출
// http://www.parkjonghyuk.net/lecture/2019-2nd-lecture/programming2/ch/chap08.pdf

#include <iostream>

class Cents
{
private:
	int	m_cents;

public:
	Cents(int cents)
	{ 
		m_cents = cents;
		std::cout << "class Cents constructor" << std::endl;
	}
	// 값을 복사해 r-value를 return
	int	getCents() const { return m_cents; }
	// return을 reference 타입으로 하면 l-value처럼 사용할 수 있음
	int	&getCents() { return m_cents; }

	// // 2. friend 함수로 연산자 오버로딩 하는 방법
	// friend Cents	operator + (const Cents &c1, const Cents &c2);

	// 3. 멤버 함수로 연산자 오버로딩을 하는 방법
	// v1 + v2 => v1.operator+(v2)
	// 파라미터가 너무 많다
	// why? this(호출하는 인스턴스)를 포함해야 하기 때문
	// unary + => 매개변수 0개
	// binary + => 매개변수 1개 
	Cents	operator + (const Cents &c2)
	{
		// 멤버 함수이기 때문에 멤버 변수에 직접 접근 가능 => getCents() 대체
		return (this->m_cents + c2.m_cents);
	}

	// 멤버 함수로만 해야하는 연산자
	// =(assignment), [](subscript), ()(function call), ->(member selection)
};

void	add1(const Cents &c1, const Cents &c2, Cents &c_out)
{
	c_out.getCents() = c1.getCents() + c2.getCents();
}

Cents	add2(const Cents &c1, const Cents &c2)
{
	// 새로운 인스턴스를 생성해서 return
	return (Cents(c1.getCents() + c2.getCents()));
}

Cents	&add3(const Cents &c1, const Cents &c2)
{
	// 안에서 값을 바꾸려면 인스턴스를 매개변수로 가져와야 함
	// 불가
}

// // 1. 일반적인 함수로 연산자 오버로딩 하는 방법
// // v1 + v2 = oprator+(v1, v2)
// Cents	operator + (const Cents &c1, const Cents &c2)
// {
// 	return (Cents(c1.getCents() + c2.getCents()));
// }

// // 2. friend 함수로 연산자 오버로딩 하는 방법
// Cents	operator + (const Cents &c1, const Cents &c2)
// {
// 	return (Cents(c1.m_cents + c2.m_cents));
// }

int main()
{
	Cents	cents1(6);
	Cents	cents2(8);
	// 혹은 default arguments 만들기
	Cents	sum1(0);
	Cents	sum2 = add2(cents1, cents2);
	Cents	sum3 = cents1 + cents2;

	// 6 cents + 8 cents
	// 왜 간단하게 i + j 형태로 사용하지 못하는가?
	add1(cents1, cents2, sum1);
	// I/O operator(<<, >>) : sum 자체도 출력할 수 있음 => 많이 쓰임
	std::cout << sum1.getCents() << std::endl;							// 14
	std::cout << sum2.getCents() << std::endl;							// 14
	std::cout << add2(cents1, cents2).getCents() << std::endl;			// 14
	std::cout << sum3.getCents() << std::endl;							// 14
	std::cout << (cents1 + cents2 + Cents(6)).getCents() << std::endl;	// 20

	// 연산자 오버로딩 불가
	// ?:, ::, sizeof, ., .*
	// 연산자 오버로딩을 해도 연산자 우선순위는 그대로
	// 가급적이면 수학적, 직관적으로 통하는 방식으로 오버로딩을 구현할 것
	// ^ : 연산자 우선순위가 매우 낮음 => 괄호가 거의 필요 => 연산자 오버로딩을 되도록이면 하지 말자

	// 연산자 오버로딩을 호출하는 조건?
	// 앞 operand를 보고 결정?
	cents1 + 1;	// inline Cents Cents::operator+(const Cents &c2)
	1 + cents2;	// no operator "+" matches these operandsC/C++(349)

	return (0);
}