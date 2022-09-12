// 14.2 예외 처리와 스택 되감기

// 함수 호출 구조는 스택
// 가장 안쪽의 스택에서 예외를 던진다면? 스택을 되감아가며 어디서 예외를 받을 지 찾게 됨

// cout, cerr, clog
// 기능 상 큰 차이는 없고, 나가는 채널의 차이
// cout : 출력 버퍼에 담아 놓고, endl가 나오면 flush
// cerr : 버퍼 없이 바로 출력
// clog

// exception specifier
// ex. void	last() throw(int)
// int 타입의 exception을 throw할 수도 있다. 항상 int는 아니다.
// 불필요하다는 견해도 있음 throw(...)로 컴파일러가 생각한다 함
// 만약 ()로 쓴다면? 예외를 throw하지 않는다는 뜻 => 주의
// warning: 'last' has a non-throwing exception specification but can still throw

#include <iostream>

void	last() throw()
{
	std::cout << "Last" << std::endl;				// 4
	std::cout << "Throws exception" << std::endl;	// 5
	throw (-1);										// 6
	std::cout << "End last" << std::endl;
}

void	third()
{
	std::cout << "Third" << std::endl;	// 3
	last();
	// 예외 처리를 해주지 않아서(catch) 아래를 호출하지 않음
	// 바로 함수 종료, unwinding
	std::cout << "End third" << std::endl;
}

void	second()
{
	std::cout << "second" << std::endl;	// 2
	try
	{
		third();
	}
	// 제대로 된 예외 처리를 해주지 않아서(catch) 아래를 호출하지 않음
	// 제대로 catch하지 못하면 계속 throw
	// 바로 함수 종료, unwinding
	catch(double)
	{
		std::cerr << "second caught double exception" << '\n';
	}
	std::cout << "End second" << std::endl;
}

void	first()
{
	std::cout << "first" << std::endl;	// 1
	try
	{
		second();
	}
	// 제대로 된 예외 처리(catch)
	// 만약 제대로 catch하지 못했다면 => main으로 unwinding
	catch(int)
	{
		std::cerr << "first caught int exception" << '\n';	// 7
	}
	std::cout << "End first" << std::endl;	// 8
}

int main()
{
	std::cout << "Start" << std::endl;	// 0
	try
	{
		first();
	}
	// 이미 catch를 했으므로 정상적으로 catch가 호출되지 않음
	// 마지막까지 catch로 잡아주지 못한다면 => 런타임에러
	catch(int)
	{
		std::cerr << "main caught int exception" << '\n';
	}
	// 만약에 모든 예외를 처리할 수 없다면 ...을 이용
	catch(...)	// catch-all handlers => ellipses(생략 기호)
	{
		std::cerr << "main caught ellipses exception";
	}
	std::cout << "End main" << std::endl;	// 9

	return (0);
}