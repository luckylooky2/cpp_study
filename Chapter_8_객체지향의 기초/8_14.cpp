// 8.14 클래스 안에 포함된 자료형

#include <iostream>


class Fruit
{
public:
	// Fruit class에서 과일의 타입을 표현하기 위해 사용
	// Fruit class 안에서만 사용한다면?
	enum class FruitType
	{
		APPLE,
		BANANA,
		CHERRY,
	};
	class InnerClass {};
	struct InnerStruct {};

private:
	FruitType	m_type;

public:
	Fruit(FruitType type) : m_type(type) {}
	FruitType getType() { return (m_type); }
};

int	main()
{
	// APPLE => Fruit::APPLE => Fruit::FruitType::APPLE
	Fruit	apple(Fruit::FruitType::APPLE);

	// APPLE => Fruit::APPLE
	if (apple.getType() == Fruit::FruitType::APPLE)
	{
		std::cout << "Apple" << std::endl;
	}
	return (0);
}