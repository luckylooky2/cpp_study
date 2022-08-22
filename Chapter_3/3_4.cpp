// 3.4 sizeof, 쉼표 연산자, 조건부 연산자

#include <iostream>

// sizeof operator
// 자료형의 크기를 알고 싶을 때
// struct, class : 사용자 정의 자료형에도 사용할 수 있음
// 함수인가? 연산자인가?
// 1. 표준에서 연산자라고 정의
// 2. 변수명일 경우, 괄호가 없어도 작동

// comma operator
// for 반복문에서 복잡해질 때 많이 사용
// 사용할 때 주의가 필요 why?
// 일반적인 경우에 사용하기 보다는 풀어쓰는 편이 직관적이고 읽기 쉬움

// conditional operator
// 삼항 연산자라고도 함(하나 밖에 없어서)
// arithmetric if : 조건을 처리할 때 if문을 안 쓰고 처리하기 때문에
// C에서는 if문을 더 많이 사용
// conditional operator을 사용한 결과는 식

int	add(int a, int b)
{
	return (a + b);
}

int main()
{
	// sizeof
	float	f;

	std::cout << sizeof(float) << std::endl;	// 4
	std::cout << sizeof(f) << std::endl;		// 4

	// comma operator
	int	x = 3;
	int	y = 10;
	int	z = (++x, ++y);
	// ++x;
	// ++y;
	// int z = y;

	std::cout << x << " " << y << " " << z << std::endl;	// 4 11 11

	// comma operator가 아님(구분 기호)
	int a = 1, b = 10;
	add(1, 2);

	int c;

	// comma는 assignment보다 우선순위가 낮음
	c = a, b;
	std::cout << c << std::endl;	// 1

	c = (a, b);
	std::cout << c << std::endl;	// 10

	c = (++a, a + b);
	std::cout << c << std::endl;	// 12

	// conditional operator
	bool	onSale = true;
	int		price;

	if (onSale)
		price = 10;
	else
		price = 100;

	// const를 사용하고자 할 때
	const int	newPrice = (onSale == true) ? 10 : 100;

	std::cout << price << std::endl;		// 10
	std::cout << newPrice << std::endl;		// 10

	int	i = 5;

	// 연산자 우선순위?
	std::cout << (x % 2 == 0) ? "even" : "odd" << std::endl;
	std::cout << ((x % 2 == 0) ? "even" : "odd") << std::endl;	// even

	return (0);
}