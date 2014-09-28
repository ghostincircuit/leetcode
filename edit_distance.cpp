#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
        vector<vector<int> > dp;
        inline int getdp(int i, int j) {
                if (i < 0 && j < 0)
                        return 0;
                if (i < 0)
                        return j+1;
                if (j < 0)
                        return i+1;
                return dp[i][j];
        }
        int minDistance(string word1, string word2) {
                auto n1 = word1.size();
                auto n2 = word2.size();
                int fuck = n1-n2;
                if (n1 == 0 || n2 == 0)
                        return (fuck > 0) ? (fuck) : (-fuck);
                dp = vector<vector<int> >(n1, vector<int>(n2));
                for (auto i = 0u; i < n1; i++) {
                        for (auto j = 0u; j < n2; j++) {
                                int pi = i-1;
                                int pj = j-1;
                                int ll,lh,hl;
                                lh = getdp(pi, j);
                                hl = getdp(i, pj);
                                ll = getdp(pi, pj);
                                if (word1[i] != word2[j])
                                        ll++;
                                dp[i][j] = std::min(ll, std::min(lh+1, hl+1));
                        }
                }
                int lcs = dp[n1-1][n2-1];
                return lcs;
        }
};

int main()
{
        Solution s;
        auto r = s.minDistance("dbcc", "bbba");
        cout << r << endl;
        return 0;
}
