// 13.2 클래스 템플릿

// 함수가 구현된 cpp 파일을 읽고 싶은데 include한 것은 hpp파일 뿐
// templatize된 MyArray 클래스를 특정한 타입, 여기서는 char 타입으로 instanciation을 할 떄
// 어떤 타입으로 해야할 지를 cpp 파일을 컴파일 할 때는 알지 못함
// => 매우 불편한 문제
#include "13_2_MyArray.hpp"
// 방법 1.프로젝트 규모가 커지면 걷잡을 수 없는 문제가 생김, 지양할 것
#include "13_2_MyArray.cpp"
// 방법 2. explicit instantiation

int	main()
{
	// 클래스 템플릿은 함수 템플릿과 달리 개체를 선언할 때 템플릿 매개변수를 반드시 명시해 주어야 한다.
	// error: use of class template 'MyArray' requires template arguments
	// 템플릿 파라미터에 들어갈 인자가 세팅이 되지 않음
	// MyArray	my_array(10);
	MyArray<char>	my_array(10);

	for (int i = 0; i < my_array.getLength(); i++)
		my_array[i] = i * 10;
	my_array.print();

	return (0);
}