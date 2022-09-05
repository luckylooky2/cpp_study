// 11_2_Student.hpp

#ifndef ELEVEN_TWO_STUDENT_HPP
#define ELEVEN_TWO_STUDENT_HPP

#include "11_2_Person.hpp"

class Student : public Person
{
private:
	unsigned int	m_intel;	// intelligence

public:
	Student(const std::string name_in = "No name", const unsigned int &intel_in = 0)
		// 추상화, 상속 책임
		: Person(name_in), m_intel(intel_in)
	{
		// Student가 생성이 될 때, m_name은 정의가 되어있지 않음
		// m_name은 Person에서 담당해야 함
		// Student에서 Person의 생성자를 호출해 간접적으로 초기화하는 방식
		// => Person에서 m_name을 초기화하는 생성자를 추가
		// m_name = name_in;
		// m_intel = intel_in;
		std::cout << "class Student constructor" << std::endl;
	}

	// m_name을 건드리기 때문에 Person으로 옮김
	// const std::string	getName() const { return (m_name); }
	// void				setName(const std::string &name)
	// {
	// 	m_name = name;
	// }

	// Person으로 옮기지 못함
	const unsigned int	getIntel() const { return (m_intel); }
	void				setIntel(const unsigned int &intel) { m_intel = intel; }

	void	study() { std::cout << this->getName() << " is studying " << std::endl; }

	~Student() { std::cout << "class Student destructor" << std::endl; }
};

std::ostream& operator<<(std::ostream &out, const Student &student)
{
	out << student.getName() << " " << student.getIntel();
	return (out);
}

#endif