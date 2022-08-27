// 6.7 포인터의 기본적인 사용법

// 포인터
// 메모리 주소를 담는 변수
// C, C++의 중요한 특징 중 하나
// CPU와 메모리가 협력하는 구조를 이해할 수 있음
// 포인터에 자료형이 필요한 이유 1
// 포인터는 규격이 같아 자료형과는 관계가 없지만 int, char를 사용
// de-referencing할 때 읽어야 하는 자료형의 크기를 알아야하기 때문
// 포인터 자체의 크기는 고정, 포인팅하는 자료형은 다름
// 포인터를 사용하는 이유?
// 함수 파라미터로 array를 줄 경우 전체가 복사가 됨 => array가 매우 클 경우 문제
// 포인터로 첫 번째 주소와, 데이터가 몇 개 있다를 알려주면 해결할 수 있음
// 다른 언어도 포인터를 안 쓰는 것처럼 보이지만, 내부적으로는 사용하고 있음

// de-reference operator(*)
// 포인터가 특정 주소를 간접적으로 가리키기만 하는 것에 대해서
// 가리키는 곳에 어떤 값이 있는지 직접적으로 접근하겠다는 의미

#include <iostream>
#include <typeinfo>

struct Something
{
	int 	a;
	int 	b;
	int 	c;
	int 	d;
};

// 파라미터, 리턴 값으로도 포인터 사용 가능
int	* doSomething(int *ptr_a)
{
	return (ptr_a);
}

int	main()
{
	// 변수가 사용할 공간과 주소를 OS로부터 빌려옴
	int	x = 5;

	// 큰 메모리에 저장되어 있는 데이터 중에서 일부분을 CPU가 사용하기 위해 메모리로부터 가져올 때는
	// 메모리 전체를 모두 뒤지면서 찾는 것이 아니라 필요한 데이터가 저장되어 있는 주소를 사용하여 직접 접근하여 가져옴
	std::cout << x << std::endl;	// 5
	// address-of operator(&) : 어떤 변수가 어떤 메모리 주소에 데이터를 담고 있는지 알고 싶을 때
	std::cout << &x << std::endl;	// 0x16f7e7488
	// de-reference operator(*)
	std::cout << *&x << std::endl;	// 5

	// // 문법상 차이는 없지만
	// int 	*ptr_x = &x;
	// int* 	ptr_y = &x;
	// // 아래와 같이 동시에 선언이 되지 않기 때문에 실수를 줄이기 위해 뒤에 붙임
	// int* 	ptr_x = &x, ptr_y = &x;
	// // 방법 1
	// typedef int* pint;
	// pint	ptr_x = &x, ptr_y = &x;
	// // 방법 2
	// int* 	ptr_x = &x, *ptr_y = &x;
	// double	d = 123.0;
	// // 주소값을 직접 할당? 쓰기 어렵기도 하고, 허용을 해주지 않음(다른 방법이 존재하긴 함)
	// // 해킹의 원리 : 다른 프로그램이 사용하고 있는 메모리의 주소를 가져옴
	// // => 다른 프로그램에서 선언한 변수는 아니지만 메모리 주소를 바꿔치기 할 수 있음
	// double	*ptr_d = 0x16f7e7488;

	// std::cout << ptr_x << std::endl;				// 0x16f7e7488
	// std::cout << typeid(ptr_x).name() << std::endl;	// Pi

	Something	str;
	Something	*ptr_str;

	std::cout << sizeof(str) << std::endl;		// 16
	std::cout << sizeof(ptr_str) << std::endl;	// 8

	// 포인팅 대상을 지정하지 않고 사용하는 경우 문제가 생길 수 있음
	// 내 프로그램이 사용하지 않는 주소가 들어가 있을 수 있기 때문(해킹?)
	int	*ptr_z;

	std::cout << *ptr_z << std::endl;

	return (0);
}