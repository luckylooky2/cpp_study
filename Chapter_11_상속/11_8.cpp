// 11.8 상속받은 함수를 감추기

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

	// 내부가 아닌 외부에서 Base::m_i의 값을 바꿀 수 있음
	using Base::m_i;
	// 상속받은 함수를 감출 수 있음
private:
	// 방법 1. using 키워드
	using Base::print;	// do not add () : 괄호는 실행시킨다는 의미
	// 방법 2. delete 키워드(C++ 11)
	void	print() = delete;
};

int	main()
{
	Base	base;
	Derived	derived(7);

	// befor using Base::m_i;
	// error: 'm_i' is a protected member of 'Base'
	// class Derived : public Base이므로 Base의 public 멤버 변수만 접근 가능
	derived.m_i = 1024;
	
	base.print();			// I'm base
	// before using Base::print;
	// error: 'print' is a private member of 'Derived'
	derived.print();


	return (0);
}