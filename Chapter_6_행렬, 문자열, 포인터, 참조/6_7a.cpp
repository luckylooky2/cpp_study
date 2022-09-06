// 6.7a 널 포인터

// NULL pointer
// 포인터의 위험성
// 쓰레기 주소값이 들어있을 때 de-referencing 시도하는 경우, 에러가 발생할 수 있음
// 이러한 문제를 방지하기 위해 사용되는 포인터

#include <iostream>
#include <cstddef>

void	doSomething(double	*ptr)
{
	if (ptr != nullptr)
	{
		// do something
	}
	else
	{
		// do nothing
	}
}

int main()
{
	double	*ptr_d1 = NULL;		// C style
	double	*ptr_d2 = nullptr;	// modern C++ style

	doSomething(ptr_d2);

	// NULL pointer 밖에 할당하지 못함
	// error: no viable conversion from 'double *' to 'std::nullptr_t'
	std::nullptr_t	nptr = ptr_d1;

	return (0);
}