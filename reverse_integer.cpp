#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
        int reverse(int x) {
                int sign = x > 0 ? 1 : -1;
                long long int mod = x > 0 ? (long long int)x : -(long long int)x;
                long long int ret = 0;
                while (mod != 0) {
                        int bit = mod%10;
                        ret *= 10;
                        ret += bit;
                        mod -= bit;
                        mod /= 10;
                }
                int sret = sign > 0 ? ret : -ret;
                return sret;
        }
};

int main()
{
        Solution s;
        int r;
        r = s.reverse(123);
        assert(r == 321);

        r = s.reverse(-123);
        assert(r == -321);

        r = s.reverse(0);
        assert(r == 0);

        r = s.reverse(1111111111);
        assert(  r == 1111111111);

        return 0;
}
