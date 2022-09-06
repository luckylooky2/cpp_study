// 10_5_Worker.hpp

#ifndef TEN_FIVE_WORKER_HPP
#define TEN_FIVE_WORKER_HPP

// // Timer class를 사용해야 하기 때문에
// #include "10_5_Timer.hpp"

// 선언과 정의를 분리한 경우
// Worker class를 선언할 때 Timer class에 대해 몰라도 컴파일 가능
// cpp 파일로 옮기기
// Worker 안에 Timer를 선언하지 않음
class Worker
{
public:
	void	doSomething();
};

#endif