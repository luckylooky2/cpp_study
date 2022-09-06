// 6.1 배열의 기초적인 사용법 1

#include <iostream>

#define NUM_STUDENTS	1000000

struct Rectangle
{
	int length;
	int width;
};

// 권장하지는 않음 : 몇 명이 될지 모름
enum	StudnetName
{
	JACKJACK,
	DASH,
	VIOLET,
	// 따로 세주지 않아도 되어 편함
	NUM_STUDENTS,
};

int main()
{
	int	student1_score;	// jackjack
	int	student2_score;	// dash
	int	student3_score;	// violet
	// 연속적인 메모리를 빌려옴
	int	students_score[NUM_STUDENTS];	// 3 int
	// initialization
	int	my_array[5] = {1, 2, 3, };		// 20
	// C++ 11
	int	my_array[] {1, 2, 3, };			// 12

	std::cout << sizeof(students_score) << std::endl;	// 12
	// 대부분의 프로그래밍 언어는 0번째부터 시작함
	students_score[JACKJACK] = 100;		// 1st element
	students_score[DASH] = 80;			// 2nd element
	students_score[VIOLET] = 90;		// 3rd element
	// OS의 허락없이 메모리를 사용
	students_score[5] = 30;				// 6th element

	Rectangle	rect_arr[10];

	std::cout << sizeof(rect_arr) << std::endl;	// 80

	int	num_students = 0;

	// 런타임에 결정
	std::cin >> num_students;

	// 컴파일 타임에 결정이 되어 있어야 함 => error
	// size가 고정이 된 array에는 사용할 수 없음
	// 1. C에서는 충분히 큰 수를 이용해 매크로로 설정
	// 2. 동적 할당을 이용
	int students_height[num_students];
	int students_height[NUM_STUDENTS];
	
	return (0);
}