// 14.3 예외 클래스와 상속

// 지금까지 기본 자료형만을 사용해 throw, catch
// 사용자 정의 자료형, 상속을 사용할 때 주의할 점

// 예외 클래스
// 1. 기본 자료형만으로 throw를 한다면? 표현하지 못하는 부분도 있을 수 있음
// 2. 어떤 경우에는, 자료형만 가지고 어떤 예외인지 표현할 수 있지 않을까?
// 3. 예외를 던진 후에 catch에서 하는 작업들을 클래스나 함수로 정의하려고 할 때

#include <iostream>

class Exception
{
public:
	void	report()
	{
		std::cerr << "Exception report" << std::endl;
	}
};

// 상속을 받을 땐 주의해야 함
class ArrayException : public Exception
{
public:
	// overriding
	void	report()
	{
		std::cerr << "Array exception" << std::endl;
	}
};

class MyArray
{
private:
	int	m_data[5];

public:
	// 멤버 함수 안에서 exception을 throw를 할 수 있음
	int& operator[](const int &index)
	{
		if (index < 0 || index >= 5)
			// throw (-1);				// Exception -1
			// throw (Exception());		// Exception report
			// 객체 잘림 
			throw (ArrayException());	// Exception report
		return (m_data[index]);
	}
};

void	doSomething()
{
	MyArray	my_array;

	try
	{
		my_array[100];
	}
	catch(const int& x)
	{
		std::cerr << "Exception " << x << '\n';
	}
	// 객체 잘림 => 상속이기 때문에 받아줌
	catch(Exception& e)
	{
		e.report();
		// 1. 객체 잘림이 발생한 채로 re-throw
		// throw (e); 
		// 2. 객체 잘림이 발생하지 않음
		throw ;
	}
	// warning: exception of type 'ArrayException &' will be caught by earlier handler
	// 부모 클래스가 먼저 catch => 부모 클래스와 자리를 바꿔줘야 함
	catch(ArrayException& e)
	{
		e.report();
		// re-throw
		throw (e);

	}
}

int	main()
{
	try
	{
		doSomething();
	}
	// 이미 처리된 catch이기 때문에 처리되지 않음
	// re-throw했다면 다시 catch
	catch (ArrayException &e)
	{
		std::cout << "main()" << std::endl;
		e.report();
	}

	return (0);
}