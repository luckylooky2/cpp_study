// 6.21 std::vector 소개

// 동적 배열을 대체할 수 있는 쉬운 자료형

#include <iostream>
#include <vector>

int	main()
{
	// delete를 해주지 않아도 됨
	std::vector<int>	array;
	std::vector<int>	array2 = {1, 2, 3, 4, 5};
	std::vector<int>	array3 = {1, 2, 3};
	std::vector<int>	array4 = {1, 2};

	std::cout << array.size() << std::endl;		// 0
	std::cout << array2.size() << std::endl;	// 5
	std::cout << array3.size() << std::endl;	// 3
	std::cout << array4.size() << std::endl;	// 2

	for (int &element : array2)
		std::cout << element << " ";
	std::cout << std::endl;

	array4.resize(10);
	std::cout << array4.size() << std::endl;	// 10
	array2.resize(2);
	array2.resize(10);
	std::cout << array2.at(3) << std::endl;		// 0

	return (0);
}