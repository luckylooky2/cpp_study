// 3.5 관계 연산자

#include <iostream>
#include <cmath>

int main()
{
	int x, y;

	// while (true)
	// {
	// 	// "1 2"와 "1 \n 2 \n"가 같은 결과
	// 	std::cin >> x >> y; 
	// 	std::cout << "Your input values are : " << x << " " << y << std::endl;	// 1 2

	// 	if (x == y)
	// 		std::cout << "equal" << std::endl;
	// 	if (x != y)
	// 		std::cout << "Not equal" << std::endl;
	// 	if (x > y)
	// 		std::cout << "x is greater than y" << std::endl;
	// 	if (x < y)
	// 		std::cout << "x is less than y" << std::endl;
	// 	if (x >= y)
	// 		std::cout << "x is greater than or equal to y" << std::endl;
	// 	if (x <= y)
	// 		std::cout << "x is less than or equal to y" << std::endl;
	// }

	// 부동소수점끼리 비교할 때 문제가 발생
	double	d1(100 - 99.99);	// 0.001
	double	d2(10 - 9.99);		// 0.001

	if (d1 == d2)
		std::cout << "equal" << std::endl;
	else
	{
		std::cout << d1 << " " << d2 << std::endl;		// 0.01 0.01
		std::cout << "Not equal" << std::endl;			// Not equal

		if (d1 > d2)
			std::cout << "d1 > d2 " << std::endl;		// d1 > d2
		else
			std::cout << "d1 < d2 " << std::endl;

		// 수치해석학 : 수치 최적화 등...
		// 결과가 다르다고 나왔으나, 그 차이는 크지 않음

		std::cout << std::abs(d1 - d2) << std::endl;	//5.32907e-15
	}

	const double	epsilon = 1e-10;
	
	if (std::abs(d1 - d2) < epsilon)
		std::cout << "Approximately equal" << std::endl; // Approximately equal
	else
		std::cout << "Not equal" << std::endl;

	return (0);
}