#include <list>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
        inline bool match(char c, char p) {
                if (p == '.')
                        return c != 0;
                else
                        return c == p;
        }

        bool isMatch(const char *s, const char *p) {
                int rows = strlen(s);
                int cols = strlen(p);
                vector<vector<bool> > dp(rows+1, vector<bool>(cols+1));
                dp[0][0] = true;
                for (int i = 1; i <= rows; i++)
                        dp[i][0] = false;
                for (int i = 1; i <= cols; i++) {
                        if (p[i-1] == '*')
                                dp[0][i] = dp[0][i-2];
                        else
                                dp[0][i] = false;
                }

                for (int i = 1; i <= rows; i++) {
                        for (int j = 1; j <= cols; j++) {
                                dp[i][j] = false;
                                if (match(s[i-1], p[j-1]))
                                        dp[i][j] = dp[i-1][j-1];
                                if (p[j-1] == '*') {
                                        dp[i][j] = dp[i][j-2] | dp[i][j];
                                        if (dp[i][j])
                                                continue;
                                        char ch = p[j-2];
                                        int k = 0;
                                        while (i-k-1 >= 0) {
                                                if (match(s[i-k-1], ch)) {
                                                        bool state = dp[i-k-1][j];
                                                        if (state == true) {
                                                                dp[i][j] = true;
                                                                break;
                                                        }
                                                } else
                                                        break;
                                                k++;
                                        }
                                }
                        }
                }
                return dp[rows][cols];
        }
};

int main()
{
        Solution s;
        bool r;

        r = s.isMatch("aaa", "aa");
        assert(r == false);

        r = s.isMatch("", "");
        assert(r == true);

        r = s.isMatch("", ".*");
        assert(r == true);

        r = s.isMatch("", "a*b*a*a*a*b*");
        assert(r == true);

        r = s.isMatch("345345345", ".*");
        assert(r == true);

        r = s.isMatch("aaaaaaaabbb", "aaa*bbb");
        assert(r == true);

        r = s.isMatch("abc", "a*b*c*");
        assert(r == true);

        r = s.isMatch("abcd", "a*b*c*");
        assert(r == false);

        r = s.isMatch("bbbba", ".*a*a");
        assert(r == true);

        r = s.isMatch("bbbba", ".*.*a");
        assert(r == true);

        r = s.isMatch("bbbba", ".*b*b*a*.*a");
        assert(r == true);

        return 0;
}
