// 2.1 기본 자료형 소개

#include <iostream>
#include <bitset>

// C++에는 훨씬 다양한 자료형이 존재
// 자료형마다 할당되는 크기가 다르다.
// char 자료형은 1 byte, int 자료형은 4 byte를 할당

int test()
{
	int			j = 3;
	int			i = -1;
	int 		k = 123;
	char 		a = 'H';
	const char	*b = "Hat";

	// 10진수로 자료형을 변환해서 출력
	std::cout << (uintptr_t)static_cast<void *>(&a) << std::endl; // 6127678959
	std::cout << (uintptr_t)static_cast<void *>(&i) << std::endl; // 6127678964

	// 왜 char 자료형의 주소는 출력할 수 없는가?
	// https://bigpel66.oopy.io/library/cpp/etc/5
	// ostream 이용 시에 C++은 char *를 string으로 인식하게 되는데 C++의 string 특성 상 문자열의 끝을 알리는 '\0'가 들어오지 않는 문자열이 끝이 났다고 인식하지 않는다. 
	// 따라서 주소가 출력되지 않고 빈 칸으로 출력된다. (C++에서 string은 '\0'이라고 하는 NULL이 들어오면 끝으로 인식하는 Zero-Terminated 구조이다.)
	std::cout << &a << std::endl; 			// H{
	std::cout << &b << std::endl; 			// 0x16d3cf5e0
	std::cout << (int *)&a << std::endl; 	// 0x16d3cf5ef
	std::cout << &i << std::endl; 			// 0x16d3cf5f4

	return (0);
}

// 1. character type
// 하나의 자료형이라도 char / char16_t(더 다양한 문자를 위해 바이트 추가) / char32_t / wchar_t(windows, linux 호환-데이터를 저장하는 방식이 다름) 등 다양하게 표현

// 문자열
// string을 이용해서 저장 : standard library
// fundamental type은 아님. 하지만 많이 사용

// 2. integer type
// signed : 음, 0, 양 / unsigned : 0, 양
// 두 자료형이 저장되는 방식이 다름 => 특정 연산할 때, unsigned가 더 빠른 경향이 있음
// 필요한 범위에 따라 : char(최소 1 byte) / short(2) / int(2) / long(4) / long long(8)
// 할당 바이트를 최소 조건으로 규정 => 컴파일러에 따라 다를 수 있음
// 무조건 long long을 쓰면 되는 것 아닌가? (long long * 사용자 수)가 되기 때문에 가급적 메모리를 적게 쓰는게 좋음

// 3. floating-point type
// 지수부와 실수부로 나눔
// 필요한 범위에 따라 : float / double / long double
// 수학적으로 정확하게 계산하지 못함, 오차가 발생할 가능성이 존재
// 정밀한 

// 4. boolean type
// bool 

// 5. void type
// void
// 저장 공간이 없음

// 6. null pointer
// decltpye(nullptr)

int main()
{
	test();

	bool	bValue = false;
	char	chValue = 'A';
	// f가 붙은 리터럴 : float 자료형
	// f가 붙지 않은 리터럴 : double 자료형
	// double 자료형을 float 자료형에 담으려고 하면 데이터 손실이 발생할 수 있음
	float	fValue = 3.141592f;
	double	dValue = 3.141592;

	// modern C++
	// 컴파일 타임에 자동으로 자료형을 결정
	auto	aValue = 3.141592;
	std::cout << sizeof(aValue) << std::endl;; 		// 8

	// 문자도 boolean도 숫자로 바꿔서 저장
	std::cout << ( bValue ? 1 : 0 ) << std::endl;; 	// 0
	std::cout << chValue << std::endl;; 			// A
	std::cout << (int)chValue << std::endl;; 		// 65
	// cout에서 출력할 때 자리수를 지정해서 출력하기 때문
	std::cout << fValue << std::endl;; 				// 3.14159
	std::cout << dValue << std::endl;; 				// 3.14159

	// 초기화하는 세 가지 방법
	// 1. copy initialization 
	int first = 123;

	// 2. direct initialization 
	int second(123);
	int second_test(123.45); // int로 캐스팅이 되어서 컴파일이 가능

	// 3. uniform initialization
	// error: expected ';' at end of declaration
	int third{ 123 };
	int third_test{ 4.5 };

	// 객체 지향은 기본 자료형이 아닌 사용자 정의 자료형을 만드는 것
	// 2, 3번 방법은 사용자 정의 자료형을 만들 때, 많이 사용

	// 변수 선언
	// 같은 자료형끼리만 다중 선언, 모든 변수에 대해서 초기화를 진행할 것
	int x, y, z;
	// 예전 컴파일러는 변수를 가장 위에서 선언해야 했음
	// 요즘엔 사용할 변수는 사용하기 직전에 선언하는 것을 선호 => 디버깅하기 편함, 리팩토링(객체화, 클래스화)하기 편함

	return (0);
}