// 7.4 주소에 의한 인수 전달 call by address

// call by address
// 실용적인 면에서는 call by reference를 쓰는 것이 더 나음
// cf> foo(&value) => call by reference로 착각할 수 있음!
// 결국 call by address도 call by value와 크게 다르지 않음

#include <iostream>

typedef int*	pint;

// 주소라는 값을 값에 의해 전달(call by value, 주소값이 복사가 될 뿐)
// 포인터 변수도 변수
void	foo(int *ptr)
{
	int	x = 5;

	std::cout << *ptr << " " << ptr << " " << &ptr << std::endl;
	*ptr = 10;
	// ptr은 지역 변수이기 때문에 함수 밖에 영향이 없음
	// 그렇기 때문에 int *const로 사용하기도 함
	ptr = &x;
}

int	main()
{
	int	value = 5;
	int	*ptr = &value;

	std::cout << value << " " << &value << " " << &ptr << std::endl;	// 5 0x7ffeed36c818 0x7ffeed36c810
	foo(ptr);															// 5 0x7ffeed36c818 0x7ffeed36c7e8
	foo(&value);														// 5 0x7ffeed36c818 0x7ffeed36c7e8
	// 리터럴 불가
	// foo(5);
	std::cout << value << " " << &value << " " << &ptr << std::endl;	// 10 0x7ffeed36c818 0x7ffeed36c810
	return (0);
}