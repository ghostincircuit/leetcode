#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
        vector<int> twoSum(vector<int> &numbers, int target) {
                vector<int> cp(numbers);
                sort(cp.begin(), cp.end());
                int n = cp.size();
                vector<int> ret;
                int lim = lower_bound(cp.begin(), cp.end(), target) - cp.begin();

                for (int i = lim; i >= 0; i--) {
                        vector<int>::iterator vi;
                        vi = lower_bound(cp.begin()+i+1, cp.end(), target - cp[i]);
                        if (vi != cp.end() && *vi == target - cp[i]) {
                                int lef = find(numbers.begin(), numbers.end(), cp[i]) - numbers.begin();
                                int rig = find(numbers.begin(), numbers.end(), *vi) - numbers.begin();
                                if (lef == rig)
                                        rig = find(numbers.begin() + lef+1, numbers.end(), *vi) - numbers.begin();
                                if (lef > rig) {
                                        int t = lef;
                                        lef = rig;
                                        rig = t;
                                }
                                ret.push_back(lef+1);
                                ret.push_back(rig+1);
                                break;
                        }
                }
                return ret;
        }
};

int main()
{
        //int a[] = {34,3,34,5,45,4,6,6,5,6};
        int a[] = {0,1,4,0};

        const int N = sizeof(a)/sizeof(a[0]);
        vector<int> numbers(a, a+N);
        

        Solution s;
        vector<int> ret = s.twoSum(numbers, 0);
        cout << ret[0] << ", " << ret[1] << endl;

        return 0;       
}
