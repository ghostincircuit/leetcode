#include <iostream>
#include <vector>
#include <string>

#include <algorithm>

using namespace std;

class Solution {
public:
        vector<int> mk;
        int cri;
        int e;
        vector<string> *rp;
        void helper(int n, int b, int l) {
                if (n == 0) {
                        rp->push_back(string("("));
                        string& ref = rp->back();
                        for (int i = 0; i < e; i++) {
                                if (mk[i])
                                        ref.push_back('(');
                                else
                                        ref.push_back(')');
                        }
                        ref.push_back(')');
                        return;
                }
                for (int i = b; l-(i-b) >= 0; i++) {
                        mk[i] = 1;
                        helper(n-1, i+1, l-(i-b)+1);
                        mk[i] = 0;
                }
        }
        vector<string> generateParenthesis(int n) {
                vector<string> ret;
                rp = &ret;
                if (n == 0)
                        return ret;
                if (n == 1) {
                        ret.push_back(string("()"));
                        return ret;
                }
                cri = n/2;
                mk = vector<int>(n*2-2, 0);
                e = n*2-2;
                helper(n-1, 0, 1);
                return ret;
        }
};

int main()
{

        Solution s;
        vector<string> r = s.generateParenthesis(4);
        sort(r.begin(), r.end());
        for (int i = 0; i < int(r.size()); i++)
                cout << r[i] << endl;

        return 0;
}
