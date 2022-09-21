// 18.3 문자열 흐름

// string stream : 문자열 흐름의 버퍼 역할
// string stream은 string type이기 때문에 공백이나 개행 문자가 나올 때까지 계속 read

// basic_stringstream의 서로 다른 자식 클래스들이기 때문에 각각 include
#include <iostream>	// cout
#include <sstream>	// string stream

int	main()
{
	{
		std::stringstream	os;
		std::string			str;

		// 버퍼에 추가(append)
		os << "Hello, World!";		// << : insertion operator, >> : extraction operator
		// 공백, 개행 문자 단위로 버퍼 read
		os >> str;
		std::cout << str << std::endl;	// Hello,

		// 버퍼를 해당 문자열로 초기화 => World!가 출력되지 않음
		os.str("Hello, World!");
		str = os.str();
		// std::endl로 스트림에 같이 저장
		os << std::endl;
		std::cout << str << std::endl;	// Hello, World!\n
	}

	{
		std::stringstream	os1, os2, os3, os4;
		std::string			str1, str2, str3, str4, str5, str6, str7, str8;
		int					i = 12345;
		double				d = 67.89;
		int					i2;
		double				d2;

		// 문자열 입력, 문자열 출력
		os1 << "12345 67.89";
		os1 >> str1 >> str2;
		std::cout << str1 << " | " << str2 << std::endl;	// 12345 | 67.89

		os2 << "1234567.89";
		os2 >> str3 >> str4;
		std::cout << str3 << " | " << str4 << std::endl;	// 1234567.89 |

		// 특정 자료형 입력, 문자열 출력
		// 특정 자료형 입력, 특정 자료형 출력도 가능
		os3 << i << d;
		os3 >> str5 >> str6;
		std::cout << str5 << " | " << str6 << std::endl;	// 1234567.89 |

		// 공백으로 구분하는 것이 스트림 전반에서 공통적으로 일어나는 현상
		// 이용하거나 피하거나
		os4 << i << " " << d << " ";
		// string stream은 string type이기 때문에 공백이나 개행 문자가 나올 때까지 계속 read
		os4 >> str7 >> str8;
		std::cout << str7 << " | " << str8 << std::endl;	// 12345 | 67.89

		// string 버퍼를 비우는 방법
		// 위에서 string을 사용하고 비운 이후에는 왜 입력받지 못하는가?
		// 2개의 공백 혹은 개행문자가 나올 때까지 출력을 하는데 나오지 않으므로
		// 더 이상 입력을 받지 못함
		os4.str("");
		os4 << "hello";
		// 함수 오버로딩 : 매개변수가 없을 때에는 버퍼에 있는 값을 string으로 리턴
		std::cout << os4.str() << std::endl;
		std::cout << os4.str() << std::endl;
		os4.str("");

		// 이런 것을 방지해주는 것이 clear() => state까지 초기화
		// os4.clear();

		os4 << i << " " << d << " ";
		os4 >> i2 >> d2;
		std::cout << i2 << " | " << d2 << std::endl;	// 12345 | 67.89
	}
	
	return (0);
}