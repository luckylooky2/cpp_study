// 9.5 증감 연산자(++, --) 오버로딩 하기

#include <iostream>

class Digit
{
private:
	int	m_digit;

public:
	Digit(int digit = 0)
		: m_digit(digit)
	{
		std::cout << "class Digit constructor" << std::endl;
	}
	
	int	getDigit() const { return (m_digit); }

	// prefix : 전위형(++d)
	Digit&	operator++()
	{
		++m_digit;
		// 자기 자신의 de-reference
		return (*this);
	}

	// postfix : 후위형(d++)
	// 1. 더미로 int를 넣어줌
	Digit	operator++(int)
	{
		// 2. return한 다음 값을 바꿔야 하기 때문에 현재 값 저장
		Digit	temp(m_digit);

		// 3. 값 증감
		// 전위 연산자 활용
		++(*this);
		// 반환자료형이 값이라서 복사되기 때문에 지역 변수라도 문제가 없음
		// Digit & 자료형으로 반환하면 문제가 발생 
		return (temp);
	}
};

// error: invalid operands to binary expression 
// ('std::ostream' (aka 'basic_ostream<char>') and 'Digit')
// const를 붙여주니 해결
// => 오버로딩의 시그니처가 <ostream>의 원 함수의 시그니처와 동일해야 하기 때문에
// 컴파일러가 함수를 구분하기 위한 구성요소를 시그너처(signature)라 한다.
// 1. 함수의 이름
// 2. 매개변수의 개수
// 3. 매개변수의 자료형
std::ostream& operator<<(std::ostream &out, const Digit &digit)
{
	out << digit.getDigit();

	return (out);
}

int main()
{
	int	a = 10;

	std::cout << ++a << std::endl;	// 11
	std::cout << a << std::endl;	// 11
	std::cout << a++ << std::endl;	// 11
	std::cout << a << std::endl;	// 12

	Digit	d(5);
	
	std::cout << ++d << std::endl;	// 6
	std::cout << d << std::endl;	// 6
	std::cout << d++ << std::endl;	// 6
	std::cout << d << std::endl;	// 7

	return (0);
}