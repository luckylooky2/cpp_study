// 14.1 예외 처리의 기본

// 정상적인 상황에서도 잘 작동할 뿐만 아니라, 비정상적인 상황에서도 잘 작동하는
// 프로그램을 만드는 것이 좋은 프로그래머

// throw, try, catch가 아래와 같은 패턴을 대체하려는 것은 아님
// 문법적으로 깔끔해보이는 장점
// 퍼포먼스가 느려질 가능성이 있음에 주의
// 예외가 발생하지 않는다면, 성능에는 큰 차이가 없음
// 하지만 예외 처리가 발생한다면 throw를 하는 과정에서 성능이 하락함
// 특정 로직을 반드시 수행해야 하는 경우에는 (ex. 파일 입력)
// 예외 처리보다는 일반적인 패턴으로 처리하는 것이 보통
// 분야에 따라 예외 처리를 쓰지 않는 곳도 있고, 많이 처리를 해야 하는 곳도 있음

// 그럼 예외 처리는 언제 사용?
// 예측할 수 없는 일이 빈번하게 발생하는 경우
// ex. 게임 서버 등.. => 갑자기 게임을 꺼버리는 예측할 수 없는 상황
// 그래도 게임 서버는 작업을 지속해야 함

// try
// 문제 여지가 생길 만한 부분 => 잘 되면 계속 작동
// catch
// 던져진 에러를 받아서 처리함
// throw
// 이상한 행위가 발생하면 throw를 해서 예외를 던짐?

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// 함수를 만들었을 때, 제대로 동작하는지를 확인하기 위한 방법
// 함수의 입력으로 잘 동작할지 예측해 볼 수 있음
// 방법 1. assert() : 컴파일타임에 확인
int	findFirstChar(const char *string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); index++)
		if (string[index] == ch)
			return (index);
	// 모든 예외상황에 대한 처리를 -1
	// => 함수를 호출한 쪽에서 -1이 반환될 경우 처리를 해줘야하는 것이 약간 불편
	return (-1);	// no match
}

double	divide(int x, int y, bool &success)
{
	if (y == 0)
	{
		success = false;
		return (0.0);
	}
	// flag 역할을 하는 success 변수를 가지고 판단
	success = true;
	return (static_cast<double>(x) / y);
}

int	main()
{
	bool	success;
	double	result = divide(5, 3, success);

	if (!success)
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	std::ifstream	input_file("temp.txt");
	
	// 흔히 사용되는 패턴
	// pointer 초기화 여부로 체크하는 경우가 많음
	// 보기에 깔끔하지 않지만 사용하는 이유
	// 1. 퍼포먼스적 측면
	// 2. 대체할 수 있는 문법이 없었기 때문
	if (!input_file)
		std::cerr << "Cannot open file" << std::endl;
	
	// throw, try, catch
	double	x;
	std::cin >> x;

	try
	{
		// 예외가 발생하면 에러 메시지를 날려줌
		// 예외 처리는 타입 캐스팅에 매우 엄격함
		if (x < 0.0)
			throw (std::string("Negative input"));
			// 런타임 에러
			// libc++abi: terminating with uncaught exception of type char const*
			// throw ("Negative input");
		std::cout << std::sqrt(x) << std::endl;
	}
	// 에러 메시지를 잡음
	catch (std::string error_message)
	{
		std::cerr << error_message << std::endl;
	}

	try
	{
		throw (-1);							// Catch integer -1
		// throw (-1.0);						// Catch double -1
		// throw ("My error message ");			// Char * My error message 
	}
	catch (int x)
	{
		std::cerr << "Catch integer " << x << std::endl;
	}
	catch (double x)
	{
		std::cerr << "Catch double " << x << std::endl;
	}
	catch (const char *error_message)
	{
		std::cerr << "Char * " << error_message << std::endl;
	}
	
	return (0);
}