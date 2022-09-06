// 12.2 가상 함수와 다형성

// virtual funtions
// virtual 키워드를 붙인 함수
// 1. 자식 클래스를 부모 클래스 포인터로 캐스팅할 경우
// 2. 부모 클래스의 특정 함수가 virutal이고
// 3. 자식 클래스에 overriding된 함수가 있을 경우
// => overriding된 자식 클래스 함수를 먼저 호출

// 일반적으로 virtual function은 스택에 쌓여서 실행되는 구조가 아니라
// virtual table에서 어디서 상속받은 인스턴스인가? 찾아가는 과정이기 떄문에 느림
// 호출이 아주 빈번한 경우(게임 엔진, 챗봇 등) 사용 지양

#include <iostream>

class A
{
public:
	virtual void	print() { std::cout << "A" << std::endl; }
};

class B : public A
{
public:
	// 문법적으로는 virtual 키워드가 없어도 그만이라 하더라도
	// 1. 관습적으로 이 함수가 부모 클래스 함수를 overriding한 것이라는 것을 명확히 하기 위해
	// 2. 디버깅할 때, 내가 지금 보는 함수에 polymorphism에 의해 가상 함수를 overriding한 것인지
	// 아는 것과 모르는 것에서 시간 차이가 많이 남
	virtual void	print() { std::cout << "B" << std::endl; }
};

class C : public B
{
public:
	virtual void	print() { std::cout << "C" << std::endl; }
};

// 실제 코딩에선 많아야 3번 정도 상속
class D : public C
{
public:
	void	print() { std::cout << "D" << std::endl; }

	// overriding을 할 때, 리턴 타입이 다르면 어떻게 되는가?
	// cannot overload functions distinguished by return type aloneC/C++(311)
	// => 리턴 타입만 바꾼 함수로는 overriding 불가능
	// 직접적으로는 C 클래스로부터 상속을 받음에도 불구하고 A 클래스에 있는 함수와 비교
	// 상속 구조를 만들 때는, 보통 overriding하려고 만드는 것
	// 프로그래머 입장에서는 상속 구조에서 가장 상위에 있는 virtual function이 중요하구나를 알 수 있음
	// int		print() { std::cout << "D" << std::endl; return (0); }
};

int	main()
{
	A	a;
	B	b;
	C	c;
	D	d;

	a.print();	// A
	b.print();	// B
	c.print();	// C
	d.print();	// D

	// 레퍼런스도 포인터와 똑같이 작동
	A	&ref = b;
	B	&ref2 = c;
	// error: non-const lvalue reference to type 'C' cannot bind to a value of unrelated type 'A'
	// a는 C 클래스의 정보를 가지고 있지 않음?
	// C	&ref3 = a;

	ref.print();	// A
	ref = d;
	ref.print();	// A
	ref2.print();	// B

	// virtual function으로 변환
	// A 클래스 함수가 virtual이니까 B 클래스 함수가 overriding되어 호출됨
	ref.print();	// B

	// virtual : 할당 vs. 초기화의 결과가 다름
	// 1. 할당한 경우 => virtual의 종착지에서 호출
	ref = d;
	ref.print();	// B
	// 2. 바로 초기화한 경우 => 자기 자신 호출
	A	&ref3 = d;
	ref3.print();	// D

	// 가장 상속 상위에 있는 클래스 함수가 virtual function이 되면
	// 자식 클래스들도 virtual function처럼 작동을 함
	// B class가 A class를 상속받지 않는 경우 => 아래 예제는 B를 출력
	// why? B class가 가장 상위에 있지만 virtual function이 아니기 때문
	B	&ref4 = c;
	ref4.print();	// C

	return (0);
}
