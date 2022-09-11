// 13.7 포인터에 대한 템플릿 특수화

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

	void	print()
	{
		std::cout << m_value << std::endl;
	}
};

// 만약 포인터인 경우에만 특별한 기능을 하고 싶다면?
// 필요에 따라서, 상속 구조를 이용해 구현할 수도 있음(앞 강의 참조)
template <class T>
class A<T *>
{
private:
	T	*m_value;

public:
	A(T *input)
		: m_value(input)
	{
		std::cout << "class A constructor" << std::endl;
	}

	void	print()
	{
		std::cout << *m_value << std::endl;
	}
};

int	main()
{
	A<int>		a_int(123);
	// 포인터를 매개변수로 => 주소값 출력
	// 만약 포인터인 경우에만 특별한 기능을 하고 싶다면?
	int			temp = 456;
	A<int *>	a_int_ptr(&temp);	
	double		temp_d = 3.141592;
	A<double *>	a_double_ptr(&temp_d);

	// before pointer specialize
	a_int.print();					// 123
	a_int_ptr.print();				// 0x16d96b470
	a_double_ptr.print();			// 0x16d96b458
	// after pointer specialize
	a_int.print();					// 123
	a_int_ptr.print();				// 456
	a_double_ptr.print();			// 3.14159

	return (0);
}