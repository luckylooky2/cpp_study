// 6.14 참조 변수

// reference
// reference 변수가 특정 변수와 같은 변수인 것처럼 동작
// 일종의 별명이라고 생각하면 됨
// 반드시 초기화가 되어야 함 => 원래 이름이 있어야 별명도 존재
// r-value(리터럴)이 아닌 l-value만 들어갈 수 있음
// 레퍼런스도 내부적으로는 포인터로 구현이 되어 있음
// 객체 지향 코드 구현에 많이 사용

// "가능하면 참조자를 쓰고, 어쩔 수 없다면 포인터를 써라"
// 매개변수에 NULL 포인터를 넘겨주는 것 or 리턴값으로 NULL 포인터를 반환하는 것이 허용될 경우, 포인터를 사용해야 한다.
// 참조자는 선언과 동시에 초기화 되어야해서 NULL이 허용되지 않기 때문이다.
// & 나 * 와 같은 연산자를 쓰지 않아 코드가 깔끔해진다.
// https://woo-dev.tistory.com/43
// 결국 레퍼런스는 포인터를 위험하게 사용하는 경우가 많기 때문에 안전하게 사용할 수 있도록 만든 개념이다.
// 포인터와 같이 주소를 통해 원본에 접근하는 핵심적인 기능을 가졌지만, 
// 가리키는 대상, 원본, 주소를 변경하지 못하게 막은 것이라고 볼 수 있다.
// 1. 기본적으로 포인터는 주소를 가리키지만 다음과 같이 널을 가리킬 수도 있다.
// => 유효하지 않는 공간을 가리키게 되면 당연히 에러를 발생시키며 프로그램에 문제를 줄 수 있다.
// 2. 그런데 포인터가 강력한 이유는 전달 받은 주소에 덧셈뺄셈하면서 다음과 같이 다른 주소에도 자유롭게 접근이 가능하다는 것이다.
// 이 말은 반대로 생각하면 포인터를 통해 할당되지 않은 메모리 공간 또는 
// 다른 용도로 사용되고 있는 메모리 공간에 임의로 접근할 수 있다는 의미이다.

#include <iostream>

struct Something
{
	int		v1;
	float	v2;
};

struct Other
{
	Something st;
};


void	doSomethingVariable(int n)
{
	// 변수 주소가 다름
	std::cout << &n << std::endl;	// 0x16af633ec
	n = 10;
	std::cout << "In doSomethingVariable " << n << std::endl;
}

// 함수 안에서 값을 못 바꾸게 하고 싶을 때는 파라미터에 const 키워드
// 예전에는 return을 하나 밖에 못했기 때문에
// 파라미터에 포인터, 레퍼런스를 전달해 여러 개를 return하는 간접적 효과로 구현
// C++ 17부터는 return을 여러 개하는 것이 어렵지 않아
// 함수가 파라미터를 수정하지 않는 방식이 인기가 있음
void	doSomethingReference(int &n)
{
	// 변수 주소가 같음 => 변수 자체가 넘어감
	// 복사하지 않아도 되어 효율이 더 좋음
	std::cout << &n << std::endl;	// 0x16af6343c
	n = 10;
	std::cout << "In doSomethingReference " << n << std::endl;
}

void	printElements(const int (&arr)[5])
{
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int	main()
{
	int	value = 5;
	int	*ptr = nullptr;

	ptr = &value;

	// ref가 value와 같은 변수(메모리)인 것처럼 작동
	// value의 별명(또 다른 이름)처럼 사용
	int	&ref = value;

	// 포인터와 비슷하게 작동하나 *을 붙여줄 필요없이 문법적으로 깔끔
	ref = 10;
	std::cout << ref << std::endl;		// 10
	std::cout << value << std::endl;	// 10
	// 주소까지 같음
	std::cout << &ref << std::endl;		// 0x16d6e7488
	std::cout << &value << std::endl;	// 0x16d6e7488
	std::cout << ptr << std::endl;		// 0x16d6e7488
	std::cout << &ptr << std::endl;		// 0x16d6e7480

	int			x = 5;
	int			&ref_x = x;
	const int	y = 8;
	// error: binding reference of type 'int' to value of 
	// type 'const int' drops 'const' qualifier
	// ref_y에서 y의 값을 마음대로 바꿀 수 있기 때문에
	// int		&ref_y = y;
	const int	&ref_y = y;

	int	value1 = 5;
	int	value2 = 10;
	int	&ref1 = value1;

	std::cout << ref1 << std::endl;		// 5
	ref1 = value2;
	std::cout << ref1 << std::endl;		// 10

	int	n = 5;

	std::cout << &n << std::endl;	// 0x16af6343c
	doSomethingVariable(n);
	std::cout << n << std::endl;	// 5
	doSomethingReference(n);
	std::cout << n << std::endl;	// 10

	const int	length = 5;
	int			arr[length] = {1, 2, 3, 4, 5};

	printElements(arr);

	Other	ot;
	// 긴 참조를 단순화할 수 있음
	// &를 붙이지 않게 되면 새로운 변수를 생성(연동되지 않음)
	int		&refot = ot.st.v1;

	ot.st.v1 = 1;
	std::cout << ot.st.v1 << std::endl;	// 1
	refot = 2;
	std::cout << refot << std::endl;	// 2

	// 기능 상 동일
	int *const	ptr_i = &value;
	const int	&ref_i = value;
	// error: 'const' qualifier may not be applied to a reference
	int	&const	ref_j = value;

	// error: cannot assign to variable 'ptr_i' with 
	// const-qualified type 'int *const'
	ptr_i = &length;
	// error: cannot assign to variable 'ref_i' with 
	// const-qualified type 'const int &'
	ref_i = length;

	return (0);
}