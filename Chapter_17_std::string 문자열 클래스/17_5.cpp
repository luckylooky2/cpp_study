// 17.5 std::string 대입, 교환, 덧붙이기, 삽입

#include <iostream>

int	main()
{
	std::string	str1("one");
	std::string	str2;

	// assign, append, push_back
	// 직관적으로 생각하는 방법이 대부분 된다고 생각하면 됨
	str2 = str1;
	std::cout << str2 << std::endl;		// one
	str2 = "two";
	std::cout << str2 << std::endl;		// two
	// assign() 리턴 값 : 자기 자신에 대한 레퍼런스(l-value)
	// chaining이 가능
	str2.assign("three");
	std::cout << str2 << std::endl;		// three
	str2.assign("three").append(" ").append("four");
	str2 += " five ";
	// push_back은 1 character, append는 문자열
	str2.push_back('6');
	std::cout << str2 << std::endl;		// three four five 6


	// swap
	str1 = "one";
	str2 = "two";

	std::cout << str1 << " " << str2 << std::endl;	// one two
	std::swap(str1, str2);
	std::cout << str1 << " " << str2 << std::endl;	// two one
	str1.swap(str2);
	std::cout << str1 << " " << str2 << std::endl;	// one two

	// insert
	str1.insert(3, " two");
	std::cout << str1 << std::endl;	// one two

	return (0);
}