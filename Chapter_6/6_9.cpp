// 6.9 포인터 연산과 배열 인덱싱

// 302호를 직접 찾는 것보다 301호의 옆 집처럼 찾는 것이 더 쉬울 수도 있음

#include <iostream>

int	main()
{
	int	value_i = 7;
	// 포인터에 자료형이 필요한 이유 2
	// 포인터 연산을 하기 위해서
	int	*ptr_i = &value_i;

	// int가 4 bytes이기 떄문에 주소가 4만큼 더해짐
	std::cout << uintptr_t(ptr_i - 1) << std::endl;	// 6161331332
	std::cout << uintptr_t(ptr_i) << std::endl;		// 6161331336
	std::cout << uintptr_t(ptr_i + 1) << std::endl;	// 6161331340
	
	double	value_d = 7.0;
	double	*ptr_d = &value_d;

	// double이 8 bytes이기 떄문에 주소가 8만큼 더해짐
	std::cout << uintptr_t(ptr_d - 1) << std::endl;	// 6156563568
	std::cout << uintptr_t(ptr_d) << std::endl;		// 6156563576
	std::cout << uintptr_t(ptr_d + 1) << std::endl;	// 6156563584

	int	array[] = {9, 7, 5, 3, 1};

	// 두 개가 같은 결과
	for (int i = 0; i < 5; i++)
	{
		std::cout << array[i] << " " << (uintptr_t)&array[i] << std::endl;
		std::cout << *(array + i) << " " << (uintptr_t)(array + i) << std::endl;
	}

	char		name[] = "Jack Jack";
	const int	n_name = sizeof(name) / sizeof(char);

	for (int i = 0; i < n_name; i++)
		std::cout << *(name + i);
	std::cout << std::endl;

	// 연습 문제
	// while, break와 포인터 연산을 사용하여 '\0'을 제외한 문자열을 출력
	int		i = 0;
	char	*name_ptr = name;

	while (true)
	{
		std::cout << *(name_ptr++);
		if (*name_ptr == '\0')
			break ;
	}
	std::cout << std::endl;

	return (0);
}