// 8.9 클래스와 const

#include <iostream>
#include <string>

class Something
{
private:
	int 		m_value = 0;
	std::string	m_string = "default";

public:
	Something(void) { std::cout << "class Something constructor" << std::endl; }
	// 함수의 매개변수로 인스턴스를 call by value할 경우 아래 복사 생성자가 호출
	Something(const Something &st_in) { std::cout << "class Something copy constructor" << std::endl; }
	void				setValue(const int &value_in) { m_value = value_in; }
	// const의 위치 기억하기
	// 멤버 변수의 값을 바꾸지 않겠다고 컴파일러에게 알려주는 것
	// const class가 아니더라도 내부에서 멤버 변수를 바꾸지 않는다면 const 멤버 함수로 만들자
	int					getValue(void) const { return (m_value); }
	// const
	// 멤버 함수를 const로 만들면 보통 리턴 값도 const로 만듦
	const std::string	&getString() const { std::cout << "const" << std::endl; return (m_string); }
	std::string			&getString() { std::cout << "non-const" << std::endl; return (m_string); }
	~Something(void) { std::cout << "class Something destructor" << std::endl; }
};

// 복사가 일어날 때 기본 생성자가 아니라 복사 생성자가 호출되어 인스턴스를 복사
// 의도한대로 함수가 작동하지 않을 수 있어 call by reference로 넘겨주는 것이 좋다.
void	print1(Something sth)
{
	std::cout << &sth << std::endl;
	// private일 때는 접근할 수 없음
	std::cout << sth.getValue() << std::endl;
}

void	print2(const Something &sth)
{
	std::cout << &sth << std::endl;
	// private일 때는 접근할 수 없음
	std::cout << sth.getValue() << std::endl;
}

int	main()
{
	// 인스턴스를 const로 만드는 것은 멤버 변수를 const로 만든다는 것과 동일
	const Something	sth;
	Something		sth2;

	// setter 함수를 사용할 수 없음
	// error: 'this' argument to member function 'setValue' has type 'const Something',
	// but function is not marked const
	sth.setValue(3);
	// getter 함수는?
	// 컴파일러는 멤버 함수가 const인지 아닌지만 판단
	sth.getValue();

	// call by value
	print1(sth);					// 0x7ffee4e1f8a8 0
	std::cout << &sth << std::endl;	// 0x7ffee4e1f8b8

	// call by reference
	print2(sth);					// 0x7ffeee6fc8b8 0
	std::cout << &sth << std::endl;	// 0x7ffeee6fc8b8

	// const의 유무에 따라 함수 오버로딩 순서가 달라짐
	sth.getString();		// const
	sth2.getString();		// non-const

	return (0);
}