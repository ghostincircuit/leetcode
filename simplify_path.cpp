#include <cassert>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
        string simplifyPath(string path) {
                string cur;
                path += string("/");
                vector<string> vs;
                for (auto i: path) {
                        if (i == '/') {
                                if (cur == string("/.")) {
                                        //do nothing
                                } else if (cur == string("/")) {
                                        //do nothing
                                } else if (cur == string("/..")) {
                                        if (!vs.empty())
                                                vs.pop_back();
                                } else {
                                        vs.push_back(cur);
                                }
                                cur = string("/");

                        } else {
                                cur.push_back(i);
                        }
                }
                string ret;
                for (auto i: vs)
                        ret += i;
                if (ret.size() == 0)
                        return string("/");
                return ret;
        }
};

int main()
{
        Solution s;
        auto r = s.simplifyPath("/");
        assert(r == string("/"));

        r = s.simplifyPath("/home/");
        assert(r == string("/home"));

        r = s.simplifyPath("/a/./b/../../c/");
        assert(r == string("/c"));

        r = s.simplifyPath("/...");
        assert(r == string("/..."));

        return 0;
}
