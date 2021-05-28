#include <iostream>
#include <chrono>

#include "div15.h"

#define N_LOOP 100000000
#define TEST_X 777777777
// #define TEST_X 1

int main () {

	for (unsigned int i = 0; i < N_LOOP; ++i)
	{
		if (div15_proposed(TEST_X) != div15_conventional(TEST_X)) {
			std::cout << "got an wrong answer: " << i << std::endl;
			return 0;
		};
	}

	auto start = std::chrono::system_clock::now();
    for (unsigned int i = 0; i < N_LOOP; ++i)
    {
        div15_conventional(TEST_X);
    }
    auto end = std::chrono::system_clock::now();
    auto duration = end - start;
    auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    std::cout << "conventional:\t" << msec << " [msec]" << std::endl;

    start = std::chrono::system_clock::now();
    for (unsigned int i = 0; i < N_LOOP; ++i) {
        div15_proposed(TEST_X);
    }
    end = std::chrono::system_clock::now();
    duration = end - start;
    msec = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    std::cout << "proposed:\t" << msec << " [msec]" << std::endl;

    return 0;
}