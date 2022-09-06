// 9.11 대입 연산자 오버로딩, 깊은 복사 vs. 얕은 복사

// 동적 할당된 메모리에 대한 포인터 변수를 멤버로 가지고 있는 class의 경우
// 복사 or 대입 연산을 할 때, 깊은 복사? 얕은 복사?인가에 따라
// 대입 연산자 오버로딩 or 복사 생성자 구현할 때 조심해야 함
// string, vector를 사용하면 크게 신경쓰지 않아도 됨
// 최근에는 대부분 container를 사용
// 하지만 이런 문제가 존재하는 걸 알고, 다른 언어에서도 깊은 복사? 얕은 복사가
// 어떻게 일어나는지 알고 공부한다면 도움이 됨

#include <cassert>
#include <iostream>

// string을 사용하면 이미 연산자 구현이 되어있기 때문에 편함
// 추가로 기능 구현?
// 1. string class를 상속받아 추가 구현
// 2. 만든 클래스에서 std::string을 사용 => 퍼포먼스가 약간은 떨어질 수 있음

// 스택과 힙이 분리되어 있기 때문에 copy 문제는 항상 발생할 여지가 있음
// => 이런 언어에서는 이런 방식으로 해결... 어떻게 해결할 것인지 생각해보는 것이 실력 향상

class MyString
{
private:
	char	*m_data = nullptr;
	int		m_length = 0;

public:
	MyString(const char *source = "")
	{
		assert(source);

		// null character 추가하기 위해 
		m_length = std::strlen(source) + 1;
		// 여러 포인터가 하나의 주소를 가리키고 있다면 하나의 포인터가 그 주소를 할당 해제했을 때
		// 다른 포인터가 그 주소를 사용할 수 있는 문제가 발생
		m_data = new char[m_length];
		for (int i = 0; i < m_length; i++)
			m_data[i] = source[i];
		m_data[m_length - 1] = '\0';
		std::cout << "class MyString constructor" << std::endl;
	}

	// copy constructor
	MyString(const MyString &source)
	{
		m_length = source.m_length;
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];
			for (int i = 0; i < m_length; i++)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
		std::cout << "class MyString copy constructor" << std::endl;
	}

	char	*getString() const { return (m_data); }
	int		getLength() const { return (m_length); }

	// assignment operator overloading
	// overloading하기 전의 기본 = 연산자도 테스트해보자
	MyString&	operator=(const MyString &source)
	{
		// // shallow copy
		// this->m_data = source.m_data;
		// this->m_length = source.m_length;

		// 1. prevent self-assignment : copy constructor에서 발생할 수 없는 문제
		// 자신이 자신에게 대입 => a = a
		if (this == &source)
			return (*this);
		// 2. 생성자는 새로 생성되는 것이기 때문에 이전에 동적 할당을 받을 수 없음
		// 하지만 assignment operator는 메모리를 가지고 있을 수 있음 => 할당 해제
		delete[] m_data;
		m_length = source.m_length;
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];
			for (int i = 0; i < m_length; i++)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
		std::cout << "assignment operator" << std::endl;
	}

	~MyString()
	{
		delete[] m_data;
		std::cout << "class MyString destructor" << std::endl;
	}
};

int	main()
{
	MyString	hello("hello");								// class MyString constructor

	// cout이 char *을 인식하지 못하기 때문에 형 변환
	std::cout << (int *)hello.getString() << std::endl;		// 0x143e06720
	std::cout << hello.getString() << std::endl;			// hello

	// 복사 생성자가 없음 => 기본 생성자를 호출
	{
		MyString copy = hello;
		// 이 방법보다는 아래를 추천
		MyString copy2(hello);
	
		// 두 인스턴스의 멤버 변수가 같은 주소를 가리킴 => 얕은 복사
		// 블록을 벗어날 때, 소멸자가 호출되면서 할당 해제
		std::cout << (int *)copy.getString() << std::endl;	// 0x143e06720
		std::cout << copy.getString() << std::endl;			// hello
	}	// class MyString destructor

	// 복사 생성자가 있음 => 복사 생성자를 호출
	{
		MyString copy = hello;								// class MyString copy constructor

		// 두 인스턴스의 멤버 변수가 같은 주소를 가리킴 => 얕은 복사
		// 블록을 벗어날 때, 소멸자가 호출되면서 할당 해제
		std::cout << (int *)copy.getString() << std::endl;	// 0x143e06730
		std::cout << copy.getString() << std::endl;			// hello
	}	// class MyString destructor

	// 댕글링 포인터
	std::cout << hello.getString() << std::endl;
	
	MyString copy3;											// class MyString constructor
	// 대입 연산자를 호출
	copy3 = hello;											// assignment operator

	// shallow copy를 막기 위해서는 복사 생성자를 구현해야 함
	// 복사 생성자를 구현할 여력이 없는 경우에도 shallow copy를 막아야 함
	// => 복사 생성자를 쓰지 않을 바에는 아예 생성자를 쓰지 말자
	// MyString(const MyString &source) = delete;

	return (0);
}