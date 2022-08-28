// 6.11 메모리 동적 할당, new와 delete

// 정적 메모리 할당
// data
// 전역 변수, 정적 변수와 같이 한 번 할당하면
// 프로그램이 끝날 때까지 존재하는 변수

// 자동 메모리 할당
// stack : 메모리 용량이 작음 => 큰 변수가 필요할 때는 부적절
// 변수나 정적 배열을 선언했을 때
// 블록 밖으로 나가면 메모리를 반납하는 변수

// 동적 메모리 할당
// heap : 메모리 용량이 훨씬 큼

#include <iostream>

int	main()
{
	// 커지면 stack overflow 위험
	int	array[1000000];

	// 동적 할당 : int 자료형에 해당하는 공간을 받아오고, 주소를 알려줌
	// 널 가드 => (std::nothrow)
	// 동적 할당을 받지 못하는 경우에도 에러를 발생시키지 않고
	// 에러 처리를 통해 ptr_i에 nullptr을 할당
	int	*ptr_i = new (std::nothrow) int(7);
	int	*ptr_i2 = ptr_i;

	*ptr_i = 10;
	std::cout << ptr_i << std::endl;	// 0x12a606720
	std::cout << *ptr_i << std::endl;	// 10
	// 동적 할당한 메모리는 필요가 없어진 경우 OS에게 반드시 돌려주어야 함
	// 물론 프로그램이 끝날 때 OS가 자동으로 회수하지만 메모리 누수의 위험이 있음
	
	delete ptr_i;
	
	// 메모리는 이미 반납이 됐는데 다시 접근한 것 => 댕글링 포인터?
	std::cout << "After delete" << std::endl;
	std::cout << ptr_i << std::endl;			// 0x12a606720
	std::cout << *ptr_i << std::endl;			// 10

	// 방법 1
	ptr_i = nullptr;
	if (ptr_i != nullptr)
	{
		std::cout << ptr_i << std::endl;
		std::cout << *ptr_i << std::endl;
	}
	// 방법 2 : 스마트 포인터

	// ptr_i2도 똑같이 해제된 메모리를 가리키고 있음
	// 방법 1 : 디버깅하면서 ptr_i2 = nullptr 코드를 추가
	// 방법 2 : 스마트 포인터를 이용

	// memory leak
	while (true)
	{
		// 두 번째 반복부터 메모리 누수가 발생
		// 실행중인 프로세스에서 메모리 사용량이 계속해서 늘어남
		int	*ptr = new int;

		std::cout << ptr << endl;
		// 필요가 없어진 동적 할당 변수는 반드시 해제
		delete ptr;
	}

	return (0);
}