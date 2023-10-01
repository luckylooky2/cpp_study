#include <iostream>

class A {
	public:
		int a = 10;
		virtual void print() { std::cout << "A" << std::endl;}
};

class B : public A {
	public:
		int b = 20;
		void	print() { std::cout << "B" << std::endl;}
};

int main()
{
	A *a = new B();
	std::cout << a->a << std::endl; // 10
	a->print(); // B
	// std::cout << a->b; // 둘 다 접근 불가

	A aa = B();
	std::cout << aa.a << std::endl; // 10
	aa.print(); // A
	// std::cout << aa.b; // 둘 다 접근 불가
}

// 왜 B의 b 멤버 변수에 접근 불가?
// 컴파일러가 얘는 A 타입인데 왜 B 타입에 접근하는가? 라면서 접근을 막음
// 실제로는 메모리에 B 타입으로 생성해서 실제로 접근도 가능한데, 컴파일러 단에서 막아서 문제가 되는 것
// 명시적 형변환의 역할 : 명시적 형변환을 통해 컴파일러에게 얘는 B 타입이라고 알려줘서 컴파일러에게 알려주는 것!

// 그렇다면 B의 멤버 함수는?
// 마찬가지로, 함수 호출도 정적 타입에 의해 컴파일러가 결정
// 가상 함수는 이러한 문제를 해결하기 위해 도입
// 부모 클래스에서 가상 함수로 정의하면, 컴파일러는 객체의 실제 동적 타입에 따라 함수 호출 결정

// 멤버 함수는 이러한 문제를 다형성을 위해 가상 함수를 통해 해결(도입)한 케이스이고
// 멤버 변수는 딱히 이러한 문제를 해결하지 않음