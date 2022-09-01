// 9.3 단항 연산자(+, -, !) 오버로딩 하기

#include <iostream>

class Cents
{
private:
	int	m_cents;

public:
	Cents(int cents)
	{ 
		m_cents = cents;
		std::cout << "class Cents constructor" << std::endl;
	}
	int	getCents() const { return m_cents; }
	int	&getCents() { return m_cents; }

	Cents	operator + () const
	{
		return (Cents(m_cents));
	}

	Cents	operator - () const
	{
		return (Cents(-m_cents));
	}

	// 뭘 return할지는 문맥, 목적상 결정해야 함
	bool	operator ! () const
	{
		return ((m_cents == 0) ? true : false);
	}

	friend std::ostream &operator << (std::ostream &out, const Cents &cents)
	{
		out << cents.m_cents;

		return (out);
	}
};

int	main()
{
	Cents	cents1(6);
	Cents	cents2(8);

	std::cout << cents1 << std::endl;			// 6
	std::cout << -cents2 << std::endl;			// -8
	std::cout << -Cents(-10) << std::endl;		// 10
	std::cout << !cents1 << std::endl;			// 0
	std::cout << !Cents(0) << std::endl;		// 1
	std::cout << +cents1 << std::endl;			// 6
	std::cout << +Cents(-10) << std::endl;		// -10

	return (0);
}