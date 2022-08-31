// 8.6 소멸자

// destructor
// 함수가 변수를 제거하는 것이 아니라
// 변수가 영역을 벗어나 사라질 때 호출되는 함수
// 소멸자는 인스턴스가 메모리에서 해제될 때 내부에서 자동적으로 호출

#include <iostream>

class Simple
{
private:
	int	m_id;

public:
	Simple(const int &id_in)
		:m_id(id_in)
	{
		std::cout << m_id << " " << "class Simple constructor" << std::endl;
	}

	~Simple()
	{
		std::cout << m_id << " " << "class Simple destructor" << std::endl;
	}
};

class IntArray
{
private:
	int	*m_arr = nullptr;
	int	m_length;

public:
	IntArray(const int &length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];
		std::cout << "class IntArray constructor" << std::endl;
	}

	int	getLength() { return (m_length); }

	~IntArray()
	{
		if (m_arr != nullptr)
		{
			delete [] m_arr;
			std::cout << "class IntArray destructor" << std::endl;
		}
	}
};

int	main()
{
	Simple	*s1 = new Simple(0);
	Simple	s2(1);
	Simple	s3(2);

	delete s1;
	// 0 class Simple constructor
	// 1 class Simple constructor
	// 2 class Simple constructor
	// 0 class Simple destructor
	// 2 class Simple destructor
	// 1 class Simple destructor

	// 소멸자는 인스턴스가 메모리에서 해제될 때 내부에서 자동적으로 호출
	// 동적 할당의 경우 영역을 벗어나도 자동으로 메모리가 해제되지 않기 때문에 
	// delete로 메모리를 해제할 때만 소멸자가 호출됨 => delete하는 위치가 중요
	// 소멸자를 프로그래머가 직접 호출하는 것은 대부분 권장하지 않음
	Simple	*s4 = new Simple(0);
	Simple	s5(1);
	Simple	s6(2);

	// 0 class Simple constructor
	// 1 class Simple constructor
	// 2 class Simple constructor
	// 2 class Simple destructor
	// 1 class Simple destructor

	while (true)
	{
		IntArray	my_int_arr(10000);

		// 불가능
		// delete하는 메서드 함수를 정의? 소멸자를 사용하면 편함
		// 소멸자는 지역 변수의 경우, 변수가 소멸되는 시점(블록)에서 소멸자 호출
		// delete[] my_int_arr.m_arr;

		// 동적 할당이 어렵다면 vector 사용
		// vector 내부에 delete가 구현이 되어있어 delete를 써줄 필요가 없음
	}

	return (0);
}