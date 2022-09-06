// 11_2_Person.hpp

#ifndef ELEVEN_TWO_PERSON_HPP
#define ELEVEN_TWO_PERSON_HPP

// base class : 부모 클래스
#include <string>
#include <iostream>

class Person
{
// 더 편하자고 private을 사용
// m_name을 자식 클래스들이 건드리기 시작하면, m_name과 관련있는 것들을 변형하려고 할 때
// 모두 돌아다니면서 고쳐야 함 => 의도적으로 막아버린다는게 더 올바른 표현
// 장기적으로 볼 때, protected / public보다 더 깔끔하고 유지 보수가 쉬움
private:
	// 자식 클래스에서 겹치는 부분을 옮김
	std::string		m_name;

public:
	// 상속을 하든 말든, 상속을 받은 쪽에서 m_name을 사용할 수 있다고 한들
	// 관리, 책임은 Person이 가지고 있음
	Person(const std::string &name_in = "No Name")
	{
		m_name = name_in;
		std::cout << "class Person constructor" << std::endl;
	}

	const std::string	getName() const { return (m_name); }
	void				setName(const std::string &name) { m_name = name; }
	void	doNothing() const { std::cout << m_name << " is doing nothing " << std::endl; }
	~Person() {std::cout << "class Person destructor" << std::endl; }
};

#endif