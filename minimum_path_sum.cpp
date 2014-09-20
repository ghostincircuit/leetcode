#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
        int helper(vector<vector<int> > &grid, int i, int j) {
                if (i == 0 && j == -1)
                        return 0;
                if (i == -1 && j == 0)
                        return 0;
                if (j < 0 || i < 0)
                        return 0x7fffffff;
                return grid[i][j];
        }

        int minPathSum(vector<vector<int> > &grid) {
                int rows = grid.size();
                int cols = rows ? grid[0].size() : 0;
                if ((rows | cols) == 0)
                        return 0;
                vector<vector<int> > dp(grid.size(), vector<int>(grid[0].size()));
                int i = 0;
                int j = 0;
                for (i = 0; i < rows; i++)
                        for (j = 0; j < cols; j++) {
                                auto r1 = helper(dp, i, j-1);
                                auto r2 = helper(dp, i-1, j);
                                r1 = r1 < r2 ? r1 : r2;
                                dp[i][j] = r1 + grid[i][j];
                        }

                return dp[rows-1][cols-1];
        }
};

int main()
{
        Solution s;
        vector<vector<int> > v = {
                {1,1,1},
                {2,2,2},
                {3,3,3}
        };

        v = {
                {1,2},
                {1,1}
        };
        auto r = s.minPathSum(v);
        cout << r << endl;
}
