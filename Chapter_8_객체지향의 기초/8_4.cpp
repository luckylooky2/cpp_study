// 8.4 생성자의 멤버 초기화 리스트

#include <iostream>

class B
{
private:
	int	m_b;

public:
	// 사용하는 곳에서 초기화 하지 않으면(매개변수가 없으면) 아래 에러 발생
	// error: constructor for 'Something' must explicitly initialize the member 
	// 'cl' which does not have a default constructor
	// 멤버 초기화 리스트 => 매개변수도 사용 가능
	B(const int &input)
		: m_b(input)
	{
		std::cout << "class B constructor" << std::endl;;	
	}

	int	getVar()
	{
		return (m_b);
	}
};

class Something
{
private:
	// 여기보다 생성자 초기화가 더 우선
	// 초기화 순서 1
	int		m_i = 0;
	double	m_d = 1.0;
	char	m_c = 'F';
	int		m_arr[5];
	B		cl;

public:
	Something()
		// member initialize list
		// uniform init. 가능 => 형 변환 안 됨에 주의
		// C++ 11 : array 초기화도 가능
		// 코딩 스타일에 따라 comma 위치 변경
		// 초기화 순서 2
		: m_i(1), 
		m_d(3.14), 
		m_c('a'), 
		m_arr{1, 2, 3, 4, 5}, 
		cl{123}
	{
		// 초기화 순서 3 => 가장 우선순위
		m_i = 1;
		m_d = 3.14;
		m_c = 'a';

		std::cout << "class Something constructor" << std::endl;
	}

	void	print()
	{
		std::cout << m_i << " " << m_d << " " << m_c << std::endl;
		for (int &elem : m_arr)
			std::cout << elem << " ";
		std::cout << std::endl;
		std::cout << cl.getVar() << std::endl;
	}
};

int	main()
{
	Something	sth;

	sth.print();	// 1 3.14 a '\n' 1 2 3 4 5  '\n' 123

	return (0);
}