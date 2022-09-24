// 19.1 람다 함수와 std::function

// 람다 함수 => 모던 C++, C++ 11
// 프로그램의 유연성, 프로그래머의 부담 줄여줌
// anonymous function

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

void	goodbye(const std::string& s)
{
	std::cout << "Goodbye " << s << std::endl;
}

class Object
{
public:
	void	hello(const std::string& s)
	{
		std::cout << "Hello " << s << std::endl;
	}
};

int	main()
{
	{
		// [] : lambda-introducer
		// (const int& i) : lambda-parameter-declaration
		// -> void : lambda-return-type-clause
		// {} -> compound-statement(function body?)
		auto	func = [](const int& i) -> void{ std::cout << i << " Hello, World!" << std::endl; };

		// 일반 함수와 똑같이 작동, i에 123 전달, 함수 body 실행
		func(123);		// 123 Hello, World!

		// 익명 함수일 때, 진정한 람다 함수
		// 함수 뒤에 ()를 넣어주면 즉시 실행
		[](const int& i) -> void{ std::cout << i << " Hello, World!" << std::endl; }(1234);		// 1234 Hello, World!
	}

	{
		std::string	name = "JackJack";
		// introducer 안에 &를 넣으면 => 블록 안에 있는 값들을 reference로 가져옴
		[&]() { std::cout << name << std::endl; }();	// JackJack
		// [this] => 클래스 멤버를 가져다 쓸 떄
		// [this]() { std::cout << name << std::endl; }();
		// [=] => 블록 안에 있는 값들을 복사하여 가져옴
		[=]() { std::cout << name << std::endl; }();	// JackJack
	}

	{
		// STL과 같이 사용
		std::vector<int>	v;
		
		v.push_back(1);
		v.push_back(2);

		// 리턴 타입이 void일 경우 거의 "-> void"를 적지 않음
		auto	func2 = [](int val) { std::cout << val << std::endl; };
		
		// 원소들에 대해 각각 실행이 되는 함수를 만들고 싶음
		// 1. function pointer를 이용하여 새로운 함수를 만드는 방법
		// 2. 이터레이터와 람다 함수를 이용
		// for_each : #include <vector>
		for_each(v.begin(), v.end(), func2);	// 1 2
		// 선호하는 방식
		for_each(v.begin(), v.end(), [](int val) { std::cout << val << std::endl; });	// 1 2
		// why 1?
		std::cout << [](int val) { std::cout << val << std::endl; } << std::endl;		// 1

		// std::function
		// 함수 포인터를 체계화한 것 => 함수를 변수처럼 사용
		std::function<void(int)>	func3 = func2;
		// std::bind
		// 간단히 말하면 호출이 가능한 객체에 인수를 바인딩 하는 것
		// 정작 func4는 매개 변수가 없음 => func3에 456이 묶여있기 때문
		std::function<void()>	func4 = std::bind(func3, 456);

		func3(123);		// 123
		func4();		// 456
	}

	{
		// placeholders
		// 인자값을 n개의 새로운 함수의 인자로 받을 수 있도록 해준다.
		Object	instance;
		// 멤버 함수를 바인딩/실행하기 위해서는 this 포인터를 인스턴스가 필요
		auto	f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f(std::string("World"));	// Hello World

		// 일반 함수를 바인딩/실행
		auto	f2 = std::bind(&goodbye, std::placeholders::_1);
		
		// placeholders가 없다면
		// error: no matching function for call to object of type
      	// 'std::__1::__bind<void (*)(const std::__1::basic_string<char> &)>'
		f2(std::string("World"));	// Goodbye World
	}
	
}
