#include <map>

typedef std::map<uint64_t, uint64_t> factors_t;

class factorizer
{
	public:
	factors_t getFactors(uint64_t n);
};