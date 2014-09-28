#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        int n = S.size();
        unsigned long long int lim = 1<<n;
        vector<vector<int> > ret(lim);
        for(auto i = lim-lim; i < lim; i++) {
            for (auto j = 0; j < n; j++) {
                if (i & (1<<j))
                        ret[i].push_back(S[j]);
            }
        }
        return ret;
    }
};

int main()
{
        Solution s;
        vector<int> v = {1,2};
        auto r = s.subsets(v);
        
        return 0;
}
