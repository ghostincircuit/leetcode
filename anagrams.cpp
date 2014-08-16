#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;



class Solution {
public:

        typedef struct sig {
                unsigned short int c[26];
                sig() {
                        memset(c, 0, sizeof(c));
                }
                bool operator<(const sig& r) const {                
                        for (int i = 0; i < 26; i++) {
                                if (c[i] < r.c[i])
                                        return true;
                                else if (c[i] == r.c[i])
                                        continue;
                                else
                                        return false;
                        }
                        return false;
                }
        } sig;

        vector<string> anagrams(vector<string> &strs) {
                map<sig, vector<string *>> mp;
                for (int i = 0; i < strs.size(); i++) {
                        sig t;                        
                        for (int j = 0; j < strs[i].size(); j++) {
                                t.c[strs[i][j] - 'a']++;
                        }
                        map<sig, vector<string *>>::iterator ti;
                        ti = mp.find(t);
                        if (ti != mp.end()) {
                                ti->second.push_back(&strs[i]);
                        } else {
                                mp[t] = vector<string *>();
                                mp[t].push_back(&strs[i]);
                        }
                }

                vector<string> ret;
                map<sig, vector<string *>>::iterator i;
                for (i = mp.begin(); i != mp.end(); i++) {
                        if (i->second.size() > 1) {
                                for (int j = 0; j < i->second.size(); j++)
                                        ret.push_back(*(i->second[j]));
                        }
                }
                return ret;
        }
};


int main()
{
        vector<string> strs;
/*
        strs.push_back(string("abcd"));
        strs.push_back(string("cdba"));
        strs.push_back(string("adcb"));
        strs.push_back(string("adcbf"));
*/

        Solution s;
        vector<string> ret;
        ret = s.anagrams(strs);
        vector<string>::iterator i;
        for (i = ret.begin(); i != ret.end(); i++)
                cout << *i << endl;
        return 0;
}
