// 7.6 인라인 함수

// inline functions
// 더 빠른 프로그램을 위해 inline 함수를 통해 최적화
// 컴파일러에게 강제라기보다는 권유(inline으로 써도 되나? 생각해보는 정도)
// inline으로 바꾼다고 해서 빨라지는 것이 아님
// inline이 아니어도 빨라지겠다 싶으면 알아서 inline 처리
// inline으로 최적화를 하는 것을 추천하진 않음(차라리 병렬 처리, cacheless 방법으로)
// inline을 자주 쓰면 프로그램이 많이 커짐 => 오히려 쓰지 않는 것이 나을 수 있음

#include <iostream>

// 함수 호출 => 변수 생성 => 복사 => 실행 => 리턴 => ...
// 이 과정을 줄이기 위해 inline 함수 사용
int	min(int a, int b)
{
	return ((a > b) ? b : a);
}

// 헤더 파일에 함수를 정의할 때 많이 사용
// 함수가 아닌 것처럼 작동 => 컴파일러가 하는 일
inline int	min_inline(int a, int b)
{
	return ((a > b) ? b : a);
}

int	main()
{
	std::cout << min(5, 6) << std::endl;			// 5
	std::cout << min(3, 2) << std::endl;			// 2

	// min_inline(5, 6)
	std::cout << ((5 > 6) ? 6 : 5) << std::endl;		// 5
	// min_inline(3, 2)
	std::cout << ((3 > 2) ? 2 : 3) << std::endl;		// 2

	return (0);
}