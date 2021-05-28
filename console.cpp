#include <iostream>
#include <chrono>

#include "factorizer.h"

int main() {
	uint64_t n;
	while (true) {
		std::cout << "Input a natural number." << std::endl;
		std::cin >> n;
		factorizer f;
		auto start = std::chrono::system_clock::now();
		factors_t factors = f.getFactors(n);
		auto end = std::chrono::system_clock::now();
		auto duration = end - start;
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
		std::cout << "time:\t" << msec << " [msec]" << std::endl;
		std::cout << n << " = ";
		for (auto iter = factors.begin(); iter != factors.end(); ++iter) {
			if (iter->second > 0) {
				std::cout << "+ " << iter->first << "^" << iter->second << " ";
			}
		}
		std::cout << std::endl;		
	}
	return 0;
}