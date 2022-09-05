// 9.4 비교 연산자(==, !=, >, >=) 오버로딩 하기

// if문 안에 사용자 정의 자료형을 사용하는 경우
// std::sort를 사용하는 경우 크기 비교 연산자 오버로딩이 필요

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

class Cents
{
private:
	int	m_cents;

public:
	Cents()
	{
		std::cout << "class Cents constructor" << std::endl;
	}

	Cents(int cents)
	{ 
		m_cents = cents;
		std::cout << "class Cents constructor" << std::endl;
	}
	int		getCents() const { return m_cents; }
	int		&getCents() { return m_cents; }
	void	setCents(const int &cents_in) { m_cents = cents_in; }

	bool operator == (const Cents &cents)
	{
		return (this->m_cents == cents.m_cents);
	}

	friend bool operator != (const Cents &c1, const Cents &c2);

	// 멤버 함수로는 왜 안되는가?
	// sort 안에서 멤버 함수로 정의한 연산자를 찾을 수 없음?
	// https://cplusplus.com/reference/algorithm/sort/
	// bool operator < (const Cents &cents)
	// {
	// 	return (this->m_cents < cents.m_cents);
	// }
};

bool operator != (const Cents &c1, const Cents &c2)
{
	return (c1.m_cents != c2.m_cents);
}

// sort에서는 >가 아니라 <를 구현해야 함
// error: invalid operands to binary expression ('const Cents' and 'const Cents')
// 연산자 오버로딩이 잘못 되었다는 뜻
bool operator < (const Cents &c1, const Cents &c2)
{
	return (c1.getCents() < c2.getCents());
}

// 멤버 함수로 만들기 어려움
std::ostream &operator << (std::ostream &out, const Cents &cents)
{
	out << cents.getCents() << " ";

	return (out);
}

int	main()
{
	Cents	cents1(6);
	Cents	cents2(8);
	int		a = 3, b = 3;

	if (a == b)
		std::cout << "Equal " << std::endl;
	// 사용자 정의 자료형에서는 사용하지 못함
	if (cents1 == cents2)
		std::cout << "Equal Class" << std::endl;
	else
		std::cout << "Not equal Class" << std::endl;
	if (cents1 != cents2)
		std::cout << "Not equal Class" << std::endl;
	else
		std::cout << "Equal Class" << std::endl;

	std::vector<Cents>	arr(20);

	 // assign
	for (unsigned i = 0; i < 20; i++)
		arr[i].setCents(i);
	// C++ 17 std::random_shuffle deprecated
	// std::random_shuffle(begin(arr), end(arr));
	std::random_device	rd;
	std::mt19937		g(rd());

	// shuffle
	std::shuffle(arr.begin(), arr.end(), g);
	// print
	for (unsigned i = 0; i < 20; i++)
		std::cout << arr[i];
	std::cout << std::endl;
	
	// sort
	// error : arr 배열의 m_cents들끼리 크기 비교를 하지 못함
	// 크기 비교 연산자 오버로딩이 필요
	std::sort(begin(arr), end(arr));
	// print
	for (unsigned i = 0; i < 20; i++)
		std::cout << arr[i];
	std::cout << std::endl;
	
	return (0);
}