#include "factorizer.h"

#include <cmath>
#include <vector>
#include <list>

factors_t factorizer::getFactors(uint64_t n) {
	std::list<uint64_t> foundPrimeNumbers;
	const uint64_t nSqrt = std::sqrt(n);
	std::vector<bool> isComposite((nSqrt + 1), false);
	isComposite[0] = true;
	isComposite[1] = true;
	for (uint64_t i = 2; i <= nSqrt; ++i) {
		if (isComposite[i] == false) {
			foundPrimeNumbers.push_back(i);
			for (uint64_t j = (i * 2); j <= nSqrt; j += i) {
				isComposite[j] = true;
			}
		}
	}
	factors_t factors;
	for (auto& prime: foundPrimeNumbers) {
		uint64_t divCount = 0;
		while ((n % prime) == 0) {
			++divCount;
			n /= prime;
		}
		factors[prime] = divCount;
	}
	if (n != 1) {
		factors[n] = 1;
	}
	return factors;
}