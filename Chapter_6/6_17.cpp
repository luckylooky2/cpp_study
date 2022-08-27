// 6.17 For-each 반복문

// C++ 11 : 훨씬 간단해진 반복문
// 동적 할당된 array는 For-each문을 사용할 수 없음
// 대신 vector 자료형을 사용할 수 있음

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

int	main()
{
	int					fibonacci[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	std::vector<int>	fibonacci_vector = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

	for (int i = 0; i < (sizeof(fibonacci) / sizeof(int)); i++)
		std::cout << fibonacci[i] << " ";
	std::cout << std::endl;

	// change array values => 함수 파라미터에 들어가는 것과 비슷
	// 변경되지 않음
	for (int number : fibonacci)
		number = 10;

	for (auto &number : fibonacci)
		number = 10;

	for (const int number : fibonacci)
		std::cout << number << " ";
	std::cout << std::endl;

	int	max_number = std::numeric_limits<int>::lowest();

	std::cout << max_number << std::endl;	// -2147483648

	for (const auto &n : fibonacci)
		max_number = std::max(max_number, n);
	std::cout << max_number << std::endl;	// 10

	return (0);
}

