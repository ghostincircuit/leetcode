#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <string>
#include <list>

using namespace std;

class Solution {
public:
        struct node {
                const string *str;
                vector<struct node *> links;
                int color;
                node(const string *_str): str(_str), color(0) {}
        };

        bool helper(const string& l, const string& r) {
                int n = l.size();
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                        if (l[i] != r[i]) {
                                cnt++;
                                if (cnt == 2)
                                        return false;
                        }
                }
                return true;
        }
        vector<struct node *> first;
        struct node *endp;
        vector<vector<string> > ret;
        vector<const string *> tmp;
        vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
                list<struct node *> open_list;
                for (auto i = dict.begin(); i != dict.end(); i++) {
                        open_list.push_back(new node(&(*i)));
                }

                node last(&end);
                endp = &last;
                vector<struct node *> half_list;
                vector<struct node *> new_list;
                new_list.push_back(&last);
                int level = 0;
                while (new_list.size() != 0) {
                        level++;
                        half_list = new_list;
                        new_list = vector<struct node *>();
                        for (auto i = half_list.begin(); i != half_list.end(); i++) {
                                if (helper(*(*i)->str, start))
                                        first.push_back(*i);
                        }
                        if (first.size())
                                break;

                        for (auto i = half_list.begin(); i != half_list.end(); i++) {
                                for (auto j = open_list.begin(); j != open_list.end(); j++) {
                                        if (helper(*((*i)->str), *((*j)->str))) {
                                                if ((*j)->color == 0)
                                                        new_list.push_back(*j);
                                                (*j)->links.push_back(*i);
                                                (*j)->color = 1;
                                        }
                                }
                        }
                        auto lst = open_list.end();
                        for (auto i = open_list.begin(); i != open_list.end(); i++) {
                                if (lst != open_list.end()) {
                                        open_list.erase(lst);
                                        lst = open_list.end();
                                }
                                if ((*i)->color)
                                        lst = i;
                        }
                        if (lst != open_list.end())
                                open_list.erase(lst);
                }
                if (first.size() == 0)
                        return ret;
                //dfs();
                tmp.push_back(&start);
                //dfs();
                rec(first);
                return ret;
        }


        void rec(vector<struct node *>& vn) {
                for (auto i = vn.begin(); i != vn.end(); i++) {
                        tmp.push_back(((*i)->str));
                        if (*i == endp) {
                                ret.push_back(vector<string>());
                                for (auto j = tmp.begin(); j != tmp.end(); j++) {
                                        assert((**j).size() != 0);
                                        ret.back().push_back(**j);
                                }
                        } else {
                                rec((*i)->links);
                        }
                        tmp.pop_back();
                }
        }
};

int main()
{
        Solution s;
        unordered_set<string> dict;


        const char *pa[] = {"hot", "dot", "dog", "lot", "log"};
        for (auto i:pa) {
                dict.insert(*(new string(i)));
        }

        auto ret = s.findLadders("hit", "cog", dict);


        for (auto i = ret.begin(); i != ret.end(); i++) {
                for (auto j = i->begin(); j != i->end(); j++) {
                        cout << *j <<" ";
                }
                cout << endl;
        }
        return 0;
}
