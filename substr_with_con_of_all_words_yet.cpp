#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

#define INVALID -1
class Solution {
public:
        vector<int> findSubstring(string S, vector<string> &L) {
                vector<int> ret;
                if (L.size() == 0 || S.size() == 0)
                        return ret;

                int wl = L[0].size();
                int wc = L.size();
                map<string, int> mp;
                for (int i = 0; i < wc; i++) {//use map to optimize
                        map<string, int>::iterator mi = mp.find(L[i]);
                        if (mi != mp.end()) {
                                mi->second++;
                        } else {
                                pair<string, int> p(L[i], 1);
                                mp.insert(p);
                        }
                }
                vector<string> lp;
                vector<int> lc;
                for (map<string, int>::iterator mi = mp.begin(); mi != mp.end(); mi++) {
                        lp.push_back((mi->first));
                        lc.push_back(mi->second);
                }
                vector<int> pos;
                for (int i = 0; i <= int(S.size())-wl; i++) {
                        string str(S.begin()+i, S.begin()+i+wl);
                        vector<string>::iterator t = lower_bound(lp.begin(),
                                                                 lp.end(),
                                                                 str);
                        if (t != lp.end() && *t == str)
                                pos.push_back(t-lp.begin());
                        else
                                pos.push_back(INVALID);
                }
                int lim = S.size()-L.size()*wl;
                int fail;

                for (int w = 0; w < wl; w++) {
                        for (int s = 0; w+s*wl <= lim;) {
                                vector<int> cnt(lc);
                                vector<int> lastpos(lc.size(), -1);
                                int start = w+s*wl;
                                int i;
                                for (i = 0; i < L.size(); i++) {
                                        if (pos[start+i*wl] == INVALID) {
                                                fail = 1;
                                                break;
                                        } else if (cnt[pos[start+i*wl]] == 0) {
                                                fail = 2;
                                                break;
                                        } else {//normal case
                                                cnt[pos[start+i*wl]]--;
                                                if (lastpos[pos[start+i*wl]] == -1)
                                                        lastpos[pos[start+i*wl]] = s+i+1;
                                        }
                                }
                                if (i == L.size()) {
                                        ret.push_back(start);
                                        s += 1;
                                } else if (fail == 1) {
                                        s += i+1;
                                } else {//fail == 2
                                        s = lastpos[pos[start+i*wl]];
                                }
                        }
                }

                return ret;
        }
};


int main()
{
        vector<string> l;
/*
        l.push_back("12");
        l.push_back("12");
        l.push_back("34");
        l.push_back("12");
        l.push_back("56");
        string s("162126341256");
*/
/*
        l.push_back("a");
        l.push_back("b");
        l.push_back("a");
        string s("abababab");
*/

        l.push_back("mississippis");
        string s("mississippi");



        Solution ss;
        vector<int> r = ss.findSubstring(s, l);
        for (int i = 0; i < r.size(); i++) {
                cout << r[i] << endl;
        }
        return 0;
}
