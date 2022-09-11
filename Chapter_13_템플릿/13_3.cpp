// 13.3 자료형이 아닌 템플릿 매개변수

#include "13_3_MyArray.hpp"

int	main()
{
	// std::array<double, 100>
	// array 템플릿을 사용할 때는 자료형, 파라미터를 같이 입력
	// MyArray를 non-type parameter를 넣도록 변경
	// 템플릿이라는 과정이 컴파일 과정에서 진행되는 것이기 때문에
	// 템플릿 안에 변수를 사용하는 방식은 런타임 결정이라 사용할 수 없음
	// => 컴파일타임에 결정되어 있어야 함
	// int	i = 100;
	// MyArray<int, i>	my_array;
	// 메모리를 결정할 때도 사용되지만 알고리즘에서 2차원, 3차원을 구현할 때도 많이 사용됨
	MyArray<int, 100>	my_array;

	for (int i = 0; i < my_array.getLength(); i++)
		my_array[i] = i + 65;
	my_array.print();

	return (0);
}