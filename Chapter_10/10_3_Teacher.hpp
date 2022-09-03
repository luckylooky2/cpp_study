// 10_3_Teacher.hpp

#ifndef TEN_THREE_TEACHER_HPP
#define TEN_THREE_TEACHER_HPP

#include <iostream>
#include <string>

class Teacher
{
private:
	std::string	m_name;
	// TODO : more members like home address, salary, age, evaluation, etc.

public:
	Teacher(const std::string name_in = "No name")
	{
		m_name = name_in;
		// std::cout << "class Teacher constructor" << std::endl;
	}

	const std::string	getName() const { return (m_name); }
	void				setName(const std::string &name)
	{
		m_name = name;
	}

	~Teacher()
	{
		// std::cout << "class Teacher destructor" << std::endl;
	}
};

std::ostream& operator<<(std::ostream &out, const Teacher &teacher)
{
	out << teacher.getName();
	return (out);
}

#endif