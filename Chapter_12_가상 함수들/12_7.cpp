// 12.7 순수 가상 함수, 추상 기본 클래스, 인터페이스 클래스

// 지금까지 다형성에서 virtual function을 구현할 때
// 자식 클래스에게 조금 더 적합한 함수를 overriding하는 관점에서 설명
// 여기에서는 설계 관점에서 기본 클래스를 만들 때
// 자식 클래스에게 이런 것을 반드시 해야한다는 제약을 걸고 강제하는 방법

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

	// pure virtual function
	// 함수를 정의하지 않고 = 0으로 선언만 한 함수
	// 
	virtual void		speak() const = 0;

	~Animal() { std::cout << "class Animal destructor" << std::endl; }
};

// 이런 식으로 밖에 구현할 수 있지만, 구현해도 호출할 수 없음
// void	Animal::speak() const
// {
// 	std::cout << m_name << " ??? " << std::endl;
// }

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

class Cow : public Animal
{
public:
	Cow(std::string name)
		: Animal(name)
	{
		std::cout << "class Cow constructor" << std::endl;
	}

	void	speak() const
	{
		std::cout << Animal::m_name << " Mooo " << std::endl;
	}

	~Cow() { std::cout << "class Cow destructor" << std::endl; }
};

// interface class
// 내부의 모든 함수들이 pure virtual function일 경우
// 자신이 무엇을 할 지는 정하지 않고, 자식 클래스에게 구현을 강제함
// interface : 외부에서 사용할 때, 이러한 기능들이 있을거다라고 예측할 수 있는 중계기 역할
class IErrorLog
{
public:
	virtual bool	reportError(const char *errorMessage) = 0;
	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
	virtual bool	reportError(const char *errorMessage) override
	{
		std::cout << "Writing error to a file" << std::endl;
		return (true);
	}
	~FileErrorLog() {};
};

class ConsoleErrorLog : public IErrorLog
{
public:
	virtual bool	reportError(const char *errorMessage) override
	{
		std::cout << "Writing error to a console" << std::endl;
		return (true);
	}
	~ConsoleErrorLog() {};
};

// Interface로 구현하면 상속하여 어떤 클래스를 만들더라도
// 하나의 부모 클래스를 통해 매개변수를 받을 수 있고, 반드시 override를 해야 함
void	doSomething(IErrorLog &log)
{
	// 인터페이스를 통해
	// IErrorLog에서 상속 받은 클래스들은 reportError를 할 수 있다만 알고 있음
	log.reportError("Runtime error!!");
}

int	main()
{
	// object of abstract class type "Animal" is not allowed:C/C++(322)
	// function "Animal::speak" is a pure virtual function
	// abstract class
	// pure virtual function이 하나라도 들어간 클래스 => 인스턴스 생성 불가
	// Animal	animal("hi");
	// pure virtual function "Animal::speak" has no overrider
	// 자식 클래스에서 pure virtual function를 정의하지 않았다면 => 인스턴스 생성 불가
	Cow		cow("hello");

	cow.speak();		// hello Mooo 

	// 다형성을 잘 구현한 예
	FileErrorLog	file_log;
	ConsoleErrorLog	console_log;

	doSomething(file_log);		// Writing error to a file
	doSomething(console_log);	// Writing error to a console

	return (0);
}