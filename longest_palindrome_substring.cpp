#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
        int helper(int m, string s, int *b) {
                int n = s.size();
                int r;
                for (r = 0; 0 <= m-r && m+r <= n-1; r++) {
                        if (s[m-r] != s[m+r])
                                break;
                }
                r--;

                r = 1+2*r;
                int rr = 0;
                for (rr = 0; 0 <= m-rr && m+1+rr <= n-1; rr++) {
                        if (s[m-rr] != s[m+rr+1])
                                break;
                }                
                rr--;

                rr = 2 + 2*rr;
                if (r > rr) {
                        int l = (r-1)/2;
                        *b = m-l;
                } else {
                        int l = (rr-2)/2;
                        *b = m-l;
                }
                return r > rr ? r : rr;
        }
        string longestPalindrome(string s) {
                int len = 1;
                int b = 0;
                int n = s.size();
                for (int i = n/2; i < int(s.size()); i++) {
                        int tb;
                        int r = helper(i, s, &tb);
                        if (r > len) {
                                b = tb;
                                len = r;
                        }
                }

                for (int i = n/2-1; i >= 0; i--) {
                        int tb;
                        int r = helper(i, s, &tb);
                        if (r > len) {
                                b = tb;
                                len = r;
                        }
                }
                return string(s.begin()+b, s.begin()+b+len);
        }
};

int main()
{
        string str(1024*64, '0');
        //string str("1221");
        //string str("1111");

        Solution s;
        string r = s.longestPalindrome(str);
        cout << str << endl;
        cout << r << endl;
        return 0;
}
