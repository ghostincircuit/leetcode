#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
        int minCut(string s) {
                int n = s.size();
                if (n <= 1)
                        return 0;

                int *dp = new int[n+1];
                int *strs = new int[n*n];
                for (int i = 0;  i< n*n; i++)
                        strs[i] = 0;

                dp[0] = 0;
                dp[1] = 0;
                
                
                for (int i = 0; i < n; i++) {
                        for (int r = 0; i-r>=0  && i+r<=n-1; r++) {
                                if (s[i+r] == s[i-r])
                                        strs[(i-r)*n+i+r] = 1;
                                else
                                        break;
                        }
                }

                for (int i = 0; i < n; i++) {
                        for (int r = 0; i-r>=0  && i+1+r<=n-1; r++) {
                                if (s[i+1+r] == s[i-r])
                                        strs[(i-r)*n+i+r+1] = 1;
                                else
                                        break;
                        }
                }

                for (int i = 2; i <= n; i++) {
                        if (strs[i-1]) {
                                dp[i] = 0;
                                continue;
                        }
                        int min = 9999999;
                        for (int j = 0; j < i; j++) {
                                int r;
                                if (strs[(j)*n+(i-1)])
                                        r = dp[j] + 1;
                                else
                                        r = 9999999;
                                min = min < r ? min : r;
                        }
                        dp[i] = min;
                }
                return dp[n];
        }
};

int main()
{
        //string str("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi");
        string str("cabababcbc");
        Solution s;
        int r = s.minCut(str);
        cout << r << endl;
        return 0;
}
