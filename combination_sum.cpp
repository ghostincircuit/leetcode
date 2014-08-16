#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
        vector<int> *c;
        vector<vector<int> > helper(vector<int>::iterator b, int target) {
                vector<vector<int> > ret;

                if (target == 0) {
                        ret.push_back(vector<int>());
                        return ret;
                }

                if (b == c->end())
                        return ret;


                for (vector<int>::iterator i = b; i != c->end(); i++) {
                        for (int k = 1; (*i)*k <= target; k++) {
                                vector<vector<int> > tmp;
                                tmp = helper(i+1, target-(*i)*k);
                                if (tmp.size()) {
                                        for (int j = 0; j < int(tmp.size()); j++) {
                                                ret.push_back(vector<int> (k, *i));
                                                ret.back().insert(ret.back().end(), tmp[j].begin(), tmp[j].end());
                                        }
                                }
                        }
                }
                return ret;
        }

        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
                vector<vector<int> > ret;
                int last = -1;
                c = new vector<int>();
                sort(candidates.begin(), candidates.end());
                for (int i = 0; i < int(candidates.size()); i++) {
                        if (candidates[i] != last) {
                                last = candidates[i];
                                c->push_back(candidates[i]);
                        }
                }

                ret = helper(c->begin(), target);

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
