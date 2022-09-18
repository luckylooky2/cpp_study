// 15.5 std::unique_ptr

// C++ 17
// 포인터가 가리키고 있는 데이터의 소유권이 한 곳에만 속할 경우 사용하는 스마트 포인터

#include <iostream>
#include <memory>
#include "15_5_Resource.hpp"

std::unique_ptr<Resource>	doSomething()
{
	// 방법은 여러 가지
	std::unique_ptr<Resource>	res1 = std::make_unique<Resource>(5);

	return (res1);
	// return (std::make_unique<Resource>(5));

}

// unique_ptr의 reference 사용 => 문제 없음
void	doSomething2(std::unique_ptr<Resource> &res)
{
	res->setAll(10);
}

// 1. w/o reference => 포인터가 복사되기 떄문에 컴파일 에러 발생
// error: call to implicitly-deleted copy constructor of 'std::unique_ptr<Resource>'
// 인자를 r-value std::move(res1)으로 넣는 방법
void	doSomething3(std::unique_ptr<Resource> res)
{
	res->setAll(10);
}

// 2. 유니크 포인터가 내부적으로 가지고 있는 포인터만 넘겨주고 처리하는 방식
void	doSomething4(Resource *res)
{
	res->setAll(100);
}

int	main(void)
{
	{
		Resource					*res = new Resource(10000000);

		// early return or throw

		// delete를 해주지 않으면 블록을 나갈 때 소멸자가 호출이 안 되어 leak 발생
		// delete res;

		// template 사용
		// copy constructor 보다는 인자로 넣어주는 constructor 사용
		// delete이 없어도 자동으로 소멸자 호출이 되어 할당 해제
		std::unique_ptr<Resource>	up_res(new Resource(10000000));
	}

	{
		// 내부적으로 move semantics를 사용하기 때문에 소유권이 이전
		// copy 호출하지 않아 더 빠름
		// 1. 기본
		std::unique_ptr<int>		up_i(new int);
		// 2. 포인터를 인자로
		auto						*ptr = new Resource(5);
		std::unique_ptr<Resource>	up_res(ptr);
		// 3. 권장하는 방법 : make_unique 사용
		// std::make_unique<Resource>가 마치 Resource 인스턴스 인것 처럼 생성자 호출
		std::unique_ptr<Resource>	res1 = std::make_unique<Resource>(5);
		// 4. 함수로부터 받는 방법
		std::unique_ptr<Resource>	res2 = doSomething();

		res1->setAll(5);
		res1->print();		// 5 5 5 5 5

		std::unique_ptr<Resource>	res3;

		std::cout << std::boolalpha;
		// nullptr인지 아닌지를 출력할 때 bool 타입으로 캐스팅해서 사용
		std::cout << static_cast<bool>(res1) << std::endl;		// true(nullptr이 아님)
		std::cout << static_cast<bool>(res3) << std::endl;		// false(nullptr)

		// unique_ptr의 중요한 특징 : 복사를 하지 못함
		// error: object of type 'std::unique_ptr<Resource>' cannot be assigned
		// because its copy assignment operator is implicitly deleted
		// => std::move() 사용 or operator overloading
		// copy semantics : 불가
		// res3 = res1;

		// move semantics : 가능
		res3 = std::move(res1);
		std::cout << std::boolalpha;

		std::cout << static_cast<bool>(res1) << std::endl;		// false
		std::cout << static_cast<bool>(res3) << std::endl;		// true

		// 내부적으로 operator overloading
		// unique_ptr도 ->, *을 사용할 수 있음
		if (res1 != nullptr) res1->print();
		if (res3 != nullptr) res3->print();	// 5 5 5 5 5 
	}

	{
		auto	res1 = std::make_unique<Resource>(5);
		auto	res2 = std::make_unique<Resource>(5);

		res1->setAll(1);
		res1->print();			// 1 1 1 1 1

		doSomething2(res1);
		res1->print();			// 10 10 10 10 10
		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;	// true

		doSomething3(std::move(res1));
		// 유니크 포인터의 특징
		// doSomething3의 생성 인자로 res1의 포인터가 이동하고
		// 함수가 끝남과 동시에 인자도 소멸 => 소멸자 호출
		// class Resource destructor
		// 만약 res1이 필요하다면? 함수의 리턴값으로 받는 방법(다시 이동하는 결과)
		// res1->print();										// null pointer
		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;	// false

		// 문법적으로는 옳지만 동적 할당이 중간에 껴있어서 컴파일러에 따라 어떻게 동작할지 모르므로 지양
		doSomething3(std::unique_ptr<Resource>(new Resource(10000000)));
		// 인자를 직접 생성하여 전달하는 방법은 make_unique를 사용하는 편이 좋음
		doSomething3(std::make_unique<Resource>(10000000));

		// res2라는 유니크 포인터가 내부적으로 가지고 있는 Resoucre 인스턴스 포인터를 가져오는 함수
		doSomething4(res2.get());
		res2->print();										// 100 100 100 100 100 
		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res2) << std::endl;	// true
	}

	// 하면 안 되는 것
	{
		Resource	*res = new Resource;

		// 1. res 포인터의 소유권을 두 유니크 포인터가 관리하는 경우
		// 두 번 지우려고 하기 때문에 반드시 문제가 생김
		std::unique_ptr<Resource>	res1(res);
		std::unique_ptr<Resource>	res2(res);

		// 2. 직접 할당 해제하는 경우
		// 마찬가지로 두 번 지우려고 하는 문제가 발생
		delete res;
	}

	return (0);
}