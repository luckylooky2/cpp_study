// 12.10 동적 형변환

// 자식 클래스의 포인터를 부모 클래스의 포인터로 바꿨다가
// 다시 자식 클래스 포인터로 바꿔주어야 하는 경우

#include <iostream>
#include <vector>

class Base
{
public:
	int	m_i	= 0;

	virtual void	print()
	{
		std::cout << "I'm base" << std::endl;
	}
};

class Derived1 : public Base
{
public:
	int	m_j	= 1024;

	virtual void	print() override
	{
		std::cout << "I'm derived" << std::endl;
	}
};

class Derived2 : public Base
{
public:
	std::string	m_name	= "Dr. Two";

	virtual void	print() override
	{
		std::cout << "I'm derived" << std::endl;
	}
};

int	main()
{
	Derived1	d1;
	// 우리는 base 포인터가 Derived1 포인터였다가 다형성 때문에 잠깐 바뀐것을 알고 있음
	Base		*base = &d1;
	// base 포인터를 다시 Derived1 포인터로 동적 형변환을 할 수 있음
	auto		*base_to_d1 = dynamic_cast<Derived1 *>(base);

	// base엔 없고, d1에만 있는 것들은 접근할 수 없음
	// 설계를 잘해서, 이러한 경우가 없도록 하는 것이 좋겠지만
	// 접근 가능
	std::cout << d1.m_j << std::endl;
	// 접근 불가능
	// std::cout << base->m_j << std::endl;
	// 동적 형변환을 통해 접근 할 수 있음
	if (base_to_d1 != nullptr)
		std::cout << base_to_d1->m_j << std::endl;
	else
		std::cout << "Failed" << std::endl;

	// 캐스팅에 실패하면 nullptr를 반환
	// Derived1으로 시작 => base *로 변환 => 다시 Derived2로 변환 => 에러
	auto *base_to_d2 = dynamic_cast<Derived2 *>(base);
	if (base_to_d2 != nullptr)
		std::cout << base_to_d2->m_name << std::endl;
	else
		std::cout << "Failed" << std::endl;

	return (0);
}