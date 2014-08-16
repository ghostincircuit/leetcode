#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
        string minWindow(string S, string T) {
                string ret;
                if (T.size() == 0)
                        return ret;

                const int IMP = S.size()+3;
                typedef unordered_map<char, vector<int>> ucvi;
                typedef pair<char, vector<int>> pcvi;
                ucvi mp;
                for (int i = 0; i != T.size(); i++) {
                        ucvi::iterator f = mp.find(T[i]);
                        if (f == mp.end())
                                mp.insert(pcvi(T[i], vector<int>(1, IMP)));
                        else
                                f->second.push_back(IMP);
                }

                int cnt = T.size();
                int min = IMP;
                int len = S.size()+4;
                int start = 0;
                for (int i = 0; i != S.size(); i++) {
                        ucvi::iterator f = mp.find(S[i]);
                        if (f != mp.end()) {
                                vector<int>& v = f->second;
                                int oldmin = *v.begin();
                                int last = 0;
                                if (v.back() == IMP) {
                                        vector<int>::iterator ti = lower_bound(v.begin(), v.end(), IMP);
                                        *ti = i;
                                        cnt--;
                                        if (cnt == 0)
                                                last = 1;
                                } else {
                                        v.erase(v.begin());
                                        v.push_back(i);
                                }
                                if (cnt == 0) {
                                        if (oldmin == min || last) {
                                                ucvi::iterator it = mp.begin();
                                                int tmp = S.size() + 4;
                                                for (; it != mp.end(); it++) {
                                                        if (tmp > *(it->second.begin()))
                                                                tmp = *(it->second.begin());
                                                }
                                                min = tmp;
                                                int nlen = i +1 - min;
                                                if (nlen < len) {
                                                        len = nlen;
                                                        start = min;
                                                }
                                        }
                                }
                        }
                }
                if (cnt != 0)
                        return string();
                else
                        return string(S.begin() + start, S.begin() + start + len);
        }
};

int main()
{
        Solution s;
        string s1 = string(1023, 'a') + string(1023, 'b') + string(1023, 'c') + string(1023, 'd') + string(1023, 'e') + string(1023, 'a');
        s1 = s1 + s1;
        string s2 = string(1024, 'a');
        string r;
        for (int i = 0; i < 1024; i++) {
                string r = s.minWindow(s1, s2);
        }
        
        cout << r;
        return 0;
}
