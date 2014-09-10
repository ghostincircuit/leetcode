#include <unordered_set>
#include <cassert>
#include <string>
using namespace std;

struct node {
        short int i;
        short int j;
        node(int ii, int jj) {i = ii; j = jj;}
};
namespace std {
        template <>
        struct hash<node>
        {
                size_t operator() (const node& r) const {
                        return (r.i << 16) + r.j;
                }
        };
        
        template<>
        struct equal_to<node>
        {
                bool operator() (const node& lhs, const node& rhs) const {
                        return lhs.i == rhs.i && lhs.j == rhs.j;
                }
        };
}

class Solution {
public:
        bool isInterleave(string s1, string s2, string s3) {
                int z1 = s1.size();
                int z2 = s2.size();
                int z3 = s3.size();
                if (z1 + z2 != z3)
                        return false;
                if (z3 == 0)
                        return true;
                unordered_set<node> o;
                unordered_set<node> n;
                n.insert(node(-1, -1));

                for (int i = 0; i < z3; i++) {
                        if (n.empty())
                                return false;
                        o = n;
                        n = unordered_set<node>();
                        for (auto j = o.begin(); j != o.end(); j++) {
                                int ii = j->i;
                                int jj = j->j;
                                if (ii + 1 < z1 && s1[ii+1] == s3[i]) {
                                        n.insert(node(ii+1, jj));
                                }
                                if (jj + 1 < z2 && s2[jj+1] == s3[i]) {
                                        n.insert(node(ii, jj+1));
                                }
                        }
                }
                return !n.empty();
        }
};

int main()
{
        Solution s;
        auto ret = false;
        string s1 = "aaa";
        string s2 = "bbb";
        string s3 = "ababab";
        ret = s.isInterleave(s1, s2, s3);
        assert(ret == true);

        s1 = "aabcc";
        s2 = "dbbca";
        s3 = "aadbbcbcac";
        ret = s.isInterleave(s1, s2, s3);
        assert(ret == true);

        s3 = "aadbbbaccc";
        ret = s.isInterleave(s1, s2, s3);
        assert(ret == false);

        s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";

        s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";

        s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
        ret = s.isInterleave(s1, s2, s3);
        assert(ret == false);

        s1 = "a";
        s2 = "";
        s3 = "c";
        ret = s.isInterleave(s1, s2, s3);
        assert(ret == false);

        return 0;
}
