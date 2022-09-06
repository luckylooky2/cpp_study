// 11_2_Teacher.hpp

#ifndef ELEVEN_TWO_TEACHER_HPP
#define ELEVEN_TWO_TEACHER_HPP

#include "11_2_Person.hpp"

class Teacher : public Person
{
private:

public:
	Teacher(const std::string name_in = "No name")
		: Person(name_in)
	{
		// m_name = name_in;
		std::cout << "class Teacher constructor" << std::endl;
	}

	// m_name을 건드리기 때문에 Person으로 옮김
	// 함수 안에서 this->getName()처럼 부모 클래스에서 가져다 쓸 수 있음
	// const std::string	getName() const { return (m_name); }
	// void				setName(const std::string &name)
	// {
	// 	m_name = name;
	// }

	void	teach() { std::cout << this->getName() << " is teaching " << std::endl; }

	~Teacher() { std::cout << "class Teacher destructor" << std::endl; }
};

// const Teacher &teacher을 받아오려면, getName()도 const function이어야 함
// Teacher, Student 둘 다 수정해야 할 것을 Person에서 한 번만 수정
std::ostream& operator<<(std::ostream &out, const Teacher &teacher)
{
	// friend를 사용할 경우 teacher.m_name을 아래와 같이 수정
	out << teacher.getName();
	return (out);
}

#endif