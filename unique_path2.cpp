#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
                int m = obstacleGrid.size();
                int n = obstacleGrid[0].size();
                int *dp = new int[n];
                int i;
                for (i = 0; i < n; i++) {
                        if (obstacleGrid[0][i] == 1)
                                break;
                        else
                                dp[i] = 1;
                }
                while (i != n) {
                        dp[i++] = 0;
                }

                for (i = 1; i < m; i++) {
                        if (dp[0] == 1) {
                                if (obstacleGrid[i][0] == 1) {
                                        dp[0] = 0;
                                }
                        }
                        for (int j = 1; j < n; j++) {
                                if (obstacleGrid[i][j] == 1) {
                                        dp[j] = 0;
                                } else {
                                        dp[j] = dp[j-1] + dp[j];
                                }
                        }
                }
                return dp[n-1];
        }
};

int main()
{
        vector<vector<int> > grid(3, vector<int>(3, 0));
        grid[0][1] = 1;
        grid[1][0] = 1;
        Solution s;
        int r = s.uniquePathsWithObstacles(grid);
        cout << r << endl;
        return 0;
}
