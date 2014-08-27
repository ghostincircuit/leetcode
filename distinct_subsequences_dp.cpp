#include <cassert>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
        int helper(const char *sb, const char *se,
                   const char *tb, const char *te) {
                int col = se - sb;
                int row = te - tb;
                if (col == 0)
                        return 0;
                int *dp0 = new int[col];
                int *dp1 = new int[col];
                dp0[0] = sb[0] == tb[0] ? 1 : 0;
                for (int i = 1; i < col; i++) {
                        if (tb[0] == sb[i])
                                dp0[i] = dp0[i-1] + 1;
                        else
                                dp0[i] = dp0[i-1];
                }
                for (int i = 0; i < col; i++)
                        dp1[i] = 0;

                for (int i = 1; i < row; i++) {
                        std::swap(dp0, dp1);
                        dp0[i-1] = 0;
                        for (int j = i; j < col; j++) {
                                if (tb[i] == sb[j])
                                        dp0[j] = dp0[j-1] + dp1[j-1];
                                else
                                        dp0[j] = dp0[j-1];
                        }
                }
                auto ret = dp0[col-1];
                delete[] dp0;
                delete[] dp1;
                return ret;
        }
        int numDistinct(string S, string T) {
                const char *sb = S.c_str();
                const char *tb = T.c_str();
                const char *se = sb + S.size();
                const char *te = tb + T.size();
                if (S.size() < T.size())
                        return 0;
                auto r = helper(sb,
                                se,
                                tb,
                                te);
                return r;
        }
};

int main()
{
        Solution so;
        string t = "123";
        string s = "12345";
        int r;
        r = so.numDistinct(s, t);
        assert(r == 1);

        t = "123";
        s = "1123";
        r = so.numDistinct(s, t);
        assert(r == 2);

        t = "123333";
        s = "1123";
        r = so.numDistinct(s, t);
        assert(r == 0);

        t = "123";
        s = "112233";
        r = so.numDistinct(s, t);
        assert(r == 8);

        return 0;
}
