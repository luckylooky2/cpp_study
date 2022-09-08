// 12.3 override, final, 공변 반환형

// override, final
// C++ 11
// 다형성을 구현할 때 유용하게 사용할 수 있는 지정자

// 다형성을 구현할 때, 부모 클래스가 다른 파일에 존재
// 코드가 커지면 모든 함수를 외우고 기억하고 있기엔 무리

// overriding vs. overloading
// 공통점 : 같은 이름의 메소드를 사용할 수 있음
// overriding
// 부모 클래스의 메소드 재정의
// 부모 클래스를 상속받은 자식 클래스가 부모 메서드와 같은 이름의 메서드를 생성해 
// 내용을 다르게 함으로써 부모와 다르게 활용이 가능하게 한다.
// 오버라이딩은 부모 클래스의 메소드를 재정의하는 것이므로, 
// 자식 클래스에서는 오버라이딩하고자 하는 메소드의 이름, 매개변수, 리턴 값이 모두 같아야 한다.
// 그렇지 않다면, overloading이 발생할 수 있음에 주의해야 한다.
// 부모 클래스의 메소드를 오버라이딩하는 것은 내용만을 새로 정의하는 것이므로 
// 선언부는 부모의 것과 완벽히 동일해야 하는 것을 볼 수 있다.
// overloading
// 상속과 관계가 없다 => 정의 되는 위치가 부모 또는 자식 어느 쪽에서 구현을 하던 상관이 없다는 의미
// 같은 메서드 이름을 가지면서도 매개변수 타입 및 개수를 변화시키고 생성함으로써
// 여러 상황에 대해 대처가 가능하게 한다.
// 메소드의 이름이 같고, 매개변수의 개수나 타입이 달라야 한다.
// 주의할 점은 '리턴 값만' 다른 것은 오버로딩을 할 수 없다는 것이다.
// 결국 오버로딩은 매개변수의 차이로만 구현할 수 있다는 것이다. 매개변수가 다르다면 리턴 값은 다르게 지정할 수 있다.
// 과적하다. => 하나의 이름으로 메소드의 기능을 추가 과적 하는 것

#include <iostream>

class A
{
public:
	virtual void	print(int x) { std::cout << "A" << std::endl; }
};

class B : public A
{
public:
	// override 키워드
	// 이 함수는 반드시 override할 것이다라고 컴파일러에게 알려줌
	// override하기 위해 정의된 프로토타입 컴파일 에러를 사전에 찾아주는 효과 => 특히 const 유무
	// member function declared with 'override' does not override a base class memberC/C++(1455)
	// 함수끼리 프로토타입이 같아야 override가 가능하기 때문에 short => int
	virtual void	print(int x) override { std::cout << "B" << std::endl; }
};

class C : public B
{
public:
	// final 키워드
	// 아래 자식 클래스에서는 override를 할 수 없게 막아줌
	virtual void	print(int x) final { std::cout << "C" << std::endl; }
};

class D : public C
{
public:
	// cannot override 'final' function "C::print" (declared at line 34)C/C++(1850)
	void	print(int x) { std::cout << "D" << std::endl; }
};

int	main()
{
	A	a;
	B	b;
	A	&ref = b;

	// b에 있는 print() 실행을 의도
	// why? 컴파일러가 매개변수가 다르면 overriding을 한다고 생각을 안 함
	// 함수 입장에서는 overriding이 아니라 overloading을 하고 싶었나보다라고 판단
	// 예비 조치 : override 키워드
	// overriding이 의도된 함수를 실수로 인해 overloading이 되지 않게끔 막아주는 키워드
	ref.print(1);	// A

	return (0);
}

// covariant types
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
	// covariant types
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
	// lldb : (B &)ref
	A	&ref = b;

	b.getThis()->print();		// B
	// (B &)ref : virtual B	*getThis()를 호출 => B * 리턴
	// 하지만 이를 호출한 ref가 A &타입이기 때문에 A *로 print()를 실행
	// print()가 virtual이 아니라서 A->print()를 호출
	ref.getThis()->print();		// A

	std::cout << typeid(b.getThis()).name() << std::endl;		// P1B => class B *
	std::cout << typeid(ref.getThis()).name() << std::endl;		// P1A => class A *

	return (0);
}