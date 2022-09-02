// 9.7 괄호 연산자(()) 오버로딩과 함수 객체

// 괄호 연산자
// 함수를 호출할 때 사용
// 오버로딩하면 함수가 객체인 것처럼 사용할 수 있음

#include <iostream>

class Accumulator
{
private:
	int	m_counter = 0;

public:
	// // 첨자 연산자([])를 오버로딩하는 방법과 똑같음
	// int			operator()(int i)
	// {
	// 	return (m_counter += i);
	// }

	// // chaining
	// Accumulator &operator()(int i)
	// {
	// 	m_counter += i;
	// 	return (*this);
	// }

	// friend std::ostream&	operator<<(std::ostream& out, const Accumulator &acc)
	// {
	// 	out << acc.m_counter;

	// 	return (out);
	// }
};

int	main()
{
	Accumulator	acc;

	std::cout << acc(10) << std::endl;		// 10
	std::cout << acc(20) << std::endl;		// 30

	// 이 class에 accumulate()라는 멤버 함수로 똑같은 기능을 구현할 수도 있음
	// 마치 함수를 호출하는 것처럼 보임 => functor
	// chaining도 구현이 가능
	// std::cout << acc(10)(20) << std::endl;	// 60
	
	return (0);
}