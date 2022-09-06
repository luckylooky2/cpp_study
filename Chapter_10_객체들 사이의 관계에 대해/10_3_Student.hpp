// 10_3_Student.hpp

#ifndef TEN_THREE_STUDENT_HPP
#define TEN_THREE_STUDENT_HPP

#include <iostream>
#include <string>

// 상속, 템플릿을 배우면 중복된 부분을 한 번만 구현하면 되기 때문에, 코딩하는 양이 줄어듦
// 중복되지 않는 부분만 별도로 구현해 합치는 방식
class Student
{
private:
	std::string		m_name;
	unsigned int	m_intel;	// intelligence
	// TODO : add more members like address, phone, favorite food, habits, etc.

public:
	Student(const std::string name_in = "No name", const unsigned int &intel_in = 0)
	{
		m_name = name_in;
		m_intel = intel_in;
		// std::cout << "class Student constructor" << std::endl;
	}

	const std::string	getName() const { return (m_name); }
	const unsigned int	getIntel() const { return (m_intel); }

	void				setName(const std::string &name)
	{
		m_name = name;
	}
	
	void				setIntel(const unsigned int &intel)
	{
		m_intel = intel;
	}

	~Student()
	{
		// std::cout << "class Student destructor" << std::endl;
	}
};

std::ostream& operator<<(std::ostream &out, const Student &student)
{
	out << student.getName() << " " << student.getIntel();
	return (out);
}

#endif