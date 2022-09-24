// 19.5 작업 기반 비동기 프로그래밍 async, future, promise

#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int	main()
{
	// multi-threading 방식
	{
		int	result;
		// 쓰레드를 생성하면서 ()안에 routine 함수를 실행
		// routine을 실행하면서 레퍼런스 타입인 result에 값을 할당
		std::thread	t([&] { result = 1 + 2; });

		t.join();
		std::cout << result << std::endl;	// 3
	}

	// task-based parallelism 방식
	// 위 예제보다 적은 코드
	{
		// 쓰레드가 작업하는데 return?
		// 쓰레드가 언제 끝날지 모르는 상황에서 바로 return 값을 받을 수 없음
		// 바로 return 값을 받는다는 보장이 없는 상황 => 일반적인 return과 다름
		// 메인 쓰레드가 수행하는 것과 "별도로" 람다 함수가 실행됨
		// thread보다는 async를 사용하는 것을 더 선호
		// std::future<int>	fut = ...
		// => 미래에 async가 끝나면 int 값을 받아오겠다
		// 위 예제의 result와 비슷한 개념, 하지만 result는 쓰레드 밖에 있기 때문에 어떤 작업을 할 지 모름
		// 반면, fut는 async와 정확히 결합이 되는 구조
		// 동시성 문제를 해결하지 않아도 됨?
		std::future<const char *>	fut = std::async([] {
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			return ("my"); });
		// thread : 쓰레드가 몇 개 있고, 어떤 일을 할지를 지정해 주는 것에 더 관심
		// async : 어떤 일을 할 것인가 위주에 더 관심
		
		std::cout << "hello\n";

		// get() : async 작업이 끝날 때(리턴 값이 발생할 때까지)까지 기다림
		std::cout << fut.get() << std::endl;
		std::cout << "world\n";
		// hello
		// my
		// world
	}

	// future and promise 방식
	{
		// multi-threading을 사용하는 방법도 괜찮으나 최근 추세는 future and promise 방식
		// future을 사용할 때, thread와 함께 사용하기 위해서는 이 방법을 사용
		std::promise<int>	prom;
		auto				fut = prom.get_future();

		// thread는 async처럼 future을 주지 않고 thread를 반환
		// 그렇기 떄문에 future를 받을 존재가 필요하여 promise를 거쳐가는 것임
		// promise에 어떤 값을 넣어주면 future가 생김
		// promise를 매개 변수로 넣어주어야 함
		auto	t = std::thread([](std::promise<int>&& prom)
		{
			// multi-threading에서 int result에 값을 넣어주고
			// task-based parallelism에서 return을 해준 것처럼
			// future and promise에서는 prom.set_value()
			prom.set_value(1 + 2);
		}, std::move(prom));

		// thread 대신에 async도 가능 => join()이 필요하지 않음
		// auto	t = std::async([](std::promise<int>&& prom)
		// 왜 thread를 사용하는가?
		// async의 리턴 값은 future이기 때문에 굳이 promise를 사용할 필요가 없음
		// 어떤 방식을 사용할지는 상황에 따라 다름
		// => 쓰레드를 제어해야하는 상황이 반드시 존재
		// => Task를 위주로 스케쥴링을 해야하는 상황이 있기도 함

		// promise가 set_value()를 통해서 값을 받을 때까지 future가 계속 wait
		std::cout << fut.get() << std::endl;
		// 쓰레드를 사용하기 때문에 join()을 호출해야 함
		t.join();
	}

	// thread와 async의 중요한 차이점
	{
		// async : 소멸자가 끝나는 것을 알아서 해줌
		{
			auto	f1 = std::async([] {
				std::cout << "async1 start\n";
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "async1 end\n";
			});

			auto	f2 = std::async([] {
				std::cout << "async2 start\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "async2 end\n";
			});

			std::cout << "Main function\n";
			// Main function
			// async1 start
			// async2 start
			// async2 end
			// async1 end
		}
		
		// thread : join() 호출해야 함
		// thread w/o join
		{
			auto	f1 = std::thread([] {
				std::cout << "async1 start\n";
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "async1 end\n";
			});

			auto	f2 = std::thread([] {
				std::cout << "async2 start\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "async2 end\n";
			});

			std::cout << "Main function\n";
			// Main function
			// libc++abi.dylib: terminating
			// zsh: abort      ./a.out
			// => join()이 없어 main()이 먼저 끝나서 오류가 발생
		}

		// async와 future이 연결되지 않은 경우
		// => sequential인 것처럼 진행됨
		{
			std::async([] {
				std::cout << "async1 start\n";
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "async1 end\n";
			});

			std::async([] {
				std::cout << "async2 start\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "async2 end\n";
			});

			std::cout << "Main function\n";
			// async1 start
			// async1 end
			// async2 start
			// async2 end
			// Main function
		}
	}

	return (0);
}