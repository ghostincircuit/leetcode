#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
        vector<string> dict;

        vector<string> letterCombinations(string digits) {
                dict.push_back(string());
                dict.push_back(string());
                dict.push_back(string("abc"));
                dict.push_back(string("def"));
                dict.push_back(string("ghi"));
                dict.push_back(string("jkl"));
                dict.push_back(string("mno"));
                dict.push_back(string("pqrs"));
                dict.push_back(string("tuv"));
                dict.push_back(string("wxyz"));

                vector<string> old_store;
                string t("");
                old_store.push_back(t);
                vector<string> new_store;
                string::iterator i = digits.begin();
                while (i != digits.end()) {
                        int digit = *i-'0';
                        new_store.clear();
                        while (old_store.size()) {
                                string t = old_store.back();old_store.pop_back();
                                int sz = dict[digit].size();
                                for (int j = 0; j < sz; j++) {
                                        string st1 = t;st1.push_back(dict[digit][j]);
                                        new_store.push_back(st1);
                                }
                        }
                        old_store = new_store;
                        i++;
                }
                return old_store;
    }
};

int main()
{
        Solution s;
        //vector<string> ret = s.letterCombinations("23");
        vector<string> ret = s.letterCombinations("");
        for (int i = 0; i < ret.size(); i++)
                cout << ret[i] << endl;
        return 0;
}
