#include <cassert>
#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
            const int N = 32;
            int sign = 1;
            long long int dend = dividend;
            long long int mod = divisor;

            if (mod == -2147483648) {
                    if (dend == mod)
                            return 1;
                    else
                            return 0;
            }

            if (mod < 0) {
                    mod = -mod;
                    dend = -dend;
            }
            if (dend < 0)
                    sign = -1;

            mod <<= N;
            long long int ret = 0;

            for (int i = 0; i < N; i++) {
                    mod >>= 1;
                    ret <<= 1;

                    if (dend >= 0) {
                            dend -= mod;
                            ret += 1;
                    } else {
                            dend += mod;
                            ret -= 1;
                    }
            }

            assert(-mod <= dend);
            assert(dend <= mod);

            if (sign == 1) {
                    if (dend == mod) {
                            ret += 1;
                            dend = 0;
                    }
                    if (dend < 0)
                            ret -= 1;
            } else {
                    if (dend == -mod) {
                            ret -= 1;
                            dend = 0;
                    }
                    if (dend > 0)
                            ret += 1;
            }

            return ret;
    }
};

#define test(a, b) assert((a) / (b) == s.divide(a, b))

int main()
{
        Solution s;
        test(13,3);
        int i = -2147483648 / -3;
        test(-2147483648, -3);
        test(-2147483648, 1);
        test(0, 2);
        test(1, 2);
        test(2, 2);
        test(3, 2);
        test(4, 2);
        test(5, 2);
        test(6, 2);
        test(0, 1);
        test(-2147483648, -2);
        test(-1010369383, -2147483648);

        return 0;
}
