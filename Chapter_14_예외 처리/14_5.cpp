// 14.5 함수 try

// function try
// 클래스 생성자에서 발생하는, 특히 초기화 리스트에서 예외를 처리할 때 사용

#include <iostream>

void	doSomething()
{
	try
	{
		throw (-1);
	}
	catch(...)
	{
		std::cerr << "Catch in doSomething()" << '\n';
	}	
}

// 방식 1.
// 자주 쓰이는 방식은 아니지만 같은 동작
// void	doSomething()
// try
// {
// 	throw (-1);
// }
// catch(...)
// {
// 	std::cerr << "Catch in doSomething()" << '\n';
// }

class A
{
private:
	int	m_x;
public:
	A(int x) : m_x(x)
	{
		if (x <= 0) throw (1);
		std::cout << "class A constructor" << std::endl;
	}
};

class B : public A
{
public:
	// 방식 2.
	B(int x) try : A(x)
	{
		// do init.
	}
	catch (...)
	{
		std::cout << "Catch in B constructor" << std::endl;
		// 생성자에서 사용할 때의 특징
		// throw가 무조건 있는 것처럼 작동 => main()에서도 catch
		throw ;
	}
};

int	main()
{
	try
	{
		doSomething();		// Catch in doSomething()

		// main()에서 catch => 생성자에서 catch하고 싶다면?
		// B 클래스 안 생성자에서 try, catch
		B	b(0);			// Catch in main()
	}
	catch(...)
	{
		std::cerr << "Catch in main()" << '\n';
	}

	return (0);
}