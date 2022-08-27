// 6.5 정적 다차원 배열

// 프로그래밍을 하다보면 좌표처럼 다차원 데이터를 다룰 때도 있음
// 1차원의 메모리를 다차원처럼 사용할 수 있게 해주는 것이 다차원 배열

#include <iostream>

int	main()
{
	const int	num_rows = 3;
	const int	num_cols = 5;

	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_cols; col++)
			std::cout << '[' << row << ']' << '[' << col << ']' << '\t';
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// row-major => 수학적으로 어떻게 사용할 것인가의 개념적 문제
	// C++ 11 : '='를 생략한 uniform initialization도 가능
	// num_rows는 생략 가능하지만, num_cols는 생략 불가능
	int	array[num_rows][num_cols] =
	{
		{1, 2, 3, },			// row 0
		{6, 7, 8, 9, 10},		// row 1
		{11, 12, 13, 14, 15}	// row 2
	};

	// 값 출력
	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_cols; col++)
			std::cout << array[row][col] << '\t';
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// 주소 출력 => 연속된 메모리
	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_cols; col++)
			std::cout << &array[row][col] << '\t';
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// 이런 방법으로 삼차원 배열도 생성
	int	array[5][4][3];

	// 연습 문제 : 행렬 * 벡터, 행렬 * 행렬을 다차원 배열을 이용해 계산

	return (0);
}