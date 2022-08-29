// 7.3 참조에 의한 인수 전달 call by reference

// call by reference

#include <iostream>
#include <cmath>	// std::sin(), std::cos()
#include <vector>

// 파라미터로 다음과 같은 방식을 많이 사용
void	foo(const int &x)
{
	std::cout << x << std::endl;
}

// 포인터를 reference로 받는 방법
// 1. (int *) &ptr
// 2. typedef int * pint; pint &ptr;
// 클래스 정의하고 이중/삼중 포인터를 쓸 때 유용 => 돌려서 사용하여 실수를 줄이는 노력
void	bar(int *&ptr)
{
	std::cout << ptr << " " << &ptr << std::endl;
}

// 파라미터가 복사되지 않음
// 클래스 생성자로 이후에 증명
void	addOne(int &y)
{
	y = y + 1;
	std::cout << y << " " << &y << std::endl;	// 6 0x7ffee3af581c
}

// C에서는 변수 한 개 밖에 리턴을 못하기 때문에
// 변수 여러 개를 리턴하려는 경우에는 call by reference/address를 사용하여 간접적으로 리턴
void	getSinCos(const double &degrees, double &sin_out, double &cos_out)
{
	// 처음에만 초기화 => 연산량 감소
	static const double	pi = 3.141592;
	const double		radians = degrees * pi / 180.0;

	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

void	printStaticArray(const int (&arr)[4])
{
	for (const int &elem : arr)
		std::cout << elem << " ";
	std::cout << std::endl;
}

void	printVector(const std::vector<int> &arr)
{
	for (int i = 0; i < 4; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int	main()
{
	int x = 5;

	std::cout << x << " " << &x << std::endl;	// 5 0x7ffee3af581c
	// 매개변수는 전달한 변수는 x와 동일
	// 변수 자체를 넘기는 것 => 주소가 같음
	addOne(x);
	std::cout << x << " " << &x << std::endl;	// 6 0x7ffee3af581c

	double	sin(0.0);
	double	cos(0.0);
	double	&sin_out = sin;
	double	&cos_out = cos;

	std::cout << sin_out << " " << cos_out << std::endl;	// 0 0
	// 리터럴을 전달하려고 한다면
	// 1. 파라미터에서 &를 제거
	// 2. 파라미터에 const 추가(물론 변경하지 않는 경우에만)
	getSinCos(90.0, sin_out, cos_out);
	std::cout << sin_out << " " << cos_out << std::endl;	// 1 3.26795e-07

	int	y = 5;
	int	*ptr = &y;

	std::cout << ptr << " " << &ptr << std::endl;	// 0x7ffee07887ec 0x7ffee07887e0
	bar(ptr);										// 0x7ffee07887ec 0x7ffee07887e0

	int					arr[] = {1, 2, 3, 4};
	// C++ 11
	std::vector<int>	new_arr {1, 2, 3, 4};

	// 파라미터를 설정하기 귀찮음
	printStaticArray(arr);	// 1 2 3 4
	printVector(new_arr);	// 1 2 3 4

	return (0);
}