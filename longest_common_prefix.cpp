#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
        typedef pair<string *, int> psi;

        int common(string& l, string& r, int lim) {
                for (auto i = 0; i < lim; i++) {
                        if (l[i] != r[i])
                                return i;
                }
                return lim;
        }

        string longestCommonPrefix(vector<string> &strs) {
                int sz = strs.size();
                if (sz <= 0)
                        return string();
                int lim = strs[0].size();
                auto i = strs.begin();
                i++;
                for (;i != strs.end(); i++) {
                        int ssz = i->size();
                        int tlim = lim > ssz ? ssz : lim;
                        int ret = common(strs[0], *i, tlim);
                        lim = ret < tlim ? ret : tlim;
                }
                string ret;
                for (auto i = 0; i < lim; i++)
                        ret.push_back(strs[0][i]);
                return ret;
        }

/*
        psi common(psi& l, psi& r) {
                psi ret;
                int sz = (l.second > r.second) ? r.second : l.second;
                auto i = 0;
                for (; i < sz; i++) {
                        if (l.first[i] != r.first[i])
                                break;
                }
                ret.first = l.first;
                ret.second = i
        }

        string longestCommonPrefix(vector<string> &strs) {
                vector<psi > cur;
                vector<psi > next;
                if (strs.size() == 0)
                        return NULL;
                for (auto& i: strs)
                        cur.push_back(make_pair(&i, i.size()));
                while (cur.size() != 1) {
                        next.clear();
                        if (cur.size() % 2 == 1) {
                                auto p = cur.end();
                                p--;
                                next.push_back(*p);
                                cur.erase(p);
                        }
                        for (auto i = 0; i != cur.size(); i+=2) {
                                auto ret = common(cur[0], cur[1]);
                                next.push_back(ret);
                        }
                        std::swap(cur, next);
                }
                string str(cur[0].second);
                for (auto i = 0; i < cur[0].second; i++)
                        str[i] = (*cur[0].first)[i];
                return str;
        }
*/
};

int main()
{
        Solution s;
        vector<string> vs;
        vs.clear();
        vs.push_back(string("01234"));
        vs.push_back(string("0123567"));
        vs.push_back(string("0123444"));
        vs.push_back(string("0123467"));
        auto ret = s.longestCommonPrefix(vs);
        cout << ret << endl;

        vs.clear();
        vs.push_back(string("0123467"));
        ret = s.longestCommonPrefix(vs);
        cout << ret << endl;

        return 0;
}
