// 4.3 using문과 모호성

// using 키워드
// 큰 프로그램을 만들다보면, 동일한 이름을 가진 변수나 함수를 정의할 수 있음
// OOP에서는 함수 이름이 겹치게 overriding, overloading이 권장될 때도 있음
// 이 때, 컴파일러는 어떤 것을 써야할지 모호한 상황이 발생함
// 이걸 쓰라고 분명하게 이야기 해주는 것이 using 키워드

#include <iostream>

namespace A
{
	int	my_var(10);
	int	my_a(10);
}

namespace B
{
	int	my_var(20);
	int	my_b(20);
}

int main()
{
	// 헤더 파일에 포함하게 되면 전역에서 사용하게 되기 때문에 문제 발생 가능성
	// 가급적이면 cpp 파일에 포함하자
	using namespace std;
	using namespace A;
	using namespace B;
	// 이런 방식은 안 됨
	// using namspace std::cout;
	using std::cout;
	using std::endl;

	// cout이 뭔가? <iostream> std에서 찾아보자
	cout << "hello world" << endl;
	// 이름이 같을 경우, 문제가 발생
	// error: reference to 'my_var' is ambiguous
	cout << my_var << endl;
	cout << A::my_var << endl;
	cout << B::my_var << endl;
	cout << my_a << endl;
	cout << my_b << endl;

	// 블록으로 감싸주는 경우
	// 이 블록은 A, B 둘 다 영향을 받아 문제가 해결되지 않음
	{
		using namespace A;
		cout << my_var << endl;
	}

	// using namespace B; 밖에 없기 때문에 문제 해결 => 여기도 블록화
	{
		using namespace B;
		cout << my_var << endl;
	}

	return (0);
}