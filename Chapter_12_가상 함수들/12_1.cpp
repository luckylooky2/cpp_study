// 12.1 다형성의 기본 개념

// 상속과 포인터를 연관지어서
// 자식 클래스의 객체에 부모 클래스의 포인터를 사용한다면?

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string	m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{
		std::cout << "class Animal constructor" << std::endl;
	}
	
	std::string	getName() const { return (m_name); }

	// virtual function
	// speak()에서 ???이 나오지 않게 함
	// 이런 성질을 다형성이라고 부름 => 이를 잘 이용하면 상속을 이용해 잘 프로그래밍을 할 수 있음
	virtual void		speak() const
	{
		std::cout << m_name << " ??? " << std::endl;
	}

	~Animal() { std::cout << "class Animal destructor" << std::endl; }
};

class Cat : public Animal
{
public:
	Cat(std::string name)
		: Animal(name)
	{
		std::cout << "class Cat constructor" << std::endl;
	}

	void	speak() const
	{
		std::cout << Animal::m_name << " Meow " << std::endl;
	}

	~Cat() { std::cout << "class Cat destructor" << std::endl; }
};

class Dog : public Animal
{
public:
	Dog(std::string name)
		: Animal(name)
	{
		std::cout << "class Dog constructor" << std::endl;
	}

	void	speak() const
	{
		std::cout << Animal::m_name << " Woof " << std::endl;
	}

	~Dog() { std::cout << "class Dog destructor" << std::endl; }
};

int	main()
{
	Animal	animal("my animal");
	Cat		cat("my cat");
	Dog		dog("my dog");

	animal.speak();		// my animal ??? 
	cat.speak();		// my cat Meow 
	dog.speak();		// my dog Woof 

	Animal	*ptr_animal1 = &cat;
	Animal	*ptr_animal2 = &dog;

	// 자식 클래스를 부모 클래스의 "포인터"를 사용하여 캐스팅하고 호출한다면
	// 자식 클래스가 부모 클래스인줄 알고 작동함
	// 왜 포인터를 사용?
	ptr_animal1->speak();	// my cat ??? 
	ptr_animal2->speak();	// my dog ??? 

	// 활용할 수 있는 경우?
	// 동물의 수가 많아지면 일일이 다 for문을 호출해야 하는 등 불편함 => for문의 개수를 줄이고 싶을 떄
	// 1. 공통 부모 클래스인 Animal class를 활용하면 배열로 만들 수 있지 않을까 
	Cat		cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog		dogs[] = { Dog("dog1"), Dog("dog2") };

	for (int i = 0; i < 5; i++)
		cats[i].speak();	// cat1 Meow cat2 Meow ... cat5 Meow

	for (int i = 0; i < 2; i++)
		dogs[i].speak();	// dog1 Woof dog2 Woof 

	Animal	*my_animals[] = { &cats[0], &cats[1], &cats[2], &cats[3], &cats[4], &dogs[0], &dogs[1] };

	// 부모 클래스 speak()에 virtual 키워드를 사용
	for (int i = 0; i < 7; i++)
		my_animals[i]->speak();	// cat1 Meow cat2 Meow ... dog1 Woof dog2 Woof 

	return (0);
}