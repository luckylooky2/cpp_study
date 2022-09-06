// 5.4 goto

// 위치를 책갈피(레이블)처럼 지정할 수 있음
// goto 키워드를 만나면 레이블의 처음으로 이동
// 반복문의 원조격 : 어셈블리어를 사용하면 반복문도 goto
// 반복문을 대신하기 위해 goto를 사용
// 실제 사용하지는 않음 => for, while문은 좀 더 계획성을 강조

#include <iostream>
#include <cmath>

int main()
{
	double	x;

tryAgain : // label
	std::cout << "Enter a non-negative number" << std::endl;
	std::cin >> x;

	if (x < 0.0)
		goto  tryAgain;
	std::cout << sqrt(x) << std::endl;

	// error: cannot jump from this goto statement to its label
	goto skip;

	int y = 5;

skip:
	y += 3;

	return (0);
}