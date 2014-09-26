#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class Solution {
public:
        typedef string::iterator si;
    
        int code(char x) {
                switch(x) {
                case 'I':
                case 'i':
                        return 1;
                case 'C':
                case 'c':
                        return 100;
                case 'V':
                case 'v':
                        return 5;
                case 'L':
                case 'l':
                        return 50;
                case 'X':
                case 'x':
                        return 10;
                case 'D':
                case 'd':
                        return 500;
                case 'M':
                case 'm':
                        return 1000;
                }
                return 0;
        }
    
        int seg(si& b, si& e) {
                si t = b + 1;
                si o = b;
                int ret;
                if (t == e) {
                        b = t;
                        return code(*o);
                }
                int after = code(*t);
                int b4 = code(*b);
                if (b4 >= after) {
                        ret = b4;
                        b = t;
                } else {
                        ret = after - b4;
                        b = ++t;
                }
                return ret;
        }

    
        int romanToInt(string s) {
                if (s == string())
                        return 0;
                si b = s.begin();
                si e = s.end();
                int sum = 0;
                do {
                        int mm = seg(b,e);
                        sum += mm;
                } while(b != e);
                return sum;
        }
};

int main()
{
        Solution s;
        auto r0 = s.romanToInt("DCXXI");
        assert(r0 == 621);
        return 0;
}
