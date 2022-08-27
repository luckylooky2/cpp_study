// 6.19 이중 포인터와 동적 다차원 배열

// 2차원 배열은 행렬 구현할 때 많이 사용

#include <iostream>

int	main()
{
	int	*ptr = nullptr;
	int	**pptr = nullptr;
	int	***ppptr = nullptr;
	int	****pppptr = nullptr;

	int	value = 5;

	ptr = &value;
	pptr = &ptr;

	std::cout << ptr << " " << *ptr << " " << &ptr << std::endl; 	// 0x16d08b464 5 0x16d08b480
	std::cout << pptr << " " << *pptr << " " << &pptr << std::endl;	// 0x16d08b480 0x16d08b464 0x16d08b470
	std::cout << **pptr << std::endl; 								// 5

	const int	row = 3;
	const int	col = 5;
	int			**matrix = new int *[row];

	for (int i = 0; i < row; i++)
		matrix[i] = new int[col];
	
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			matrix[i][j] = i * col + j + 1;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}

	for (int i = 0; i < row; i++)
		delete [] matrix[i];
	delete [] matrix;

	// 연습 문제 : matrix를 1차원 array로 만들어보기

	return (0);
}