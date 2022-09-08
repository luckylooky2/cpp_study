// 12.9 객체 잘림과 reference_wrapper

// 부모 클래스보다 자식 클래스가 더 많은 정보를 가지고 있음
// e.g., 추가적인 변수, 함수, 함수 오버로딩

// object slicing
// 만약 부모 클래스 인스턴스에 자식 클래스 인스턴스를 강제로 대입한다면
// 자식 클래스 정보들은 잘려서 사라짐
// 이러한 실수를 방지할 수 있는 reference_wrapper

#include <iostream>
#include <vector>

class Base
{
public:
	int	m_i	= 0;

	virtual void	print()
	{
		std::cout << "I'm base" << std::endl;
	}
};

class Derived : public Base
{
public:
	int	m_j	= 0;

	virtual void	print() override
	{
		std::cout << "I'm derived" << std::endl;
	}
};

void	doSomething(Base &b)
{
	b.print();
}

int	main()
{
	Derived	d;
	// 포인터 => 다형성 구현
	Base	&b = d;
	b.print();		// I'm derived

	// 대입 : 복사하는 과정에서 자식 클래스의 내용이 잘려 나감
	// 다형성 사용할 수 없음
	Base	c = d;
	c.print();		// I'm base

	// 마찬가지로 매개변수가 &b vs. b
	// &b
	doSomething(d);	// I'm derived
	// b
	doSomething(d);	// I'm base

	// 객체 잘림은 피하는 것이 좋기 때문에, 의도해야 하는 상황이라면
	// 주석으로 설명을 남기는 것이 좋음
	
	Base	base;
	Derived	derived;

	// 역시 같은 문제 발생
	std::vector<Base>	my_vec1;
	my_vec1.push_back(base);
	my_vec1.push_back(derived);

	for (auto &elem : my_vec1)
		elem.print();	// I'm base I'm base
	
	// 1. reference => vector는 reference type 지원하지 않음
	// std::reference_wrapper를 사용
	// std::vector<Base &>	my_vec1;
	std::vector<std::reference_wrapper<Base> >	my_vec2;
	my_vec2.push_back(base);
	my_vec2.push_back(derived);

	for (auto &elem : my_vec2)
		// wrapper로 감싸줬기 때문에 .get()
		elem.get().print();	// I'm base I'm derived

	// 2. pointer
	std::vector<Base *>	my_vec3;
	my_vec3.push_back(&base);
	my_vec3.push_back(&derived);

	for (auto &elem : my_vec3)
		elem->print();	// I'm base I'm derived

	return (0);
}
