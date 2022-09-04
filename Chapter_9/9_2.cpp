// 9.2 입출력 연산자(<<, >>) 오버로딩 하기

#include <iostream>
#include <fstream>

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{
		std::cout << "class Point constructor" << std::endl;
	}

	double &getX() { return m_x; }
	double &getY() { return m_y; }
	double &getZ() { return m_z; }

	void	print()
	{
		std::cout << m_x << " " << m_y << " " << m_z << std::endl;
	}

	// 첫 번째 매개변수가 클래스가 아니고 ostream라서 멤버 함수로 만들기 어려움
	// error: overloaded 'operator<<' must be a binary operator (has 3 parameters)
	// 일반 함수로 만들거나 friend 함수로 만들기
	friend std::ostream &operator << (std::ostream &out, const Point &point)
	{
		out << point.m_x << " " << point.m_y << " " << point.m_z;

		return (out);
	}

	// // 입력 받을 인스턴스는 const가 아니어야 함 => 입력받아 수정해야 하기 때문에
	// friend std::istream &operator >> (std::istream &in, Point &point)
	// {
	// 	in >> point.m_x >> point.m_y >> point.m_z;

	// 	return (in);
	// }
};

// 일반 함수로 연산자 오버로딩 하기 => 멤버 변수를 사용하지 못함
std::istream &operator >> (std::istream &in, Point &point)
{
	in >> point.getX() >> point.getY() >> point.getZ();

	return (in);
}

int	main()
{
	Point	p1(0, 0, 5), p2(1, 2, 3);

	p1.print();	// 0 0 5
	p2.print();	// 1 2 3

	// 1. 연산자 오버로딩을 써서 간결하게 표현할 수 있음
	std::cout << p1 << std::endl << p2 << std::endl;

	// 2. 파일 출력이 ostream으로 가능
	// 파일 스트림 생성
	std::ofstream	of("out.txt");

	// p1, p2 표준 입력 받기
	std::cin >> p1 >> p2;
	std::cin.ignore(32767, '\n');

	// 파일 출력
	std::cout << p1 << std::endl << p2 << std::endl;
	of << p1 << std::endl << p2 << std::endl;

	return (0);
}