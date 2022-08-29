// 7.1 매개변수와 인자의 구분

#include <iostream>

int foo(int x, int y);

// x와 y는 함수가 종료될 때 사라짐(지역 변수)
// x, y : parameters => 인자가 전달됨
int foo(int x, int y)
{
	return (x + y);
}

int	main()
{
	int x = 1, y = 2;

	foo(6, 7);		// 6, 7 : arguments (acutal parameters)
	// 항상 값만 전달되는 것은 아님
	// 값에 의한 전달, 참조에 의한 전달, 주소에 의한 전달이 가능
	foo(x, y +1);

	return (0);
}