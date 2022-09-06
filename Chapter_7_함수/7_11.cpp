// 7.11 std::vector를 스택처럼 사용하기

// 동적 할당 메모리를 직접 사용하는 것보다 vector를 사용하는 것이 쉬움
// vector 안에는 포인터 외에도 크기를 관리하는 변수 등 다양한 기능이 있음
// 내부적으로 new, delete을 호출하면서 담을 공간을 만들거나 지움
// vector는 어떻게하면 new, delete을 적게 호출할까를 생각해야 함
// why? new, delete을 호출하는 것은 상대적으로 느림

#include <iostream>
#include <vector>

void	printVector(std::vector<int> &vector)
{
	for (auto &elem : vector)
		std::cout << elem << " ";
	std::cout << std::endl;
}

void	printStack(std::vector<int> &stack)
{
	for (auto &elem : stack)
		std::cout << elem << " ";
	std::cout << "capacity : " << stack.capacity() << " ";
	std::cout << std::endl;
}

int	main()
{
	int					*arr = new int[3] {1, 2, 3};
	std::vector<int>	vec{1, 2, 3};

	delete[] arr;
	// size : 현재 사용하고 있는 메모리
	// capacity : 가지고 있는 총 메모리
	printVector(vec);							// 1 2 3
	std::cout << vec.size() << std::endl;		// 3
	std::cout << vec.capacity() << std::endl;	// 3

	vec.resize(10);
	printVector(vec);							// 1 2 3 0 0 0 0 0 0 0 
	std::cout << vec.size() << std::endl;		// 10
	std::cout << vec.capacity() << std::endl;	// 10

	// 현재보다 작은 숫자로 resize할 때는 delete, new의 과정을 거치지 않고
	// size를 줄임 => capacity와 size가 차이가 나는 이유
	vec.resize(2);
	printVector(vec);							// 1 2
	std::cout << vec.size() << std::endl;		// 2
	std::cout << vec.capacity() << std::endl;	// 10

	// 에러가 발생할 가능성
	std::cout << vec[2] << std::endl;			// 3
	// libc++abi.dylib: terminating with uncaught exception of type std::out_of_range: vector
	// std::cout << vec.at(2) << std::endl;

	int	*ptr = vec.data();

	std::cout << ptr[2] << std::endl;			// 3

	// reserve : 메모리의 용량을 미리 확보하겠다
	// 원소가 추가될 때 delete, new 과정을 거치지 않아 더 빠름
	vec.reserve(1024);
	printVector(vec);							// 1 2
	std::cout << vec.size() << std::endl;		// 2
	std::cout << vec.capacity() << std::endl;	// 1024

	// vector를 스택처럼 사용하기
	// when? stack overflow를 발생시키지 않으면서 재귀 호출을 반드시 써야 할 때
	std::vector<int>	stack;	// size : 0

	stack.push_back(3);
	printStack(stack);		// 3 capacity : 1 
	stack.push_back(5);
	printStack(stack);		// 3 5 capacity : 2
	stack.push_back(7);
	printStack(stack);		// 3 5 7 capacity : 4
	stack.pop_back();
	printStack(stack);		// 3 5 capacity : 4
	stack.pop_back();
	printStack(stack);		// 3 capacity : 4
	stack.pop_back();
	printStack(stack);		// capacity : 4

	return (0);
}