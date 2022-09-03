#ifndef STATUS_HPP
#define STATUS_HPP

#include <iostream>

class Status
{
private:
	unsigned int	m_hp;
	unsigned int	m_mp;

public:
	Status(const unsigned int &hp_in = 1000, const unsigned int &mp_in = 500)
	{
		m_hp = hp_in;
		m_mp = mp_in;
		std::cout << "class Status constructor" << std::endl;
	}

	unsigned int	getHp() const { return (m_hp); }
	unsigned int	getMp() const { return (m_mp); }

	void	setStatus(const Status &status)
	{
		setStatus(status.m_hp, status.m_mp);
	}

	void	setStatus(const unsigned int &hp_in, const unsigned int &mp_in)
	{
		m_hp = hp_in;
		m_mp = mp_in;
	}

	Status	&operator =(const Status &status)
	{
		this->m_hp = status.m_hp;
		this->m_mp = status.m_mp;
		return (*this);
	}

	~Status()
	{
		std::cout << "class Status destructor" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& out, const Status &status)
{
	out << status.getHp() << " " << status.getMp();
	return (out);
}

#endif