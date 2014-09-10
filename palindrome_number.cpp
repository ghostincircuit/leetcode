#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
        bool isPalindrome(int x) {
                if (x == -0x7fffffff-1)
                        return false;
                if (x < 0)
                        x = -x;
                if (x == 0)
                        return true;
                int y = x;
                int bit = 1;
                int base = 1;
                while (y > 9) {
                        y /= 10;
                        bit++;
                        base *= 10;
                }
                int hb = base;
                int lb = 1;
                while (hb > lb) {
                        if ((x/lb)%10 != (x/hb)%10)
                                return false;
                        hb /= 10;
                        lb *= 10;
                }
                return true;
        }
};

int main()
{
        Solution s;
        assert(s.isPalindrome(44) == true);
        assert(s.isPalindrome(414) == true);
        assert(s.isPalindrome(14) == false);
        assert(s.isPalindrome(714) == false);
        assert(s.isPalindrome(0) == true);
        assert(s.isPalindrome(3) == true);
        assert(s.isPalindrome(-3) == true);
        assert(s.isPalindrome(-33) == true);
        assert(s.isPalindrome(-333) == true);
        assert(s.isPalindrome(-17) == false);
        return 0;
}
