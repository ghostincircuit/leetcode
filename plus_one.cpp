#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
        vector<int> plusOne(vector<int> &digits) {
                auto p = digits.end();
                auto b = digits.begin();
                p--;
                bool carry = true;
                while (p >= b) {
                        if (carry == true && *p == 9) {
                                carry = true;
                                p--;
                        } else {
                                carry = false;
                                break;
                        }
                        
                }
                auto n = digits.size();
                auto sz = n;
                if (carry == true)
                        sz++;
                vector<int> ret(sz);
                p = digits.end();
                auto pp = ret.end();
                p--;
                pp--;
                carry = true;
                while (n--) {
                        if (carry) {
                                *pp = *p +1;
                                if (*pp == 10) {
                                        *pp = 0;
                                        carry = true;
                                }
                                else
                                        carry = false;
                        } else {
                                *pp = *p;
                        }
                        pp--;
                        p--;
                }
                if (carry)
                        *pp = 1;
        return ret;
        }
};

int main()
{
        Solution s;
        vector<int> vi = {9,9,9,9};
        auto r = s.plusOne(vi);
        for (auto i: r)
                cout << i;
        cout << endl;
        return 0;
}
