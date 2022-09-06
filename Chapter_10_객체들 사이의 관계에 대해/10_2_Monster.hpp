// 10_2_Monster.hpp

#ifndef TEN_TWO_MONSTER_HPP
#define TEN_TWO_MONSTER_HPP
#include "10_2_Position2D.hpp"
#include <string>

class Monster
{
private:
	// std::string에서 (char *data, unsigned length)를 묶어서 class로 사용하는 것처럼
	// x, y 좌표도 class로 정의하는 것이 좋음
	std::string	m_name;
	// Position2D class를 다른 class를 만들 때 사용한다는 개념과
	// Position2D 인스턴스를 class 내부에서 사용한다는 개념은 다르다는 것에 주의
	// 서브 클래스
	Position2D	m_location;

public:
	Monster(const std::string name_in, const Position2D &pos_in)
	{
		m_name = name_in;
		m_location = pos_in;
		std::cout << "class Monster constructor" << std::endl;
	}

	// 중요
	// Monster 인스턴스를 제어하고자 할 때,
	// Monster class 입장에서는 Position2D 멤버 함수가 어떻게 동작하는지 알 필요가 없음
	// 단순히 호출하면 되는 것 => 기능을 분리, 추상화
	void	moveTo(const Position2D &pos_target)
	{
		// 방법 1.
		// Position2D class에서 assignment operator overloading
		// m_location = pos_target;처럼 사용 가능
		// 방법 2.
		// 함수 추가 => 함수 오버로딩 가능
		// 방법 3.
		// getter 함수 추가?
		m_location.setPosition(pos_target);
	}

	~Monster()
	{
		std::cout << "class Monster destructor" << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& out, const Monster &monster)
	{
		// << monster.m_location이 가능한 이유?
		// Position2D class에서도 operator overloading을 했기 때문
		out << monster.m_name << " " << monster.m_location;
		return (out);
	}
};

#endif