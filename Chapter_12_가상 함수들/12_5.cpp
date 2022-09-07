// 12.5 동적 바인딩과 정적 바인딩

// 가상 함수를 이용하는 다형성이 내부적으로 어떻게 작동하는지를 이해하려면
// 동적 바인딩과 정적 바인딩의 차이를 이해하면 됨
// 속도 : 정적 바인딩이 빠름
// 유연함 : 동적 바인딩이 더 유연함
// 게임 엔진처럼 유연하게 변하는 프로그래밍이 필요할 때는 동적 바인딩이 유리

#include <iostream>

int	add(int x, int y) { return (x + y); }
int	subtract(int x, int y) { return (x - y); }
int	multiply(int x, int y) { return (x * y); }

int	main()
{
	int x, y;

	std::cin >> x >> y;

	int	op;

	std::cout << "0 : add, 1 : subtract, 2 : multiply" << std::endl;
	std::cin >> op;

	// static binding(early binding)
	int	result;

	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	// 모든 식별자들이 컴파일타임에 정리가 되어 있을 떄 : 정적 바인딩
	std::cout << result << std::endl;

	// dynamic binding(late binding)
	// 컴파일타임에 func_ptr가 어떤 것이 될지 결정되지 않음
	// func_ptr가 가리키는 주소가 add? subtract? multiply?
	// 어떤 함수의 주소가 될 지 런타임에 결정
	int	(*func_ptr)(int, int) = nullptr;

	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = subtract; break;
	case 2: func_ptr = multiply; break;
	}

	// 값을 구할 때도, func_ptr를 통해 동적으로 할당된 함수 포인터를 찾아가서
	// 함수를 실행시키는 간접적인 방식을 택함
	std::cout << func_ptr(x, y) << std::endl;

	return (0);
}