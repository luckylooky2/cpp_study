// 3.9 비트 플래그, 비트 마스크

#include <iostream>

// 비트단위 연산자가 실전에서 어떻게 사용되는지? 어떤 용도로 주로 사용되는지?

int main()
{
	bool	item1_flag = false;
	bool	item2_flag = false;
	bool	item3_flag = false;
	bool	item4_flag = false;

	// event!
	item1_flag = true;

	// die! item2 los
	item2_flag = false;

	if (item3_flag == true)
	{
		// event
	}

	if (item3_flag == true && item4_flag == false)
	{
		item3_flag = false;
		item4_flag = true;
	}

	// 모든 아이템을 검사하려면? 모든 변수를 파라미터를 넘겨주나?
	// struct? array?
	// unsigned char 자료형 하나로도 8개의 아이템 소지 유무를 알 수 있음
	// invokeEvent(item1_flag, item2_flag, ...);

	const unsigned char	opt0 = 1 << 0;
	const unsigned char	opt1 = 1 << 1;
	const unsigned char	opt2 = 1 << 2;
	const unsigned char	opt3 = 1 << 3;

	std::cout << std::bitset<8>(opt0) << std::endl;			// 0000 0001
	std::cout << std::bitset<8>(opt1) << std::endl;			// 0000 0010
	std::cout << std::bitset<8>(opt2) << std::endl;			// 0000 0100
	std::cout << std::bitset<8>(opt3) << std::endl;			// 0000 1000

	unsigned char		items_flag = 0;

	std::cout << std::bitset<8>(items_flag) << std::endl;	// 0000 0000

	// item0 on
	items_flag |= opt0;
	std::cout << std::bitset<8>(items_flag) << std::endl;	// 0000 0001
	// item3 on
	items_flag |= opt3;
	std::cout << std::bitset<8>(items_flag) << std::endl;	// 0000 1001
	// item3 off
	items_flag &= ~opt3;
	std::cout << std::bitset<8>(items_flag) << std::endl;	// 0000 0001
	// has item0 or item1?
	if (items_flag & opt0)
		std::cout << "has item0" << std::endl;
	if (items_flag & opt1)
		std::cout << "has item1" << std::endl;
	// obtain both item2, 3
	items_flag |= (opt2 | opt3);
	std::cout << std::bitset<8>(items_flag) << std::endl;	// 0000 1101
	// item change
	if ((items_flag & opt2) && !(items_flag & opt1))
		items_flag ^= (opt2 | opt1);
	std::cout << std::bitset<8>(items_flag) << std::endl;	// 0000 1011

	// bit flag 사용 예제

	// 다른 파라미터를 다 타이핑하는 것은 부담, 여러 파라미터를 사용하지 않고 하나만 사용하는 경우
	// O_CREAT | O_TRUNC 등도 같은 활용법
	// glClear(GL_COLOR_BUFFER_BIT | GT_DEPTH_BUFFER_BIT);

	// color hex code (RGB 각 256 bit)
	// #FFFFFF => RGB를 분리
	unsigned int 		pixel_color = 0xDAA520;				// 0x00DAA520
	const unsigned int	red_mask = 0xFF0000;
	const unsigned int	green_mask = 0x00FF00;
	const unsigned int	blue_mask = 0x0000FF;

	std::cout << std::bitset<32>(pixel_color) << std::endl;	// 00000000 11011010 10100101 00100000
	std::cout << std::bitset<32>(red_mask) << std::endl;	// 00000000 11111111 00000000 00000000
	std::cout << std::bitset<32>(green_mask) << std::endl;	// 00000000 00000000 11111111 00000000
	std::cout << std::bitset<32>(blue_mask) << std::endl;	// 00000000 00000000 00000000 11111111

	// 담을 공간이 8 bit 밖에 안 되는데, 계산 결과는 32 bit
	unsigned int 		red = (pixel_color & red_mask) >> 16;
	unsigned int 		green = (pixel_color & green_mask) >> 8;
	unsigned int 		blue = (pixel_color & blue_mask);

	std::cout << std::bitset<8>(red) << std::endl;		// 11011010
	std::cout << std::bitset<8>(green) << std::endl;	// 10100101
	std::cout << std::bitset<8>(blue) << std::endl;		// 00100000

	// 연습 문제
	// 아래 두 줄이 왜 동일하게 작동하는지 설명해보세요
	myflags &= ~(option4 | option5);
	myflags &= ~option4 & ~option5;

	return (0);
}
