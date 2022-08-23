// 4.9 자료형에게 가명 붙여주기

// alias
// typedef를 많이 사용하긴 함
// C++ 11에 using을 사용할 수 있음 => using namespace와는 약간 다름

#include <iostream>
#include <vector>

int main()
{
	// double을 거리, 속도 등에 따라 이름을 지어주고 싶은 경우
	// 주석 겸 코드 유지 관리 용도
	typedef double	distance_t;
	typedef double	velocity_t;
	// 복잡한 자료형
	typedef std::vector<std::pair<std::string, int> > pairlist_t;
	// 같은 표현 : 실제 메모리 대입은 아니고, 컴파일러에게 알려주는 용도
	using pairlist_t = std::vector<std::pair<std::string, int> >;

	// 컴파일러 입장에서는 동일
	double		my_distance;
	distance_t	home_to_work;
	distance_t	home_to_school;
	pairlist_t pairlist1;
	pairlist_t pairlist2;

	return (0);
}