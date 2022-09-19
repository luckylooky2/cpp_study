// 15.3 이동 생성자와 이동 대입

// move semantics가 어떻게 작동, 구현, 이득이 있는지?

#include <iostream>
#include "15_3_Resource.hpp"
#include "15_3_AutoPtr.hpp"
#include "15_3_Timer.hpp"


AutoPtr<Resource>	generateResource()
{
	// 동적 할당 후 반환
	AutoPtr<Resource>	res(new Resource(10000000));
	// 2. class Resource length constructor
	// 3. class AutoPtr default constructor

	// 반환할 때 인스턴스를 복사하는 과정
	return (res);
}

int main(void)
{
	std::streambuf	*orig_buf = std::cout.rdbuf();
	Timer			timer;

	std::cout.rdbuf(NULL);	// disconnect cout from buffer
	{
		AutoPtr<Resource>	main_res;
		// 1. class AutoPtr default constructor
		// 포인터이기 떄문에 아직 Resource 인스턴스는 존재하지 않음
		
		main_res = generateResource();
		// AutoPtr 복사 연산 과정에서 Resouce 인스턴스를 생성 후 복사 연산(deep copy)
		// 4. class AutoPtr copy assignment
		// 5. class Resource default constructor
		// 6. class Resource copy assignment
		// r-value(generateResource())로서 인스턴스 소멸
		// 7. class AutoPtr destructor
		// 8. class Resource destructor
	}
	// main_res 인스턴스 소멸
	// 9. class AutoPtr destructor
	// 10. class Resource destructor

	std::cout.rdbuf(orig_buf);
	// value semantics
	// before disconnect cout
	timer.elapsed();			// 0.0455422
	// after disconnect cout
	timer.elapsed();			// 0.0381415
	// log를 출력하는데 시간이 소요됐을 수도 있음 => 차이가 날 수 있으므로 가급적 꺼놓고 측정

	// move semantics
	timer.elapsed();			// 7.7042e-05
	// deep copy 수행의 차이, 복사 연산을 하지 않기 떄문
	
	return (0);
}
