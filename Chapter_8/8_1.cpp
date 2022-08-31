// 8.1 객체지향 프로그래밍과 클래스

#include <iostream>
#include <string>
#include <vector>

// Friend : name, address, age, hegiht, weight

// 데이터만 담을 때는 struct
struct Friend_t
{
	std::string	name;
	std::string	address;
	int			age;
	double		height;
	double		weight;
};

// 기능과 함께 담을 때는 class
// class를 정의하는 것만으로는 메모리를 할당받지 않음 => instanciation
class Friend
{
public :	// access specifier
	// member라는 뜻의 m_
	std::string	m_name;
	std::string	m_address;
	int			m_age;
	double		m_height;
	double		m_weight;

	// 정의하는 곳이기 때문에 매개변수 없이 직접 접근할 수 있음
	void	print()
	{
		std::cout << m_name << " " << m_address << " "  << m_age << " " << m_height << " " << m_weight << std::endl;
	}
};

void	print(const std::string &name, const std::string &address, const int &age, const double &height, const double &weight);
{
	std::cout << name << " " << address << " "  << age << " " << height << " " << weight << std::endl;
}

int	main()
{
	std::string					name;
	std::string					address;
	int							age;
	double						height;
	double						weight;

	// 친구는 줄어들고 늘어날 수 있기 때문에 vector를 사용
	std::vector<std::string>	name_t;
	std::vector<std::string>	address_t;
	std::vector<int>			age_t;
	std::vector<double>			height_t;
	std::vector<double>			weight_t;

	// 번거롭고 코드의 양이 많아짐
	print(name_t[0], address_t[0], age_t[0], height_t[0], weight_t[0]);
	
	// 1. struct
	Friend_t			fr = {"Jack Jack", "Uptown", 2, 30, 10};
	// 2. class
	// instance(인스턴스) : 메모리를 차지하도록 할당하는 것
	Friend				ins = {"Jack Jack", "Uptown", 2, 30, 10};	// instanciation
	std::vector<Friend>	my_friends;

	// ins가 print하는 것처럼 보임
	// 데이터 + 기능이 묶여있는 개념을 object(객체)라고 부름
	// object를 구현하는 것을 class
	ins.print();

	my_friends.resize(2);
	for (auto &elem : my_friends)
		elem.print();

	return (0);
}