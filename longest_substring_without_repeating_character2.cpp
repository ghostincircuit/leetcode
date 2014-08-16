#include <cstring>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const int N = 256;
class Solution {
public:
        int table[256];
        int longest;

        int find_update(int ref, int now) {
                int min = ref;
                for (int i = 0; i < 256; i++) {
                        if (table[i] >= 0 && ref >= table[i]) {
                                if (table[i] < min) {
                                        min = table[i];
                                }
                                if (ref == table[i])
                                        table[i] = now;
                                else
                                        table[i] = -1;
                        }
                }
                return now - min;
        }

        int lengthOfLongestSubstring(string s) {
                longest = 0;
                int i;
                int n = s.size();
                memset(table, 0xff, sizeof(table));

                for (i = 0; i < n; i++) {
                        if (table[s[i]] >= 0) {
                                int le = find_update(table[s[i]], i);
                                if (le > longest)
                                        longest = le;
                        } else {
                                table[s[i]] = i;
                        }
                }
                int le = find_update(i, i);
                if (le > longest)
                        longest = le;
                return longest;

        }
};

int main()
{
        //string str("111234555");
        //string str("1231abcdd");
        //string str("12331");
        string str("wlrbbmqbhcdarzowkkyhi");
        Solution s;
        int k = s.lengthOfLongestSubstring(str);
        printf("%d\n", k);
        return 0;
}
