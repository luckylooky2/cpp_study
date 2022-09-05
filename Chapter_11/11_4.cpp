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

	return (0);
}