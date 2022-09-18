// 15.7 순환 의존성 문제와 std::weak_ptr

// shared_ptr를 사용할 때 발생할 수 있는 순환 의존성 문제
// std::weak_ptr로 해결

#include <iostream>
#include <memory>
#include <string>

class Person
{
private:
	std::string				m_name;
	// Person을 지우려고 할 때, m_partner도 지우려고 하는데
	// shared_ptr에 의해서 카운트가 되기 때문에 지우지 않고 넘어감
	// 자기 자신도 지우지 못하는 상태가 됨(순환 상태)
	// std::shared_ptr<Person>	m_partner;
	// 이 경우 weak_ptr을 사용하여 해결
	std::weak_ptr<Person>	m_partner;

public:
	Person(const std::string &name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	// shared_ptr를 이용하여 서로 파트너를 맺는 함수
	friend bool	partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return (false);
		p1->m_partner = p2;
		p2->m_partner = p1;
		std::cout << p1->m_name << " is partnered with " << p2->m_name << std::endl;
		return (true);
	}

	const std::shared_ptr<Person>	getPartner() const
	{
		return (m_partner.lock());
	}

	const std::string	getName() const
	{
		return (m_name);
	}
};

int	main()
{
	auto	lucy = std::make_shared<Person>("Lucy");
	auto	ricky = std::make_shared<Person>("Ricky");
	
	// 없을 때는 소멸자가 잘 동작
	partnerUp(lucy, ricky);
	// Lucy created
	// Ricky created
	// Ricky destroyed
	// Lucy destroyed

	// 있는 경우 소멸자가 호출되지 않고 leak이 발생
	// Lucy created
	// Ricky created
	// Lucy is partnered with Ricky

	// weak_ptr
	partnerUp(lucy, ricky);
	// Lucy created
	// Ricky created
	// Lucy is partnered with Ricky
	// Ricky destroyed
	// Lucy destroyed

	// weak_ptr 단점
	// weak_ptr의 내용물을 사용하려고 할 때 lock을 해야 함
	// 직접 weak_ptr을 사용할 수 없음
	// 순환 의존성을 깨기 위해 이런 구조가 만들어진 것
	// m_partner.lock()의 리턴 => shared_ptr
	// 즉, shared_ptr로 바꿔서 사용해야 함
	std::cout << lucy->getPartner()->getName() << std::endl;	// Ricky

	return (0);
}