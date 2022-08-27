// 6.2 배열의 기초적인 사용법 2

#include <iostream>

// 배열을 함수의 파라미터로 사용할 수 있음
// 파라미터로 사용하는 배열은 배열이 아니고 문법상 포인터 변수
// => 단순히 배열을 받으려고 사용한다는 의미
void	doSomething(int students_score[20])
{
	// 배열 변수와 &배열 변수의 주소 값이 다름
	// why? 배열 변수가 아니라 포인터이기 때문
	std::cout << students_score << std::endl;			// 0x16dbbb438
	std::cout << &students_score << std::endl;			// 0x16fb6b3f8
	// warning: sizeof on array function parameter will return 
	// size of 'int *' instead of 'int [20]' [-Wsizeof-array-argument]
	std::cout << sizeof(students_score) << std::endl;	// 8
	std::cout << students_score[0] << std::endl;		// 1
	std::cout << students_score[1] << std::endl;		// 2
	std::cout << students_score[2] << std::endl;		// 3
}

int main()
{
	const int	num_students = 20;
	int			students_score[num_students] = {1, 2, 3, 4, 5, };

	// 배열 : 배열 변수와 &배열 변수의 주소가 같음
	std::cout << students_score << std::endl;			// 0x16dbbb438
	std::cout << &students_score << std::endl;			// 0x16dbbb438
	std::cout << sizeof(students_score) << std::endl;	// 80
	// 배열 변수 자체는 배열의 첫 번째 요소의 주소
	std::cout << &(students_score[0]) << std::endl;		// 0x16dbbb438
	std::cout << &(students_score[1]) << std::endl;		// 0x16dbbb43c
	std::cout << &(students_score[2]) << std::endl;		// 0x16dbbb440
	std::cout << &(students_score[3]) << std::endl;		// 0x16dbbb434

	doSomething(students_score);

	return (0);
}