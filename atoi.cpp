#include <cstdio>
#include <cassert>

class Solution {
public:
    int atoi(const char *str) {
            long long int sum = 0;
            int sign = 1;
            
            const int SPACE = 0;
            const int SIGN = 1;
            const int DIGITS = 2;
            const int OVER = 3;
            int digit_cnt = 0;
            int state = SPACE;
            int valid = 0;

            while (1) {
                    if (state == SPACE) {
                            if (*str == ' ' ||
                                *str == '\t' ||
                                *str == '\n') {
                                    str++;
                            } else {
                                    state = SIGN;
                            }
                    }

                    else if (state == SIGN) {
                            if (*str == '+') {
                                    sign = 1;
                                    str++;
                            } else if (*str == '-') {
                                    sign = -1;
                                    str++;
                            }
                            state = DIGITS;
                    }

                    else if (state == DIGITS) {
                            const int MAX_DIGITS = 10;
                            if (*str >= '0' &&
                                *str <= '9') {
                                    valid = 1;
                                    sum = sum * 10 + (*str - '0');
                                    str++;
                                    digit_cnt++;
                                    if (digit_cnt >= MAX_DIGITS+1)
                                            state = OVER;
                            }
                            else {
                                    if (valid == 0)
                                            return 0;
                                    state = OVER;
                            }
                    }
                        
                    else {
                            const int INT_MAXX = 2147483647;
                            const int INT_MINX = -2147483648;
                            if (sign == -1)
                                    sum = -sum;
                            if (sum > INT_MAXX)
                                    return INT_MAXX;
                            if (sum < INT_MINX)
                                    return INT_MINX;
                            
                            return sum;
                    }
            }
    }
};

int main()
{
        Solution s;
        assert(s.atoi("+=2") == 0);
        assert(s.atoi("123") == 123);
        assert(s.atoi("-123") == -123);
        assert(s.atoi("    1234") == 1234);
        assert(s.atoi("2147483647") == 2147483647);
        assert(s.atoi("2147483648") == 2147483647);
        assert(s.atoi("-2147483648") == -2147483648);
        assert(s.atoi("-2147483649") == -2147483648);
        assert(s.atoi("-12147483649") == -2147483648);
        assert(s.atoi("-2147483649123123123123") == -2147483648);
        return 0;
}
