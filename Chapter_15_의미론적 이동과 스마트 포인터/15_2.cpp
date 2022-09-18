// 15.2 오른쪽-값 참조

// r-value references
// 스마트 포인터를 사용할 때, move semantics를 항상 사용할 수 있는 것은 아님
// move semantics를 사용할 수 있을지 없을지를 판별할 때 r-value references를 사용

#include <iostream>

void	doSomething(int &lref)
{
	// 일반적인 경우 l-value로 move semantics를 사용하면
	// 충돌이 날 가능성이 있음
	std::cout << "l-value ref" << std::endl;
}

void	doSomething(int &&rref)
{
	// r-value로 가져온 경우에는
	// move semantics를 자유롭게 사용해도 됨
	// 어차피 다른 곳에서 사용하지 못하기 때문
	std::cout << "r-value ref" << std::endl;
}

int	getResult()
{
	return (100 * 100);
}

int	main(void)
{
	// 변수 x(l-value)는 메모리 공간을 갖고, 5 자체(r-value)는 문이 끝나면 사라짐
	// x에 5를 복사해서 사용하겠다는 의미
	int			x = 5;
	int			y = getResult();
	const int	cx = 6;
	const int	cy = getResult();

	// l-value reference
	// reference라고 한다면 기본적으로 l-value reference를 의미함
	int	&lr1 = x;	// modifiable l-values
	// 불가
	// int	&lr2 = cx;	// non-modifiable l-values
	// 참조하고 있는 변수가 메모리를 가지고 있는 것이라는 전제 하에 사용하는 것
	// int	&lr3 = 5;	// r-values

	// 모두 가능
	const int	&lr4 = x;	// modifiable l-values
	const int	&lr5 = cx;	// non-modifiable l-values
	const int	&lr6 = 5;	// r-values

	// r-value reference
	// AND 기호와는 전혀 상관 없음
	// r-value만 받을 수 있음 => 사라질 운명인 값을 어딘가에 보관할 수 있게 함
	// 불가
	// int	&&rr1 = x;			// modifiable l-values
	// int	&&rr2 = cx;			// non-modifiable l-values
	// 가능
	int	&&rr3 = 5;				// r-values
	int	&&rrr = getResult();	// r-values

	// 불가
	// const int	&&rr4 = x;	// modifiable l-values
	// const int	&&rr5 = cx;	// non-modifiable l-values
	// 가능
	const int	&&rr6 = 5;	// r-values

	std::cout << rr3 << std::endl;	// 5
	rr3 = 10;
	std::cout << rr3 << std::endl;	// 10

	doSomething(x);				// l-value
	doSomething(5); 			// r-value
	doSomething(getResult()); 	// r-value

	return (0);
}