// 11.6 유도된 클래스에 새로운 기능 추가하기

#include <iostream>

class Base
{
private:
	int	m_value;

public:
	Base(int value)
		: m_value(value)
	{
		std::cout << "class Base constructor" << std::endl;
	}

	int	&getValue() { return (m_value); }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{
		std::cout << "class Derived constructor" << std::endl;
	}

	// Base class의 m_value값을 Derived class에서 바꾸는 함수
	// m_value만 수정하는 것이라면 Base class에 정의하는 것이 맞음
	// 그래서 Derived class에 멤버 변수와 같이 사용한다고 가정
	void	setValue(const int &value)
	{
		// error: 'm_value' is a private member of 'Base'
		// 방법 1. Base::m_value protected로 수정
		Base::getValue() = value;
		// 방법 2. Base::getValue()를 추가하여 호출
		// => 상위 클래스 함수를 거쳐야 하기 때문에 복잡 && 퍼포먼스 하락 가능성
		// 반드시 2번이 옳은 것은 아니고, 상황에 따라 설계하는 것이 좋음
	}
};

int	main()
{
	Base	b(100);
	Derived	d(200);

	std::cout << b.getValue() << std::endl;		// 100
	std::cout << d.getValue() << std::endl;		// 200

	d.setValue(300);
	std::cout << d.getValue() << std::endl;		// 300

	return (0);
}