// 15.1 '이동'의 의미와 스마트 포인터 소개

// C언어 계열은 동적 할당을 통해 메모리를 직접 관리하는 것이 불편함
// 스마트 포인터 도입으로 해결

#include <iostream>
#include "15_1_Resource.hpp"
#include "15_1_AutoPtr.hpp"

void	doSomething()
{
	// 동적 할당
	Resource	*res = new Resource;

	// work with res

	// 문제 1. delete을 호출하지 않는 경우
	// delete res;
	// 문제 2. 조건문을 걸었는데 early return을 하는 경우 => return 하기 전에 delete
	if (true)
	{
		// delete res;
		return ;
	}
	// 여전히 불편함

	// 동적 할당을 한 곳에서 해제를 해야 한다
	// RAII : resource acquisition is initialization

	// try catch 문에서도 관리가 어려움
	try
	{
		Resource	*res = new Resource;

		if (true)
		{
			throw (-1);
		}
		// throw을 하면서 delete를 할 수 없음
		delete res;
	}
	catch(...)
	{
		std::cerr << "error detected" << '\n';
	}
	
	return ;
}

void	doSomething2()
{
	try
	{
		// 자체가 포인터이기 때문에 *res가 아님
		AutoPtr<Resource>	res = new Resource;	// smart pointer
		
		if (false)
		{
			throw (-1);
		}

		// delete res;
	}
	catch(...)
	{
		std::cerr << "error detected" << '\n';
	}
}


// 해결
// 1. 동적 할당 변수를 직접 관리하는 방법
// 2. 항상 관리를 자동으로 해줄 수 있는 추가적인 클래스를 만듦 => class AutoPtr
int	main(void)
{
	// no destructor called with memory leak
	// 예외 처리 => 지역 변수 res 메모리 해제 => memory leak
	doSomething();	// class Resource construct
	// destructor called with no memory leak
	// 지역 변수 res 메모리 해제 => ~Autoptr 소멸자 호출 => delete => ~Resource 소멸자 호출
	doSomething2();	// class Resource construct class Resource destruct

	// int	i;
	// int	*ptr(&i);
	// int	*ptr2 = nullptr;와 같은 형태라고 보면 됨
	AutoPtr<Resource>	res1(new Resource);
	AutoPtr<Resource>	res2;

	std::cout << std::boolalpha;
	std::cout << res1.m_ptr << std::endl;	// 0x12de04420
	std::cout << res2.m_ptr << std::endl;	// 0x0

	// 할당 연산자 => 두 포인터가 똑같은 주소를 가리키고 있음
	// double free 문제 => 런타임 에러
	// 소유권을 항상 한 개만 가지고 있게 하는 방법 => 소유권을 이동시킴
	// before defining assignment operator overloading
	res2 = res1;							// value semantics
	std::cout << res1.m_ptr << std::endl;	// 0x12de04420
	std::cout << res2.m_ptr << std::endl;	// 0x12de04420
	// class Resource destruct
	// class Resource destruct

	// after defining assignment operator overloading
	// double free 해결
	res2 = res1;							// move semantics
	std::cout << res1.m_ptr << std::endl;	// 0x0
	std::cout << res2.m_ptr << std::endl;	// 0x12de04420
	// class Resource destruct

	// syntax vs. semantics
	int	x = 1, y = 1;
	x + y;	// add

	std::string	str1("Hello"), str2("World");
	// 기호는 같은데 의미적으로 다름 => semantics
	str1 + str2;	// append

	// 아래가 어떻게 동작할지는 semantics에 따라 달라짐
	// 1. value semantics(copy semantics)
	// 2. reference semantics(pointer)
	// 3. move semantics(move)
	// 아래는 copy semantics를 구현한 것이 아니라 move semantics를 구현한 것
	res2 = res1;

	// AutoPtr의 한계
	// res1을 어떤 함수의 인자로 전달하는 경우
	// 그 함수 안에 있는 AutoPtr로 소유권이 이동될 수 있음
	// 함수가 종료되면 AutoPtr가 소멸되면서 밖에서는 접근할 수 없는 문제가 발생

	return (0);
}