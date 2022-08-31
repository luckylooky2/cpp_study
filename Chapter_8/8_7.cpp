// 8.7 this 포인터와 연쇄 호출

#include <iostream>

class Simple
{
private:
	int	m_id;

public:
	Simple(const int &id_in)
	{
		// 모든 멤버(프로퍼티, 메서드)에 this->가 생략되어 있는 것
		this->setId(id_in);
		// 자기 자신을 가리키는 this 포인터(중요!)
		std::cout << this << std::endl;
		std::cout << "class Simple constructor" << std::endl;
	}

	void	setId(const int &id_in)	{ m_id = id_in; }
	int		getId()	{ return (m_id); }
};

class Calc
{
private:
	int	m_value;

public:
	Calc(const int &init_value)
	{
		m_value = init_value;
		std::cout << "class Calc constructor" << std::endl;
	}

	Calc	&add(const int &value) { m_value += value; return (*this); }
	Calc	&sub(const int &value) { m_value -= value; return (*this); }
	Calc	&mult(const int &value) { m_value *= value; return (*this); }
	
	void	print()
	{
		std::cout << m_value << std::endl;
	}
};

int	main()
{
	Simple	s1(1), s2(2);	// 0x7ffee4bfb8b8 0x7ffee4bfb8b0

	// setId 함수가 s1, s2에 각각 저장되어 있을까?
	// 하나를 만들어 놓고 중복해서 사용할 것이라고 추측
	// 개념적으로 Simple::setId(&s1, 1)과 같이 함수를 중복해서 사용
	s1.setId(11);
	s2.setId(12);
	std::cout << &s1 << std::endl;	// 0x7ffee4bfb8b8
	std::cout << &s2 << std::endl;	// 0x7ffee4bfb8b0

	Calc	cal1(10), cal2(10);

	cal1.add(10);
	cal1.sub(2);
	cal1.mult(5);
	cal1.print();							// 90
	
	// chaining function이 일어나는 과정
	Calc	&temp1 = cal2.add(10);
	Calc	&temp2 = temp1.sub(2);
	Calc	&temp3 = temp2.mult(5);

	// chaining member function
	// 실용성에 대해선 약간의 의문
	cal2.add(10).sub(2).mult(5).print();	// 90

	return (0);
}