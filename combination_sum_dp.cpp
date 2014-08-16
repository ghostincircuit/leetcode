#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define dd(i, j) (dp[(i)*l+(j)])
class Solution {
public:
        struct dp_state {
                vector<int> c;
                int valid;
                dp_state() {valid = 0;}
        };

        int l;
        void helper(int i, int j, vector<int>& cand, vector<vector<int> >& ret, struct dp_state *dp, vector<int> *t) {
                if (i == 0) {
                        ret.push_back(vector<int>(t->size()));
                        reverse_copy(t->begin(), t->end(), ret.back().begin());
                } else {
                        vector<int>& c = dd(i, j).c;
                        for (vector<int>::iterator ii = c.begin();
                             ii != c.end();
                             ii++) {
                                t->insert(t->end(), *ii, cand[i-1]);
                                helper(i-1, j-(*ii)*cand[i-1], cand, ret, dp, t);
                                t->erase(t->end()-*ii, t->end());
                        }
                }
        }

        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
                sort(candidates.begin(), candidates.end());
                vector<int> c;
                int last = -1;
                for (vector<int>::iterator i = candidates.begin(); i < candidates.end(); i++) {
                        if (*i != last) {
                                last = *i;
                                c.push_back(*i);
                        }
                }
                int n = c.size()+1;
                l = target+1;
                struct dp_state *dp = new dp_state[n*l];
                dp[0].valid = 1;

                for (int i = 1; i < n; i++) {
                        for (int j = 0; j < l; j++) {
                                for (int k = 0; k*c[i-1] <= j; k++) {
                                        if (dd(i-1, j-k*c[i-1]).valid) {
                                                dd(i,j).valid = 1;
                                                dd(i,j).c.push_back(k);
                                        }
                                }
                        }
                }
                vector<int> t;
                vector<vector<int> > ret;
                if (dd(n-1, l-1).valid)
                        helper(n-1, l-1, c, ret, dp, &t);
                return ret;
        }
};

int main() {

        Solution so;
        int s[] = {1,2,3,4,5,6,7,8,9,10,11,12};
        vector<int> c;
        for (int i = 0; i < int(sizeof(s)/sizeof(s[0])); i++)
                c.push_back(s[i]);

        vector<vector<int> > r;
        r = so.combinationSum(c, 64);
        for (int i = 0; i < int(r.size()); i++) {
                for (int j = 0; j < int(r[i].size()); j++) {
                        cout << r[i][j] << ' ';
                }
                cout << endl;
        }
}
