// 11.1 상속의 기본 [1/2]

// Inheritance(is-a relationship)
// 부모 클래스는 사라지지 않고, 안 보일 뿐
// 원래 상속의 취지 : 여러 클래스들로부터 일반화된 요소를 뽑아 클래스를 만드는 것
// 가능하면 encapsulation을 유지하는 방향으로 설계
// 재사용이 편함
// 여러 derived class들을 유도해서 만들 수 있음
// 구현, 타이핑 양이 많은 것보다 상속이 훨씬 편함
// 상속을 하는 이유는 보통, 부모 클래스의 멤버(m_i)와 자식 클래스의 멤버(m_d)를 함께 사용하기 위함
// 보통 생성자를 만들 때도 m_i, m_d 같이 사용

#include <iostream>

class Mother
{
// private : 모든 곳(자식 클래스 포함)에서 접근할 수 없음
// private 상태를 유지하면서 자식 클래스가 접근할 수 있음
protected:
	int	m_i;

public:
	// 상속을 위한 기본 생성자
	Mother() { m_i = 0; }

	Mother(const int &i_in)
	{
		m_i = i_in;
		std::cout << "class Mother constructor" << std::endl;
	}
	int		getValue() { return (m_i); }
	void	setValue(const int &i_in) { m_i = i_in; }
};

// Mother class를 상속받는 Child class
// public 대신 private도 가능 
// 기본적으로 Mother class에 있는 모든 멤버 사용 가능
class Child : public Mother
{
private:
	double	m_d;

public:
	// 부모 클래스 "기본 생성자" 문제
	// error: constructor for 'Child' must explicitly initialize 
	// the base class 'Mother' which does not have a default constructor
	// Child class 생성자가 호출될 때, Mother class "기본 생성자"가 같이 호출됨
	// 특별한 생성 단계가 존재
	// Mother class에 생성자를 정의하여 "기본 생성자"가 사라짐
	// 방법 1 : 부모 class에 기본 생성자 정의
	Child(const int &i_in, const double &d_in)
	// 방법 2 : Child class가 들어온 i_in을 Mother class에 넣어주면서 생성자 호출
		// : Mother(i_in), m_d(d_in)
	
	// 생성자로 생성할 때, 부모 클래스 멤버 접근 문제
	// "m_i" is not a nonstatic data member or base class of class "Child"
	// constructor가 존재하는 이유 : 메모리가 할당될 때 초기화를 해달라는 의미
	// 메모리를 할당되고 거기에 값을 넣어달라는 의미가 아님
	// Child class를 생성할 때, m_i가 메모리에 없다는 뜻 => 생성자가 호출되는 순서가 중요
	// initializer_list를 사용하지 않고
		// : m_i(i_in), m_d(d_in)
	{
		Mother::setValue(i_in);
		m_d = d_in;
		std::cout << "class Child constructor" << std::endl;
	}

	double	getValue() { return (m_d); }
	// child.getValue()는 Mother? Child?
	// 부모 클래스와 같은 함수가 존재할 경우, 자신 클래스의 더 우선하여 호출
	void	setValue(const double &d_in) { m_d = d_in; }
	// 부모 클래스 멤버와 자식 클래스 멤버 getter, setter 함수를 설정하는 방법
	// 방법 1 : 한 번에 처리하는 방법
	void	setValue(const int &i_in, const double &d_in)
	{
		// 부모 클래스 멤버 접근 문제
		// member "Mother::m_i" (declared at line 12) is inaccessibleC/C++(265)
		// m_i = i_in;
		// 1-1. protected 사용
		m_i = i_in;
		// 1-2. 부모 클래스의 메서드 사용
		Mother::setValue(i_in);
		m_d = d_in;
	}
	// 방법 2 : 따로 처리하는 방법
	// setDoubleValue(), setIntValue()
};

class Son : public Mother
{

};

int	main()
{
	Mother	mother(100);
	Son		son;
	// 안 되는 이유? Mother class의 생성자도 같이 가져오는 것 아닌가?
	// Son		son(200);
	Child	child(128, 1024.0);

	mother.setValue(1024);
	std::cout << mother.getValue() << std::endl;	// 1024

	son.setValue(128);
	std::cout << son.getValue() << std::endl;		// 128

	child.setValue(100, 200);
	// 이런 형식도 가능
	std::cout << child.Mother::getValue() << std::endl;		// 100
	std::cout << child.getValue() << std::endl;				// 200

	return (0);
}