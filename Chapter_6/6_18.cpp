// 6.18 void 포인터

#include <iostream>

enum Type
{
	INT,
	FLOAT,
	CHAR,
};

int	main()
{
	int		i = 5;
	char	c = 'a';
	float	f = 3.0;
	// generic pointer(모든 자료형을 다룰 수 있기 때문에)
	void	*ptr = nullptr;
	Type	type = FLOAT;

	// void 포인터에 담는 순간, 해당 자료형이 어떤 것인지 알 방법이 없음
	ptr = &i;
	ptr = &c;
	ptr = &f;

	std::cout << &ptr << std::endl;		// 0x16cf53478
	// error: arithmetic on a pointer to void
	std::cout << ptr + 1 << std::endl;
	// warning: ISO C++ does not allow indirection on 
	// operand of type 'void *' [-Wvoid-ptr-dereference]
	std::cout << *ptr << std::endl;
	// casting
	// 다형성 구현을 하다보면, 부득이하게 이렇게 해야 할 때가 있음
	std::cout << *(static_cast<float *>(ptr)) << std::endl;

	if (type == INT)
		std::cout << *(static_cast<int *>(ptr)) << std::endl;
	else if (type == FLOAT)
		std::cout << *(static_cast<float *>(ptr)) << std::endl;
	else if (type == CHAR)
		std::cout << *(static_cast<char *>(ptr)) << std::endl;
	
	return (0);
}