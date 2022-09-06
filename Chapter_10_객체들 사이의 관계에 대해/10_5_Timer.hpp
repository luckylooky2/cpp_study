// 10_5_Timer.hpp

#ifndef TEN_FIVE_TIMER_HPP
#define TEN_FIVE_TIMER_HPP

#include <iostream>
#include <vector>
#include <algorithm>	// sorting 시간 측정
#include <random>
#include <chrono>

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t>	start_time = clock_t::now();

public:
	void	elapsed()
	{
		std::chrono::time_point<clock_t>	end_time = clock_t::now();

		std::cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << std::endl;
	}
};

#endif