// 6.8 포인터와 정적 배열

// 결론 : 포인터와 정적 배열은 같음

#include <iostream>

struct MyStruct
{
	int	array[5] = {9, 7, 5, 3, 1};
};

void	printArray(int array[])
{
	// 파라미터가 array처럼 보이지만 복사된 포인터
	std::cout << sizeof(array) << std::endl;		// 8
	std::cout << *array << std::endl;				// 9
	std::cout << *(array + 1) << std::endl;			// 7
	// C : 함수 안에서 값을 바꾸기 위해 포인터를 많이 사용
	// C++ : 레퍼런스(참조)를 더 많이 사용
	*array = 100;
}

void	printStruct(MyStruct ms)
{
	// array가 struct나 class 안에 정의되어 있을 때는 포인터로 강제 변환이 되지 않음
	std::cout << sizeof(ms.array) << std::endl;		// 20
}

int	main()
{
	int	array[5] = {9, 7, 5, 3, 1};

	std::cout << array[0] << " " << array[1] << std::endl;	// 9 7
	// 사실 정적 배열 식별자는 배열 첫 번째 요소의 주소를 담는 포인터
	std::cout << array << std::endl;						// 0x16d0cb470
	std::cout << *array << std::endl;						// 9
	std::cout << &array[0] << std::endl;					// 0x16d0cb470
	std::cout << sizeof(array) << std::endl;				// 20

	int	*ptr = array;
	
	std::cout << ptr << std::endl;			// 0x16d0cb470
	std::cout << *ptr << std::endl;			// 9
	// 차이점
	std::cout << &ptr << std::endl;			// 0x16d0cb450
	std::cout << sizeof(ptr) << std::endl;	// 8

	char	name[] = "jackjack";

	std::cout << *name << std::endl;	// j

	MyStruct	ms;

	printArray(array);
	std::cout << *array << std::endl;	// 100
	printStruct(ms);

	return (0);
}