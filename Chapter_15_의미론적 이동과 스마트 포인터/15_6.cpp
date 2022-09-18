// 15.6 std::shared_ptr

#include <iostream>
#include <memory>
#include "15_6_Resource.hpp"

int	main()
{
	Resource	*res = new Resource(5);

	res->setAll(1);
	
	{
		// 내부적으로 가리키고 있는 포인터가 몇 군데서 공유를 하고 있는지 카운트
		std::shared_ptr<Resource>	ptr1(res);
		ptr1->print();		// 1 1 1 1 1
		{
			std::shared_ptr<Resource>	ptr2(ptr1);
			// 단계적이 아니고 res로부터 직접 만들어지는 경우?
			// ptr1 입장에서는 소유권이 자기 말고 다른 곳에 있는 것을 알 방법이 없음
			// ptr2가 소멸될 때 소멸자를 호출하기 떄문에 ptr1을 사용한다면 문제가 발생할 수 있음
			// std::shared_ptr<Resource>	ptr2(res);

			ptr2->setAll(3);
			ptr2->print();		// 3 3 3 3 3 

			std::cout << "Going out of the inner block" << std::endl;
			// 블록을 나가면서 ptr2가 소멸되지만 소유권은 ptr1에도 있기 떄문에 소멸자를 호출하지 않음
		}
		ptr1->print();		// 3 3 3 3 3 
		std::cout << "Going out of the outer block" << std::endl;
	}
	// 소유하고 있는 포인터가 없기 떄문에 소멸자 호출
	// class Resource destructor
	// std::getchar();		// 한 글자 표준 입력 대기

	// 위처럼 인스턴스 포인터를 이용해 간접 초기화하는 방식보다는
	// make_shared를 이용한 직접 초기화 방식으로 쉐어드 포인터를 생성
	{
		auto	ptr1 = std::make_shared<Resource>(3);
		{
			// copy하여 넣어주는 것으로 보이지만 위처럼 포인터를 관리하고 있음
			auto	ptr2 = ptr1;
		}
	}
	// std::getchar();

	return (0);
}