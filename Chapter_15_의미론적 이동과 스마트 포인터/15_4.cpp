// 15.4 std::move

#include <iostream>
#include <vector>
#include "15_4_AutoPtr.hpp"
#include "15_4_Resource.hpp"

template<class T>
void	MySwap(T &a, T &b)
{
	// value semantics
	// T	tmp = a;
	
	// a = b;
	// b = tmp;

	// move semantics
	T	tmp{ std::move(a) };

	a = std::move(b);
	b = std::move(tmp);
}

int	main()
{
	{
		AutoPtr<Resource>	res1(new Resource(10000000));

		std::cout << res1.m_ptr << std::endl;	// 0x153e06720

		// value semantics
		AutoPtr<Resource>	res2 = res1;

		std::cout << res1.m_ptr << std::endl;	// 0x153e06720
		std::cout << res2.m_ptr << std::endl;	// 0x153e06730
		
		// move semantics
		// std::move는 r-value로 리턴 => 서로 다른 함수 오버로딩(&&)
		// r-value를 가지고 수행하는 기능(함수, 연산자)을 구현을 해야 의도대로 작동을 함
		// res3으로 옮긴 후에는 res1에는 아무 것도 남아 있지 않기 떄문에
		// 사용하는 것은 프로그래머의 책임 => 잘 모르고 사용하면 독이 될 수 있음
		AutoPtr<Resource>	res3 = std::move(res1);

		std::cout << res1.m_ptr << std::endl;	// 0x0
		std::cout << res3.m_ptr << std::endl;	// 0x153e06720
	}

	{
		AutoPtr<Resource>	res1(new Resource(3));
		AutoPtr<Resource>	res2(new Resource(5));

		res1->setAll(3);
		res2->setAll(5);
		res1->print();		// 3 3 3 
		res2->print();		// 5 5 5 5 5
		// value semantics
		MySwap(res1, res2);
		res1->print();		// 5 5 5 5 5 
		res2->print();		// 3 3 3 
		// move semantics
		// 복사 생성, 연산 대신에 이동 연산으로 더 깔끔 && 더 빠름
		MySwap(res1, res2);
		res1->print();		// 5 5 5 5 5 
		res2->print();		// 3 3 3 
	}

	{
		std::vector<std::string>	v;
		std::string					str = "Hello";

		// str을 l-value로 취급
		// 함수가 끝나도 str을 사용할 것이다라는 가정을 하고 사용
		// 즉, value semantics를 사용할 것이다라는 뜻
		v.push_back(str);
		std::cout << str << std::endl;					// Hello
		std::cout << v[0] << std::endl;					// Hello
		// str을 r-value로 취급 => move semantics
		// push_back 안에서 동적 할당을 하기 때문에 move semantics가 가능한 것?
		// 보이는 것은 r-value이지만? 포인터로 보내는 것인가?
		v.push_back(std::move(str));
		// str에 있던 것이 move가 된 것
		std::cout << str << std::endl;					// 
		std::cout << v[0] << " " << v[1] << std::endl;	// Hello Hello
	}

	{
		// std::string에 대해서도 작동
		std::string	x{ "abc" };
		std::string	y{ "de" };

		std::cout << "x: " << x << std::endl;	// x : abc
		std::cout << "y: " << y << std::endl;	// y : de
		MySwap(x, y);
		std::cout << "x: " << x << std::endl;	// x : de
		std::cout << "y: " << y << std::endl;	// y : abc
	}

	return (0);
}

// 스마트 포인터라는 큰 개념 안에 유니크 포인터, 쉐어드 포인터
// 유니크 포인터를 사용하려면 move semantics가 구현이 되어 있어야 함
// 스마트 포인터는 주소를 잃어버려도 leak이 나지 않게 하는 목적으로 설계?