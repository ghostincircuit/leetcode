#include <iostream>

using namespace std;

class Solution {
public:
        int uniquePaths(int m, int n) {
                int *dp = new int[n];
                for (int i = 0; i < n; i++)
                        dp[i] = 1;

                for (int i = 1; i < m; i++) {
                        for (int j = 1; j < n; j++) {
                                dp[j] += dp[j-1];
                        }
                }
                return dp[n-1];
        }
};

int main()
{
        Solution s;
        int r = s.uniquePaths(3,3);
        cout << r << endl;
}
