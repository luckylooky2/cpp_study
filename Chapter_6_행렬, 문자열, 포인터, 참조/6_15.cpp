// 6.15 참조와 const

// 함수의 파라미터로 참조를 사용할 때 편함

#include <iostream>

// 변수 복사가 일어나지 않음
void	doSomething(const int &x)
{
	std::cout << x << std::endl;
}

int	main()
{
	// 가능
	int			x = 5;
	int			&ref_x = x;
	// 가능 => ref_x의 값을 바꿀 수 없음
	int			x = 5;
	const int	&ref_x = x;
	// 불가능 => ref_x에서 x의 값을 마음대로 바꿀 수 있기 때문에
	const int	x = 5;
	int			&ref_x = x;
	// 가능
	const int	x = 5;
	const int	&ref_x = x;
	const int	&ref_x2 = ref_x;

	// reference 변수에는 l-valeu(리터럴)을 할당할 수 없지만
	int			&ref_y = 5;
	// const reference 변수에는 리터럴 할당 가능
	const int	&ref_y = 3 + 4;
	// 차이는 무엇인가? 성능 측면?
	const int	var_y = 3 + 4;
	
	// error: cannot assign to variable 'ref_y' with 
	// const-qualified type 'const int &'
	// 6_14.cpp 참고
	ref_y = var_y;
	std::cout << ref_y << std::endl;	// 7
	std::cout << &ref_y << std::endl;	// 0x16b22f47c

	int	a = 1;

	// 원래 가능
	doSomething(a);
	// const reference라면 argument로 리터럴을 사용할 수 있음
	doSomething(1);
	doSomething(a + 3);
	doSomething(3 * 4);

	return (0);
}