// 18.1 istream으로 입력 받기

#include <iostream>
#include <string>
#include <iomanip>	// I/O manipulators

int	main()
{
	{
		int	i;
		
		// 기본적인 방식
		std::cout << "Enter a number >> ";
		std::cin >> i;					// 123
		std::cout << i << std::endl;	// 123

		// 기본적으로 스트림은 버퍼에 임시적으로 저장된 것을 일부 꺼내오는 방식
		// 1. 버퍼의 크기를 정해놓고 입력을 받는 방식
		char	buf1[10];
		char	buf2[10];

		// 글자가 10글자가 넘어가면 런타임 에러
		std::cin >> buf1;					// abcdefghijk
		std::cout << buf1 << std::endl;		// abcdefghijk

		// setw : n - 1글자만 받게 함('\0')
		std::cin >> std::setw(5) >> buf2;	// abcdefghijk
		std::cout << buf2 << std::endl;		// abcd
		// 추가적으로 입력받지 않음 : 입력한 값이 버퍼에 남아있기 떄문
		std::cin >> std::setw(5) >> buf2;
		std::cout << buf2 << std::endl;		// efgh
		std::cin >> std::setw(5) >> buf2;
		std::cout << buf2 << std::endl;		// ijk

		// 파일 입출력 스트림과 표준 입출력 스트림은 거의 비슷
		// 버퍼를 이용한다는 점?
	}

	{
		// 2. 한 글자씩 입력을 받는 방식
		// 중간에 공백을 무시하고 출력
		// 공백으로 구분하기 때문에
		char	ch;

		while (std::cin >> ch)
			std::cout << ch;
		// Hello World 
		// HelloWorld => 공백을 무시하고 출력

		int		i;
		float	f;
		
		// 공백을 입력하면 나눠져서 들어가고
		// 공백이 없으면 한 번에 들어감
		std::cin >> i >> f;				// 1 12.24
		std::cout << i << " " << f;		// 1 12.24

		// 공백을 입력받고 싶다면?
		while (std::cin.get(ch))
			std::cout << ch;
		// Hello World 
		// Hello World

		char	buf[5];

		std::cin.get(buf, 5);			// Hello, World!!!
		// read한 개수를 출력
		std::cin.gcount();				// 4
		std::cout << buf << std::endl;	// Hell

		std::cin.get(buf, 5);
		std::cin.gcount();				// 4
		std::cout << buf << std::endl;	// o, W
	}

	{
		char	buf[5];

		std::cin.getline(buf, 5);		// Hello, World!!!
		std::cin.gcount();				// 4
		std::cout << buf << std::endl;	// Hell

		// getline이 버퍼를 다 읽어와서 더 이상 read하지 못함
		std::cin.getline(buf, 5); 
		std::cin.gcount();				// 0
		std::cout << buf << std::endl;	// 
	}

	{
		char	buf[100];

		// 개행 문자를 read하지 않음 => 버퍼에 남아있음
		std::cin.get(buf, 100);			// abc
		std::cout << buf << std::endl;	// abc

		// 개행 문자까지 읽어들이기 때문에 입력 받지 않고 버퍼 read
		std::cin.getline(buf, 100);
		std::cout << buf << std::endl;	// '\n'
	}

	{
		// 버퍼 사이즈를 고민하지 않아도 됨
		std::string	buf;

		// getline을 호출하는 다른 방법
		std::getline(std::cin, buf);					// Hello
		// cin.getline을 사용해서 읽지 않았다는 의미
		std::cout << std::cin.gcount() << std::endl;	// 0
		std::cout << buf << std::endl;					// Hello
	}

	{
		char	buf[1024];

		// 버퍼에서 읽어올 때, 앞의 n글자를 무시하는 기능
		std::cin.ignore(2);
		// 다음 글자가 무엇인지를 버퍼를 들여다보기만 하고, 꺼내지는 않음
		std::cout << (char)std::cin.peek() << std::endl;	// l

		std::cin >> buf;				// Hello
		std::cout << buf << std::endl;	// llo

		// 버퍼로 다시 되돌림
		std::cin.unget();
		std::cin >> buf;
		std::cout << buf << std::endl;	// o

		// 원하는 글자를 버퍼에 넣음
		std::cin.putback('A');
		std::cin >> buf;
		std::cout << buf << std::endl;	// A
	}

	return (0);
}

// 버퍼 사이즈보다 큰 값을 읽어오려고 하면?