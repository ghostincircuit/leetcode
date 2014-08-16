#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:
        int sqrt(int x) {
                long long upper = (long long)x+1;
                long long lower = 0;
                while (1) {
                        long long mid = (upper + lower)/2;
                        long long  mm = mid*mid;
                        if (mm <= x) {
                                lower = mid;
                        } else {
                                upper = mid;
                        }
                        if ((upper - lower) == 1) {
                                break;
                        }
                }
                return (int)lower;
        }
};

int main()
{
        Solution s;

        int l, r;
        int j = 2147483647;
        l = s.sqrt(j);
        r = int(sqrt(j));
        assert(l == r);

        /*
        for (int i = 0; i < int((1u<<31)-1); i++) {
                l = s.sqrt(i);
                r = int(sqrt(i));
                assert(l == r);
                if ((i & 0x07ffffff) == 0)
                        cout << "1/16" << endl;
        }
        */
        return 0;
}
