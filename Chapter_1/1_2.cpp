// 1.2 주석 (comments)

#include <iostream>

int main(void)
{
	// 주석 다는 방법
	// 1. int x = 2;
	// 2. /* x = 5; */
	// /*를 아무리 많이 달아도 */로 주석이 닫힘
	int y = 3;

	std::cout << 1 + 2 << std::endl;

	int sight = 10;

	// ...

	// set sight to be 0 (x) => 코드를 봐서 바로 알 수 있는 부분
	// 마법의 물약을 먹어서 시야 거리가 0 (o) => 코드를 작성한 이윤
	sight = 0;

	int	n_items;
	int	price_per_item;

	// 1 + 1 event
	int cost = n_items / 2 * price_per_item;

	return 0;
}

// 이틀만 지나도 코드를 작성한 이유가 기억나지 않는다면,
// 주석을 다는 편이 좋음
