// 5.1 제어 흐름 소개

// 프로그래밍 : 컴퓨터에게 해 나갈 일을 지정하는 일
// 복잡한 작업을 위해 여러 가지 순서를 제어할 수 있음

// 1. 중단 halt

// 2. 점프 jump : goto, break, continue

// 3. 조건 분기 conditional branches : if, switch

// 4. 반복 loops : while, do while, for

// 5. 예외 처리 exceptions : try, catch, throw

#include <iostream>

int main()
{
	std::cout << "I love you " << std::endl;

	// 중단 : 아래 코드가 남아있는 경우, 아래 주석을 추가
	// return : 정상적으로 종료
	return (0);
	// exit : 긴급하게 종료
	// 코드 어디에서나 호출하면 바로 프로세스가 종료
	// 디버깅하기 위해 사용하는 경우가 많음
	// 실제 프로그램에 삽입되어 들어간다기보다는 프로그래밍 과정에 분석하기 위해 사용
	exit(0);

	// ...

	std::cout << "I love you, too" << std::endl;

	return (0);
}

