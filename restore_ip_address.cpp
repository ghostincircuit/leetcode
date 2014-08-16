#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
        const char *str;
        int n;

        int atoi(const char *begin, const char *end) {
                int sum = 0;
                if (*begin == '0' && end - begin > 1)
                        return -1;
                while (begin != end) {
                        sum = sum * 10 + *begin - '0';
                        begin++;
                }
                if (sum < 256)
                        return sum;
                else
                        return -1;
        }

        vector<string> restoreIpAddresses(string s) {
                str = s.c_str();
                n = s.size();
                vector<string> ret;
                if (n > 3*4)
                        return ret;
                if (n < 4)
                        return ret;

                for (int i = 1; i <= n-3; i++) {
                        for (int j = i+1; j <= n-2; j++) {
                                for (int k = j+1; k <= n-1; k++) {
                                        int slot[4];
                                        slot[0] = atoi(str, str+i);
                                        slot[1] = atoi(str+i, str+j);
                                        slot[2] = atoi(str+j, str+k);
                                        slot[3] = atoi(str+k, str+n);
                                        if (slot[0] < 0 ||
                                            slot[1] < 0 ||
                                            slot[2] < 0 ||
                                            slot[3] < 0) {
                                                //invalid
                                        } else {
                                                string t =
                                                        string(str, str+i) + string(".") +
                                                        string(str+i, str+j) + string(".") +
                                                        string(str+j, str+k) + string(".") +
                                                        string(str+k, str+n);
                                                ret.push_back(t);
                                        }
                                }
                        }
                }
                return ret;
        }
};

int main()
{
        vector<string> ret;


        //string t("25525511135");
        string t("010010");
        //string t("0000");


        Solution s;
        ret = s.restoreIpAddresses(t);
        
        for (int i = 0; i < ret.size(); i++)
                cout << ret[i] << endl;
        return 0;
}
