#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:
        int sqrt(int x) {
                long long upper = x+1;
                long long lower = 0;
                long long last = x+1;;
                while (1) {
                        long long mid = (upper + lower)/2;
                        long long  mm = mid*mid;
                        if (mm <= x) {
                                lower = mid;
                        } else {
                                upper = mid;
                        }
                        if ((upper - lower) == last) {
                                //break;
                        } else {
                                last = upper - lower;
                                continue;
                        }
                }
                return (int)lower;
        }
};

int main()
{
        Solution s;

        int j = 0x1002001;
        assert(s.sqrt(j) == int(sqrtf(j)));

        for (int i = 0; i < int((1u<<31)-1); i++) {
                assert(s.sqrt(i) == int(sqrtf(float(i))));
        }
        return 0;
}
