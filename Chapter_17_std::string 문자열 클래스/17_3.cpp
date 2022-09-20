// 17.3 std::string의 길이와 용량

#include <iostream>
#include <string>

int	main()
{
	// C++ string에는 문자열 맨 마지막에 '\0'가 없음에 주의
	// string 클래스에는 길이를 저장하는 공간이 있기 떄문에 끝났는지 확인할 필요가 없음
	std::string	my_str("012345678");

	// 문자열 길이
	std::cout << my_str.size()  << std::endl;		// 9
	// 빈 문자열인지
	std::cout << std::boolalpha;
	std::cout << my_str.empty()  << std::endl;		// false
	std::cout << my_str.length()  << std::endl;		// 9
	// 여분의 용량을 넣는 이유
	// 가급적이면 memory allocation(new, delete)을 안 하려고 함 => 느려지기 때문에
	std::cout << my_str.capacity()  << std::endl;	// 22
	std::cout << my_str.max_size()  << std::endl;	// 18446744073709551599

	// (const char [1])""
	// 리터럴에는 '\0'이 숨어있기 때문에
	std::string	my_str2("");

	std::cout << my_str2.size()  << std::endl;	// 0
	std::cout << my_str2.empty()  << std::endl;	// true

	// 임의로 용량을 잡아둘 수 있음
	my_str.reserve(1000);

	return (0);
}