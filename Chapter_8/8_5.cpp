// 8.5 위임 생성자

// 위임 생성자
// 생성자가 다른 생성자를 사용하는 것

#include <iostream>
#include <string>

class Student
{
private:
	int			m_id;
	std::string	m_name;

public:
	Student(const std::string &name_in)
		// 방법 1 => 비추천 : 한 기능을 하는 코드는 한 곳에서만 나와야 한다, 유지 보수
		// name_in을 입력하는 기능은 한 번만 구현
		// : m_id(0), m_name(name_in)
		// 방법 2 => 위임 생성자
		// : Student(0, name_in)
	{
		init(0, name_in);
		std::cout << "class Student constructor" << std::endl;
	}

	// 만약 이름만 매개변수로 넣어서 인스턴스를 생성하고 싶은 경우
	// default argument는 오른쪽부터 넣어야 하기 때문에 불가
	Student(const int &id_in, const std::string &name_in)
		// : m_id(id_in), m_name(name_in)
	{
		init(id_in, name_in);
		std::cout << "class Student constructor" << std::endl;
	}

	// 초기화 자체를 따로 함수화하기도 함
	void	init(const int &id_in, const std::string &name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}

	void	print()
	{
		std::cout << m_id << " " << m_name << std::endl;
	}
};

int	main()
{
	Student	me(0, "chanhyle");
	Student	you("gyyu");

	me.print();			// 0 chanhyle
	you.print();		// 0 gyyu

	return (0);
}