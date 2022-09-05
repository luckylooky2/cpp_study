// 11.3 유도된 클래스들의 생성 순서

#include <iostream>

class Mother
{
private:
	int	m_i;

public:
	// 아래와 같이 default argument를 입력한다면 
	// default constructor는 필요하지 않음
	// Mother() : m_i(0) {}

	Mother(const int &i_in = 0)
	{
		m_i = i_in;
		std::cout << "class Mother constructor" << std::endl;
	}
};

class Child : public Mother
{
private:
	double	m_d;
public:
	// 의도적으로 Mother class constuctor을 호출을 하지 않아도
	// 자동으로 반드시 Mother class default constructor을 호출
	// Mother 초기화 => Child 초기화
	Child()
	// 하지만 public, protected여도 초기화 리스트로는 사용 불가
	// error: member initializer 'm_i' does not name a non-static data member or base class
		// : m_i(10)
	// 이유를 확인하려면 클래스들의 생성 순서를 확인
	// Mother class constructor가 호출 되기 전에 초기화 리스트에서 강제로 m_i를 사용할 수 없는 것
	// 초기화 리스트에 Mother()이 숨겨져 있음
	// Mother에서 생성, 초기화를 한 후에 블록 안에서 m_i를 사용할 수 있음(public, protected 한정)
	// Mother()이 뒤에 있어도 먼저 초기화
		: m_d(1.0), Mother(1024)
	{
		// // private이기 때문에 접근 불가
		// m_i = 10;
		// // public, protected라면 사용 가능
		// m_i = 10;
		// this->m_i = 10;
		// this->Mother::m_i = 10;
		m_d = 1.0;
		std::cout << "class Child constructor" << std::endl;
	}
};

class A
{
public:
	A() { std::cout << "class A constuctor" << std::endl; }
};

class B : public A
{
public:
	B() { std::cout << "class B constuctor" << std::endl; }
};

class C : public B
{
public:
	C() { std::cout << "class C constuctor" << std::endl; }
};

int	main()
{
	Child	c1;
	// class Mother constructor
	// class Child constructor

	B	b;
	// class A constuctor
	// class B constuctor


	C	c;
	// class A constuctor
	// class B constuctor
	// class C constuctor

	// 소멸자는?
	// 생성자 호출의 역으로 호출

	return (0);
}