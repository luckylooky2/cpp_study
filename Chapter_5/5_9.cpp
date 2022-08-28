// 5.9 난수 만들기

// 컴퓨터는 정확히 동일한 확률로 난수를 만들 능력이 없음
// 여러 가지 방법으로 난수처럼 보이는 수를 만듦

unsigned int 	PRNG(int num)	// Pseudo Random Number Generator
{
	// static으로 해주어야 같은 값이 나오지 않음
	static unsigned int	seed = 5523;	// seed number

	seed = 8253729 * seed + 2396403;
	return (seed % num);
}

unsigned int	getRandomNumberVer1(int max)
{
	// 나눗셈 연산은 보통 느림
	// static 키워드를 통해 값을 저장해서 사용 or 전역 상수를 만들어서 사용하는 방법
	static const double	fraction = 1.0 / (RAND_MAX + 1.0);

	// 0 <= std::rand() * fraction <= 1
	return (0 + static_cast<int>((max - 0 + 1) * (std::rand() * fraction)));
}

unsigned int	getRandomNumberVer2(int max)
{
	// max 값이 작으면 상관없지만
	// max 값이 커진다면 결과가 한 쪽으로 쏠리는 현상이 나타날 수 있음
	// 정밀한 계산을 원한다면 => <random> 라이브러리 사용
	return (std::rand() % max);
}

void	printNumber(unsigned int (*fp) (int), int num)
{
	for (int cnt = 1; cnt <= 10; ++cnt)
	{
		std::cout << fp(num) << '\t';
		if (cnt % 5 == 0)
			std::cout << std::endl;
	}
}

#include <iostream>
#include <cstdlib>	// std::rand(), std::srand()
#include <ctime>	// std::time()
#include <random>	// C++ 11

int main()
{
	// 항상 같은 결과
	printNumber(PRNG, 32768);

	// seed number가 고정되어 있으면 다른 숫자를 생성할 수 없음
	// 디버깅이 필요하다면 seed number를 고정하는 편이 쉬움
	std::srand(5523);
	// seed number를 현재 시간과 연동
	std::srand(static_cast<unsigned int>(std::time(0)));	// seed number
	for (int cnt = 1; cnt <= 10; ++cnt)
	{
		std::cout << std::rand() << '\t';
		if (cnt % 5 == 0)
			std::cout << std::endl;
	}
	printNumber(getRandomNumberVer1, 100);
	printNumber(getRandomNumberVer2, 100);
	
	// 시간에 연동하는 것이 아니라 특정 device에 연동
	std::random_device	rd;
	// 32 or 64 bit 생성기 생성
	std::mt19937		mesenne(rd());
	// 1 ~ 6이 나올 확률이 동일 => 정규 분포, 포아송 분포도 존재
	std::uniform_int_distribution<>	dice(1,6);
	
	for (int cnt = 1; cnt <= 10; ++cnt)
	{
		std::cout << dice(mesenne) << '\t';
		if (cnt % 5 == 0)
			std::cout << std::endl;
	}

	return (0);
}