// 16.2 STL 반복자 소개

// iterator
// 컨테이너 자료형의 저장된 멤버를 하나씩 접근할 때, 공통적인 방법으로 접근할 수 있는 기능
// const_iterator : 상수화
// 장점) 이터레이터는 다른 컨테이너에서도 일관되게 사용할 수 있음, 필요에 따라 선택해서 사용

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

int	main()
{
	std::vector<int>		vec;
	// 다른 컨테이너 자료형도 이터레이터를 공통으로 사용할 수 있음
	std::list<int>			lst;
	std::set<int>			set;
	std::map<int, char>		map;
	// 반복자 자체를 변수로 할당
	// 특정 컨테이너 타입에 해당하는 이터레이터
	std::vector<int>::const_iterator	itr;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	for (int i = 0; i < 10; i++)
		set.insert(i);
	for (int i = 0; i < 10; i++)
		map.insert(std::make_pair(i, char(i + 65)));

	// begin()의 리턴 값 : 이터레이터
	// 포인터라고 생각하면 될 듯?
	itr = vec.begin();
	// vector : i < size
	// iterator : itr != vec.end()
	while (itr != vec.end())
	{
		// operator overloading
		std::cout  << *itr << " ";
		++itr;
	}
	std::cout << std::endl;		// 0 1 2 3 4 5 6 7 8 9 

	// 동일
	for (auto itr = lst.begin(); itr != lst.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;		// 0 1 2 3 4 5 6 7 8 9 

	for (auto &elem : set)
		std::cout << elem << " ";
	std::cout << std::endl;		// 0 1 2 3 4 5 6 7 8 9 

	for (auto itr = map.begin(); itr != map.end(); itr++)
		std::cout << itr->first << " " << itr->second << " ";
	std::cout << std::endl;		// 0 A 1 B 2 C 3 D 4 E 5 F 6 G 7 H 8 I 9 J 

	return (0);
}