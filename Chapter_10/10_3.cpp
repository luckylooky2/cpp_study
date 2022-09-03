// 10.3 집합 관계

// 구성 관계 : class가 멤버 변수들을 꽉 쥐고 있는 형태
// 집합 관계 : 조금 더 느슨한 관계

#include <vector>
#include <string>
#include "10_3_Lecture.hpp"

int main()
{
	// composition relationship
	// 이름과 지력을 일일이 외워서 입력해야 하는 불편함
	Lecture	lec1("Introduction to Computer Programming");
	lec1.assignTeacher(Teacher("Prof. Hong"));
	lec1.registerStudent(Student("Jack Jack", 0));
	lec1.registerStudent(Student("Dash", 1));
	lec1.registerStudent(Student("Violet", 2));

	Lecture	lec2("Computational Thinking");
	lec1.assignTeacher(Teacher("Prof. Good"));
	lec1.registerStudent(Student("Jack Jack", 0));

	std::cout << lec1 << std::endl;
	std::cout << lec2 << std::endl;
	
	// lec2과 lec1에 있는 Jack Jack은 같은 사람인데 지능이 같이 오를지?
	// composition으로 구현했기 때문에 동기화가 되지 않음
	// 1. aggregation으로 구현
	// 2. 동기화를 직접 구현하는 방법 => 불편함
	// composition과 aggregation을 바꿔가며 구현할 수 있음
	lec2.study();
	std::cout << lec1 << std::endl;
	std::cout << lec2 << std::endl;

	// aggregation relationship

	return (0);
}