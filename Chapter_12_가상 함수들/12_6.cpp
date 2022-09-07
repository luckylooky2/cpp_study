// 12.6 가상(함수) 표

// 다형성을 사용할 때, 상속 구조에 따라 가상 함수들이 어떻게 호출될 지 결정됨
// 가상 함수 표를 만들어서 사용

#include <iostream>

class Base
{
public:
	// 내부적으로 virtual function이 선언되면
	// 정적 바인딩을 하는 것이 아니라
	// virtual table을 만들고 동적 바인딩을 함
	// 동적 바인딩은 func_ptr를 거쳐가는 구조라고 생각하면 편함
	// virutal function이 없다면 모두 정적 바인딩
	// FunctionPointer	*_vptr;
	virtual void	func1() {};
	virtual void	func2() {};
};

class Derived : public Base
{
public:
	// 자식 클래스에 virtual function이 없더라도
	// 부모 클래스에서 이미 virtual function로 선언이 되었기 때문에
	// 자식 클래스도 virtual table을 가짐
	// FunctionPointer	*_vptr;
	// func1() overriding
	virtual void	func1() {};
	virtual void	func3() {};
};

int	main()
{
	Base	base;
	Derived	derived;

	// 부모 클래스
	// virtual function이 선언되어 있을 경우, 정적 바인딩으로 직접 호출하지 않고
	// 1. virtual table을 찾음(*_vptr)
	// 2. virtual table 안에는 func1, func2에 대한 함수 포인터가 존재
	// 3. func1을 찾고, 함수 포인터가 가리키는 곳으로 감
	// 4. 해당 주소에 있는 함수를 실행
	// overriding이 되지 않은 부모 클래스이기 때문에
	// 자기 자신을 돌아서 오는 구조로 되어 있음
	base.func1();

	// 자식 클래스
	// 1. virtual table을 찾음(*_vptr)
	// 2. virtual table 안에는 func1, func2에 대한 함수 포인터가 존재
	// 3. func1을 찾고, 함수 포인터가 가리키는 곳으로 감
	// overriding
	// 4. 자식 클래스) 주소에 있는 함수를 실행
	// not overriding
	// 4. 부모 클래스) 주소에 있는 함수를 실행
	// => 자식 클래스로 생성이 된 인스턴스를 부모 클래스 포인터/레퍼런스로 캐스팅해도
	// virtual table이 바뀌지 않기 때문에 두 클래스에 접근할 수 있고, 다형성을 사용할 수 있음
	derived.func1();

	// 왜 1 byte? 8 bytes?
	// no virtual function
	std::cout << sizeof(Base) << std::endl;		// 1
	std::cout << sizeof(Derived) << std::endl;	// 1
	// virtual function
	// virtual table에 대한 포인터이기 때문에 8 bytes
	std::cout << sizeof(Base) << std::endl;		// 8
	std::cout << sizeof(Derived) << std::endl;	// 8


	return (0);
}

// 동적 바인딩으로 어떻게 설명?