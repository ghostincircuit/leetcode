#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
        vector<string> ret;
        unordered_set<string> *di;
        vector<const string *> tmp;
    
        void helper(string::iterator b, string::iterator e) {
                if (b == e) {
                        string base;
                        auto en = tmp.end();
                        en--;
                        auto i = tmp.begin();
                        for (; i != en; i++) {
                                base += **i;
                                base += " ";
                        }
                        if (en >= tmp.begin())
                                base += **en;
                        ret.emplace_back(base);
                        return;
                }
                for (auto i = di->begin(); i != di->end(); i++) {
                        const string& str = *i;
                        auto sz = str.size();
                        if (b + sz > e)
                                continue;
                        auto j = 0;
                        for (; j < sz; j++) {
                                if (*(b+j) != str[j])
                                        break;
                        }
                        if (j != sz)
                                continue;
                        tmp.push_back(&str);
                        helper(b + sz, e);
                        tmp.pop_back();
                }
        }
    
        vector<string> wordBreak(string s, unordered_set<string> &dict) {
                if (s.size() == 0)
                        return ret;
                di = &dict;
                helper(s.begin(), s.end());
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
