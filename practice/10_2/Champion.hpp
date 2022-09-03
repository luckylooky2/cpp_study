#ifndef CHAMPION_HPP
#define CHAMPION_HPP

#include "Status.hpp"
#include <string>

class Champion
{
private:
	std::string	m_id;
	Status		m_status;

public:
	Champion(const std::string &name, const Status &status)
	{
		m_id = name;
		m_status = status;
		std::cout << "class Champion constructor" << std::endl;
	}

	std::string			getId() const { return (m_id); }
	// const를 꼭 붙여야 함
	const Status		&getStatus() const { return (m_status); }
	
	void	LevelUp(const Status &status)
	{
		// m_status.setStatus(status);
		m_status = status;
	}

	~Champion()
	{
		std::cout << "class Champion destructor" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& out, const Champion &champion)
{
	out << champion.getId() << " " << champion.getStatus();
	return (out);
}


#endif