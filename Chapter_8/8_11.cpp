// 8.11 정적 멤버 함수

#include <iostream>

class Something
{
public:
	// 내부 클래스를 이용한 static 변수 초기화
	class _init
	{
	public:
		_init()
		{
			s_value = 1024;
		}
	};

private:
	int				m_value;
	// static 변수 선언
	static int		s_value;
	static _init	s_intializer;

public:
	// 생성자에서 static member variable을 초기화할 수 없음
	// static 생성자가 아니기 때문 => static 생성자는 C++ 표준에서 지원하지 않음
	// how? 내부 클래스를 이용
	Something()
		: m_value(123) // , s_value(1024)
	{}

	// private static memeber variable에 접근하기 위해서 
	static int	getValue()
	{
		// this is not passed => only static variable
		// => 인스턴스에서 class에 접근하지 못함
		// why? 정적으로 메모리에 접근하기 때문에
		// error: invalid use of 'this' outside of a non-static member function
		// return (this->s_value);
		// return (m_value);
		return (s_value);
	}

	// this is passed : 특정한 인스턴스를 가리키는 포인터
	int	temp()
	{
		return (this->s_value);
	}
};

// static 변수 정의 및 초기화
int					Something::s_value = 100;
Something::_init	Something::s_intializer;

int	main()
{
	// private으로 바꾸면 접근 불가
	// error: 's_value' is a private member of 'Something'
	// std::cout << Something::s_value << std::endl;		// 100
	std::cout << Something::getValue() << std::endl;	// 100

	Something	sth1;

	// private으로 바꾸면 접근 불가
	// std::cout << sth1.s_value << std::endl;			// 100
	std::cout << sth1.getValue() << std::endl;		// 100

	// member function pointer(non-static)
	// 멤버 함수는 멤버 변수와 다르게 같은 주소를 가리킴(static 변수처럼)
	// 1. non-static 멤버 함수는 class 안에 존재(인스턴스에 복사되지 않음)
	// 2. 인스턴스에서 멤버 함수를 실행시킬 때는 this라는 키워드가 class를 가리킴
	// 3. class의 멤버 함수가 this 키워드를 통해 특정된 인스턴스를 인자로 함수를 실행시킴
	// error: cannot create a non-constant pointer to member function
	// int	(Something::*fp)() = &sth1.temp;
	// class에 직접 접근해야 함
	int	(Something::*fp)() = &Something::temp;
	// member function pointer(static)
	// error: cannot initialize a variable of type 'int (Something::*)()' with an rvalue of type 'int (*)()'
	// class의 멤버 함수 타입으로 변환이 되지 않음
	// int	(Something::*fp2)() = &Something::getValue;
	int	(*fp2)() = &Something::getValue;

	// 사용할 때
	// non-static member function은 인스턴스에 종속이 되어있는 형태로 
	// 구현되어 있기 떄문에 인스턴스에서 호출을 해야함
	// => this 포인터가 없으면 작동을 하지 못함
	// 인스턴스에서 호출 : this 포인터를 준다
	// 함수 포인터 : non-static member function이 실제로 있는 주소
	// 즉, 인스턴스에서 non-static member function가 동작하는 방식대로 사용하는 것
	std::cout << (sth1.*fp)() << std::endl;	// 100
	std::cout << sth1.temp() << std::endl;	// 100

	return (0);
}