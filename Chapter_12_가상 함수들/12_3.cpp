// 12.3 override, final, 공변 반환형

// override, final
// 다형성을 구현할 때 유용하게 사용할 수 있는 지정자

// covariant types

// 다형성을 구현할 때, 부모 클래스가 다른 파일에 존재
// 코드가 커지면 모든 함수를 외우고 기억하고 있기엔 무리

#include <iostream>

// class A
// {
// public:
// 	virtual void	print(int x) { std::cout << "A" << std::endl; }
// };

// class B : public A
// {
// public:
// 	// override 키워드
// 	// 이 함수는 반드시 override할 것이다라고 컴파일러에게 알려줌
// 	// override하기 위해 정의된 프로토타입 컴파일 에러를 사전에 찾아주는 효과 => 특히 const 유무
// 	// member function declared with 'override' does not override a base class memberC/C++(1455)
// 	// 함수끼리 프로토타입이 같아야 override가 가능하기 때문에 short => int
// 	virtual void	print(int x) override { std::cout << "B" << std::endl; }
// };

// class C : public B
// {
// public:
// 	// final 키워드
// 	// 아래 자식 클래스에서는 override를 할 수 없개 막아줌
// 	virtual void	print(int x) final { std::cout << "C" << std::endl; }
// };

// class D : public C
// {
// public:
// 	// cannot override 'final' function "C::print" (declared at line 34)C/C++(1850)
// 	void	print(int x) { std::cout << "D" << std::endl; }
// };

// int	main()
// {
// 	A	a;
// 	B	b;
// 	A	&ref = b;

// 	// b에 있는 print() 실행을 의도
// 	// why? 컴파일러가 매개변수가 다르면 overriding을 한다고 생각을 안 함
// 	// 함수 입장에서는 overriding이 아니라 overloading을 하고 싶었나보다라고 판단
// 	// 예비 조치 : override 키워드
// 	// overriding이 의도된 함수를 overloading이 되지 않게끔 막아주는 키워드
// 	ref.print(1);	// A

// 	return (0);
// }

class A
{
public:
	void		print() { std::cout << "A" << std::endl; }
	virtual A	*getThis() { return (this); }
};

class B : public A
{
public:
	void		print() { std::cout << "B" << std::endl; }
	// 일반적으로는 리턴 타입이 다르면 override 불가
	// 부모-자식 관계에 있는 클래스가 리턴 타입인 경우 override가 가능
	virtual B	*getThis() { return (this); }
};

class C : public B
{
public:
	void		print() { std::cout << "C" << std::endl; }
	virtual C	*getThis() { return (this); }
};

int main()
{
	A	a;
	B	b;
	C	c;
	A	&ref = b;

	b.getThis()->print();		// B
	// virtual B	*getThis()를 호출 => B * 리턴
	// 그걸 다시 내부적으로 A *로 바꿔서 리턴
	ref.getThis()->print();		// A

	std::cout << typeid(b.getThis()).name() << std::endl;		// P1B => class B *
	std::cout << typeid(ref.getThis()).name() << std::endl;		// P1A => class A *

	return (0);
}