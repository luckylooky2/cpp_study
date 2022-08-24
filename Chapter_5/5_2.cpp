// 5.2 조건문 if

#include <iostream>

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int main()
{
	int	x, y;
	
	std::cin >> x;
	// if 괄호 안에는 boolean type
	// 숫자 0이 아니면 true
	if (x > 10)
	{
		std::cout << x << " is greater than 10";
		std::cout << '\n';
	}
	// if문의 결과가 false라면 else로 이동
	// implicit block : if문 다음에 명령문이 하나일 경우에는 중괄호 생략 가능
	else
		std::cout << x << " is greater than 10" << std::endl;

	// redefinition error?
	// 스코프, 듀레이션이 중괄호로 제한이 되기 때문에 정상 작동
	if (1)
		int	x = 5;
	else
		int	x = 6;
	std::cout << x << std::endl;

	// chaining
	if (x > 10)
		std::cout << x << " is greater than 10" << std::endl;
	else if (x < 10)
		std::cout << x << " is less than 10" << std::endl;
	// x == 10일 경우를 처리하고 싶다면
	else
		std::cout << x << " is exactly 10" << std::endl;
	
	// 중첩 if문은 직관적으로 파악하기 어렵기 때문에 사용을 지양
	// else의 위치가 indenting과 관계없이 자동으로 가까운 if문에 붙기 때문에 조심해야 함
	if (x >= 10)
		if (x <= 20)
			std::cout << "x ix between 10 and 20" << std::endl;
		else
			std::cout << "..." << std::endl;
	
	std::cin >> x >> y;
	if (x > 0 && y > 0)
		std::cout << "both numbers are positive" << std::endl;
	else if (x > 0 || y > 0)
		std::cout << "one of the numbers is positive" << std::endl;
	else
		std::cout << "Neither number is positive" << std::endl;

	min(x, y);

	// null statement
	// 왜 null statement를 사용하는지 주석을 추가
	if (x > 10)
		;
	if (x > 20)
	{
	};
	// 주의 : x = 1 항상 실행
	if (x > 30);
	{
		x = 1;
	}

	std::cin >> x;
	// if (x == 0)와 비교해서 주의
	if (x = 0)	// x = 0; if(x)
		std::cout << x << std::endl;
	std::cout << x << std::endl;

	return (0);
}