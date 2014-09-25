class Solution {
public:
        bool wordBreak(string s, unordered_set<string> &dict) {
                vector<bool> dp(s.size()+1, false);
                for (int i = 0; i < s.size(); i++) {
                        if (dp[i] == false && i != 0)
                                continue;
                
                        for (auto& j:dict) {
                                int sz = j.size();
                                if (i + sz >= dp.size())
                                        continue;
                                int k = 0;
                                for (; k < sz; k++)
                                        if (j[k] != s[i+k])
                                                break;
                                if (k != sz)
                                        continue;
                                dp[i+sz] = true;
                        }
                }
                return dp[s.size()];
        }
};
