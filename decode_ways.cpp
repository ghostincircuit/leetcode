#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
        int atoi(const char *str) {
                int sum = 0;
                return (*str-'0')*10 + *(str+1)-'0';
        }
        int numDecodings(string s) {
                if (s.size() == 0)
                        return 0;
                else if (s.size() == 1) {
                        if (s[0] != '0')
                                return 1;
                        else
                                return 0;
                }
                int *dpp = new int[s.size()+1];
                dpp[0] = 1;
                int *dp = dpp+1;
                if (s[0] != '0')
                        dp[0] = 1;
                else
                        dp[0] = 0;

                for (int i = 1; i < s.size(); i++) {
                        int sum = 0;
                        if (s[i] != '0')
                                sum += dp[i-1];
                        int t = atoi(s.c_str()+i-1);
                        if (t >= 10 && t <=26)
                                sum += dp[i-2];
                        dp[i] = sum;
                }
                return dp[s.size()-1];
        }
};


int main()
{
        Solution s;

        string str("0000");
        int r = s.numDecodings(str);
        cout << r << endl;
        return 0;
}
