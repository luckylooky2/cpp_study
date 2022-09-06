// 9.6 첨자 연산자([]) 오버로딩 하기

// subscript operator
// 값 접근, 수정 등...

#include <iostream>
#include <cassert>

class IntList
{
private:
	int	m_list[10];
	
public:
	void	setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int	getItem(int index) const
	{
		return (m_list[index]);
	}

	// 배열 포인터를 가져오기
	int	*getList()
	{
		return (m_list);
	}
};

class NewIntList
{
private:
	// vector를 사용할 경우, vector 내의 연산자 오버로딩을 그대로 사용할 수도 있음
	int	m_list[10];
	
public:
	NewIntList(int num = 0)
	{
		for (int i = 0; i < 10; i++)
			m_list[i] = num;
		std::cout << "class ConstIntList constructor" << std::endl;
	}

	// getter, setter 함수를 사용할 필요가 없음
	// 용도에 따라 파라미터로 다른 자료형이 들어올 수 있음
	// map : key를 string으로 사용
	int&	operator [] (const int index)
	{
		// 런타임 에러 디버깅할 때 시간을 아낄 수 있음
		// []는 많이 사용됨 => if문을 사용하면 많이 느려짐
		// assert 사용해서 디버깅을 깔끔하게 하자
		assert(index >= 0);
		assert(index < 10);

		return (m_list[index]);
	}

	// const class 함수 오버로딩 => const의 유무에 따라 함수 오버로딩 순서가 달라짐
	const int&	operator [] (const int index) const 
	{
		assert(index >= 0);
		assert(index < 10);

		return (m_list[index]);
	}
};

int main()
{
	IntList	my_list;

	my_list.setItem(3, 1);
	std::cout << my_list.getItem(3) << std::endl;	// 1
	std::cout << my_list.getList()[3] << std::endl;	// 1

	// operator overloading
	NewIntList			new_list;
	// error: default initialization of an object of const type 'const ConstIntList' 
	// without a user-provided default constructor
	// const 자료형이라서 기본 생성자로 생성할 수 없음
	const NewIntList	const_list(12);

	// l-value가 될수도 있어야 하기 때문에 reference 타입으로 return
	new_list[3] = 100;
	std::cout << new_list[3] << std::endl;		// 100

	// error: cannot assign to return value 
	// because function 'operator[]' returns a const value
	// const_list[3] = 100;
	std::cout << const_list[3] << std::endl;	// 12

	// class list
	NewIntList	*class_list = new NewIntList[5];

	// 서로 다름에 주의
	class_list[3] = NewIntList(0);		// class_list에 접근
	(*class_list)[3];					// class_list 안의 m_list에 접근

	return (0);
}
