// 12.4 가상 소멸자

// 상속 구조에서 생성자는 보통 자식 클래스 자신의 생성자를 사용
// 하지만 소멸자는 가상 소멸자를 사용하는 것이 좋음

#include <iostream>

class Base
{
public:
	Base() { std::cout << "class Base constructor" << std::endl; }
	virtual ~Base() { std::cout << "class Base destructor" << std::endl; }
};

class Derived : public Base
{
private:
	int	*m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
		std::cout << "class Derived constructor" << std::endl;
	}
	// override 키워드를 붙일 수 없음
	// 만약 virtual ~Base()라면 override 키워드를 붙일 수 있음
	// 자식 클래스에서도 virtual을 붙여주는 것이 표현해주는 측면에서 좋음
	virtual	~Derived() override
	{
		std::cout << "class Derived destructor" << std::endl;
		delete[] m_array;
	}
};

int	main()
{
	// 다형성을 사용하지 않는 경우
	Derived	derived(5);

	// 다형성을 사용하는 경우
	Derived	*derived2 = new Derived(5);
	Base	*base = derived2;

	// 보통, 인스턴스가 어떤 자식 클래스로부터 만들어졌는지 모르는 경우가 많음
	// 그래서 부모 클래스 포인터를 이용해서 할당 해제하면 편함
	// Animal class는 하나인데 Cat, Dog, Cow class 등은 많음
	// 다형성의 장점을 충분히 사용하려면, 지울 때도 부모 클래스 포인터를 이용
	// no virtual destructor
	// ~Base만 호출 => 메모리 누수가 발생
	delete base;		// class Base destructor 
	// virtual destructor
	delete base;		// class Derived destructor class Base destructor 

	return (0);
}