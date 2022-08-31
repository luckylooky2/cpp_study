// 8.12 친구 함수와 클래스

// friend 키워드

#include <iostream>

// 두 class에 동시에 접근하는 friend 함수의 경우 정의 문제가 발생
// 전방 선언으로 해결
class B;

class A
{
private:
	int	m_value = 1;

	// 함수를 class의 친구로 선언 => member function이 된다는 뜻?
	friend void	doSomething(A &a, B &b);
	// 다른 클래스의 멤버 함수처럼 사용하고 싶은 경우
	friend class B;
	// error: incomplete type 'B' named in nested name specifier
	// B가 있는 건 아는데 B 안에 foo()가 있는지는 모름 
	friend void	B::foo(A &a);
};

class B
{
private:
	int	m_value = 2;

	friend void	doSomething(A &a, B &b);

public: 
	void	foo(A &a)
	{
		std::cout << a.m_value << std::endl;
	}
};

void	doSomething(A &a, B &b)
{
	// 연산자 오버로딩을 할 때 이런 경우가 많이 생김
	// 1. public으로 변경 => 객체 지향에 어긋남
	// 2. friend 키워드를 이용헤 private 멤버에 접근
	std::cout << a.m_value << std::endl;

	// a, b의 값을 둘 다 출력
	std::cout << b.m_value << std::endl;
}

int	main()
{
	A	a;
	B	b;

	doSomething(a, b);	// 1
	b.foo(a);			// 1

	return (0);
}