// 8.10 정적 멤버 변수

// 함수 안에 있는 static 변수와 class에 정의된 static 변수는 다름
// class 내의 함수가 class 멤버 변수에 바로 접근할 수 있는 것처럼
// 함수 안에 있는 static 변수
// 함수 안에서 밖에 접근하지 못함 => 밖에서 사용할 경우 값을 return을 해줘야 함
// class에 정의된 static 변수
// class(인스턴스, 객체)와는 관계가 없음
// 인스턴스 생성, 소멸과 관계없이 전역 변수처럼 프로그램 실행, 종료에 종속
// 내부 look-up table로 사용하면 메모리를 아낄 수 있음


#include <iostream>

class Something
{
public:
	int						m_value = 1;
	// 정적 멤버 변수는 초기화가 불가능 => 중복 선언 방지
	// 정적 멤버 변수 선언은 class 안에서
	// 전방 선언 => 실제 메모리를 사용하지 않음, 단순히 static 변수를 컴파일러에게 알려주는 것
	// 모든 객체가 공유
	// error: non-const static data member must be initialized out of line
	// extern 키워드와 비슷한 에러
	static int				m_static;
	// const 정적 멤버 변수는 반드시 초기화 => const이기 때문에
	const static int		m_conststatic = 100;
	// 컴파일타임에 변수가 확정이 되야하는 경우 constexpr
	// static constexpr int	m_constexprstatic = 1;
};

// 정적 멤버 변수 정의는 class 밖에서(global scope)
// 정의 => 실제 메모리가 할당
// 정의할 때는 private, protected와 관계없이 접근할 수 있음
// 없을 경우 error: ld: symbol(s) not found for architecture x86_64
// 주의!
// 헤더 파일이 아닌 cpp 파일에 추가 => 중복 선언 문제가 발생할수도
int	Something::m_static = 0;
// 값을 바꿀 수 없기 때문에 불가
// int	Something::m_conststatic = 0;

int	generateId()
{
	static int	s_id = 0;
	
	return (++s_id);
}

int main()
{
	generateId();	// 0
	generateId();	// 1

	// 메모리에 정적으로 존재하기 때문에 인스턴스가 생성되기 전에도 존재
	std::cout << &Something::m_static << " " << Something::m_static << std::endl;	// 0x1085170c8 0
	std::cout << Something::m_conststatic << std::endl;								// 100
	// error: ld: symbol(s) not found for architecture x86_64
	std::cout << &Something::m_conststatic << std::endl;

	Something	sth1;
	Something	sth2;

	// public
	sth1.m_value = 2;
	sth1.m_static = 2;
	std::cout << &sth1.m_value << " " << sth1.m_value << std::endl;		// 0x7ffeeb39d8b8 2
	std::cout << &sth2.m_value << " " << sth2.m_value << std::endl; 	// 0x7ffeeb39d8b0 1
	std::cout << &sth1.m_static << " " << sth1.m_static << std::endl;	// 0x1085170c8 2
	// sth2의 정적 멤버 변수 값도 바뀜
	std::cout << &sth2.m_static << " " << sth2.m_static << std::endl; 	// 0x1085170c8 2

	// 일반 멤버 변수와 헷갈릴 수 있기 때문에 
	sth1.m_static = 10;
	// 보다는 다음을 추천
	Something::m_static = 10;

	// this 키워드가 static member variable에는 적용이 되나?
	// 인스턴스를 통해 접근할 수 있기 때문에, this를 통해서가 아닐수도?

	return (0);
}