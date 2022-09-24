// 19.4 레이스 컨디션, std::atomic, std::scoped_lock

// 같은 메모리를 공유한다는 것
// 다른 병렬 처리보다 구현하기가 쉬움
// 반대급부로 동기화의 문제가 발생한다는 단점

#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

// 여러 개의 쓰레드가 동시에 접근 가능하게 해야 하기 때문에
// 전역 변수로 선언
// int	shared_memory(0);
// race condition 해결
// 방법 1.
// atomic : 쪼갤 수 없는 => 과정을 한 번에 처리하게 만듦
// 일반 증감 연산보다 성능 상 더 느려짐
std::atomic<int>	shared_memory(0);

int	main()
{
	auto	count_func = []() {
		for (int i = 0; i < 1000; ++i)
		{
			// 없을 경우에는 단번에 일을 끝내서 문제가 안 보일 수 있음
			// 우연히 생긴 오류인지, 코드에 의한 오류인지 알 수 없는 경우가 많음
			// 오류인지조차 모를 수 있음
			// 여기 예제에서는 CPU가 너무 빨라서 t1이 완료 후 t2가 실행됨
			// 즉 병렬 처리가 아닌 것처럼 작동
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			// atomic일 경우 => 따로 연산자 오버로딩이 되어 있음
			shared_memory++;
			// 방법 2. fetch_add(1)
			shared_memory.fetch_add(1);
			// 방법 3. mutex.lock()
			mutex.lock();
			mutex.unlock();
			// unlock을 혹시나 못할 때 lock guard => 사용 권장
			// 스코프를 벗어나면서 소멸자? => 자동으로 unlock()
			std::lock_guard	lock(mutex);
			// C++ 17 : 더 발전된 lock_guard
			std::scoped_lock	lock(mutex);
		}
	};

	std::thread	t1 = std::thread(count_func);
	std::thread	t2 = std::thread(count_func);

	t1.join();
	t2.join();	// 2000?

	// only t1
	std::cout << "After" << std::endl;
	std::cout << "shared_memory : " << shared_memory << std::endl;	// shared_memory : 1000

	// with t2
	// 병렬 처리의 문제점
	// 일을 덜하는 것은 아님 => 왜 2000이 안되나?
	// 1. read shared_memory
	// 2. shared_memory++
	// 3. write shared_memory
	// 하나의 쓰레드가 2번을 하는 사이에 다른 쓰레드가 1번을 함 => 동시에 변수에 접근하는 문제
	std::cout << "After" << std::endl;
	std::cout << "shared_memory : " << shared_memory << std::endl;	// shared_memory : 1999

	return (0);
}