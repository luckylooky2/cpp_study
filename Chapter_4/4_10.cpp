// 4.10 구조체

#include <iostream>
#include <string>

struct Person
{
	// 직접 초기화 가능
	double		height = 3.0;
	float		weight;
	int			age;
	std::string	name;

	// 함수도 가능
	void	print(void)
	{
		// 변수에 직접 접근할 수 있음
		std::cout << height << std::endl;
		std::cout << weight << std::endl;
		std::cout << age << std::endl;
		std::cout << name << std::endl;
	}
};

// struct in struct
struct Family
{
	Person me, mom, dad;
};

// 변수가 많아지면, 파라미터의 개수가 늘어나는 불편함
// 하나로 묶어서 사용하는 아이디어
void	printPersonVariable(double height, ...)
{

}

void	printPersonStruct(Person person)
{

}

struct Employee		// 16 = 2 + (2, padding) + 4 + 8
{
	short	id;		// 2 bytes
	int		age;	// 4 bytes
	double	wage;	// 8 bytes
};

int main()
{
	double		height;
	float		weight;
	int			age;
	std::string	name;
	Person		me;
	Person		me2;
	Employee	test;
	// struct 선언보다 초기화가 할당에 더 우선
	// Person		me{2.0, 100.0, 20, "Jack Jack"};

	// member selection operator
	me.height = 100.0;
	me.weight = 50.0;
	me.age = 20.0;
	me.name = "chanhyle";
	me.print();

	// struct -> struct 복사, class -> class 복사
	// assignment operator가 항상 의도한 대로 작동하지 않을 수 있음
	me2 = me;
	me2.print();

	std::cout << sizeof test << std::endl;	// 16

	return (0);
}