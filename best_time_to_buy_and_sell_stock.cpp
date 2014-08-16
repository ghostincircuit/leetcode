#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
        int maxProfit(vector<int> &prices) {
                if (prices.size() <= 1)
                        return 0;
                int min = prices[0];
                int max = 0;
                for (auto i = prices.begin()+1; i != prices.end(); i++) {
                        if (*i - min > max)
                                max = *i - min;
                        if (*i < min)
                                min = *i;
                }
                return max;
        }
};

int main()
{
        vector<int> p0 = {0,1,2,3,4,5};
        Solution s;
        assert(s.maxProfit(p0) == 5);

        vector<int> p1 = {4,3,3,2,1};
        assert(s.maxProfit(p1) == 0);

        vector<int> p2 = {4,3,3,2,1,4};
        assert(s.maxProfit(p2) == 3);


        return 0;
}
