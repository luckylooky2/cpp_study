// 4.1 지역 변수의 범위와 지속기간

// scope

// duration
// 메모리에서 사라지는 시점

#include <iostream>

// 블록에 이름을 붙여주기 위해 namespace를 사용함
namespace work1
{
	int a = 1;

	void	doSomething()
	{
		a += 3;
	}
}

// C++ 17 : nested namespace
// 2개 이상 중첩은 거의 사용하지 않음
namespace work2::work3::work4
{
	int a = 1;

	// 리턴 타입, 이름, 파라미터가 모두 같아야 같은 함수 => 하나라도 다르면 다른 함수
	void	doSomething(int b)
	{
		a += b;
	}
}

int main()
{
	// error: use of undeclared identifier 'apple'
	// apple = 1;

	int	apple = 5;
	// 같은 영역에서 중복 선언은 안 됨
	// int apple = 10;

	std::cout << apple << std::endl;		// 5
	std::cout << &apple << std::endl;		// 0x16bb97488

	// 현대 프로그래밍에서는 가급적 변수가 살아남는 기간을 줄이려고 함
	// 사용하는 곳 근처에서만 살아남도록 함
	{
		apple = 1;
		std::cout << apple << std::endl;	// 1
		std::cout << &apple << std::endl;	// 0x16bb97488

		// 더 작은 영역에 같은 이름이 있을 경우에는 이름을 숨김 (name hiding)
		// 밖의 블록에서 선언된 apple의 이름이 숨겨짐
		// 이름은 같지만 완전히 다름
		// 혼동되지 않게 이름을 다르게 지을 것
		int apple = 100;
		std::cout << apple << std::endl;	// 100
		std::cout << &apple << std::endl;	// 0x16bb97484
	}

	std::cout << apple << std::endl;		// 1
	std::cout << &apple << std::endl;		// 0x16bb97488

	// :: 영역(범위) 결정 연산자
	work1::doSomething();
	work2::work3::work4::doSomething(apple);

	return (0);
}

// error: C++ requires a type specifier for all declarations
// 메모리가 이미 반납됨
// apple = 3;