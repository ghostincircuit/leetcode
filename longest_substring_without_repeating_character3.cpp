#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
        int lengthOfLongestSubstring(string s) {
                if (s.size() == 0)
                        return 0;
                vector<int> dict(256, -1);
                dict[s[0]] = 0;
                int max = 1;
                int front = 0;
                int i;
                for (i = 1; i < int(s.size()); i++) {
                        unsigned char c = s[i];
                        if (dict[c] == -1) {
                        } else if (dict[c]+1 > front){
                                front = dict[c] + 1;
                        }
                        dict[c] = i;
                        if (i-front+1 > max)
                                max = i-front+1;
                }
                return max;
        }
};

int main()
{
        Solution s;

        string str("1");
        assert(1 == s.lengthOfLongestSubstring(str));

        str = string("12");
        assert(2 == s.lengthOfLongestSubstring(str));

        str = string("12345");
        assert(5 == s.lengthOfLongestSubstring(str));

        str = string("wlrbmqbhcdarzowkk");
        assert(12 == s.lengthOfLongestSubstring(str));
 
        return 0;
}
