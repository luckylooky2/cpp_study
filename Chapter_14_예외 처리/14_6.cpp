// 14.6 예외 처리의 위험성과 단점

#include <iostream>

class A
{
public:
	// 소멸자 안에서 throw => 금기시 됨
	// warning: '~A' has a non-throwing exception specification 
	// but can still throw [-Wexceptions]
	// 소멸자의 기능은 단순히 메모리를 해제 => 예외 처리를 할 수 있는 상황이 아님
	~A()
	{
		throw ("error");
		std::cout << "class A destructor" << std::endl;
	};
};

int	main()
{
	try
	{
		// 1. 메모리 처리가 안 되어 메모리 누수가 발생할 수 있음 
		int				*i = new int[1000000];
		// 해결 : 스마트 포인터(유니크 포인터)
		// 영역을 벗어나거나 예외 처리를 할 때, 알아서 메모리를 할당 해제
		unique_ptr<int>	up_i(i);
		// 2. 소멸자에서 예외 처리를 했다면 런타임 에러가 발생
		A 				a;
		// 3. 퍼포먼스가 느려짐
		// for문 등에서 try, catch를 하는 것은 효율성이 떨어짐
		// 최근에는 zero-cost exception이 등장
		// 4. 오류와 예외 처리는 다름
		// 모든 오류를 다 예외 처리로 잡으려고 하지 말라
		// ex. 사용자 입력은 정상적인 입력을 다시 받는 것이 자연스러움
		// => 네트워크 요청, 응답, 분산 처리, 병렬 처리, 하드웨어 처리 작업 등은 예측하기 어려움
		// 논리적으로 대책을 마련하기 어려운 경우에 예외 처리를 사용 

		// do something with i
		throw ("error");
		// 에러가 발생한다면 할당 해제하지 않고 바로 catch로 넘어감
		// 다시 i의 주소에 접근할 방법이 없음 => 블록
		delete[] i;

	}
	catch(...)
	{
		std::cout << "Catch" << std::endl;
	}
	
	return (0);
}