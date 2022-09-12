// 14.4 std::exception 소개

// 다양한 경우에 대해 exception을 이미 구현해놓음
// 표준 라이브러리 : string, 알고리즘 등에 적절한 예외 처리를 구현

#include <iostream>
// exception class를 사용할 수 있음
#include <exception>
#include <string>

// std::exception을 상속하여 Exception class를 구현
class CustomException : public std::exception
{
public:
	// std::exception에서 가장 중요하게 알아둬야 할 함수 => override
	// C++ 11 : noexcept => 적어도 이 안에서는 throw를 하지 않음
	const char	*what()	const noexcept override
	{
		return ("Custom exception");
	}
};

int	main()
{
	try
	{
		std::string	s;

		// 이미 예외 처리 => resize()안에서 throw
		// 그에 맞추어 적절하게 대응만 하면 됨
		s.resize(-1);

		// exception(의 자식 클래스)을 직접 가져다 사용하는 경우
		throw (std::runtime_error("Bad thing happened"));
		// std::exception을 상속받아 커스텀한 경우
		// throw (CustomException());
	}
	// 확인 용도
	catch(std::length_error& e)
	{
		std::cerr << "Length error" << std::endl;		// Length error
		std::cerr << e.what() << std::endl;				// basic_string

	}
	// std::exception은 부모 클래스
	catch(const std::exception& e)
	{
		// 무엇인지를 나타내는 const char *
		// std::basic_string::resize
		std::cerr << e.what() << '\n';					// basic_string
		// 던진 자식 exception class를 정확하게 알고 싶을 때
		std::cout << typeid(e).name() << std::endl;		// St12length_error
	}

	return (0);
}