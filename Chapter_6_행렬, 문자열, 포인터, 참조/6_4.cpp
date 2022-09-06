// 6.4 배열과 선택 정렬

// 선택 정렬
// 해당 숫자와 뒤에 나오는 가장 작은 숫자와 바꾸는 방식
// 큰 숫자가 뒤로 밀리는 방식
// 3 5 2 1 4
// 1 5 2 3 4
// 1 2 5 3 4
// 1 2 3 5 4
// 1 2 3 4 5 

#include <iostream>

void	printArray(const int array[], const int length)
{
	for (int i = 0; i < length; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void	swap(int *a, int *b)
{
	int	temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int	main()
{
	const int	length = 5;
	int			array[length] = {3, 5, 2, 1, 4};
	int			smallest;

	printArray(array, length);
	// 선택 정렬
	for (int i = 0; i < length - 1; i++)
	{
		smallest = i;
		for (int j = i + 1; j < length; j++)
			if (array[smallest] > array[j])
				smallest = j;
		// std::swap()을 사용하는 방법도 있음
		swap(&array[i], &array[smallest]);
		printArray(array, length);
	}

	return (0);
}