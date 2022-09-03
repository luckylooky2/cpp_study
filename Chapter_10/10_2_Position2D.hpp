// 10_2_Position2D.hpp

#ifndef TEN_TWO_POSITION2D_HPP
#define TEN_TWO_POSITION2D_HPP

#include <iostream>

class Position2D
{
private:
	int	m_x;
	int	m_y;

public:
	Position2D(const int &x_in = 0, const int &y_in = 0)
	{
		m_x = x_in;
		m_y = y_in;
		std::cout << "class Position2D constructor" << std::endl;
	}

	void	setPosition(const Position2D &pos_target)
	{
		setPosition(pos_target.m_x, pos_target.m_y);
		// 재활용
		// m_x = pos_target.x_target;
		// m_y = pos_target.y_target;
	}

	void	setPosition(const int &x_target, const int &y_target)
	{
		m_x = x_target;
		m_y = y_target;
	}
	
	~Position2D()
	{
		std::cout << "class Position2D destructor" << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& out, const Position2D &p)
	{
		out << p.m_x << " " << p.m_y;
		return (out);
	}
};

#endif