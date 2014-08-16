#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
        vector<int> rec;
        void build_prefix(char *needle) {
                if (needle == NULL || needle[0] == 0)
                        return;

                rec.push_back(-1);

                int k = -1;
                for (int q = 1; needle[q]; q++) {
                        while(k != -1 && needle[k+1] != needle[q]) {
                                k = rec[k];
                        }

                        if (needle[k+1] == needle[q])
                                k++;
                        rec.push_back(k);
                }
        }

        char *strStr(char *haystack, char *needle) {
                build_prefix(needle);
                if (!rec.size())
                        return haystack;

                int k = -1;
                for (int i = 0; haystack[i]; i++) {
                        while(k != -1 && haystack[i] != needle[k+1]) {
                                k = rec[k];
                        }
                        if (needle[k+1] == haystack[i])
                                k++;
                        if (needle[k+1] == 0) {
                                return haystack + i-k;
                        }
                }
                return NULL;
        }
};

int main()
{
        char *t = "";
        char *p = "";

        Solution s;
        
        char *r = s.strStr(t, p);
        cout << t << endl;
        cout << r << endl;
        return 0;
}
