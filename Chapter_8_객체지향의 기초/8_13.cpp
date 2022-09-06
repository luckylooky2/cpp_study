// 8.13 익명 개체

#include <iostream>

class A
{
public:
	A() { std::cout << "class A constructor" << std::endl; };
	~A() { std::cout << "class A destructor" << std::endl; };
	void	print()
	{
		std::cout << "hello" << std::endl;
	}
};

class Cents
{
private:
	int	m_cents;

public:
	Cents(int cents) { m_cents = cents; }
	int	getCents() const { return m_cents; }
};

Cents	add(const Cents &c1, const Cents &c2)
{
	return (Cents(c1.getCents() + c2.getCents()));
}

int	main()
{
	A	a;

	a.print();		// hello
	a.print();		// hello
	// 익명 개체
	// r-value처럼 작동
	// 재사용할 수 없음 => 사라짐(두 익명 개체가 서로 다른 객체(메모리))
	A().print();	// class A constructor hello class A destructor
	A().print();	// class A constructor hello class A destructor

	std::cout << add(Cents(6), Cents(8)).getCents() << std::endl;	// 14
	// operator overloading
	// int()가 캐스팅인가? 
	std::cout << int(6) + int(8) << std::endl;	// 14

	return (0);
}