// 12.11 유도 클래스에서 출력 연산자 사용하기

// 다형성은 여러 가지로 편리하고 유연한 사용 방법을 제공하지만
// 모든 경우에 다형성을 사용할 수 없음
// 대표적인 경우 : 출력 연산자는 overriding 불가

#include <iostream>

class Base
{
public:
	Base() {}

	// friend function은 멤버 함수가 아님 => 직접 overriding이 불가능
	// print 멤버 함수를 새로 만들고 일을 위임
	friend std::ostream& operator<<(std::ostream &out, const Base &b)
	{
		return (b.print(out));
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return (out);
	}
	// virtual 함수 여러 개를 조합하는 방식으로 구현
	// => 자식 클래스들이 virtual function들을 부품 조립하듯이 사용하는 방식도 있음
};

class Derived : public Base
{
public:
	Derived() {}

	// 자식 클래스는 출력 연산자 오버로딩 함수를 가지고 있을 필요가 없음
	// 다형성에 의해 부모 클래스의 출력 연산자 오버로딩 함수를 호출하기 때문?
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return (out);
	}
};

int	main()
{
	Base	b;
	Derived	d;
	Base	&bref = d;
	
	std::cout << b << std::endl;		// Base
	// note that this works even with no operator<< that 
	// explicitly handles Derived class
	std::cout << d << std::endl;		// Derived
	std::cout << bref << std::endl;		// Derived

	return (0);
}