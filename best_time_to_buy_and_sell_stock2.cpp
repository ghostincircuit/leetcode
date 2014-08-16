#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
            if (prices.size() <= 1)
                    return 0;
            int sum = 0;
            for (auto i = prices.begin()+1; i != prices.end(); i++) {
                    int r = (*i) - *(i-1);
                    if (r > 0)
                            sum += r;
            }
            return sum;
    }
};

int main()
{
        Solution s;
        vector<int> t0 = {0,1,2,3,3,4,5};
        assert(s.maxProfit(t0) == 5);
        
        vector<int> t1 = {5,4,3,2,2,1,0};
        assert(s.maxProfit(t1) == 0);

        vector<int> t2 = {5,4,3,2,0,1,2,1,0,5};
        assert(s.maxProfit(t2) == 7);

        return 0;
}
