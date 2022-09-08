// 11.4 유도된 클래스들의 생성과 초기화

#include <iostream>

class Mother
{
private:
	int	m_i;

public:
	Mother() { std::cout << "class Mother constructor" << std::endl; }
	~Mother() { std::cout << "class Mother destructor" << std::endl; }
};

class Child : public Mother
{
private:
	double	m_d;
	int		m_temp;

public:
	Child() { std::cout << "class Child constructor" << std::endl; }
	~Child() { std::cout << "class Child destructor" << std::endl; }
};

class A
{
public:
	A(int a)
	{
		std::cout << "class A constuctor" << " ";
		std::cout << "A : " << a << std::endl;
	}

	~A() { std::cout << "class A destuctor" << std::endl; }
};

class B : public A
{
public:
	B(int a, double b)
		: A(a)
	{
		std::cout << "class B constuctor" << " ";
		std::cout << "B : " << b << std::endl;
	}

	~B() { std::cout << "class B destuctor" << std::endl; }
};

class C : public B
{
public:
	C(int a, double b, char c)
	// 바로 위 부모 클래스만 생성자를 호출할 수 있음
	// A(a) : 호출할 수 없음
		: B(a, b)
	{
		std::cout << "class C constuctor" << " ";
		std::cout << "C : " << c << std::endl;
	}

	~C() { std::cout << "class C destuctor" << std::endl; }
};

int	main()
{
	// 자식 클래스에 할당을 할 때는
	// 부모 클래스에 들어있는 멤버도 다 같이 담을만큼 할당을 함
	Child	c1;

	std::cout << sizeof(Mother) << std::endl;		// 4
	// float	m_f;
	std::cout << sizeof(Child) << std::endl;		// 8
	// double	m_d;
	std::cout << sizeof(Child) << std::endl;		// 16 : padding
	// double	m_d;
	// int		m_temp;
	std::cout << sizeof(Child) << std::endl;		// 24 : padding

	// 소멸자는? 생성자의 역으로 호출
	// error: no matching constructor for initialization of 'C'
	// C		c2;
	C			c3(1024, 3.14, 'a');
	// class A constuctor A : 1024
	// class B constuctor B : 3.14
	// class C constuctor C : a
	// class C destuctor
	// class B destuctor
	// class A destuctor

	return (0);
}