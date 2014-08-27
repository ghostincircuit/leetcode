#include <cassert>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
        int helper(const char *sb, const char *se,
                   const char *tb, const char *te) {
            
            if (sb == se && tb != te)
                    return 0;
            if (tb == te)
                    return 1;
            
            int sum = 0;
            for (auto i = sb; i != (se-(te-tb)+1); i++) {
                    if (*i == *tb) {
                            auto r = helper(i+1, se, tb+1, te);
                            sum += r;
            }
            }
            return sum;
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
