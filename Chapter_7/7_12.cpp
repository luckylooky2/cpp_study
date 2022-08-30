// 7.12 재귀적 함수 호출

// recursion
// 장점 : iteration보다 간결한 코드
// 단점 : stack을 사용해야 하기 때문에 횟수의 한계, 성능이 중요한 프로그램에서는 추천하지 않음

#include <iostream>

// 재귀 호출이 가능한 이유?
// 코드는 다른 곳에 저장이 되어있고 함수를 호출할 때는 주소를 보고 가는 것이기 때문
// 같은 코드를 따로따로 실행시키고 있는 것
void	CountDown(const int &count)
{
	// 종료하는 조건이 반드시 있어야 함
	if (count >= 0)
	{
		std::cout << count << std::endl;
		// stack overflow 위험
		// count와 count - 1은 서로 다른 변수이기 때문에 주소가 서로 다름
		CountDown(count - 1);
	}
}

int	sumTo(int sumto)
{
	if (sumto <= 0)
		return (0);
	else if (sumto <= 1)
		return (1);
	else
		return (sumto + sumTo(sumto - 1));
}

int	main()
{
	CountDown(10);
	std::cout << sumTo(10) << std::endl;	// 55

	// 연습 문제 : 피보나치 수열

	return (0);
}