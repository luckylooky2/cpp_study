// 19.3 std::thread와 멀티쓰레딩의 기초

// 현대 CPU는 멀티 코어를 가지고 있기 때문에 멀티쓰레드를 적절히 활용하여
// 더 효율적으로 프로그래밍하는 능력이 필요

// 프로세스
// 하나의 프로세스가 여러 개의 쓰레드를 관리할 수 있음
// 여러 개의 CPU 코어를 동시에 사용해 효율적으로 사용하는 것을 의미

// 쓰레드
// 메인 쓰레드 : 메인 함수를 실행하는 쓰레드를 보통 메인 쓰레드라 칭함
// 메인 쓰레드가 자식 쓰레드들을 시켜서 작업을 나누어서 실행
// cf> 자식 쓰레드가 또 자식 쓰레드를 만들수도 있음
// 자식 쓰레드가 언제 끝날지, 어떤 자식 쓰레드가 먼저 끝날지는 메인 쓰레드가 알 수 없음
// 메인 쓰레드는 자식 쓰레드를 기다림
// => 자식 쓰레드가 다 끝났다면 정보를 취합해 다음 작업을 실행

// 멀티프로세싱
// CPU 코어가 1개일 경우, 멀티쓰레드를 사용하는 것이 효과가 거의 없음
// 메인 보드 하나에 여러 개의 CPU를 꽂아 사용 => 멀티프로세싱
// 하지만 2개 이상 꽂으면 메모리 속도 때문에 한계가 있어 속도 향상이 거의 없었음
// 효율을 어떻게든 높이기 위해 사용된 방법 => 분산 처리 시스템
// 네트워크를 이용해 여러 PC들을 연결시키고, 여러 개의 PC의 CPU를 효율적으로 활용하였음
// 분산 처리 : 메모리를 공유할 수 없음 => 통신을 할 떄 오버헤드, 비효율적인 면이 있었음

// 멀티쓰레딩
// 여러 개의 CPU 코어를 사용하는 멀티쓰레딩은 멀티프로세싱보다 효율지 좋음 => 대세
// 장) 메모리를 공유할 수 없는 분산 처리의 단점을 극복함 => 프로그래머를 편하게 함
// 단) 양날의 검 => 동기화 문제로 프로그래머를 위험하게 하기도 함
// 자동으로 멀티쓰레딩을 알아서 해주는 것이 아니고 멀티쓰레딩 프로그램을 구현해야 함
// 멀티프로세싱이 더 느린 이유? 컨텍스트 스위칭 비용이 더 비싸기 때문
// 회의실의 책상을 다 빼는 꼴
// https://www.youtube.com/watch?v=DmZnOg5Ced8

// Windows => Task Manager, Mac => Activity Monitor
// core : 8, logical processors : 16
// 하이퍼 쓰레딩이라는 기술을 이용하여 물리적 코어의 2배가 있는 것처럼 물리적 코어를 사용할 수 있음
// Utilization : 8% => 현재 CPU가 사용되고 있는 부분(녹화 프로그램...)

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

int	main()
{
	// 아무 일도 안 하고 있는 것 같지만 자원을 사용 중
	// Utilization : 8% => 15%
	// logical processors를 고려한 점유율 => 1 / 16 * 100(%)
	// while (true)
	// {

	// }

	// CPU 코어의 개수
	const int	num_pro = std::thread::hardware_concurrency();

	std::cout << num_pro << std::endl;						// 6
	// tid
	std::cout << std::this_thread::get_id() << std::endl;	// 0x107a10dc0

	// 람다 함수를 이용한 쓰레드 생성
	// libc++abi.dylib: terminating
	// zsh: abort      ./a.out
	// 생성된 쓰레드는 생성한 쓰레드와 상관없이 실행됨(detached 상태)
	// 메인 쓰레드가 먼저 끝나서 발생한 오류 => join(다시 메인 쓰레드와 합쳐지기 때문에)
	// 모든 레드는 동시에 실행됨(concurrency) => 순서가 일정하지 않음
	std::thread	t1 = std::thread([]() { 
		std::cout << std::this_thread::get_id() << std::endl;	// 0x7000021d5000
		while (true){}});
	std::thread	t2 = std::thread([]() { 
		std::cout << std::this_thread::get_id() << std::endl;	// 0x7000022db000
		while (true){}});
	std::thread	t3 = std::thread([]() { 
		std::cout << std::this_thread::get_id() << std::endl;	// 0x700002258000
		while (true){}});
	std::thread	t4 = std::thread([]() { 
		std::cout << std::this_thread::get_id() << std::endl;	// 0x70000235e000
		while (true){}});

	std::vector<std::thread>	my_threads;

	my_threads.resize(num_pro);

	for (auto &e : my_threads)
		e = std::thread([]() { 
		std::cout << std::this_thread::get_id() << std::endl;	// 0x70000ed0b000
		while (true){}});

	// t1 ~ t4가 끝날 때까지 wait
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	for (auto &e : my_threads)
		e.join();

	return (0);
}

std::mutex	mutex;	// mutual exclusion

int	main()
{
	auto	work_func = [](const std::string& name)
	{
		for (int i = 0; i < 3; ++i)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			// 다른 쓰레드가 못 들어오게 막음 => 다른 쓰레드들은 대기 중
			mutex.lock();
			std::cout << name << " " << std::this_thread::get_id() << " is working " << i << std::endl;
			// unlock을 안 해주면 계속 wait하기 때문에 반드시 unlock
			mutex.unlock();
		}
	};

	// work_func("Jack Jack");
	// work_func("Dash");
	// 싱글쓰레딩
	// Jack Jack이 일하는 동안 Dash는 놀고 있음 => 비효율적
	// Jack Jack 0x11052adc0 is working 0
	// Jack Jack 0x11052adc0 is working 1
	// Jack Jack 0x11052adc0 is working 2
	// Dash 0x11052adc0 is working 0
	// Dash 0x11052adc0 is working 1
	// Dash 0x11052adc0 is working 2

	// 멀티쓰레딩
	std::thread	t1 = std::thread(work_func, "Jack Jack");
	std::thread	t2 = std::thread(work_func, "Dash");

	t1.join();
	t2.join();
	// 동시에 일하기는 하지만 출력이 뒤엉킴 => mutex를 이용하여 해결
	// w/o mutex
	// Jack JackDash  0x700003761000 is working 0x7000036de000 is working 00

	// Dash Jack Jack 0x7000036de000 is working 0x700003761000 is working 1
	// 1
	// Dash 0x700003761000 is working 2
	// Jack Jack 0x7000036de000 is working 2

	// with mutex
	// Dash 0x700001b1e000 is working 0
	// Jack Jack 0x700001a9b000 is working 0
	// Dash 0x700001b1e000 is working 1
	// Jack Jack 0x700001a9b000 is working 1
	// Dash 0x700001b1e000 is working 2
	// Jack Jack 0x700001a9b000 is working 2

	return (0);
}