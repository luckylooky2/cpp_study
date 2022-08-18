// 1.12 네임스페이스(명칭 공간)

// namespace std?
// _LIBCPP_BEGIN_NAMESPACE_STD 매크로를 통해서 namespace를 정의
#include <iostream>

namespace MyFunction1
{
	// namespace 중첩
	namespace InnerSpace
	{
		int	doSomething(int a, int b)
		{
			return (a + b);
		}
	}
} // namespace name

// 완전히 이름이 같은 두 함수 => 컴파일 오류 : redefinition
// 해결?
// 1. 함수 이름을 바꾸는 방법
// 2. 함수 이름을 유지하는 방법 : namespace로 감싸는 방법

// 같은 namespace로 생성
// error: redefinition of 'doSomething'
namespace MyFunction2
{
	int	doSomething(int a, int b)
	{
		return (a * b);
	}
} // namespace name


int	main()
{

	// namespace 안에 똑같은 이름의 함수가 있다면
	// 	std::cout << doSomething(3, 4) << std::endl;
	// error: call to 'doSomething' is ambiguous

	// using namespace는 되도록 사용할 스코프 안에서 선언
	// 전역에서 선언한다면 오류를 초래할 수 있음
	using namespace MyFunction1::InnerSpace;
	using namespace MyFunction2;

	std::cout << "Hello, World" << std::endl;
	// 두 namespace 생성 후 실행
	// error: use of undeclared identifier 'doSomething'
	// namespace::function()으로 접근
	std::cout << MyFunction1::InnerSpace::doSomething(3, 4) << std::endl;

	return (0);
}