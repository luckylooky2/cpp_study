// 4.7 열거형

#include <iostream>

// 역시 사용자 정의 자료형
enum Color
{
	COLOR_BLACK = -3,
	COLOR_RED,
	COLOR_BLUE = 5,
	COLOR_GREEN,
	COLOR_SKYBLUE,
};

// 전역처럼 작동하기 때문에 enum간 중복 x
// 같은 enum에서 값이 겹치지 않게 주의
enum Feeling
{
	HAPPY,
	JOY,
	TIRED,
	BLUE,
};

int	computeDamage(int weapon_id)
{
	// 무기와 번호의 매칭이 특별한 의미가 없어 실수할 가능성
	// 열거형을 이용
	if (weapon_id == 0) // sword
		return (1);
	else if (weapon_id == 1) // hammer
		return (2);
	return (0);
}

int main()
{
	computeDamage(1);

	Color	paint = COLOR_BLACK;
	Color	house(COLOR_BLUE);
	// Color	apple{COLOR_RED};

	std::cout << house << std::endl;	// 5

	int 	color_id = COLOR_RED;
	// 불가 : 이렇게 안 쓰려고 만든 것
	// int 자료형과 100% 호환이 되지는 않음
	Color	my_color = 3;
	// 가능
	Color	my_color = static_cast<Color>(3);

	std::cout << color_id << std::endl;	// -2

	// 불가
	std::cin >> my_color;

	int	number;
	
	std::cin >> number;
	if (number == COLOR_BLACK)
		my_color = COLOR_BLACK;

	return (0);
}