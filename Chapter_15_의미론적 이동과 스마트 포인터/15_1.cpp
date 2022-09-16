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



// 해결
// 1. 동적 할당 변수를 직접 관리하는 방법
// 2. 항상 관리를 자동으로 해줄 수 있는 추가적인 클래스를 만듦 => class AutoPtr
int	main(void)
{
	doSomething();

	return (0);
}