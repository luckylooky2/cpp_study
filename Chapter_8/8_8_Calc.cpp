// 8_8_Calc.cpp
// 헤더 파일의 각 함수를 정의해 놓은 파일

// 정의부를 헤더 파일에 남겨 놓는것을 더 권장할 때도 있음
// 1. template 구현을 cpp 파일로 옮긴다면 더 번거로울 때가 존재
// 물론 cpp 파일로 구현해도 됨
// 2. 바쁠 때? 어쩔 수 없는 경우

#include "8_8_Calc.hpp"

// add()가 어디에 있는지 알 수 없어서 멤버 접근이 불가
// Calc:: => Calc class의 멤버라는 표시

Calc::Calc(const int &init_value)
{
	m_value = init_value;
	std::cout << "class Calc constructor" << std::endl;
}

Calc	&Calc::add(const int &value) { m_value += value; return (*this); }
Calc	&Calc::sub(const int &value) { m_value -= value; return (*this); }
Calc	&Calc::mult(const int &value) { m_value *= value; return (*this); }

void	Calc::print()
{
	std::cout << m_value << std::endl;
}

Calc::~Calc()
{
	std::cout << "class Calc destructor" << std::endl;
}