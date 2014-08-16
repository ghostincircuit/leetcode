#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
        bool isMatch(const char *s, const char *p) {
                switch (*p) {
                case 0:
                        return *s == 0;
                case '*':
                        for (; *p == '*'; p++);

                        if (*p == 0)
                                return true;

                        while (*s) {
                                const char *ss = s;
                                const char *pp = p;
                                while (*ss && *pp && (*ss == *pp || *pp == '?') && *pp != '*') {
                                        ss++;
                                        pp++;
                                }
                                if (0 == *pp && *ss == 0)
                                        return true;
                                else if (*pp == '*')
                                        return isMatch(ss, pp);
                                else if (*ss == 0)
                                        return false;
                                s++;
                        }
                        return false;
                default:
                        while (*p && *p != '*') {
                                if (*p == *s || (*p == '?' && *s)) {
                                        p++;
                                        s++;
                                }
                                else
                                        break;
                        }
                        if (*p == 0)
                                return *s == 0;
                        else if (*p == '*')
                                return isMatch(s, p);
                        else
                                return false;
                }
        }
};

int main()
{
        Solution so;

        const char *s0 = "1234";
        const char *p0 = "1234";
        assert(true == so.isMatch(s0, p0));

        s0 = "1234";
        p0 = "1233";
        assert(false == so.isMatch(s0, p0));

        s0 = "1234";
        p0 = "12?4";
        assert(true == so.isMatch(s0, p0));

        s0 = "1234";
        p0 = "1*";
        assert(true == so.isMatch(s0, p0));

        s0 = "1234";
        p0 = "*";
        assert(true == so.isMatch(s0, p0));

        s0 = "";
        p0 = "*";
        assert(true == so.isMatch(s0, p0));

        s0 = "abacadefg";
        p0 = "a*ac*g";
        assert(true == so.isMatch(s0, p0));

        s0 = "abacadefg";
        p0 = "a*ad*g";
        assert(true == so.isMatch(s0, p0));

        s0 = "abacadefg";
        p0 = "a*adf*g";
        assert(false == so.isMatch(s0, p0));

        s0 = "adbdcdbdcg";
        p0 = "a*b*cd*g";
        assert(true == so.isMatch(s0, p0));

        s0 = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
        //s0 = "aba";
        p0 = "a*******b";
        assert(false == so.isMatch(s0, p0));


        s0 = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
        p0 = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
        assert(so.isMatch(s0, p0) == true);

        return 0;
}
