// 19.7 완벽한 전달과 std::forward

#include <iostream>
#include <vector>
#include <utility>	// std::forward

struct MyStruct
{};

void	func(MyStruct& s)
{
	std::cout << "Pass by L-ref" << std::endl;
}

void	func(MyStruct&& s)
{
	std::cout << "Pass by R-ref" << std::endl;
}

// 템플릿을 통해 접근하게 만듦
// wrapper 함수를 만들어서 func()를 호출
template<typename T>
void	func_wrapper(T t)
{
	func(t);
}

template<typename T>
// 1. 매개변수를 && r-value로 받음
void	func_wrapper2(T&& t)
{
	// 2. std::forward<T>(t)
	func(std::forward<T>(t));
}

int	main()
{
	MyStruct	s;

	// 직접적으로 사용하는 것은 컴파일러가 l-value, r-value를 구분해줌
	func(s);					// Pass by L-ref
	func(MyStruct());			// Pass by R-ref

	// 템플릿을 사용하면 구분을 해주지 않음
	// templatize되면서 l-value, r-value 정보가 날라감
	// perfect forwarding을 통해 해결
	func_wrapper(s);			// Pass by L-ref
	func_wrapper(MyStruct());	// Pass by L-ref

	func_wrapper2(s);			// Pass by L-ref
	func_wrapper2(MyStruct());	// Pass by R-ref

	return (0);
}
