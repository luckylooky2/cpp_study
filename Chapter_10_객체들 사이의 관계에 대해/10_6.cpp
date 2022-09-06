// 10.6 컨테이너 클래스

// container
// 다른 class를 담는 역할을 하는 class
// 이러한 컨테이너들은 ~가 ~의 멤버다, member-of 관계를 표시할 수 있음
// 템플릿을 이해하는데 편리함

#include <iostream>
#include <string>
#include <vector>

// int가 담기는 array를 구현해보기
class IntArray
{
private:
	int	m_length = 0;
	int	*m_data = nullptr;

public:
	// constructor
	IntArray(/* args */);
	// destructor
	~IntArray();
	// initialize()
	// reset()
	// resize()
	// insertBefore(const int &value, const int &index);
	// remove(const int &index);
	// push_back(const int &value);
};


int	main()
{
	// int가 vector나 array에 담겨 있는 컨테이너
	std::vector<int>	int_vec;
	std::array<int, 10>	int_arr;

	IntArray	my_arr{1, 3, 5, 7, 9};

	my_arr.insertBefore(10, 1);
	my_arr.remove(3);
	my_arr.push_back(13);

	return (0);
}