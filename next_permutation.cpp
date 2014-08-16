#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::iterator vii;
class Solution {
public:
        void reverse(vii b, vii e) {
                while (b < e) {
                        int t = *b;
                        *b = *e;
                        *e = t;
                        b++;
                        e--;
                }
        }

        void nextPermutation(vector<int> &num) {

                if (num.size() == 1)
                        return;
                vii i;
                vii ii;
                ii = num.end()-1;
                i = ii-1;
                while (i >= num.begin() && *i >= *ii) {
                        i--;
                        ii--;
                }
                if (ii == num.begin()) {
                        reverse(num.begin(), num.end()-1);
                        return;
                } else {
                        vii iii = num.end()-1;
                        while (iii != ii && *iii <= *i) {
                                iii--;
                        }
                        //switch iii and i
                        int t = *iii;
                        *iii = *i;
                        *i = t;
                        reverse(ii, num.end()-1);
                }

        }
};

int main()
{
        Solution s;
        int a[] = {1,2,3};
        vector<int> vi(a, sizeof(a)/sizeof(a[0]) + a);
        int k = 10;
        do {
                for (int i = 0; i < vi.size(); i++) {
                        cout << vi[i] << ' ';
                }
                cout << endl;
                s.nextPermutation(vi);
        } while(k--);
        return 0;
}
