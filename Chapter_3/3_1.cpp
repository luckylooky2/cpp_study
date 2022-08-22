// 3.1 연산자 우선순위와 결합법칙

#include <iostream>
#include <cmath>

// 연산자 우선순위(Precedence)
// 5 : * / % (left-to-right)
// 6 : + - (left-to-right)
// 15 : ? : (right-to-left)
// 16 : = += -= *= /= (right-to-left)
// cf > 우선순위를 잘 모를 땐? ()를 이용해 확실하게 함

// 연산자 결합 법칙(Associativity)
// 연산자가 같은 우선순위에 있을 때(결합할 때), 무엇을 먼저 할 것인가?
// left-to-right : 3 * 4 / 2
// right-to-left : = += -= ...

// cf> 3 * 4 / 2 vs. 4 / 2 * 3
// 자료형이 int, double이 섞여있을 때, 결과가 달라질 수 있음

// C vs C++ 비교해보기

int main()
{
	// 숫자 계산식을 표현할 때, 함수보다는 간단한 연산자를 사용하는 것이 쉬움
	// add(4, multi(2, 3));

	// 컴파일러는 그래프를 이용해 수식, 우선순위를 계산
	int x = 4 + 2 * 3;

	// std::pow returns double
	// int 자료형에 대해 효율적으로 계산을 하고 싶다?
	// 제곱 함수를 만들거나, 표를 만드는 방법
	int	y = std::pow(2, 3);

	// 연습 문제
	int a = 0, b = 0, c = 0, d = 0, t = 0, r = 0, w = 0;
	
	r = 1 + 2 + 3 + 4;
	a = b = c;
	t /= --w + 5;
	a || b && c || d;

	return (0);
}