#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
        string getPermutation(int n, int k) {
                static const int tab[9] = {0, 1, 5, 23, 119, 719, 5039, 40319, 362879};
                k--;
                int mod = tab[n-1] + 1;
                k = k % mod;
                int i;
                for (i = 0; k >= tab[i]; i++)
                        ;
                i--;
                int left = k - tab[i];
                int nn = n;
                int array[] = {1,2,3,4,5,6,7,8,9};
                int *tail = array + n-1;
                int *head = tail - i;
                while (head < tail) {
                        std::swap(*head, *tail);
                        head++;
                        tail--;
                }
                while (left--) {
                        next_perm(array, nn);
                }
                string str;
                for (i = 0; i < n; i++)
                        str.push_back(array[i] + '0');
                return str;

        }
        void next_perm(int a[], int n) {
                int *tail = a+n-1;
                int *p = tail;
                while (a < p && *(p-1) >= *(p)) {
                        p--;
                }
                int *th = p;
                int *p2 = tail;
                while (p < p2) {
                        std::swap(*p, *p2);
                        p++;
                        p2--;
                }
                p = th;
                if (th == a)
                        return;

                while (p != a + n) {
                        if (*(th-1) < *p)
                                break;
                        p++;
                }
                std::swap(*p, *(th-1));
        }
};


int main()
{
/*
        int a[] = {1,2,3,4,5};
        for (auto i = 0; i < 33; i++) {
                cout << i << ": ";
                for (auto i = 0; i < 4; i++)
                        cout << a[i];
                cout << endl;
                Solution s;
                s.next_perm(a, 4);
        }
        return 0;
*/
        Solution s;
        for (auto i = 1; i < 32; i++) {
                auto r = s.getPermutation(9, i);
                cout << r << endl;
        }
        return 0;
}
