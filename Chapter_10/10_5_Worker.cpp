// 10_5_Worker.cpp

#include "10_5_Worker.hpp"
#include "10_5_Timer.hpp"

void	Worker::doSomething()
{
	// timer 변수는 doSomething() 안에서만 유효 => 제어
	Timer	timer;		// start timer

	// do some work here

	timer.elapsed();	// end timer and report elapsed time
}
