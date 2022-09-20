// 17.2 std::string의 생성자들과 형변환

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// string으로 바꾸는 또 다른 방법
template <typename T>
std::string	ToString(T x)
{
	std::ostringstream	osstream;

	// output string stream으로 입력
	osstream << x;
	// stream에 있는 내용을 string으로 바꿔서 처리
	return (osstream.str());
}

// 
template <typename T>
bool	FromString(const std::string& str, T& x)
{
	// input string stream을 초기화할 때 str을 넣어서 초기화
	std::istringstream	isstream(str);
	// stream을 x로 흘려 보냄, x의 타입은 T
	// 흘려 보낼 수 있으면 true, 아니면 false
	return ((isstream >> x) ? true : false);
}

int	main()
{
	{
		// default 생성자 호출
		std::string	my_string;
		std::cout << my_string << std::endl;	// 

		std::string	my_string2("my string");
		std::cout << my_string2 << std::endl;	// my string

		// 복사 생성자 호출
		std::string	my_string3(my_string2);
		std::cout << my_string3 << std::endl;	// my string

		// 3번째부터 복사
		std::string	my_string4(my_string2, 3);
		std::cout << my_string4 << std::endl;	// string

		// 3번째부터 5글자만 복사
		std::string	my_string5(my_string2, 3, 5);
		std::cout << my_string5 << std::endl;	// strin

		const char	*literal = "my string";
		std::string	my_string6(literal, 4);
		std::cout << my_string6 << std::endl;	// my s

		std::string	my_string7(10, 'A');
		std::cout << my_string7 << std::endl;	// AAAAAAAAAA
	}
	
	{
		std::vector<char>	vec;

		for (auto e : "Today is a good day.")
			vec.push_back(e);

		// STL algorithm, iterator와 함께 사용
		std::string			string1(vec.begin(), vec.end());
		std::string			string2(vec.begin(), std::find(vec.begin(), vec.end(), 'g'));

		std::cout << string1 << std::endl;	// Today is a good day.
		std::cout << string2 << std::endl;	// Today is a 
	}

	{
		// 정수 타입을 문자열로 받지 못함
		// std::string			my_str(4);
		// 정수가 아닌 문자열로 들어간 것
		// 출력 file명을 결정할 떄 유용 => 파이썬의 용법과 비슷
		std::string	my_str(std::to_string(1004));

		std::cout << my_str << std::endl;	// 1004
		my_str += std::to_string(1000);
		std::cout << my_str << std::endl;	// 10041000

		int			i = std::stoi(my_str);
		float		f = stof(my_str);

		std::cout << my_str << std::endl;	// 10041000(string)
		std::cout << i << std::endl;		// 10041000(int)
		std::cout << f << std::endl;		// 1.0041e+07

		// 숫자 => 숫자로 된 문자열
		std::string		my_str2(ToString(3.141592));

		std::cout << my_str2 << std::endl;	// 3.14159

		double		d;

		// 숫자로 된 문자열 => 숫자
		FromString(my_str2, d);
		std::cout << d << std::endl;	// 3.14159
		// 숫자로 되지 않은 문자열은 숫자로 변환하지 못함
		FromString("Hello", d);
		std::cout << d << std::endl;	// 0
	}

	return (0);
}