// 10_3_Lecture.hpp

#ifndef TEN_THREE_LECTURE_HPP
#define TEN_THREE_LECTURE_HPP

#include <vector>
#include "10_3_Teacher.hpp"
#include "10_3_Student.hpp"

class Lecture
{
private:
	std::string				m_name;
	// composition
	// Lecture가 사라질 때, Teacher, Student도 같이 사라짐

	Teacher					*teacher;
	// cf> students => vector의 인스턴스, Lecture 인스턴스가 사라지면 사라짐
	// Student *가 가리키고 있는 주소의 값들은 그대로 유지
	std::vector<Student *>	students;
	

public:
	Lecture(const std::string name_in)
	{
		m_name = name_in;
		// std::cout << "class Lecture constructor" << std::endl;
	}

	const std::string			getName() const { return (m_name); }
	const Teacher				*getTeacher() const { return (teacher); }
	const std::vector<Student*>	getStudents() const { return (students); }

	void	assignTeacher(Teacher *teacher_in)
	{
		teacher = teacher_in;
	}

	void	registerStudent(Student *student_in)
	{
		// stack처럼 사용
		// std::vector가 복사해서 생성하기 떄문
		// 멤버 변수의 주소를 가지고 오는 방법으로 해결
		students.push_back(student_in);
	}

	void	study()
	{
		std::cout << m_name << " Study " << std::endl << std::endl;
		// reference가 아니라 value로 받아오면 값이 업데이트가 되지 않음
		// for (Student &elem : students)
		// 	elem.setIntel(elem.getIntel() + 1);
		// aggregation relationship
		for (Student *elem : students)
			elem->setIntel(elem->getIntel() + 1);
	}

	~Lecture()
	{
		// do NOT delete teacher
		// do NOT delete students
		// std::cout << "class Lecture destructor" << std::endl;
	}
};

std::ostream& operator<<(std::ostream &out, const Lecture &lecture)
{
	out << "Lecture name : " << lecture.getName() << std::endl;
	out << lecture.getTeacher() << std::endl;
	// for (auto &elem : lecture.getStudents())
	// 	out << elem << std::endl;
	// aggregation relationship
	for (auto elem : lecture.getStudents())
		out << *elem << std::endl;
	return (out);
}

#endif