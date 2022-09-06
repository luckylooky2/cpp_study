// 6.20 std::array 소개

#include <iostream>
#include <array>

// array가 복사가 되기 때문에 reference를 사용하면 효율적
void	printLength(const std::array<int, 5> &my_arr)
{
	std::cout << my_arr.size() << std::endl;
}

void	printArray(const std::array<int, 5> &my_arr)
{
	// For-each문 가능
	for (auto &element : my_arr)
		std::cout << element << " ";
	std::cout << std::endl;
}

int	main()
{
	int					new_array[5] = {1, 2, 3, 4, 5};
	std::array<int, 5>	my_arr = {1, 32, 3, 14, 5};

	// 무조건 접근
	std::cout << my_arr[0] << std::endl;		// 1
	// 접근할 수 없는 메모리면 예외 처리를 발생시킴
	std::cout << my_arr.at(0) << std::endl;		// 1
	std::cout << my_arr.size() << std::endl;	// 5
	printLength(my_arr);						// 5
	
	printArray(my_arr);							// 1 32 3 14 5 
	std::sort(my_arr.begin(), my_arr.end());
	printArray(my_arr);							// 1 3 5 14 32 
	std::sort(my_arr.rbegin(), my_arr.rend());
	printArray(my_arr);							// 32 14 5 3 1 

	return (0);
}