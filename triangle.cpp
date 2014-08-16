#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
        int minimumTotal(vector<vector<int> > &triangle) {
                auto n = triangle.size();
                if (n == 0)
                        return 0;
                if (n == 1)
                        return triangle[0][0];
                vector<int> *dp0, *dp1;
                dp0 = new vector<int>(n);
                dp1 = new vector<int>(n);
                (*dp0)[0] = triangle[0][0];
                for (auto i = 1u; i < n; i++) {
                        for (auto j = 0u; j < i+1; j++) {
                                auto left = j-1;
                                auto right = j;
                                auto min = 0;
                                if (left < 0)
                                        min = (*dp0)[right];
                                else if (right == i)
                                        min = (*dp0)[left];
                                else
                                        min = std::min((*dp0)[left], (*dp0)[right]);
                                (*dp1)[j] = min + triangle[i][j];
                        }
                        swap(dp0, dp1);
                }
                auto min = (*dp0)[0];
                for (auto r: (*dp0)) {
                        if (r < min)
                                min = r;
                }
                delete dp0;
                delete dp1;
                return min;
        }
};

int main()
{
        vector<vector<int> > vv;
        vector<int> v;
        v = {2};
        vv.push_back(v);

        v = {3,4};
        vv.push_back(v);

        v = {6,5,7};
        vv.push_back(v);

        v = {4,1,8,3};
        vv.push_back(v);

        Solution s;
        auto r = s.minimumTotal(vv);
        assert(r == 11);
        return 0;
}
