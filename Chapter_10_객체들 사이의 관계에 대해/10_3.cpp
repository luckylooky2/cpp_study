// 10.3 집합 관계

// 구성 관계 : class가 멤버 변수들을 꽉 쥐고 있는 형태
// 집합 관계 : 조금 더 느슨한 관계

// 1. 다른 클래스에도 속할 수 있는가? => Yes
// std1은 lec3에도 lec4에도 속할 수 있음(인스턴스 수준)
// 2. 멤버의 존재를 클래스가 관리할 수 있는가? => No
// lec3이 소멸되어도, std1은 소멸되지 않음
// 3. 방향성 => 단방향

// 항상 aggregation이 잘 동작하는 것은 아님
// 분산 처리 시스템에서는 컴퓨터 메모리가 분리되어 있기 떄문에 따로 짜야 함
// Student 데이터의 사본을 모든 컴퓨터가 가지고 있다가
// 업데이트가 발생하면 동기화를 하는 과정이 필요

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
	lec2.assignTeacher(Teacher("Prof. Good"));
	lec2.registerStudent(Student("Jack Jack", 0));

	std::cout << lec1 << std::endl;
	std::cout << lec2 << std::endl;
	
	// lec2과 lec1에 있는 Jack Jack은 같은 사람인데 지능이 같이 오를지?
	// composition으로 구현했기 때문에 동기화가 되지 않음
	// 1. aggregation으로 구현 => 포인터 변환
	// 2. 동기화를 직접 구현하는 방법 => 불편함
	// composition과 aggregation을 바꿔가며 구현할 수 있음
	lec2.study();
	std::cout << lec1 << std::endl;
	std::cout << lec2 << std::endl;

	// aggregation relationship

	// 여기서는 지역 변수이지만, 함수 밖에서 사용하고 싶을 경우 동적 할당
	// Student	*std1 = new Student("Jack Jack", 0);
	Student	std1("Jack Jack", 0);
	Student	std2("Dash", 1);
	Student	std3("Violet", 2);
	Teacher	tch1("Prof. Hong");
	Teacher	tch2("Prof. Good");

	Lecture	lec3("Introduction to Computer Programming");
	lec3.assignTeacher(&tch1);
	// 여전히 결과는 같음
	// std::vector가 복사해서 생성하기 떄문 => 주소값(포인터)로 넘김
	lec3.registerStudent(&std1);
	lec3.registerStudent(&std2);
	lec3.registerStudent(&std3);

	Lecture	lec4("Computational Thinking");
	lec4.assignTeacher(&tch2);
	// 문제 해결 : lec3의 std1과 lec4의 std1은 같은 사람이기 떄문에 포인터로 넘김
	lec4.registerStudent(&std1);

	std::cout << lec3 << std::endl;
	std::cout << lec4 << std::endl;
	
	lec4.study();
	std::cout << lec3 << std::endl;
	std::cout << lec4 << std::endl;

	return (0);
}

// composition relationship
// Lecture name : Introduction to Computer Programming
// Prof. Hong
// Jack Jack 0
// Dash 1
// Violet 2

// Lecture name : Computational Thinking
// Prof. Good
// Jack Jack 0

// Computational Thinking Study

// Lecture name : Introduction to Computer Programming
// Prof. Hong
// Jack Jack 0
// Dash 1
// Violet 2

// Lecture name : Computational Thinking
// Prof. Good
// Jack Jack 1

// aggregation relationship
// Lecture name : Introduction to Computer Programming
// 0x16f22f690
// Jack Jack 0
// Dash 1
// Violet 2

// Lecture name : Computational Thinking
// 0x16f22f660
// Jack Jack 0

// Computational Thinking Study

// Lecture name : Introduction to Computer Programming
// 0x16f22f690
// Jack Jack 1
// Dash 1
// Violet 2

// Lecture name : Computational Thinking
// 0x16f22f660
// Jack Jack 1