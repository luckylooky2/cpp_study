#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
private:
	int	m_value;
public:
	Base(const int in_value) : m_value(in_value)
	{
		std::cout << "class Base default constructor" << std::endl;
	}

	Base(const Base &base)
	{
		std::cout << "class Base copy constructor" << std::endl;
		m_value = base.getValue();
	}

	~Base()
	{
		std::cout << "class Base destructor" << std::endl;
	}

	const int	getValue() const { return (m_value); }
	void	emplace(int in_value)
	{

	}
};

std::ostream& operator<<(std::ostream& out, const Base& base)
{
	out << base.getValue();
	return (out);
}

#endif