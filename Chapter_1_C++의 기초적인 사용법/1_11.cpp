// 1.11 헤더파일 만들기

#include <iostream>

// 방법 1
// 필요할 때마다 prototype을 Declare
// int	add(int a, int b);
// 단점 : 일일이 필요할 때마다 Declaration하는 것은 불편함

// 방법 2
// 헤더파일 : Declaration을 일괄적으로 모아놓은 파일
// #include "1_11.hpp"
// 헤더파일이 많아짐에 따라 코딩을 하면서 폴더로 헤더파일을 묶고 정리하는 습관을 들어야 함

// 객체 지향 프로그래밍을 하게 되면 클래스를 정의하게 되는데
// 클래스를 main 파일에 정의하지 않고
// 대부분 헤더파일/cpp 파일에 정의하고 #include 함

#include "1_11.hpp"

int main()
{
	std::cout << add(1, 2) << std::endl;

	return (0);
}
