#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
            n++;
            vector<int> ret;
            int *dp[2];
            dp[0] = new int[n];
            dp[1] = new int[n];
            if (n == 0)
                    return ret;
            dp[0][0] = 1;
            auto idx = 1;
            while (idx != n) {
                    idx++;
                    for (auto j = 0; j < idx; j++) {
                            auto left = (j-1 >= 0) ? dp[0][j-1] : 0;
                            auto right = (j != idx-1) ? dp[0][j] : 0;
                            dp[1][j] = left + right;
                    }
                    swap(dp[0], dp[1]);
            }
            ret = vector<int>(dp[0], dp[0]+idx);
            delete[] dp[0];
            delete[] dp[1];
            return ret;
    }
};

int main()
{
        Solution s;
        auto r = s.getRow(4);
        for (auto& i:r) {
                cout << i << " ";
        }
        cout << endl;
        return 0;
}
