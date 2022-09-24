// 19_7_CustomVector.cpp

#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>	// std::forward

class CustomVector
{
public:
	unsigned	n_data = 0;
	int			*ptr = nullptr;

	CustomVector(const unsigned& _n_data, const int& _init = 0)
	{
		std::cout << "class CustomVector constructor\n";
		// 초기화하는 함수를 분리하는 것이 더 편리
		init(_n_data, _init);
	}

	CustomVector(CustomVector& l_input)
	{
		std::cout << "class CustomVector Copy constructor\n";
		init(l_input.n_data);
		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = l_input.ptr[i];
	}

	CustomVector(CustomVector&& r_input)
	{
		std::cout << "class CustomVector Move constructor\n";
		n_data = r_input.n_data;
		ptr = r_input.ptr;
		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	~CustomVector()
	{
		delete[] ptr;
	}

	void	init(const unsigned& _n_data, const int& _init = 0)
	{
		n_data = _n_data;
		ptr = new int[n_data];
		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = _init;
	}
};

void	doSomething(CustomVector& vec)
{
	std::cout << "Pass by L-reference\n";

	// copy constr.
	CustomVector	new_vec(vec);
}

void	doSomething(CustomVector&& vec)
{
	std::cout << "Pass by R-reference\n";

	// move constr.
	// r-value로 받았더라도 r-value로 변경하여 생성해야 함
	// 그렇지 않으면 복사 생성자를 호출
	// vec 자체는 변수이기 때문에 l-value
	CustomVector	new_vec(std::move(vec));
}

// before std::forward
template<typename T>
void	doSomethingTemplate(T vec)
{
	doSomething(vec);
}

// after std::forward
template<typename T>
void	doSomethingTemplate2(T&& vec)
{
	doSomething(std::forward<T>(vec));
}

int	main()
{
	CustomVector	my_vec(10, 1024);
	CustomVector	temp(my_vec);
	std::cout << my_vec.n_data << std::endl;	// 10

	// 복사가 일어나지 않기 때문에 더 빠름
	CustomVector	my_vec2(10, 1024);
	CustomVector	temp2(std::move(my_vec2));
	std::cout << my_vec2.n_data << std::endl;	// 0

	CustomVector	my_vec3(10, 1024);
	// 아래서 my_vec3를 더 사용하기 때문에 
	// class CustomVector Copy constructor
	doSomething(my_vec3);						// Pass by L-reference
	// class CustomVector Move constructor
	doSomething(CustomVector(10, 8));			// Pass by R-reference

	// before std::forward
	CustomVector	my_vec4(10, 1024);
	doSomethingTemplate(my_vec4);				// Pass by L-reference
	doSomethingTemplate(CustomVector(10, 8));	// Pass by L-reference

	// after std::forward
	CustomVector	my_vec5(10, 1024);
	doSomethingTemplate2(my_vec5);				// Pass by L-reference
	doSomethingTemplate2(CustomVector(10, 8));	// Pass by R-reference

	return (0);
}
