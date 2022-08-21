// 1.1 프로그램의 구조

#include <iostream>
#include <unistd.h>

int main(void)
{	
	// 표현식
	1 + 1;
	// 명령문
	int x = 2;
	x = 5;
	int y = x + 3;

	// https://stackoverflow.com/questions/213907/stdendl-vs-n
	// https://m.blog.naver.com/goan109/221413446498
	// 1. std::cout << '\n'
	// 버퍼를 비우는 과정이 없어 더 빠르다.
	// terminal 같은 non-interative device에서는 동작에 차이가 없다.
	std::cout << "123\n456";
	// 2. std::endl
	// 버퍼를 비우는 과정이 있어 더 느리다.
	std::cout << "123" << std::endl << "456";
	sleep(3);

	return (0);
}
