// 13.8 멤버 함수를 한 번 더 템플릿화하기

#include <iostream>

template <class T>
class A
{
private:
	T	m_value;

public:
	A(const T& input)
		: m_value(input)
	{
		std::cout << "class A constructor" << std::endl;
	}

	// 클래스 템플릿 안에 함수 템플릿?
	// TT는 doSomething()에서만 적용이 되는 템플릿 파라미터
	template <typename TT>
	void	doSomething()
	{
		std::cout << typeid(T).name() << " " << typeid(TT).name() << std::endl;
	}

	// 파라미터를 가지고 있는 경우
	template <typename TT>
	void	doSomething(const TT& input)
	{
		std::cout << typeid(T).name() << " " << typeid(TT).name() << std::endl;
	}

	void	print()
	{
		std::cout << m_value << std::endl;
	}
};

int main()
{
	A<int>	a_int(123);

	a_int.print();						// 123
	a_int.doSomething<float>();			// i f(int float)
	a_int.doSomething<char>();			// i c(int char)
	// warning: implicit conversion from 'double' to 'int' changes value from 123.4 to 123
	a_int.doSomething<int>(123.4);		// i i(int int)
	// 파라미터를 가지고 있는 경우 <>이 필요 없음
	a_int.doSomething(123.4);			// i d(int double)
	a_int.doSomething('a');				// i c(int char)

	A<char>	a_char('A');
	
	a_char.print();						// A
	a_char.doSomething<int>();			// c i(char int)
	// 템플릿을 이용하여 int 타입으로 출력하고 싶을 떄
	a_char.doSomething(1);				// c i(char int)
	// 변환하고 싶은 타입을 명시하고 싶을 때 
	a_char.doSomething(int());			// c i(char int)

	return (0);
}