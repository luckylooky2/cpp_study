// 8.8 클래스 코드와 헤더 파일

// 헤더 파일을 만들어 class의 선언과 정의를 분리

#include "8_8_Calc.hpp"

int	main()
{
	Calc	cal1(10), cal2(10);

	cal1.add(10);							// 90
	cal1.sub(2);
	cal1.mult(5);
	cal1.print();
	cal2.add(10).sub(2).mult(5).print();	// 90

	return (0);
}