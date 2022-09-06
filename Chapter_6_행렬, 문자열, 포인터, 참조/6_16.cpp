// 6.16 포인터와 참조의 멤버 선택 연산자

#include <iostream>

struct Person
{
	int		age;
	double	weight;
};


int	main()
{
	Person	person;

	// 멤버 선택 연산자 
	person.age = 5;
	person.weight = 30;

	Person	&ref = person;

	ref.age = 15;
	ref.weight = 35;

	Person	*ptr = &person;

	ptr->age = 30;
	(*ptr).age = 20;
	ptr->weight = 40;

	Person	&ref2 = *ptr;

	ref2.age = 45;

	std::cout << &person << std::endl;	// 0x16dacf478
	std::cout << &ref2 << std::endl;	// 0x16dacf478

	return (0);
}