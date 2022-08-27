// 6.13 포인터와 const

#include <iostream>

int	main()
{
	// const int *
	// 참조하는 값에 대한 const
	// 가능
	int			value = 0;
	const int	*ptr = &value;
	// 불가능
	// ptr에서 value의 값을 마음대로 바꿀 수 있기 때문에
	const int	value = 0;
	int			*ptr = &value;

	// 1. value assigning => 불가능
	// error: read-only variable is not assignable
	*ptr = 6;
	// 이 경우는 가능
	value = 5;
	// 2. reading =>가능
	std::cout << *ptr << std::endl;		// 5

	int	value2 = 10;

	// 3. address assigning => 가능
	ptr = &value2;
	std::cout << *ptr << std::endl;		// 10

	// int *const
	// 포인터를 상수로 만드는 const => 진정한 의미의 포인터 상수라고 생각
	int	*const ptr2 = &value;

	// 1. value assigning => 가능
	*ptr2 = 10;
	// 2. reading => 가능
	std::cout << *ptr2 << std::endl;	// 10
	// 3. address assigning => 불가능
	// error: cannot assign to variable 'ptr2' with const-qualified type 'int *const'
	ptr2 = &value2;

	// const int *const
	// error: default initialization of an object of const type 'const int *const'
	// 이후에 어떠한 것도 바꾸지 못하기 때문에 반드시 초기화가 필요
	const int *const	ptr3 = &value;

	return (0);
}