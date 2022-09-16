// 13.1 함수 템플릿

// 프로그래밍 언어에는 프로그래머의 단순 반복 작업을 줄여줌
// 템플릿은 여러 가지 자료형에 대해 거의 비슷한 코드를 반복해서 작성하는 것을 방지
// 템플릿은 사용자가 템플릿 매개 변수에 대해 제공하는 인수를 기반으로 컴파일 시간에 일반 형식 또는 함수를 생성하는 구문입니다.
// 컴파일러가 컴파일 도중에 각 템플릿 인스턴스에 대한 코드를 만들어 준다.
// 컴파일 도중에 다형성을 부여할 수 있다. 가상 테이블이 없어서 프로그램이 더 빠르다.
// 자바에서는 generic라고 부름

#include <iostream>

// 여러 가지 자료형이 반복되는 부분을 T로 치환
// typename 대신에 class를 쓸 수도 있음 => 문법상 차이는 없고, 뉘앙스 차이? 
template<typename T>

// T 자리에 어떤 것이 들어가야 할지 컴파일러가 찾아내고
// 손으로 일일이 타이핑할 것을 컴파일러가 대신 해주는 기능
// instanciation
// 아래처럼 T로 정의한 자료형 말고, 
// int, float 등.. 특정 자료형에 대해 만드는 것을 뜻함
// 서로 다른 자료형을 비교하려면
// template<typename T, typename T2>처럼 사용해야 함
T getMax(T x, T y)
{
	return ((x > y) ? x : y);
}

// int getMax(int x, int y)
// {
// 	return ((x > y) ? x : y);
// }

// 비슷한 패턴, 반복되는 부분이 존재
// 템플릿이 있어서 작업량이 줄어듦 => 프로그래머가 손으로 할 것을 컴파일러에게 넘겨줌
// char getMax(char x, char y)
// {
// 	return ((x > y) ? x : y);
// }

class Cents
{
private:
	int	m_cents;

public:
	Cents(int cents)
	{ 
		m_cents = cents;
		std::cout << "class Cents constructor" << std::endl;
	}

	int	getCents() const { return m_cents; }
	int	&getCents() { return m_cents; }
};

std::ostream& operator<< (std::ostream &out, const Cents &cents)
{
	out << cents.getCents();
	return (out);
}

bool operator>(const Cents &c1, const Cents &c2)
{
	return ((c1.getCents() > c2.getCents()) ? true : false);
}

int	main()
{
	std::cout << getMax(1, 2) << std::endl;						// 2
	std::cout << getMax(3.14, 1.592) << std::endl;				// 3.14
	std::cout << getMax(1.0f, 3.4f) << std::endl;				// 3.4
	std::cout << getMax('a', 'c') << std::endl;					// c
	// error: invalid operands to binary expression ('std::ostream' (aka 'basic_ostream<char>') and 'Cents')
	// error: invalid operands to binary expression ('Cents' and 'Cents')
	// output, comparison operator가 필요, 출력도 Cents로 바뀌기 때문
	// 어떤 타입으로 instanciation할 것인지도 알려주기 때문에 에러 메시지에 맞춰 수정하자
	// 템플릿을 쓰는 것은 쉬운데, 필요한 기능들이 모두 구현이 되어 있어야 함
	std::cout << getMax(Cents(5), Cents(9)) << std::endl;		// 9

	return (0);
}