// 4.8 영역 제한 열거형(열거형 클래스)

// C++ 11
// 열거형의 단점을 보완

#include <iostream>

int main()
{
	enum Color
	{
		RED,
		BLUE,
	};

	enum Fruit
	{
		BANANA,
		APPLE,
	};

	enum class NewColor
	{
		RED,
		BLUE,
	};

	enum class NewFruit
	{
		BANANA,
		APPLE,
	};

	Color		color = RED;
	Fruit		fruit = BANANA;
	NewColor	new_color = NewColor::RED;
	NewFruit	new_fruit = NewFruit::BANANA;

	// 같으면 실수할 가능성이 높아짐
	if (color == fruit)
		std::cout << "equal" << std::endl;		// equal
	else
		std::cout << "Not equal" << std::endl;
	// 비교를 하지 못하게 막아버림
	// 같은 enum class 안에 있는 값끼리는 비교 가능
	if (new_color == new_fruit)
		std::cout << "equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;

	return (0);
}