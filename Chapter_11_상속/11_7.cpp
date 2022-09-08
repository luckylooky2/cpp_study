// 11.7 상속받은 함수를 오버라이딩 하기

// override
// 부모 클래스, 자식 클래스 간 기능 차이가 많지 않을 수 있음
// 겹치는 부분을 약간씩 다르게 구현하려고 할 때 사용

#include <iostream>

class Base
{
protected:
	int	m_i;

public:
	Base(int value = 0)
		: m_i(value)
	{
		std::cout << "class Base constructor" << std::endl;
	}

	void	print()
	{
		std::cout << "I'm base" << std::endl;
	}

};

class Derived : public Base
{
private:
	double	m_d;

public:
	Derived(double value)
		: Base(), m_d(value)
	{
		std::cout << "class Derived constuctor" << std::endl;		
	}

	// 함수 이름은 똑같이 유지하면서 부모 클래스 함수에 추가로 구현
	// 공통적인 것은 Base class에서 구현하고
	// 각자 다른 부분은 상속하여 자식 클래스에서 구현하는 방법
	void	print()
	{
		Base::print();
		std::cout << "I'm derived" << std::endl;
		// 의도(부모 클래스 호출)와 달리 자식 클래스 재귀 호출 => infinite loop
		// print();
	}
};

std::ostream& operator<<(std::ostream &out, const Base &base)
{
	out << "This is base output" << std::endl;
	return (out);
}

std::ostream& operator<<(std::ostream &out, const Derived &derived)
{
	// 부모 클래스로 캐스팅이 되는 이유?
	// Derived class를 메모리에 할당할 때, Derived + Base 데이터를 모두 할당
	// 업캐스팅 : static_cast밖에 사용하지 못함
	// 부모 클래스도 출력하고 싶은 경우
	// 1. 연산자 오버로딩을 통해서 => 업캐스팅하여 연산자 오버로딩 사용
	// 2. 출력 함수가 있다면 Base::print()처럼 사용
	std::cout << static_cast<Base>(derived);
	out << "This is derived output" << std::endl;
	return (out);
}

int	main()
{
	Base	base;
	Derived	derived(5);

	base.print();		// I'm base
	derived.print();	// I'm derived

	// 함수 이름은 똑같이 유지하면서 부모 클래스 함수에 추가로 구현하고 싶을 경우
	// Base::print(), Derived::print()를 구분해줘야 하는 문제
	// => 다형성 때문에 이러한 문제가 발생
	base.print();		// I'm base
	derived.print();	// I'm base I'm derived

	std::cout << base;		// This is base output
	std::cout << derived;	// This is base output This is derived output

	return (0);
}