// 12.10 동적 형변환

// 자식 클래스의 포인터를 부모 클래스의 포인터로 바꿨다가
// 다시 자식 클래스 포인터로 바꿔주어야 하는 경우
// 업캐스팅?
// 업캐스팅이란 기초클래스의 포인터변수로 유도클래스의 객체를 가리키는 것을 의미한다.
// 자식 클래스로 생성 => 부모 클래스 포인터로 형 변환
// dynamic_cast를 사용하지 않고 static_cast를 사용
// 다운캐스팅?
// 다운캐스팅이란 업캐스팅된 포인터변수를 유도클래스의 포인터변수로 형변환시키는 것을 의미한다.
// 1. 자식 클래스로 생성 => 부모 클래스 포인터를 자식 클래스 포인터로 형 변환
// 2. 부모 클래스로 생성 => 부모 클래스 포인터를 자식 클래스 포인터로 형 변환

// dynamic_cast
// 안전한 다운캐스팅을 위해 사용된다.
// 다형성을 가진 객체간 변환만 가능. 즉 virtual 멤버 함수 또는 virtual 소멸자가 
// 부모 클래스에 존재해서 가상 함수 테이블이 생성되어 있어야 한다. 그렇지 않으면 컴파일 에러가 난다.
// 부모 클래스의 포인터에서 자식 클래스의 포인터로 다운 캐스팅 해주는 연산자 입니다.
// 런타임에 실제로 해당 타입이 다운 캐스팅이 가능한지 검사하기 때문에
// (포인터가 실패하면 nullptr를 반환, 레퍼런스가 실패하면 exception),
// 런타임 비용이 조금 높은 캐스트 연산자 입니다.

#include <iostream>
#include <vector>

class Base
{
public:
	int	m_i	= 10;

	virtual void	print()
	{
		std::cout << "I'm base" << std::endl;
	}
};

class Derived1 : public Base
{
public:
	int	m_j	= 1024;

	virtual void	print() override
	{
		std::cout << "I'm derived" << std::endl;
	}
};

class Derived2 : public Base
{
public:
	std::string	m_name	= "Dr. Two";

	virtual void	print() override
	{
		std::cout << "I'm derived" << std::endl;
	}
};

int	main()
{
	Derived1	d1;
	Base		b1;
	// 1. 자식 클래스로 생성 => 부모 클래스 포인터를 자식 클래스 포인터로 형 변환(다운캐스팅)
	// 1-1. Derived1으로 시작 => base *로 변환 => 다시 Derived1로 변환하는 경우
	// => 어떤 캐스팅을 써도 문제가 없음
	// 우리는 base 포인터가 Derived1 포인터였다가 다형성 때문에 잠깐 바뀐것을 알고 있음
	// 업캐스팅
	Base		*base = &d1;
	// base 포인터를 다시 Derived1 포인터로 동적 형변환을 할 수 있음
	// auto		*base_to_d1 = dynamic_cast<Derived1 *>(base);	// 가능
	auto		*base_to_d1 = static_cast<Derived1 *>(base);	// 가능
	// auto		*base_to_d1 = (Derived1 *)base;					// 가능
	// 암묵적 형 변환은 불가
	// Derived1 *ptr1 = &b1;

	// base엔 없고, d1에만 있는 것들은 접근할 수 없음
	// 설계를 잘해서, 이러한 경우가 없도록 하는 것이 좋겠지만
	// 접근 가능
	std::cout << d1.m_j << std::endl;
	// 접근 불가능
	// std::cout << base->m_j << std::endl;
	if (base_to_d1 != nullptr)
		std::cout << base_to_d1->m_j << std::endl;
	else
		std::cout << "Failed" << std::endl;

	// 1-2. Derived1으로 시작 => base *로 변환 => 다시 Derived2로 변환하는 경우
	// => Error
	// dynamic_cast
	// 컴파일타임이 아닌 런타임에 검사, 캐스팅에 실패하면 nullptr를 반환
	// dynamic_cast은 사용을 지양? => Functional / lambda function을 더 많이 사용
	// 하지만 이런 경우에는 dynamic_cast를 쓰는 편이 좋다고 생각
	auto *base_to_d2 = dynamic_cast<Derived2 *>(base);
	if (base_to_d2 != nullptr)
		std::cout << base_to_d2->m_name << std::endl;
	else
		std::cout << "Failed" << std::endl;
	
	// static_cast
	// 컴파일타임에 검사, 캐스팅을 웬만하면 다 하려고 함
	// 즉, nullptr을 반환하지 않음 => 런타임에서 에러 체크를 하지 않음
	// dynamic과 static은 필요한 상황에 따라 사용
	auto *base_to_d3 = static_cast<Derived2 *>(base);
	if (base_to_d3 != nullptr)
		std::cout << base_to_d3->m_name << std::endl;
	else
		std::cout << "Failed" << std::endl;

	// 2. 부모 클래스로 생성 => 부모 클래스 포인터를 자식 클래스 포인터로 형 변환(다운캐스팅)
	Base *bptr = &b1;

	auto	dptr1 = dynamic_cast<Derived1 *>(bptr);
	if (dptr1 != nullptr)
		std::cout << dptr1->m_i << std::endl;
	else
		std::cout << "Failed" << std::endl;

	auto	dptr2 = static_cast<Derived2 *>(bptr);
	// 접근할 수는 있지만 값이 없음? 이상한 값에 접근하는 듯?
	// 런타임에 검사를 하지 않기 때문에 의도와 다른 결과가 나올 가능성이 큼
	if (dptr2 != nullptr)
		std::cout << dptr2->m_name << std::endl;
	else
		std::cout << "Failed" << std::endl;

	return (0);
}