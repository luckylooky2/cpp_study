// 6.12 동적 할당 배열

// 런타임에 배열의 크기를 결정하고, OS로부터 메모리를 받아오기 때문에
// 좀 더 유동적으로 사용할 수 있음

#include <iostream>

int	main()
{
	// 정적 할당
	int	length = 5;
	int	array[length];
	
	std::cin >> length;
	// 동적 할당
	// 전부 0으로 초기화하고 싶다 => ()
	// uniform initialization은 가능 => {1, 2, 3, }
	int	*new_array = new int[length]();

	array[0] = 1;
	array[1] = 2;

	for (int i = 0; i < length; i++)
		std::cout << (uintptr_t)&array[i] << " " << array[i] << std::endl;

	// 반드시 동적 할당 해제
	// warning: 'delete' applied to a pointer that was allocated with 'new[]';
	// did you mean 'delete[]'? [-Wmismatched-new-delete]
	delete [] new_array;

	// 가능
	int	*array_1 = new int[5] {1, 2, 3, 4, 5};
	int	*array_2 = new int[] {1, 2, 3, 4, 5};
	// 불가능
	// error: excess elements in array initializer
	int	*array_3 = new int[3] {1, 2, 3, 4, 5};

	// resizing
	// 1. 더 큰 메모리를 동적 할당하고, 기존 데이터 복사 + 새로운 데이터 추가
	// 2. OS에게 메모리 요청을 할 때, 3칸을 유지하면서 2칸을 더 줄 수 있는지 요청
	// 3. vector 자료형을 이용
	
	return (0);
}