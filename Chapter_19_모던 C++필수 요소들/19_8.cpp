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
		// const 값인데 복사를 해버리면 상관 없음
		// int e
		auto	e = p->m_x;

		// decltype은 auto와 다르게 reference까지 그대로 가져옴
		// 변수가 선언이 된 타입을 그대로 가져옴
		// typedef int x_type
		typedef decltype(x)			x_type;
		// typedef const int cx_type
		typedef decltype(cx)		cx_type;
		// typedef const int &crx_type
		typedef decltype(crx)		crx_type;
		// typedef int m_x_type
		typedef decltype(p->m_x)	m_x_type;

		// add reference to l-values
		// typedef int &xp_type
		typedef decltype((x))		xp_type;
		// typedef const int &cx_type
		typedef decltype((cx))		cxp_type;
		// 원래 &가 있었다면 유지
		// typedef const int &crx_type
		typedef decltype((crx))		crxp_type;
		// & 때문에 변화가 되면 안 된다는 const 조건이 같이 옴
		// typedef const int &m_x_type
		typedef decltype((p->m_x))	m_xp_type;
	}

	const S foo()
	{
		return (S());
	}

	const int&	foobar()
	{
		return (123);
	}

	void	ex10()
	{
		std::vector<int>	vect = {42, 43};

		// Examples 클래스 안에 선언된 inner structure이기 떄문
		// struct Examples::S
		auto	a = foo();
		// const 유지
		// typedef const Examples::S foo_type
		typedef decltype(foo())	foo_type;

		auto	b = foobar();
		// const int & 그대로 유지
		// typedef const int &foobar_type
		typedef decltype(foobar())	foobar_type;

		auto	itr = vect.begin();
		// typedef std::__1::vector<int>::iterator iterator_type
		typedef decltype(vect.begin())	iterator_type;

		auto	first_element = vect[0];
		// vector의 오버로딩 되어있는 [] operator가 return 할 때 &를 리턴
		// int &second_element
		// inline int &std::__1::vector<int>::operator[](size_t __n) noexcept
		decltype(vect[1])	second_element = vect[1];
	}

	void	ex11()
	{
		int	x = 0;
		int	y = 0;
		const int	cx = 42;
		const int 	cy = 43;
		double		d1 = 3.14;
		double		d2 = 2.72;

		// typedef int prod_xy_type => 정수 x 정수
		typedef decltype(x * y)	prod_xy_type;
		// int a
		auto	a = x * y;
		
		// typedef int prod_cxcy_type => 곱한 결과는 r-value이기 때문에
		typedef decltype(cx * cy)	prod_cxcy_type;
		// int b
		auto	b = cx * cy;

		// 주의 => double일 때는 &로 받음
		// typedef double &cond_type
		typedef decltype(d1 < d2 ? d1 : d2)	cond_type;			// result is l-value. * is added.
		// double c
		auto	c = (d1 < d2 ? d1 : d2);

		// typedef double cond_type_mixed => 승급
		typedef decltype(x < d2 ? x : d2)	cond_type_mixed;
		// double d
		auto	d = (x < d2 ? x : d2);

		// error
		// 입력되는 두 변수들의 타입이 다를 경우, 작동하지 않음
		// 매번 캐스팅하기는 불편 => 만들어보자
		// auto	e = std::min(x, dbl);
	}

	template<typename T, typename S>
	// T, S가 타입이 같은 경우 위에서처럼 &타입이 됨 => 불편한 경우
	auto	fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
	{
		return ((x < y ? x : y));
	}

	template<typename T, typename S>
	// std::remove_reference : 레퍼런스를 붙는다면 제거한 typename을 사용하라
	auto	fpmin(T x, S y) ->
		typename std::remove_reference<decltype(x < y ? x : y)>::type
	{
		return ((x < y ? x : y));
	}

	void	ex12()
	{
		int	i = 42;
		double	d = 45.1;
		// 자료형이 다르므로 캐스팅
		auto	a = std::min(static_cast<double>(i), d);

		int	&j = i;

		// typedef double &fpmin_return_type1
		// 실수를 할 확률이 높아짐
		typedef decltype(fpmin_wrong(d, d))	fpmin_return_type1;
		// typedef double fpmin_return_type2
		typedef decltype(fpmin_wrong(i, d))	fpmin_return_type2;
		// typedef double fpmin_return_type3
		typedef decltype(fpmin_wrong(j, d))	fpmin_return_type3;
	}

	void	ex13()
	{
		std::vector<int>	vect;		// vector is empty

		// decltype은 실제로는 수행을 시키지 않기 때문에
		// 괄호 안에 vect[0]을 실행하지 않아 문제가 발생하지 않음
		// 컴파일타임에 결정을 함
		// typedef int &integer
		typedef decltype(vect[0])	integer;
	}

	template<typaname R>
	class SomeFunctor
	{
	public:
		typedef R result_type;

		SomeFunctor() {}
		result_type	operator() ()
		{
			return (R());
		}
	};

	void	ex14()
	{
		// R = int
		// result_type = int
		SomeFunctor<int>	func;
		// 1. func의 타입을 찾아냄
		// 2. SomeFunctor<int> 안의 result_type를 찾음(int)
		// 결과적으로 integer = int
		typedef	decltype(func)::result_type	integer;	// nested type
	}

	// 람다도 decltype으로 데이터 타입을 찾을 수 있음
	// 람다는 데이터 타입을 선언하기 불편
	void	ex15()
	{
		// int lambda()
		// class lambda []()->int
		auto	lambda = []() {return 42};
		// 같은 기능을 하는 람다 함수가 생김
		// lambda []()->int lambda2
		decltype(lambda)		lambda2(lambda2);
		// reference 타입
		// lambda []()->int &lambda3
		decltype((lambda)) 		lambda3(lambda2);

		std::cout << "Lambda functions" << std::endl;
		// 서로 다름
		std::cout << &lambda << " " << &lambda2 << std::endl;
		// 서로 같음
		std::cout << &lambda << " " << &lambda3 << std::endl;
	}

	void	ex16()
	{
		// generic lambda
		// 다른 함수에서는 파라미터로 auto를 사용하지 못하는데
		// 람다에서 사용할 수 있음
		auto	lambda = [](auto x, auto y)
		{
			return (x + y);
		}
		// double, int, double
		std::cout << lambda(1.1, 2) << lambda(3, 4) << lambda(4.5, 2.2) << std::endl;
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