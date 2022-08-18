// 1.13 전처리기(preprocessor)와의 첫 만남

#include <iostream>
#include <algorithm>

// 코드에서 "MY_NUMBER"을 만나면 9로 치환
#define MY_NUMBER 9

// 문자열도 가능
#define MY_WORD	 "Hello World"

// 함수도 가능
// 1. 단, 앞 뒤로 괄호를 추가하는 것을 잊지 말 것
// why? 매크로가 치환될 때 괄호가 없으면 문제가 생길 가능성이 있기 때문

// 2. 최소 단위를 괄호로 묶을 것
// why? 이항/삼항 연산자를 사용할 경우, 계산에 오류가 발생할 가능성 차단
#define MAX(a, b) ( ( a > b ) ? (a) : (b) )

// if문과 같은 효과를 전처리 단계에서 처리
// OS, 그래픽카드 사양 등을 구별할 때 많이 사용
#define MAC_OS

// define의 스코프는 현재 파일에 한정
#define WINDOWS
void	printIfWindows();

int	main()
{
	std::cout << MY_NUMBER << std::endl;
	std::cout << MY_WORD << std::endl;
	std::cout << MAX(2 + 3, 2) << std::endl;
	// 역시 namespace std MACRO : _LIBCPP_BEGIN_NAMESPACE_STD
	std::cout << std::max(2 + 3, 2) << std::endl;
#ifdef MAC_OS
	std::cout << "MacOS " << std::endl;
#endif
#ifndef MAC_OS
	std::cout << "Windows " << std::endl;
#endif
	printIfWindows();

	return (0);
}