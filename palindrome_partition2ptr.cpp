#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
        const char *e;
        int mret;
        inline bool isp(const char *b, const char *e) {
                e--;
                while (b < e) {
                        if (*b != *e)
                                return false;
                        else {
                                b++;
                                e--;
                        }
                }
                return true;
        }
        int helper(const char *b, int t, int sum) {
                bool r = isp(b, e);
                int min = e-b-1;
                if (r == false && (sum >= mret || t == 0))
                        return min+1;//no need to go further
                else if (r == true) {
                        mret = (mret > sum ? sum : mret);
                        return 0;
                } else {//can go without more div, r==flase and t != 0
                        for (const char *i = e-1; i > b; i--) {
                                if (isp(b, i)) {
                                        int ret = helper(i, t < min ? t-1 : min-1, sum+1);
                                        if (ret < min)
                                                min = ret+1;
                                        if (ret == 0)
                                                break;
                                }
                        }
                }
                return min;
        }

        int minCut(string s) {
                int n = s.size();
                mret = s.size()-1;
                if (n <= 1)
                        return 0;
                e = s.c_str() + s.size();
                int r =  helper(s.c_str(), n-1, 0);
                return r;
        }
};

int main()
{
        //string str("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi");
        string str("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp");
        //string str("12321");
        Solution s;
        int r = s.minCut(str);
        cout << r << endl;
        //cout << sizeof(str.begin()) << endl;
        return 0;
}
