// 9.8 형변환(static_cast)을 오버로딩 하기

#include <iostream>

class Cents
{
private:
	int	m_cents;

public:
	Cents(int cents = 0)
	{ 
		m_cents = cents;
		std::cout << "class Cents constructor" << std::endl;
	}
	int	getCents() const { return m_cents; }
	void	setCents(int cents) { m_cents = cents; }

	operator int()
	{
		return (m_cents);
	}
};

void	printInt(const int &value)
{
	std::cout << value << std::endl;
}

class Dollar
{
private:
	int	m_dollars = 0;

public:
	Dollar(const int &input) : m_dollars(input) { std::cout << "class Dollar constructor" << std::endl; }
	
	operator Cents()
	{
		return (Cents(m_dollars * 100));
	}
};

int main()
{
	Cents	cents(7);

	// error: no matching function for call to 'printInt'
	// cents : 자체가 int가 아님
	printInt(cents);

	// int() operator overloading
	// cents : 자체가 int
	printInt(cents);									// 7
	std::cout << cents << std::endl;					// 7
	std::cout << int(cents) << std::endl;				// 7
	std::cout << (int)cents << std::endl;				// 7
	std::cout << static_cast<int>(cents) << std::endl;	// 7

	Dollar	dollar(2);
	Cents	cent = dollar;

	// class Cents에서 int() 형 변환 오버로딩이 되어있어 가능
	printInt(Cents(dollar));	// 200
	printInt(cent);				// 200

	return (0);
}