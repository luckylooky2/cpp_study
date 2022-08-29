// 7.7 함수 오버로딩

// function overloading
// 동일한 이름을 갖는 함수를 여러 개 만드는 것
// 어떤 숫자를 더하고 싶은데, 자료형을 신경쓰고 싶지 않다
// 들어오는 매개변수는 다른데, 수행하는 기능은 비슷비슷한 경우

// 이름이 같아도 매개변수가 다르면 다른 함수로 인식
// 그것 중에 매개변수 타입이 가장 잘 맞는 함수를 찾아서 실행

#include <iostream>

// int와 my_int는 같은 자료형
typedef int	my_int;
void	printInt(int x) {};
void	printInt(my_int x) {};

// addInt(), addDouble() => add()
int	add(int x, int y)
{
	return (x + y);
}

double	add(double x, double y)
{
	return (x + y);
}

// C++에서는 리턴 타입이 다른 것만으로는 함수 오버로딩이 불가
// error: functions that differ only in their return type cannot be overloaded
int		add(double x, double y)
{
	return (x + y);
}

// 어떻게 구현?
// 1. 함수 이름을 바꿈
// 2. 매개변수를 바꿈 
// 2-1. reference parameter => 두 줄로 써야하는 불편함이 존재
int		getRandom() => void	getRandom(int &x)
double	getRandom() => void	getRandom(double &x)
int	x;
getRandom(x);

// 2-2. dummy parameter
int		getRandom() => int		getRandom(int dummy)
double	getRandom() => double	getRandom(double dummy)
int	x = getRandom(int());

void	print(char value) {std::cout << "char *" << std::endl;};
void	print(int value) {std::cout << "int" << std::endl;};
void	print2(unsigned int value) {std::cout << "int" << std::endl;};
void	print2(float value) {std::cout << "int" << std::endl;};

int main()
{
	// 어떤 add()를 사용할 지는 컴파일 시점에 결정되어야 함
	std::cout << add(1, 2) << std::endl;		// 3
	std::cout << add(1.5, 2.5) << std::endl;	// 4
	// error: call to 'add' is ambiguous
	std::cout << add(1.5, 2) << std::endl;		// 4

	// 가장 가까운 자료형으로 매칭을 못 할 경우
	print(0);		// int
	print('a');		// char
	// error: no matching function for call to 'print'
	print("a");
	// 가장 가까운 자료형이 2개 이상일 경우
	// error: call to 'print2' is ambiguous
	print2('a');
	print2(0);
	print2(3.141592);
	
	// 함수 오버로드를 잘 사용하면 편하지만, 자료형에 주의를 기울여야 함
	// 모든 타입에 대해 정리를 해 주는 편이 좋음

	return (0);
}