#include <cstring>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
        int longest;
        int e;
        unsigned char dict[256];
        vector<unsigned char> uc;

        int find_sub(int i) {
                memset(dict, 0, sizeof(dict));
                int j = i;
                while (j < e) {
                        if (dict[uc[j]] == 1)
                                return j-i;
                        else {
                                dict[uc[j]] = 1;
                                j++;
                        }
                }
                return j-i;
        }

        int lengthOfLongestSubstring(string s) {
                unsigned char w;
                longest = 0;
                e = s.end() - s.begin();
                for (int i = 0; i < s.size(); i++)
                        uc.push_back(s[i] + 128);

                int n = s.size();
                int i = 0;
                while (n-i > longest) {
                        int ret = find_sub(i);
                        if (ret > longest)
                                longest = ret;
                        i++;
                }
                return longest;
        }
};

int main()
{
        string str("12");
        Solution s;
        printf("%d\n", s.lengthOfLongestSubstring(str));
        return 0;
}
