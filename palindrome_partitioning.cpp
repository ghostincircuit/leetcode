#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
        bool helper2(string::iterator b, string::iterator e) {
                e--;
                while (b < e) {
                        if (*b == *e) {
                                b++;
                                e--;
                        } else
                                return false;
                }
                return true;
        }

        vector<vector<string>> helper1(string::iterator b, string::iterator e) {
                vector<vector<string>> ret;
                assert(b < e);
                string::iterator i = b+1;
                if (i == e) {
                        ret.push_back(vector<string>());
                        ret[0].push_back(string(b,e));
                        return ret;
                }
                while (i <= e-1) {
                        if (helper2(b, i)) {
                                vector<vector<string>> tmp = helper1(i, e);
                                for (int k = 0; k < tmp.size(); k++) {
                                        ret.push_back(vector<string>());
                                        vector<string>& ref = ret.back();
                                        ref.push_back(string(b, i));
                                        ref.insert(ref.end(), tmp[k].begin(), tmp[k].end());
                                }

                        }
                        i++;
                }
                if (helper2(b, e)) {
                        ret.push_back(vector<string>());
                        ret.back().push_back(string(b, e));
                }
                return ret;
        }

        vector<vector<string>> partition(string s) {
                vector<vector<string>> ret;
                if (s.size() == 0)
                        return ret;
                if (s.size() == 1) {
                        ret.push_back(vector<string>());
                        ret[0].push_back(s);
                        return ret;
                }
                ret = helper1(s.begin(), s.end());
                return ret;
        }
};

int main()
{
        Solution s;

        string str("2212");
        vector<vector<string>> r = s.partition(str);
        for (int i = 0; i < r.size(); i++) {
                for (int j = 0; j < r[i].size(); j++) {
                        cout << r[i][j] << " ";
                }
                cout << endl;
        }
        return 0;
}
