// 19.8 자료형 추론 auto와 decltype

#include <iostream>
#include <vector>
#include <algorithm>

class Examples
{
public:
	void	ex1()
	{
		std::vector<int>	vect;
		for (std::vector<int>::iterator	itr = vect.begin(); itr != vect.end(); ++itr)
			std::cout << *itr;
		// 편한 도구
		for (auto	itr = vect.begin(); itr != vect.end(); ++itr)
			std::cout << *itr;
		for (auto	itr : vect)
			std::cout << itr;
	}

	void	ex2()
	{
		int	x = int();
		// int auto_x
		auto auto_x = x;

		const int	&crx = x;
		// auto는 const, &를 다 떼버림 => auto의 중요한 성질
		// "가장 기본적인 자료형만 자동으로 추론"
		// int auto_crx1
		auto		auto_crx1 = crx;

		// auto 앞 뒤에 원하는 것을 붙여줘야 함
		// const int &auto_crx2
		const auto&	auto_crx2 = crx;

		// 값이 자주 변하기 떄문에 최적화할 때 빼달라
		// 멀티쓰레딩에 많이 사용
		volatile int	vx = 1024;
		// int avx
		auto			avx = vx;
		// volatile int vavx
		volatile auto	vavx = vx;
	}

	template<class T>
	void	func_ex31(T arg)
	{}

	template<class T>
	void	func_ex32(const T& arg)
	{}

	void	ex3()
	{
		const int	&crx = 123;

		// inline void Examples::func_ex3<int>(int arg)
		func_ex31(crx);
		// inline void Examples::func_ex32<int>(const int &arg)
		func_ex32(crx);
	}

	void	ex4()
	{
		const int	c = 0;
		// 가져오려는 값이 그냥 변수 const라면 자동으로 auto가 const를 붙여줌
		// const 레퍼런스를 가져오는 것은 예외
		// why? 원래 가져오려는 값의 const 여부에 따라 다를 듯?
		auto		&rc = c;
		// 컴파일 에러
		// rc = 123;
	}

	void	ex5()	// amendment
	{
		int		i = 42;
		// auto&& : r-value로 선언을 하고 싶다는 의도
		// 대입이 l-value라면 &&를 무시
		auto&&	ri_1 = i;	// l-value
		// 대입이 r-value라면 잘 동작
		auto&&	ri_2 = 42;	// r-value
	}

	void	ex6()
	{
		int			x = 42;
		const int	*p1 = &x;
		// const int *p2
		// 포인터이기 때문에 const 성질을 그대로 가져와야 함
		auto		p2 = p1;
		// 컴파일 에러
		// *p2 = 42;
	}

	// 서로 다른 자료형을 곱하는 함수
	template<typename T, typename S>
	void	func_ex7(T lhs, S rhs)
	{
		// 곱셈의 결과를 알기 어려움
		auto	prod1 = lhs * rhs;

		// 이것을 해결하기 위해 C++ 11 이전 "일부" 컴파일러들은
		// typeof를 이용하여 데이터 타입을 리턴해주는 함수가 있었음
		// typedef typeof(lhs * rhs) product_type;
		// 공식적으로 이를 해결
		// 실제로 계산하지는 않고, 추론만 함
		typedef decltype(lhs * rhs) product_type;

		product_type		prod2 = lhs * rhs;
		decltype(lhs * rhs)	prod3 = lhs * rhs;
	}

	// decltype을 리턴 타입으로도 사용 가능
	template<typename T, typename S>
	// 사용할 수 없음 => lhs, rhs가 정의되어 있지 않기 때문에
	// decltype(lhs * rhs)	func_ex8(T lhs, S rhs)
	auto	func_ex8(T lhs, S rhs) -> decltype(lhs * rhs)
	{
		return (lhs * rhs);
	}

	void	ex7_8()
	{
		func_ex7(1.0, 345);
		// double a
		auto	a = func_ex8(1.2, 345);
	}

	struct S
	{
		int	m_x;

		S()
		{
			m_x = 42;
		}
	};

	void	ex9()
	{
		int			x;
		const int	cx = 42;
		const int	&crx = x;
		const S		*p = new S();

		// int a
		auto	a = x;
		// int b
		auto	b = cx;
		// int c
		auto	c = crx;
		// const Examples::S *d
		auto	d = p;
		// int e
		auto	e = p->m_x;
	}
	
};


int	main()
{
	Examples	examples;

	examples.ex1();
	examples.ex2();
	examples.ex3();
	examples.ex10();
	examples.ex12();
	examples.ex14();
	examples.ex15();
	examples.ex16();

	return (0);
}