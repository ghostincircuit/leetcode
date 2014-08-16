#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {
public:
        vector<int> findSubstring(string S, vector<string> &L) {
                if (L.size() == 0 || S.size() == 0)
                        return vector<int>();

                unordered_map<string, int> mp;
                for (int i = 0; i < L.size(); i++) {
                        unordered_map<string, int>::iterator t = mp.find(L[i]);
                        if (t != mp.end()) {
                                t->second++;
                        } else {
                                mp[L[i]] = 1;
                        }
                }
                vector<string> str;
                vector<int> stc;
                unordered_map<string, int>::iterator t;
                for (t = mp.begin(); t != mp.end(); t++) {
                        str.push_back(t->first);
                        stc.push_back(t->second);
                }

                vector<int> Sp(S.size(), -1);
                for (int i = 0; i < str.size(); i++) {
                        int pos = 0;
                        for (; pos < S.size();) {
                                pos = S.find(str[i], pos);
                                if (pos >= 0) {
                                        Sp[pos] = i;
                                        pos++;
                                } else {
                                        break;
                                }
                        }
                }
                vector<int> ret;
                int wl = L[0].size();
                for (int w = 0; w < wl; w++) {
                        int upp = S.size()-L.size()*wl;
                        for (int i = w; i <= upp;) {
                                int p;
                                vector<int> stcr = stc;
                                vector<int> lastpos(stcr.size(), -1);
                                int fail_reason = 0;
                                int j;
                                for (j = 0; j != L.size(); j++) {
                                        p = j*wl + i;
                                        if (Sp[p] == -1) {
                                                fail_reason = 1;
                                                break;
                                                //fail
                                        } else if (stcr[Sp[p]] == 0) {
                                                fail_reason = 2;
                                                break;
                                                //fail
                                        } else {
                                                stcr[Sp[p]]--;
                                                if (lastpos[Sp[p]] == -1) {
                                                        lastpos[Sp[p]] = p;
                                                }
                                        }
                                }
                                if (j == L.size()) {
                                        //found
                                        ret.push_back(i);
                                        i += wl;
                                } else if (fail_reason == 1) {
                                        i += wl*(j+1);
                                } else {
                                        i  = lastpos[Sp[i]] + wl;
                                }
                        }
                }
                return ret;
        }
};


int main()
{
/*
        string S("lingmindraboofooowingdingbarrwingmonkeypoundcake");
        vector<string> L;
        L.push_back("fooo");
        L.push_back("barr");
        L.push_back("wing");
        L.push_back("ding");
*/
///*
        string S("a");
        vector<string> L;
        L.push_back("aa");
        L.push_back("aa");
//*/
        Solution s;
        vector<int> ret = s.findSubstring(S, L);
        for (int i = 0; i < ret.size(); i++) {
                cout << ret[i] << endl;
        }
        return 0;
}
