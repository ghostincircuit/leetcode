#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
        int threeSumClosest(vector<int> &num, int target) {
                sort(num.begin(), num.end());
                int n = num.size();
                int match = num[0] + num[1] + num[2];
                int mk;
                for (int i = 0; i < n-2; i++) {
                        int rem = target - num[i];
                        mk = num[i+1] + num[n-1];
                        int j, k;
                        for (j = i+1, k = n-1; j < k;) {
                                if (abs(num[k] + num[j] - rem) < abs(mk-rem))
                                        mk = num[k] + num[j];
                                if (num[k] + num[j] == rem)
                                        break;
                                else if (num[k] + num[j] > rem)
                                        k--;
                                else
                                        j++;
                        }
                        if (abs(num[i] + mk - target) < abs(match - target)) {
                                match = num[i] + mk;
                        }
                }
                return match;
        }
};

int main()
{
        Solution s;
        int v[] = {-3,0,1,2};
        vector<int> i(v, v+sizeof(v)/sizeof(v[0]));
        int r = s.threeSumClosest(i, 1);
        cout << r << endl;
        return 0;
}
