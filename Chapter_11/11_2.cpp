// 11.2 상속의 기본 [2/2]

#include <iostream>
#include "11_2_Teacher.hpp"
#include "11_2_Student.hpp"

// Teacher, Student 모두 m_name이라는 멤버가 있음
// class Person => 공통적인 것을 일반화할 수 있음

int	main()
{
	Person	ps;
	Teacher	tch("Dr. H");
	Student std("Jack Jack");

	std.setName("Jack Jack 2");
	std::cout << std << std::endl;		// Jack Jack 2 0
	// 모든 함수를 Person에 몰아서 정의하는 경우도 있음
	// 하지만 대부분 상속받은 클래스에 필요한 기능을 나누어서 정의함
	// 다른 사람이 봤을 때도 납득이 가는 구조로 설계해야 협업에 편함
	std.doNothing();					// Jack Jack 2 is doing nothing 
	std.study();						// Jack Jack 2 is studying 

	tch.setName("Dr. K");
	std::cout << tch << std::endl;		// Dr. K
	tch.doNothing();					// Dr. K is doing nothing 
	tch.teach();						// Dr. K is teaching 

	ps.setName("Mr. incredible");
	ps.getName();
	// 자식 클래스에 있는 것을 부모 클래스에서 사용하지 못함
	ps.study();		// error
	ps.teach();		// error

	return (0);
}

// 자료화면 캡쳐 필요