// 7.10 스택과 힙

// code 											: 작성한 프로그램
// initialized data(BSS, Block started by symbol)	: (zero-initialized) global, static
// uninitialized data(data)							: (initialized) global, static
// stack											: local
// heap												: new

// stack
// 장점 : 빠름, 다음 실행할 코드의 위치를 알고 있음
// 단점 : 공간이 작음(stack overflow) e.g., 재귀 호출이 많아질 경우
int	arr[100000000];

// heap
// 장점 : 공간이 큼
// 단점 : 메모리 어디에 생길지 예측하기가 힘듦(OS가 공간을 찾아야 함)

#include <iostream>

// 1. 전역 변수 g_i data에 할당
// 2. stack : 현재 실행시켜야 하는 것이 가장 위에 있어 실행이 빠름
// 2-3. second() : int x		=> 2.4 second() 제거
// 2-2. first() : int x, int y	=> 2.5 first() 제거
// 2-1. main() : int a, int b	=> 2.6 main() 제거
// 3. g_i 제거

int	g_i	= 0;

int	second(int x)
{
	return (x * 2);
}

int	first(int x)
{
	int	y = 3;
	return (second(x + y));
}

int	main()
{
	int	a = 1, b;

	b = first(a);
	std::cout << b << std::endl;	// 8

	return (0);
}

// stack
// 1. main() : int *ptr;
// 4. nullptr로 할당 후 사용

// heap
// 2. sizeof(int) * 10000000 bytes => 메모리 첫 번째 주소를 리턴
// 3. 동적 할당한 메모리 해제 => stack의 ptr은 살아 있음

int	main()
{
	int	*ptr = nullptr;

	ptr = new int[10000000];
	delete[] ptr;
	ptr = nullptr;

	return (0);
}

// stack
// 1. main()
// 2. initArray() : int *ptr2 => 4. initArray() 제거
// 5. 메모리 누수 : 동적 할당한 메모리를 사용할 수 없음

// heap
// 3. sizeof(int) * 1000 bytes

void	initArray()
{
	int	*ptr2 = new int[1000];
	
	// delete[] ptr2;
}

int main()
{
	initArray();

	return (0);
}

