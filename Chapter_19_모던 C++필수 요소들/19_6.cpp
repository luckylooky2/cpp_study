// 19.6 멀티쓰레딩 예제(백터 내적 계산)

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>		// std::inner_product(내적)
#include <execution>	// parallel execution

std::mutex	mutex;

// dot_product를 부분부분 잘라서 하는 함수
// n_data를 n_threads만큼 할당하는 과정 => 인덱스를 넘겨줌
void	dotProductNaive(const std::vector<int>& v0, const std::vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	// product한 값을 sum에 누적
	for (unsigned i = i_start; i < i_end; ++i)
		sum += v0[i] * v1[i];
}

// 어디에 lock을 걸 것인가가 중요 => lock 영역이 적을수록 퍼포먼스 향상 
void	dotProductLock(const std::vector<int>& v0, const std::vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	for (unsigned i = i_start; i < i_end; ++i)
	{
		// lock이 너무 많이 실행되면 오히려 느려짐
		// 하지만, scoped_lock을 밖으로 빼는 것은
		// 수행 시간은 빨라지지만 병렬 처리하는 의미가 없음(sequential)
		std::scoped_lock	lock(mutex);	// C++ 17
		sum += v0[i] * v1[i];
	}
}

void	dotProductAtomic(const std::vector<int>& v0, const std::vector<int>& v1,
	const unsigned i_start, const unsigned i_end, std::atomic<unsigned long long>& sum)
{
	for (unsigned i = i_start; i < i_end; ++i)
	{
		// lock이 너무 많이 실행되면 오히려 느려짐
		// 하지만, scoped_lock을 밖으로 빼는 것은
		// 수행 시간은 빨라지지만 병렬 처리하는 의미가 없음(sequential)
		std::scoped_lock	lock(mutex);	// C++ 17
		sum += v0[i] * v1[i];
	}
}

auto	dotProductFuture(const std::vector<int>& v0, const std::vector<int>& v1,
	const unsigned i_start, const unsigned i_end)
{
	int	sum = 0;	// local sum
	for (unsigned i = i_start; i < i_end; ++i)
	{
		// lock이 너무 많이 실행되면 오히려 느려짐
		// 하지만, scoped_lock을 밖으로 빼는 것은
		// 수행 시간은 빨라지지만 병렬 처리하는 의미가 없음(sequential)
		std::scoped_lock	lock(mutex);	// C++ 17
		sum += v0[i] * v1[i];
	}
	return (sum);
}

int	main()
{
	/*
	v0 = {1, 2, 3}
	v1 = {4, 5, 6}
	*/
	// dot_product : 2차원, 3차원 배열들 끼리의 inner_product
	// inner_product : v0, v1이 차원(원소)이 엄청 많을 떄
	// v0_dot_v1 = 1*4 + 2*5 + 3*6;

	const long long	n_data = 100'100'000;	// C++ 17
	const unsigned	n_threads = 4;			// 쓰레드의 수에 따라 효율이 달라짐

	std::vector<int>	v0, v1;

	v0.reserve(n_data);
	v1.reserve(n_data);

	std::random_device	seed;
	std::mt19937		engine(seed());

	std::uniform_int_distribution<>	uniformDist(1, 10);

	// 랜덤 값 push
	for (long long i = 0; i < n_data; ++i)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}

	// std::inner_product
	std::cout << "std::inner_product\n";
	{
		const auto							sta = std::chrono::steady_clock::now();
		// 3번째 파라미터는 begin()만 있으면 됨 => v0, v1이 똑같다는 가정
		// 0ull : 리턴 값을 ULL 범위로 확장
		const auto							sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);
		const std::chrono::duration<double>	dur = std::chrono::steady_clock::now() - sta;

		// 계산하는데 걸린 시간
		std::cout << dur.count() << std::endl;
		// sum of inner_product
		std::cout << sum << std::endl;
		std::cout << std::endl;
	}
	// std::inner_product
	// 1.14465
	// 3028264733

	// Naive
	std::cout << "Naive" << std::endl;
	{
		const auto					sta = std::chrono::steady_clock::now();
		unsigned long long			sum = 0;
		std::vector<std::thread>	threads;
		
		threads.resize(n_threads);

		// assumes remainder = 0;
		// 쓰레드 당 작업 개수
		const unsigned	n_per_thread = n_data / n_threads;
		// 쓰레드 생성
		for (unsigned t = 0; t < n_threads; ++t)
		{
			// C처럼 routine 함수 뒤에 routine 함수의 인자를 전달함
			// std::ref => reference로 만듦 : 값을 바꾸기 위해
			threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1), \
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
		}

		// wait
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const std::chrono::duration<double>	dur = std::chrono::steady_clock::now() - sta;
		
		// 시간 측정
		std::cout << dur.count() << std::endl;
		std::cout << sum << std::endl;
		std::cout << std::endl;
	}
	// Naive
	// 0.933153
	// 716977462 => 결과 값이 다름(race condition)

	// Naive Lock
	std::cout << "Naive Lock" << std::endl;
	{
		const auto					sta = std::chrono::steady_clock::now();
		unsigned long long			sum = 0;
		std::vector<std::thread>	threads;
		
		threads.resize(n_threads);

		const unsigned	n_per_thread = n_data / n_threads;

		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1), \
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
		}

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const std::chrono::duration<double>	dur = std::chrono::steady_clock::now() - sta;
		
		std::cout << dur.count() << std::endl;
		std::cout << sum << std::endl;
		std::cout << std::endl;
	}
	// Naive Lock
	// 5.75706 => 훨씬 느림(멀티쓰레딩을 한 보람이 없음)
	// 3027975203

	// Naive Atomic
	std::cout << "Naive Atomic" << std::endl;
	{
		const auto						sta = std::chrono::steady_clock::now();
		std::atomic<unsigned long long>	sum = 0;
		std::vector<std::thread>		threads;
		
		threads.resize(n_threads);

		const unsigned	n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1), \
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
		}

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const std::chrono::duration<double>	dur = std::chrono::steady_clock::now() - sta;
		
		std::cout << dur.count() << std::endl;
		std::cout << sum << std::endl;
		std::cout << std::endl;
	}
	// Naive Atomic
	// 7.92327 => 역시 Lock과 큰 차이없이 느림
	// 3028063146

	// Future	
	std::cout << "Future" << std::endl;
	{
		const auto						sta = std::chrono::steady_clock::now();
		unsigned long long				sum = 0;
		std::vector<std::future<int>>	futures;
		
		futures.resize(n_threads);

		const unsigned	n_per_thread = n_data / n_threads;

		for (unsigned t = 0; t < n_threads; ++t)
		{
			// 전역 변수를 하는 sum이 들어갈 필요가 없음
			// local sum을 계산하여 return
			futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1), \
				t * n_per_thread, (t + 1) * n_per_thread);
		}

		// 위에서는 global variable sum에 다른 쓰레드들이 접근하여 더하는 방식이었다면
		// 비동기로 따로 local sum을 계산하고 값을 받아 sum에 더함
		for (unsigned t = 0; t < n_threads; ++t)
			sum += futures[t].get();

		const std::chrono::duration<double>	dur = std::chrono::steady_clock::now() - sta;
		

		std::cout << dur.count() << std::endl;
		std::cout << sum << std::endl;	
		std::cout << std::endl;
	}
	// Future	
	// 5.71382
	// 3028352361

	// dot_product의 병렬 프로그래밍 버전
	std::cout << "std::transform_reduce\n";
	{
		const auto	sta = std::chrono::steady_clock::now();
		// const auto	sum = std::transform_reduce(std::execution::seq, v0.begin(), v0.end(), v1.begin(), 0ull);
		// par : parallel
		const auto	sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);
		const std::chrono::duration<double>	dur = std::chrono::steady_clock::now() - sta;

		std::cout << dur.count() << std::endl;
		std::cout << sum << std::endl;
		std::cout << std::endl;
	}

	// async 예제는 divide and conquer
	// TODO : divide and conquer 방식으로 thread를 사용하여
	// TODO : divide and conquer 방식으로 atomic & thread를 사용하여
	// TODO : divide and conquer 방식으로 promise & thread를 사용하여

	return (0);
}