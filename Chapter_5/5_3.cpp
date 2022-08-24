// 5.3 switch-case

// if문과 비슷하게 조건을 다룸
// 특별한 경우에 if문보다 간결하고 깔끔하게 정리할 수 있음

#include <iostream>

// -std=c++11로 실행
enum class Colors
{
	BLACK,
	WHITE, 
	RED,
	GREEN,
	BLUE,
};

void	printColorName(Colors color)
{
	if (color == Colors::BLACK)
		std::cout << "BLACK" << std::endl;
	else if (color == Colors::WHITE)
		std::cout << "WHITE" << std::endl;
	else if (color == Colors::RED)
		std::cout << "RED" << std::endl;
	else if (color == Colors::GREEN)
		std::cout << "GREEN" << std::endl;
	else if (color == Colors::BLUE)
		std::cout << "BLUE" << std::endl;

	switch (color)
	{
		case Colors::BLACK:
			std::cout << "BLACK" << std::endl;
			break ;
		case Colors::WHITE:
			std::cout << "WHITE" << std::endl;
			break ;
		case Colors::RED:
			std::cout << "RED" << std::endl;
			break ;
		case Colors::GREEN:
			std::cout << "GREEN" << std::endl;
			break ;
		case Colors::BLUE:
			std::cout << "BLUE" << std::endl;
			break ;
	}

	// ()과 case의 type을 맞춰야 함
	switch (static_cast<int>(color))
	{
		case 0:
			std::cout << "BLACK" << std::endl;
			break ;
		case 1:
			std::cout << "WHITE" << std::endl;
			break ;
		case 2:
			std::cout << "RED" << std::endl;
			break ;
		case 3:
			std::cout << "GREEN" << std::endl;
			break ;
		case 4:
			std::cout << "BLUE" << std::endl;
			break ;
	}

}

int main()
{
	printColorName(Colors::BLUE);

	int	x;

	std::cin >> x;
	// break를 넣지 않는 경우, 해당 case 아래로 계속 실행
	// 의도적으로 break를 실행하지 않는 경우도 있음 : 아래로 계속 실행을 하고 싶은 경우
	switch (x)
	{
		case 0:
			std::cout << "Zero" << std::endl;
			break ;
		case 1:
			std::cout << "One" << std::endl;
			break ;
		case 2:
			std::cout << "Two" << std::endl;
			break ;
		default:
			std::cout << "undefined input" << std::endl;
	}

	switch (x)
	{
		// 선언은 가능
		int a;
		// note: jump bypasses variable initialization
		// 메모리 할당이 불가능
		// int b = 5;
		int b;

		case 0:
			// 선언은 여기에 했어도 case 밖에 선언한 것과 같음
			// case를 블록으로 감싸면 이러한 문제 해결 가능 => 블록 안으로 스코프 제한
			int	c;

			// 할당은 case 안에서 가능
			b = 5;
			std::cout << b << std::endl;
			std::cout << "Zero" << std::endl;;
			break ;
		case 1:
			std::cout << "One" << std::endl;
			
			std::cout << c << std::endl;	// -1301544959
			break ;
		case 2:
			std::cout << "Two" << std::endl;
			break ;
		// ...
	}

	return (0);
}