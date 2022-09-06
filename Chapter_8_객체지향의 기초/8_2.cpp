// 8.2 캡슐화, 접근 지정자, 접근 함수

// 접근 지정자
// class 외부에서 이 변수들에 접근을 가능하게 할 건지?
// public : 외부에서 접근할 수 있음
// private : 외부에서 접근하지 못함 => access function을 통해 접근 가능 
// protected : 상속과 관련한 개념

// 캡슐화
// 굳이 getter, setter를 쓰는 이유 중 하나? 유지 보수, 리팩터링에 편함
// 멤버 변수를 public으로 선언을 하면 클래스 밖에서 자유롭게 사용
// 만약 멤버 변수 이름을 바꿀 일이 생긴다면 사용된 모든 곳에서 바꿔줘야 함
// e.g., today.m_day = 5 => today._day = 5
// 하지만 캡슐화를 했다면 클래스 내에서 해결할 수 있음

#include <iostream>
#include <string>
#include <vector>

class Date
{
private :	// access specifier
	int	m_day;
	int	m_month;
	int	m_year;
public :	// access specifier
	// 같은 class의 멤버라면 public이라도 private에 접근할 수 있음
	// encapsulation을 하려면 외부와 의사소통을 하는 존재가 있어야 함
	void	setDate(const int &year_input, const int &month_input, const int &day_input)
	{
		m_year = year_input;
		m_month = month_input;
		m_day = day_input;
	}

	void	setDay(const int &day_input)
	{
		m_day = day_input;
	}

	void	setMonth(const int &month_input)
	{
		m_month = month_input;
	}

	void	setYear(const int &year_input)
	{
		m_year = year_input;
	}

	// getter 함수의 특징
	// 1. 변수로 return하면 변수 복사 => return을 reference 타입으로 쓰는 경우도 있음
	// 2. getter는 단순히 가져오기만 하는 용도 => return const
	const int	&getDay(void)
	{
		return (m_day);
	}

	const int	&getMonth(void)
	{
		return (m_month);
	}

	const int	&getYear(void)
	{
		return (m_year);
	}

	// 수동으로 하는 방법 => 더 쉬운 방법도 있음(memcpy)
	// 복잡한 클래스를 만드는데 실수를 조금이라도 덜 하기 위해
	void	copy(const Date &original)
	{
		// private 멤버인데 자유롭게 접근?
		// 서로 다른 메모리임에도 불구하고, 같은 클래스라면
		// 다른 인스턴스에 들어있는 private 멤버에 접근이 가능함
		m_year = original.m_year;
		m_month = original.m_month;
		m_day = original.m_day;
	}
	
};

int	main()
{
	Date	today;

	// error: 'm_day' is a private member of 'Date'
	// class에 access specifier를 지정해주지 않았으면(default) private
	// today.m_day = 8;
	// today.m_month = 30;
	// today.m_year = 2022;

	today.setDate(8, 30, 2022);
	today.setMonth(7);
	std::cout << today.getMonth() << std::endl;		// 7

	Date	copy;

	// copy instance
	// 방법 1
	copy.setDate(today.getYear(), today.getMonth(), today.getDay());
	// 방법 2
	copy.copy(today);
	std::cout << today.getMonth() << std::endl;		// 7

	return (0);
}