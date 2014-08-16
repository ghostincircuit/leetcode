#include <cassert>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
        bool isMatch(const char *s, const char *p) {
                int m = strlen(p);
                int n = strlen(s);
                if (m == 0)
                        return false;
                else if (n == 0) {
                        if (p[0] == '*')
                                return true;
                        else
                                return false;
                }
                vector<bool> dp0(n+1, false);
                vector<bool> dp1(n+1, false);


                dp0[0] = true;
                int i;
                for (i = 1; i <= m; i++) {
                        int j;
                        if (p[i-1] == '*' && dp0[0])
                                dp0[0] = true;
                        switch (p[i-1]) {
                        case '?':
                                for (j = 1; j <= n; j++) {
                                        if (dp0[j-1])
                                                dp1[j] = true;
                                }
                                break;
                        case '*':
                                for (j = 0; j <= n; j++) {
                                        if (dp0[j])
                                                break;
                                }

                                while (j <= n) {
                                        dp1[j] = true;
                                        j++;
                                }
                                break;
                        default:
                                for (int j = 1; j <= n; j++) {
                                        dp1[j] = dp0[j-1] && (s[j-1] == p[i-1]);
                                }
                                break;
                        }
                        dp0 = dp1;
                }
                return dp0[n];
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

        s0 = "1";
        p0 = "**1";
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

/*
        s0 = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
        p0 = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
        assert(so.isMatch(s0, p0));
*/
        return 0;
}
