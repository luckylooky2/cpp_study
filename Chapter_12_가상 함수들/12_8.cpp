// 12.8 가상 기본 클래스와 다이아몬드 문제

// 다중 상속 문제 : 다이아몬드 클래스
// A 클래스가 2개 생기는 문제가 발생

#include <iostream>

class PoweredDevice
{
public:
	int	m_i;

	PoweredDevice(int power)
	{
		std::cout << "PoweredDevice : " << power << '\n';
	}
};

// 가상 기본 클래스로 수정
class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		std::cout << "Scanner : " << scanner << '\n';
	}
};

// 가상 기본 클래스로 수정
class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		std::cout << "Printer : " << printer << '\n';
	}
};

class Copier : public Scanner, public Printer
{
public:
	// error: constructor for 'Copier' must explicitly initialize 
	// the base class 'PoweredDevice' which does not have a default constructor
	// PoweredDevice(power) 추가
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)
	{
		std::cout << "Copier" << '\n';
	}
};

int	main()
{
	Copier	cop(1, 2, 3);

	// 가상 기본 클래스 수정 전
	// error: ambiguous conversion from derived class 'Copier' to base class 'PoweredDevice':
	// 서로 주소가 다름 => 서로 다른 인스턴스를 생성

	// 가상 기본 클래스를 통해 해결
	std::cout << &cop.Scanner::PoweredDevice::m_i << std::endl;		// 0x7ffee3ec5800
	std::cout << &cop.Printer::PoweredDevice::m_i << std::endl;		// 0x7ffee3ec5800
	return (0);
}

// 가상 기본 클래스가 어떤 것인가?