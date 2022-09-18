// 16.3 STL 알고리즘 소개

// 대학에서 배우는 algorithm과는 다름
// algorithm 라이브러리는 자료구조, sorting과 더 가깝다고 생각
// vector는 insert()가 느릴 수 있고(항상 그런 것은 아님)
// list는 insert()가 더 빠를 수 있음(항상 그런 것은 아님)

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int	main()
{
	std::vector<int>	container;

	for (int i = 0; i < 10; i++)
		container.push_back(i);
	
	auto itr = min_element(container.begin(), container.end());
	std::cout << *itr << std::endl;		// 0

	itr = max_element(container.begin(), container.end());
	std::cout << *itr << std::endl;		// 9

	// 사용자 정의 자료형에 대해서는 비교 연산자 오버로딩이 필요
	itr = find(container.begin(), container.end(), 3);
	container.insert(itr, 128);
	for (auto &elem : container) std::cout << elem << " ";
	std::cout << std::endl;				// 0 1 2 128 3 4 5 6 7 8 9 

	sort(container.begin(), container.end());
	for (auto &elem : container) std::cout << elem << " ";
	std::cout << std::endl;				// 0 1 2 3 4 5 6 7 8 9 128 
	
	reverse(container.begin(), container.end());
	for (auto &elem : container) std::cout << elem << " ";
	std::cout << std::endl;				// 128 9 8 7 6 5 4 3 2 1 0 

	// list는 sorting이 내부 메서드로 정의되어 있음
	// list와 vector의 차이를 이해하고 나면 그럴 수 밖에 없음을 알게 될 것
	std::list<int>	lst;

	for (int i = 0; i < 10; i++)
		lst.push_back(i);

	lst.sort();
	for (auto &elem : lst) std::cout << elem << " ";
	std::cout << std::endl;				// 0 1 2 3 4 5 6 7 8 9 
	
	lst.reverse();
	for (auto &elem : lst) std::cout << elem << " ";
	std::cout << std::endl;				// 9 8 7 6 5 4 3 2 1 0 


	return (0);
}