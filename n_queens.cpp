#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
        vector<int> pos;
        int lim;
        vector<vector<string> > ret;
        void helper(int level) {
                if (level == lim) {
                        vector<string> vs(lim, string(lim, '.'));
                        for (auto i = 0; i < lim; i++) {
                                vs[i][pos[i]] = 'Q';
                        }
                        ret.push_back(vs);
                        return;
                }
                vector<int> possible(lim, 0);
                for (auto i = 0; i < level; i++) {
                        int p = pos[i];
                        possible[p] = 1;
                        int left = p - (level - i);
                        int right = p + (level - i);
                        if (left >= 0)
                                possible[left] = 1;
                        if (right < lim)
                                possible[right] = 1;
                }
                for (auto i = 0; i < lim; i++) {
                        if (possible[i] == 0) {
                                pos.push_back(i);
                                helper(level+1);
                                pos.pop_back();
                        }
                }
        }

        vector<vector<string> > solveNQueens(int n) {
                lim = n;
                helper(0);
                return ret;
        }
};

int main()
{
        Solution s;
        auto ret = s.solveNQueens(8);

        for (auto& i: ret) {
                for (auto& j: i)
                        cout << j << endl;
                cout << "------------------------" << endl;
        }
        return 0;
}
