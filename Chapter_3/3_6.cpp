// 3.6 논리 연산자

#include <iostream>

int main()
{
	bool	x = true;
	bool	y = false;

	// logical NOT
	std::cout << !x << std::endl;			// false
	// logical AND
	std::cout << (x && y) << std::endl;		// false
	// logical OR
	std::cout << (x || y) << std::endl;		// true
	// logical XOR : C/C++에는 존재하지 않음 
	if (x != y)
	{
		// do something
	}
	
	bool	hit = true;
	int		health = 21;

	// if 중첩문을 사용할 경우, 스코프 등이 오히려 더 복잡해짐
	// 논리 연산자를 적극적으로 사용
	if (hit == true && health < 20)
	{
		std::cout << "die " << std::endl;
	}
	else
		health -= 20;

	int	a = 5;
	int	b = 7;

	// !이 ==보다 우선순위가 높음
	// warning: logical not is only applied to the left hand side of this comparison
	// if (!(a == b))
	if (!a == b)
		std::cout << "x does not equal y" << std::endl;
	else
		std::cout << "x equals y" << std::endl;

	int	life = 1;

	if (life == 0 || life == 1)
		std::cout << "life is 0 or 1" << std::endl;

	// short circuit evaluation
	a = 2;
	b = 2;
	if (a == 1 && b++ == 2)
	{
		// do something
	}
	std::cout << b << std::endl;	// 2

	// De Morgan's Law
	!(x || y);
	!x && !y;

	// 연습 문제
	(true && true) || false;			// true
	(false && true) || true;			// true 
	(false && true) || false || true;	// true
	(14 > 13 || 2 > 1) && (9 > 1);		// true
	!(2314123 > 2 || 123123 > 2387);	// false

	// &&가 ||보다 우선순위가 높음
	bool	v1 = true;
	bool	v2 = false;
	bool	v3 = false;

	std::cout << (v1 || v2 && v3) << std::endl;		// true
	std::cout << (v1 || (v2 && v3)) << std::endl;	// true
	std::cout << ((v1 || v2) && v3) << std::endl;	// false

	return (0);
}