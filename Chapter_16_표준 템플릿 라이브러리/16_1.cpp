// 16.1 표준 템플릿 라이브러리(STL)와 컨테이너 소개

// Standard Template Libraries
// 1. Containers
// 2. Iterators
// 3. Algorithms
// 4. Functions

// STL과 C++ 표준 라이브러리의 차이가 무엇인가?
// 굳이 구분짓자면 위의 4개에 해당하는 라이브러리를 STL, 그 외 표준 라이브러리로 구분

// 하나 하나 공부하기보다는, 필요할 때 reference를 찾아 읽으면서 활용하는 것이 좋음
// 가져다 사용하는 것도 중요하지만
// 자료 구조의 원리를 아는 것도 중요하기 때문에 한 번씩 구현해 볼 것

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>

void	sequence_containers()
{
	// vector => #include <vector>
	{
		std::vector<int>	vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);
		for (auto &elem : vec)
			std::cout << elem << ' ';
		std::cout << std::endl;		// 0 1 2 3 4 5 6 7 8 9 
	}

	// deque => #include <deque>
	// vector와 다르게 앞, 뒤로 추가할 수 있음
	{
		std::deque<int>	deq;

		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.push_front(i);
		}
		for (auto &elem : deq)
			std::cout << elem << ' ';
		std::cout << std::endl;		// 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9 
	}
}

void	associative_containers()
{
	// set => #include <set>
	// 같은 원소가 이미 있다면 추가하지 않음
	{
		std::set<std::string>	str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");
		std::cout << str_set.size() << std::endl;	// 2
		for (auto &elem : str_set)
			std::cout << elem << ' ';
		std::cout << std::endl;						// Hello World 
	}

	// multiset : duplication is allowed
	// 같은 원소가 있어도 추가함, 원소의 순서는 어떻게 정해지나?
	{
		std::multiset<std::string>	str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");
		std::cout << str_set.size() << std::endl;	// 3
		for (auto &elem : str_set)
			std::cout << elem << ' ';
		std::cout << std::endl;						// Hello Hello World 
	}

	// map : key / value => #include <map>
	// 웹 프로그래밍의 JSON의 구조와 비슷
	{
		std::map<char, int>	map;

		// key가 없을 경우 추가
		// 'c'가 먼저 추가되어도 정렬됨 why?
		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50;
		std::cout << map['a'] << std::endl;		// 10
		// key가 있는 경우 value 변경
		map['a'] = 100;
		std::cout << map['a'] << std::endl;		// 100
		// first, second를 메서드로 호출
		// error: called object type 'char' is not a function or function pointer
		for (auto & elem : map)
			std::cout << elem.first << " " << elem.second << ' ';
		std::cout << std::endl;		// a 100 b 20 c 50 
	}

	// multimap : duplicated keys
	{
		std::multimap<char, int>	map;

		map.insert(std::pair('a', 10));		// before C++ 14, pair<char, int>('a', 10);
		map.insert(std::pair('b', 10));
		map.insert(std::pair('c', 10));
		map.insert(std::pair('a', 100));
		std::cout << map.count('a') << std::endl;	// 2
		for (auto & elem : map)
			std::cout << elem.first << " " << elem.second << ' ';
		std::cout << std::endl;		// a 10 a 100 b 10 c 10 
	}
}

void	container_adapters()
{
	// stack => #include <stack>
	// LIFO
	{
		std::cout << "Stack" << std::endl;

		std::stack<int>	stack;

		// 사용자 정의 클래스를 만들어 어떤 차이가 있는지 확인해 볼 것
		// copy or move를 해서 추가(stack에 넣을 객체 생성 => 복사 객체 생성 => 복사 => 복사 객체 소멸)
		stack.push(1);		// push adds a copy
		// 새로운 객체를 만들어서 바로 추가(stack에 넣을 객체 생성 => 복사)
		stack.emplace(2);	// emplace constructs a new object
		stack.emplace(3);
		std::cout << stack.top() << std::endl;	// 3
		stack.pop();
		std::cout << stack.top() << std::endl;	// 2
	}

	// queue => #include <queue>
	// FIFO
	{
		std::cout << "Queue" << std::endl;

		std::queue<int>	queue;

		// 사용자 정의 클래스를 만들어 어떤 차이가 있는지 확인해 볼 것
		// 복사를 해서 추가(대입 연산?)
		queue.push(1);
		queue.push(2);
		queue.push(3);
		std::cout << queue.front() << " " << queue.back() << std::endl;	// 1 3
		queue.pop();
		std::cout << queue.front() << " " << queue.back() << std::endl;	// 2 3
	}
	
	// priority queue
	{
		std::cout << "Queue" << std::endl;

		// 자동으로 sorting
		// 사용자 정의 자료형을 사용하는 경우
		// 크기 비교 연산자 오버로딩이 필요
		std::priority_queue<int>	queue;

		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			queue.push(n);
		for (int i = 0; i < 10; i++)
		{
			std::cout << queue.top() << ' ';
			queue.pop();
		}
		std::cout << std::endl;		// 9 8 7 6 5 4 3 2 1 0
	}
}

int	main()
{
	// 크게 3가지로 구분
	sequence_containers();
	associative_containers();
	container_adapters();

	return (0);
}