// 17.1 std::string과 std::wstring

// 문자열을 쉽게 사용하기 위한 string class

#include <string>
#include <cstddef>
#include <iostream>
#include <locale>

int	main(void)
{
	// c-style string example
	// 번거로움
	{
		char	*strHello = new char[7];

		strcpy(strHello, "hello!");
		std::cout << strHello << std::endl;
	}

	// basic_string<>, string, wstring
	// 구현된 라이브러리를 참고하는 방법(go to definition)
	{
		// typedef basic_string<char, char_traits<char>, allocator<char> > string;
		// typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wstring;
		// basic_string이라는 템플릿 클래스의 인스턴스
		std::string		string;
		std::wstring	wstring;
		// typedef unsigned short wchar_t
		// data size를 많이 사용하는 문자 : wide character, unicode
		// 여러 언어를 다뤄야할 때, 국가별 설정을 할 떄 많이 사용
		wchar_t			wc;
	}

	const std::wstring	texts[] = 
	{
		L"안녕하세요",
	  	L"Ñá", //Spanish
		L"forêt intérêt", //French
		L"Gesäß", //German
		L"取消波蘇日奇諾", //Chinese
		L"日本人のビット", //Japanese
		L"немного русский", //Russian
		L"ένα κομμάτι της ελληνικής", // Greek
		L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
		L"کمی از ایران ", // Persian (I know it, from 300 movie)
		L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
		L"Но какво, по дяволите, е това?" //Bulgarian
	};

	// 로케일을 wcout에서 사용하겠다.
	std::locale::global(std::locale(""));
	// wide cout
	std::wcout.imbue(std::locale());
	for (size_t i = 0; i < 11; ++i)
		std::wcout << texts[i] << std::endl;

	return (0);
}