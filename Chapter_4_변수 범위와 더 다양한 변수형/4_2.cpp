// 4.2 전역 변수, 정적 변수, 내부 연결, 외부 연결

// 범위가 있는 지역 변수는 프로그래머 입장에서는 불편할 수도 있음
// 대부분의 경우, 지역 변수만을 사용하기 때문에 지역 변수 위주로 설명

// 전역 변수
// 어디서든 사용할 수 있고, 다른 파일로 넘어가서 사용할 수도 있는 변수
// 편할수도 있겠다? 반드시 사용해야 하는 이유가 있는 경우 빼고는 가급적이면 사용하지 말자

// linkage
// 지역 변수 : 범위가 제한되어 있음, linkage가 없음
// 내부 연결 : 파일 내 어디에서나 사용할 수 있는 경우
// 외부 연결 : 다른 파일에서도 직접 사용할 수 있는 경우(파일들 간에 연결 관계)

// 링킹 단계에서 지역 변수를 연결해 줄 필요가 없음
// 정적 변수는 다른 파일에서 참조할 수 없음
// static int g_value = 1;

#include <iostream>
#include "4_2.hpp"

// forward declaration
// extern 키워드가 생략
extern void	test(void);
// 초기화를 해주면 안 됨 why?
// warning: 'extern' variable has an initializer [-Wextern-initializer]
// 링킹 에러 발생
// duplicate symbol '_test_value' in
// error: linker command failed with exit code 1 (use -v to see invocation)
// 여기서도 메모리 할당(초기화), test.cpp에서도 메모리 할당(초기화) => 동일한 변수(심볼) 이슈 발생
extern int	test_value;

// 전역 변수
int	value = 123;

void	doSomething()
{
	// 정적 변수
	// 메모리 관점 : 블록 안에서 반복해서 할당되는 메모리를 정적으로 재사용한다라는 의미
	// 처음 호출할 때만 초기화, 이후 호출할 때는 skip
	// internal linkage
	static int	a = 1;
	++a;
	std::cout << a << std::endl;
}

int main()
{
	std::cout << value << std::endl;		// 123

	// 지역 변수
	// 영역을 벗어나는 순간 => 메모리 반납, scope, duration 제한
	// name hiding
	int	value = 1;

	// 전역 변수의 문제점 : 변수 관리, 추적이 어려움
	// 1. 함수에 파라미터를 활용하는 방법
	// 2. g_value처럼 이름으로 구별하는 방법
	// 3. 객체 지향을 사용하여 전역 변수를 사용하지 않는 방향으로 설계
	std::cout << value << std::endl;		// 1
	// 그러면 같은 이름의 전역 변수를 사용할 수 없나?
	// global scope operator(전역 연산자)를 사용
	std::cout << ::value << std::endl;		// 123

	// wihtout static
	doSomething();	// 2
	doSomething();	// 2
	// with static
	doSomething();	// 2
	doSomething();	// 3

	// extern
	test();
	std::cout << test_value << std::endl;

	// extern 함수에서 참조한 Constants와 여기서 참조한 Constants의 메모리가 다름
	// 서로 다른 파일에 헤더 파일로 정의되어 있기 때문?
	// 메모리의 낭비
	std::cout << Constants::pi << std::endl;	// 3.14159
	std::cout << &Constants::pi << std::endl;	// 0x1026b7e10
	// 1. 새 cpp 파일을 만듦 : 실제로 코드가 정의되어 있는 파일(초기화 포함)
	// 2. 헤더 파일은 extern 키워드를 활용해 외부 연결(초기화 비포함)
	std::cout << &Constants::pi << std::endl;	// 0x102ff7ee0

	return (0);
}