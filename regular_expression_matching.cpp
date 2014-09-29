#include <list>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
        struct node {
                char ch;
                int cnt;
                int star;
                node(char a=0, int b=0, int c=0) {ch = a; cnt = b; star = c;}
        };
        list<node> li;
        typedef list<node>::iterator lni;

        inline bool match(char a, char p) {
                if (p == '.' && a != 0)
                        return true;
                if (p != '.' && a == p)
                        return true;
                else
                        return false;
        }

        bool rec(const char *s, lni p) {
                if (*s == 0 && p != li.end() && p->cnt != 0)
                        return false;
                if (*s && p == li.end())
                        return false;
                if (*s == 0 && p == li.end())
                        return true;
                char ch = p->ch;
                int cnt = p->cnt;
                int star = p->star;
                int i = 0;
                for (; i < cnt; i++) {
                        if (!match(s[i], ch))
                                break;
                }
                if (cnt != i)
                        return false;
                const char *start = s+i;
                const char *pt = start;
                lni pp = p;
                pp++;

                if (star == 0)
                        return rec(start, pp);

                if ((ch != '.' && pp != li.end() && pp->cnt && pp->ch != '.') ||
                    pp == li.end()) {
                        while (match(*pt, ch))
                                pt++;
                        return rec(pt, pp);
                } else {
                        while (1) {
                                auto r = rec(pt, pp);
                                if (r == true)
                                        return true;
                                if (match(*pt, ch))
                                        pt++;
                                else
                                        break;
                        }
                        return false;
                }
        }

        bool isMatch(const char *s, const char *p) {
                //parse pattern
                while(*p) {
                        char cur = *p;
                        node n;
                        ++p;
                        if (*p == '*') {
                                n = node(cur, 0, 1);
                                ++p;
                        } else {
                                n = node(cur, 1, 0);
                        }
                        if (li.size() == 0) {
                                li.push_back(n);
                                continue;
                        }
                        node& prev = li.back();
                        if (prev.ch == n.ch) {
                                prev.cnt += n.cnt;
                                prev.star |= n.star;
                        } else {
                                li.push_back(n);
                        }
                }
                auto ret = rec(s, li.begin());
                li.clear();
                return ret;
        }
};

int main()
{
        Solution s;
        bool r;

        r = s.isMatch("aaa", "aa");
        assert(r == false);

        r = s.isMatch("", "");
        assert(r == true);

        r = s.isMatch("", ".*");
        assert(r == true);

        r = s.isMatch("", "a*b*a*a*a*b*");
        assert(r == true);

        r = s.isMatch("345345345", ".*");
        assert(r == true);

        r = s.isMatch("aaaaaaaabbb", "aaa*bbb");
        assert(r == true);

        r = s.isMatch("abc", "a*b*c*");
        assert(r == true);

        r = s.isMatch("abcd", "a*b*c*");
        assert(r == false);

        r = s.isMatch("bbbba", ".*a*a");
        assert(r == true);

        r = s.isMatch("bbbba", ".*.*a");
        assert(r == true);

        r = s.isMatch("bbbba", ".*b*b*a*.*a");
        assert(r == true);

        return 0;
}
