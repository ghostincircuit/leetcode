#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
        int largestRectangleArea(vector<int> &height) {
                int sz = height.size();
                if (sz == 0)
                        return 0;
                if (sz == 1)
                        return height[0];
                int s = height[0];
                vector<int> hi;
                vector<int> idx;
                for (auto i = 0; i <= height[0]; i++) {
                        hi.push_back(i);
                        idx.push_back(0);
                }
                int prev;
                int cur = height[0];
                int i;
                for (i = 1; i < sz; i++) {
                        prev = cur;
                        cur = height[i];
                        if (prev < cur) {
                                hi.push_back(cur);
                                idx.push_back(i);
                                s = s > cur ? s : cur;
                        }
                        if (prev >= cur) {
                                auto j = lower_bound(hi.begin(), hi.end(), cur);
                                int id = j - hi.begin();
                                auto k = idx.begin() + id;
                                int ns = (1 + i - *k) * cur;
                                s = ns > s ? ns : s;
                                if (*j == cur) {
                                        j++;
                                        k++;
                                }

                                hi.erase(j, hi.end());
                                idx.erase(k, idx.end());
                                hi.push_back(cur);
                                idx.push_back(i);
                        }
                }
                if (prev >= cur)
                        return s;
                for (i = 0; i < hi.size(); i++) {
                        int ns = (sz-idx[i]) * hi[i];
                        s = ns > s ? ns : s;
                }
                return s;
        }
};

int main()
{
        Solution s;
        vector<int> hi = {2,1,2};
        
        //hi = {0,0};
        auto r = s.largestRectangleArea(hi);
        cout << r << endl;
        return 0;
}
