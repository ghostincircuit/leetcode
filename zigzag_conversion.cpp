#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
        string convert(string s, int nRows) {
                int n = s.size();
                int row = nRows;
                string ret;

                if (row == 1)
                        return s;
                int batch = 2*row-2;
                int col = (n+batch-1)/batch;
                int mid = row-1;
                for (int i = 0; i < row; i++) {
                        for (int j = 0; j < col; j++) {
                                int idx = j*batch + i;
                                int jdx = (2*mid - i) + j*batch;
                                if (idx < n)
                                        ret.push_back(s[idx]);
                                if (jdx < n && i != 0 && i != mid)
                                        ret.push_back(s[jdx]);
                        }
                }
                return ret;
        }
};

int main()
{
        Solution s;
        string ret;
        ret = s.convert("PAYPALISHIRING", 3);
        assert(ret == string("PAHNAPLSIIGYIR"));

        ret = s.convert("PA", 2);
        assert(ret == string("PA"));

        ret = s.convert("P", 1);
        assert(ret == string("P"));

        ret = s.convert("ABCD", 3);
        assert(ret == string("ABDC"));

        ret = s.convert("ABC", 3);
        assert(ret == string("ABC"));

        ret = s.convert("ABC", 2);
        assert(ret == "ACB");

        ret = s.convert("ABCD", 2);
        assert(ret == "ACBD");

        return 0;
}
