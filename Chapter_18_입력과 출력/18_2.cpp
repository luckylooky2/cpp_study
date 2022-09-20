// 18.2 ostream으로 출력하기

#include <iostream>
#include <iomanip>

int	main()
{
	// 출력 플래그를 설정할 수 있음
	// std::ios::showpos => + 기호 출력
	std::cout.setf(std::ios::showpos);
	std::cout << 108 << std::endl;		// +108
	
	// 플래그 해제
	std::cout.unsetf(std::ios::showpos);
	std::cout << 109 << std::endl;		// 109
	
	// 16진수로 출력
	// 1. 10진수 플래그를 꺼야 함
	std::cout.unsetf(std::ios::dec);
	std::cout.setf(std::ios::hex);
	// 2. std::ios::basefield 플래그 추가
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout << 110 << std::endl;		// 6e
	// 3. iomanip를 사용
	std::cout << std::hex;
	std::cout << 111 << std::endl;		// 6f

	// 대문자로 출력
	std::cout.setf(std::ios::uppercase);
	std::cout << 111 << std::endl;		// 6F

	// boolean을 단어로 출력
	std::cout << std::boolalpha;
	std::cout << true << " " << false << std::endl;	// true false

	// setprecision
	// std::cout << std::defaultfloat;
	// 소수점 표기(앞 자리부터 고정)
	std::cout << std::showpoint;
	std::cout << std::setprecision(3) << 123.456 << std::endl;	// 123.
	std::cout << std::setprecision(4) << 123.456 << std::endl;	// 123.5
	std::cout << std::setprecision(5) << 123.456 << std::endl;	// 123.46
	std::cout << std::setprecision(6) << 123.456 << std::endl;	// 123.456
	std::cout << std::setprecision(7) << 123.456 << std::endl;	// 123.456
	// 소수점 뒷자리를 고정
	std::cout << std::fixed;
	std::cout << std::setprecision(3) << 123.456 << std::endl;	// 123.456
	std::cout << std::setprecision(4) << 123.456 << std::endl;	// 123.4560
	std::cout << std::setprecision(5) << 123.456 << std::endl;	// 123.45600
	std::cout << std::setprecision(6) << 123.456 << std::endl;	// 123.456000
	std::cout << std::setprecision(7) << 123.456 << std::endl;	// 123.4560000
	// 과학적 표기법(uppercase on)
	std::cout << std::scientific;
	std::cout << std::setprecision(3) << 123.456 << std::endl;	// 1.235E+02
	std::cout << std::setprecision(4) << 123.456 << std::endl;	// 1.2346E+02
	std::cout << std::setprecision(5) << 123.456 << std::endl;	// 1.23456E+02
	std::cout << std::setprecision(6) << 123.456 << std::endl;	// 1.234560E+02
	std::cout << std::setprecision(7) << 123.456 << std::endl;	// 1.2345600E+02

	std::cout << std::dec << -12345 << std::endl;						// -12345
	std::cout << std::setw(10) << -12345 << std::endl;					//     -12345
	std::cout << std::setw(10) << std::left << -12345 << std::endl;		// -12345    
	std::cout << std::setw(10) << std::right << -12345 << std::endl;	//     -12345
	std::cout << std::setw(10) << std::internal << -12345 << std::endl;	// -    12345

	// 빈칸을 *로 채움
	std::cout.fill('*');

	return (0);
}