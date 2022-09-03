// 9.12 이니셜라이저 리스트 std::initializer_list

// 기본 자료형(int) 배열 => initializer list를 이용해 편하게 초기화
// 사용자 정의 자료형(class) => 생성자, 대입 연산자를 만들 때 편하게 초기화

#include <iostream>
#include <cassert>
#include <initializer_list>

class IntArray
{
private:
	unsigned	m_length = 0;		// unsigned int 
	int			*m_data = nullptr;

public:
	// 1. 동적 할당 생성자
	IntArray(unsigned length)
		: m_length(length)
	{
		m_data = new int[length];
	}

	// 2. 초기화 생성자 : 위임 생성자 활용
	// 중복되는 기능은 가급적 쪼개서 한 곳에서만 이루어지는게 좋음
	// IntArray(5) : 1.
	// IntArray {1, 2, 3, 4, 5} : 1. => 2.
	IntArray(const std::initializer_list<int> &list)
		: IntArray(list.size())
	{
		int	cnt = 0;

		for (auto &elem : list)
			m_data[cnt++] = elem;

		// error
		// cf> initializer_list는 [] 연산자를 제공하지 않음
		// for문, for-each문 : 내부적으로 iterator를 사용하여 반복
		// 다른 사람들이 구현한 것이기 때문에, 어떻게 사용하는지는 공부해야 함
		// for (unsigned cnt = 0; cnt < m_length; cnt++)
		// 	m_data[cnt] = list[cnt];

	}

	~IntArray()
	{
		delete[] (this->m_data);
	}

	friend std::ostream& operator<<(std::ostream& out, const IntArray &arr)
	{
		for (unsigned i = 0; i < arr.m_length; i++)
			out << arr.m_data[i] << " ";
		return (out);
	}

	// initializer_list를 이용해 생성자를 구현한다면
	// assignment operator overloading도 같이 해주는 것이 좋음
};

int main()
{
	// 기본 자료형(int) 배열 => initializer list를 이용해 편하게 초기화
	int	my_arr[5] = {1, 2, 3, 4, 5};
	int	*my_arr2 = new int[5]{1, 2, 3, 4, 5};

	// std::initializer_list
	auto il = {10, 20, 30};

	// error: no matching constructor for initialization of 'IntArray' 
	// 파라미터에 맞는 생성자를 정의해야 함
	IntArray	int_array {1, 2, 3, 4, 5};
	// copy constructor를 만들지 않아도 되는가?
	IntArray	int_array2  = {1, 2, 3, 4, 5};

	std::cout << int_array << std::endl;

	return (0);
}