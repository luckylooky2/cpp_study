// 7.5 다양한 반환 값들(값, 참조, 주소, 구조체, 튜플)

#include <iostream>
#include <array>
#include <tuple>

// int, double 2개의 리턴 값을 받고 싶음
// 사용자 정의 자료형처럼 쓰임
std::tuple<int, double>	getTuple()
{
	int		a = 10;
	double	d = 3.14;

	return (std::make_tuple(a, d));
};

struct	Alpha
{
	int a, b, c, d;
};

Alpha	getStruct()
{
	Alpha	my_alpha = {1, 2, 3, 4};
	
	return (my_alpha);
}

// return by value
// 장점 : 간단, 안전
// 단점 : 복사, 변수 생성 등이 여러 번 일어남, 성능 손실
int	getValue(int x)
{
	int	value = x * 2;
	
	return (value);
}

// return by address
int	*getPointer(int x)
{
	int	value = x * 2;
	
	// 사라질 변수의 주소값을 주는 것은 위험 => 의도와 다른 결과가 나올 수 있음
	// warning: address of stack memory associated with local variable 'value' returned
	return (&value);
}

// 메모리를 생성하고 그 메모리의 포인터를 함수의 리턴값으로 돌려받는 패턴
// 디자인 패턴 중 factory pattern(공장 패턴)
int	*allocateMemory(int size)
{
	return (new int[size]);
}

// return by reference
int	&getReference(int x)
{
	int	value = x * 2;

	// 리턴할 때는 reference인지 value인지 구분이 안 감
	// 리턴 타입을 보고 판단 => 실수할 가능성이 큼
	// warning: reference to stack memory associated with local variable 'value' returned
	return (value);
}

int	&get(std::array<int, 100> &my_array, int i)
{
	return my_array[i];
}

int	main()
{
	// return by value
	int	value = getValue(3);	// 6
	// return by address
	int	*ptr = getPointer(5);

	std::cout << *ptr << std::endl;		// 10

	int	*array = allocateMemory(1024);
	
	// 동적 할당과 해제를 분리하는 것은 이해를 힘들게 함
	delete [] array;

	// return by reference
	// 안전 : reference 반환 => reference가 가리키고 있는 변수의 값이 val로 복사
	int	val = getReference(10);
	// 안전하지 않음 : ref는 이미 함수의 지역 변수로 반납한 변수를 가리킴
	int	&ref = getReference(10);

	std::cout << val << std::endl;				// 20
	std::cout << ref << std::endl;				// -1767237792

	// reference를 편하게 사용하는 경우
	std::array<int, 100>	my_array;

	my_array[30] = 10;
	// reference로 리턴 => my_array[30]과 같은 형태가 됨
	// 이런 패턴으로 사용하는 경우가 엄청 많음
	// reference를 보내줘서 변수처럼 편리하게 작업할 수 있게 함
	get(my_array, 30) = 1024;
	std::cout << my_array[30] << std::endl;			// 1024

	// 여러 변수를 리턴하고 싶을 때
	// 1. 구조체
	// 단점 : 함수 하나를 만들 때마다, 구조체를 하나씩 만들어야 함 => 구현 overhead가 큼
	Alpha					my_alpha = getStruct();
	// 2. 튜플
	// C++ 11
	std::tuple<int, double>	my_tp = getTuple();

	std::cout << std::get<0>(my_tp) << std::endl;	// 10
	std::cout << std::get<1>(my_tp) << std::endl;	// 3.14

	// C++ 17
	auto	[a, d] = getTuple();

	std::cout << a << std::endl;					// 10
	std::cout << d << std::endl;					// 3.14

	return (0);
}