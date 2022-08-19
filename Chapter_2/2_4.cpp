// 2.4 무치형 (Void, 보이드)

#include <iostream>

int main()
{
	// void는 메모리를 차지할 수 없기 때문에 다음과 같이 사용이 불가능
	void	my_void_type;

	int		i = 123;
	float	f = 123.456f;

	void	*my_void;

	// &를 붙이면 주소값을 나타냄
	my_void = (void *)&i;
	my_void = (void *)&f;

	// 자료형의 크기는 각각 다를 수 있지만 (1 byte, 4 bytes ...)
	// 자료형의 주소를 표현하는 데이터 양은 동일! => (void *)로 캐스팅이 가능
	// 나중에 (int *), (float *)처럼 바꿔서 사용할 수 있음

	return (0);
}