// 10.2 구성 관계

#include "10_2_Monster.hpp"

int	main()
{
	Monster	mon1("Sanson", Position2D(0, 0));
	// mon1.m_location은 mon1에 속함
	// mon1과 mon1.m_location은 구성 관계
	// m_location은 다른 멤버를 알 필요가 없음 => 자기 역할만 하면 됨
	// Position2D에 +, - 등 operator overloading을 하면 Monster에 정의하는 것보다 깔끔

	// 1. 다른 클래스에도 속할 수 있는가? => No
	// mon1.m_location과 mon2.m_location는 교환할 수 없음(인스턴스 수준)
	// 단, Warrior class를 만들었을 때 재사용 가능(클래스 수준)
	// 2. 멤버의 존재를 클래스가 관리할 수 있는가? => Yes
	// mon1이 소멸되면, mon1.m_location 소멸됨
	// 3. 방향성 => 단방향
	// Monster는 Position2D 멤버 함수를 알고 사용
	// Position2D는 Monster에 대해 알지 못함 => 일로 가라니까 가나 보다
	// 만약, Monster에 대해 알아야 한다면 설계가 잘못된 것
	Monster	mon2("Parsival", Position2D(0, 0));

	// game loop
	while (1)
	{
		// event
		mon1.moveTo(Position2D(1, 1));
		std::cout << mon1 << std::endl;		// Sanson 1 1
	}

	return (0);
}