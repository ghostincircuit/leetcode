#include <cassert>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
        bool isScramble(string s1, string s2) {
                int n = s1.size();
                vector<bool> dp0(n, false);
                vector<vector<bool> > dp1(n, dp0);
                vector<vector<vector<bool> > > dp(n+1, dp1);
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++)
                                if (s1[i] == s2[j])
                                        dp[1][i][j] = true;

                for (int i = 2; i <= n; i++) {
                        for (int j = 0; j <= n-i; j++)
                                for (int k = 0; k <= n-i; k++)
                                        for (int l = 1; l < i; l++) {
                                                int r = i-l;
                                                if (dp[l][j][k] == true &&
                                                    dp[r][j+l][k+l] == true)
                                                        dp[i][j][k] = true;
                                                if (dp[l][j][k+r] == true &&
                                                    dp[r][j+l][k] == true)
                                                        dp[i][j][k] = true;
                                        }
                }
                return dp[n][0][0];
        }

};

int main()
{
        Solution s;
        bool r;
        r = s.isScramble("1234", "1234");
        assert(r == true);

        r = s.isScramble("1234", "4123");
        assert(r == true);

        r = s.isScramble("1234", "4231");
        assert(r == true);

        return 0;
}
