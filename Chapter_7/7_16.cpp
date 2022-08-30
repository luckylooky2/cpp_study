// 7.16 생략부호 Ellipsis

// 매개변수 개수가 정해져있지 않은 경우

#include <iostream>
#include <cstdarg>

double	findAverage(int count, ...)
{
	double	sum = 0;
	va_list	list;

	va_start(list, count);
	for (int arg = 0; arg < count; arg++)
		// 어떤 타입으로 받을 건지 미리 정해야 함
		sum += va_arg(list, int);
	va_end(list);
	
	return (sum / count);
}

int	main()
{
	std::cout << findAverage(1, 1, 2, 3, "hello", 'c') << std::endl;	// 1
	std::cout << findAverage(3, 1, 2, 3) << std::endl;					// 2
	std::cout << findAverage(5, 1, 2, 3, 4, 5) << std::endl;			// 3
	// 인자 개수가 다르면 의도치 않은 결과가 나옴
	std::cout << findAverage(10, 1, 2, 3, 4, 5) << std::endl;			// -5.26632e+08

	return (0);
}