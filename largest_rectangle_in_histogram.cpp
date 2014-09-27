#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
        vector<int> wall;
        vector<int> dist;
        int largestRectangleArea(vector<int> &height) {
                wall = {0};
                dist = {-1};
                int max = 0;
                for (auto i = 0; i <= height.size(); i++) {
                        auto cur = 0;
                        if (i != height.size())
                                cur = height[i];
                        if (cur > wall.back()) {
                                wall.push_back(cur);
                                dist.push_back(i);
                        } else if (cur < wall.back()) {
                                auto pos = upper_bound(wall.begin(), wall.end(), cur) - wall.begin();
                                for (auto j = pos; j < wall.size(); j++) {
                                        auto s = (i - dist[j]) * wall[j];
                                        max = s > max ? s : max;
                                }
                                wall.erase(wall.begin()+pos+1, wall.end());
                                dist.erase(dist.begin()+pos+1, dist.end());
                                wall.back() = cur;
                        }
                }
                return max;
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
