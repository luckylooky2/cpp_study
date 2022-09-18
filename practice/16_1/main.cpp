#include <iostream>
#include <stack>
#include "Base.hpp"

// If you are adding already created elements, use push() which can be used to copy or move them.
// If you want to create the elements in place on the stack, 
// use emplace(), where you can pass in the usual constructor parameters for the type of element.

int	main()
{
	std::cout << "Stack" << std::endl;

	std::stack<Base>	stack;
	Base				b1(1);
	Base				b2(2);
	// class Base default constructor
	// class Base default constructor

	// 새롭게 넣을 데이터가 L-value 면 copy, R-value 면 move 가 일어나게 된다. (C++11 이후부터)
	stack.push(3);
	// class Base default constructor
	// class Base copy constructor
	// class Base destructor

	// copy 나 move 를 통해 추가하는 것이 아니라 오브젝트 생성하면서 스택에 바로 때려넣기 때문에 코스트가 없다.
	stack.emplace(3);	
	//class Base default constructor
	std::cout << stack.top() << std::endl;	// 3

	return (0);
}