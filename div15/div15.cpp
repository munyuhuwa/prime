#include "div15.h"

// std::pair<unsigned int, unsigned int> div15_proposed(unsigned int x) {
//     unsigned int q = 0;
//     unsigned int r = x;
//     while (r >= 15) {
//         if (r == 15) {
//             q = q + 1;
//             r = 0;
//             break;
//         }
//         unsigned int q16 = (r >> 4);// 16で割ったときの商
//         unsigned int r16 = (r & 0b1111);// 16で割ったときの剰余
//         q = q + q16;
//         r = q16 + r16;
//     }
//     return std::make_pair(q, r);
// }

std::pair<unsigned int, unsigned int> div15_proposed(unsigned int r)
{
	unsigned int q = 0;
	unsigned int q16;
	while (r > 15)
	{

		q16 = (r >> 4);	 // 16で割ったときの商
		q += q16;
		r = q16 + (r & 0b1111);
	}
	if (r == 15)
	{
		++q;
		r = 0;
	}
	return std::make_pair(q, r);
}

std::pair<unsigned int, unsigned int> div15_conventional(unsigned int x) {
    unsigned int q = x / 15;
    unsigned int r = x - q * 15;
    return std::make_pair(q, r);
}