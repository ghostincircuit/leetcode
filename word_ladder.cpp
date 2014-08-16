#include <iostream>
#include <string>
#include <unordered_set>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
        int N;
        inline bool adj(const string& a, const string& b) {
                int cnt = 0;
                for (int i = 0; i < N; i++)
                        if (a[i] != b[i]) {
                                cnt++;
                                if (cnt == 2)
                                        return false;
                        }

                return true;
        }
        int ladderLength(string start, string end, unordered_set<string> &dict) {
                N = start.size();
                list<const string *> dt;
                int del = 0;
                for (auto i = dict.begin(); i != dict.end(); i++) {
                        dt.push_back(&*i);
                }
                queue<const string *> q;
                int steps = 1;
                q.push(&start);
                q.push(0);
                while (1) {
                        auto tmp = q.front();q.pop();
                        if (tmp == 0) {
                                if (q.empty())
                                        return 0;
                                else {
                                        steps++;
                                        q.push(0);
                                        continue;
                                }
                        }
                        if (adj(*tmp, end))
                                return steps+1;

                        del = 0;
                        for (auto i = dt.begin(); i != dt.end(); i++) {
                                if (del) {
                                        auto j = i;
                                        j--;
                                        dt.erase(j);
                                }
                                if (adj(**i, *tmp)) {
                                        del = 1;
                                        q.push(*i);
                                } else {
                                        del = 0;
                                }
                        }
                        if (del) {
                                auto i = dt.end();
                                i--;
                                dt.erase(i);
                        }
                }
        }
};

int main()
{
        Solution s;
        unordered_set<string> dict;
        int r;

/*
        dict.insert("baa");
        dict.insert("bba");
        dict.insert("cba");
        dict.insert("cbz");
        dict.insert("czz");
        r = s.adj(s.calc("aaa"), s.calc("aba"));
        r = s.adj(s.calc("aaa"), s.calc("abb"));
        r = s.adj(s.calc("aaa"), s.calc("aab"));
                  
        r = s.ladderLength("aaa", "zzz", dict);
*/

/*
        dict.insert("aab");
        dict.insert("bab");
        dict.insert("bcb");
        dict.insert("ccb");
        dict.insert("ccc");
        r = s.ladderLength("aaa", "ccd", dict);
*/

/*
        dict.insert("aba");
        r = s.ladderLength("aaa", "abb", dict);
*/

/*
        dict.insert("zzz");
        r = s.ladderLength("aaa", "abb", dict);
*/

/*
        dict.insert("hot");
        dict.insert("dot");
        dict.insert("dog");        
        r = s.ladderLength("hot", "dot", dict);
*/

/*
        dict.insert("hot");
        dict.insert("dog");        
        r = s.ladderLength("hot", "dog", dict);
*/


        dict.insert("a");
        dict.insert("b");
        dict.insert("c");        
        r = s.ladderLength("a", "c", dict);

        cout << r << endl;
}
