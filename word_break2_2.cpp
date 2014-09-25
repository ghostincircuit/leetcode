#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
        vector<string> ret;
        vector<vector<int> *> dp;
        string tmp;
        string *str;
        void rec(int i) {
                string& s = *str;
                if (dp[i] == NULL) {
                        tmp.pop_back();
                        ret.push_back(tmp);
                        return;
                }
                vector<int>& l = *dp[i];
                for (int j = 0; j < l.size(); j++) {
                        auto save = tmp.end() - tmp.begin();
                        tmp.append(s.begin() + i, s.begin() + l[j]);
                        tmp.append(" ");
                        rec(l[j]);
                        tmp.erase(save);
                }
        }

        vector<string> wordBreak(string s, unordered_set<string> &dict) {
                str = &s;
                dp = vector<vector<int> *>(s.size()+1, NULL);
                for (int i = dp.size()-1; i != -1; i--) {
                        if (dp[i] == NULL && i != dp.size()-1)
                                continue;
                        for(auto& j: dict) {
                                int sz = j.size();
                                if (i-sz < 0)
                                        continue;
                                int k = i-sz;
                                int l = 0;
                                for (; l < sz; l++)
                                        if (j[l] != s[k+l])
                                                break;
                                if (l != sz)
                                        continue;
                                if (dp[k] == NULL)
                                        dp[k] = new vector<int>;
                                dp[k]->push_back(i);
                        }
                }
                if (dp[0] == NULL)
                        return ret;
                rec(0);
                return ret;

        }
        
};

int main()
{
        Solution s;
        unordered_set<string> di;
        di.insert(string("this"));
        di.insert(string("got"));
        di.insert(string("gots"));
        di.insert(string("snapp"));
        di.insert(string("napp"));

        auto r = s.wordBreak("thisgotsnapp", di);
        for (auto i = r.begin(); i != r.end(); i++)
                cout << *i << endl;
        return 0;
        
}
