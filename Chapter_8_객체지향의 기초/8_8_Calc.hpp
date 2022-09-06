// 8_8_Calc.hpp

#ifndef EIGHT_EIGHT_CALC_HPP
#define EIGHT_EIGHT_CALC_HPP

#include <iostream>

// 헤더 파일에서 using namespace를 사용하면
// include하는 전체 파일에 영향을 주기 때문에 쓰면 안 됨

class Calc
{
private:
	int	m_value;

public:
	Calc(const int &init_value);
	// class 내에 멤버 함수의 정의를 적어놨으면 컴파일러가 inline으로 간주
	// inline Calc	&Calc::add(const int &value) { m_value += value; return (*this); }
	Calc	&add(const int &value);
	Calc	&sub(const int &value);
	Calc	&mult(const int &value);
	void	print();
	~Calc();
};

#endif