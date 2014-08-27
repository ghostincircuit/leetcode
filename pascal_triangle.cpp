#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
        vector<vector<int> > generate(int numRows) {
                vector<vector<int> > ret;
                if (numRows == 0)
                        return ret;
                int n = 1;
                ret.emplace_back(1, 1);
                while (numRows != n) {
                        n++;
                        auto last = *(ret.end()-1);
                        ret.emplace_back(n);
                        for (auto i = 0; i < n; i++) {
                                auto left = i-1;
                                auto right = i;
                                if (left < 0)
                                        left = 0;
                                else
                                        left = last[left];
                                if (right == n-1)
                                        right = 0;
                                else
                                        right = last[right];
                                (*(ret.end()-1))[i] = left + right;
                        }
                }
                return ret;
        }
};

int main()
{
        Solution s;
        auto r = s.generate(0);
        for (auto& i:r) {
                for (auto& j:i) {
                        cout << j << " ";
                }
                cout << endl;
        }
        return 0;
}
