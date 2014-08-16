#include <iostream>
using namespace std;

class Solution {
public:
        void sortColors(int A[], int n) {
                int *b = A;
                int *e = A+n-1;
                while (1) {
                        while (*b == 0 && b <= e)
                                b++;
                        if (b > e) {
                                break;
                        }
                        while (*e != 0 && b <= e)
                                e--;
                        if (b > e)
                                break;
                        int tmp = *b;
                        *b = *e;
                        *e = tmp;
                        b++;
                        e--;
                }
                if (b < A+n) {
                        e = A+n-1;
                        while (1) {
                                while (*b == 1 && b <= e)
                                        b++;
                                if (b > e) {
                                        break;
                                }
                                while (*e != 1 && b <= e)
                                        e--;
                                if (b > e)
                                        break;
                                int tmp = *b;
                                *b = *e;
                                *e = tmp;
                                b++;
                                e--;
                        }
                }
        }
};

int main()
{
        int r[] = {2,0};
        int n = sizeof(r)/sizeof(r[0]);
        Solution s;
        s.sortColors(r, n);
        for (int i = 0; i < n; i++)
                cout << r[i] << ' ';
        cout << endl;
        return 0;
}
