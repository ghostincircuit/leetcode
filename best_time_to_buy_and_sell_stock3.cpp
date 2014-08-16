#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
        int maxProfit(vector<int> &prices) {
                int n = prices.size();
                vector<int> prev(n, 0);
                vector<int> post(n, 0);

                int p = 0;
                int max = 0;
                for (int i = 0; i < n; i++) {
                        if (prices[i] - prices[p] > max)
                                max = prices[i] - prices[p];
                        if (prices[i] < prices[p])
                                p = i;
                        prev[i] = max;
                }

                p = n-1;
                max = 0;
                for (int i = n-1; i >= 0; i--) {
                        if (prices[p] - prices[i] > max)
                                max = prices[p] - prices[i];
                        if (prices[p] < prices[i])
                                p = i;
                        post[i] = max;                       
                }
                
                max = 0;
                for (int i = 0; i < n; i++)
                        if (prev[i] + post[i] > max)
                                max = prev[i] + post[i];
                return max;
        }
};

int main()
{
        Solution s;
        vector<int> v1 = {0,1,2,3,2,3,4};
        assert(s.maxProfit(v1) == 5);

        vector<int> v2 = {0,1,2};
        assert(s.maxProfit(v2) == 2);

        vector<int> v3 = {0,1};
        assert(s.maxProfit(v3) == 1);

        vector<int> v4 = {2};
        assert(s.maxProfit(v4) == 0);
        return 0;
}
