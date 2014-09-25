#include <map>
#include <vector>
using namespace std;

class Solution {
public:
        typedef map<int, int> uii; 
        uii mp;
        vector<int> tmp;
        vector<vector<int> > ret;
        void rec(uii::iterator i) {
                if (i == mp.end())
                        ret.emplace_back(tmp);
                else {
                        int cnt = i->second;
                        int k = i->first;
                        int save = tmp.size();
                        auto kk = i;
                        kk++;
                        rec(kk);
                        for (int i = 0; i < cnt; i++) {
                                tmp.push_back(k);
                                rec(kk);
                        }
                        tmp.erase(tmp.begin() + save, tmp.end());
                }
        }
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
                for (auto i: S) {
                        auto k = mp.find(i);
                        if (k == mp.end()) {
                                mp.insert(make_pair(i, 1));
                        } else {
                                (k->second)++;
                        }
                }
                rec(mp.begin());
                return ret;
        
        }
};

int main()
{
        Solution s;
        vector<int> in = {0};
        auto r = s.subsetsWithDup(in);
        return 0;
}
