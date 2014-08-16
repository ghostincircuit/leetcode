#include <iostream>

using namespace std;

class Solution {
public:
        int removeDuplicates(int A[], int n) {
                int b = 0;
                if (n <= 2)
                        return n;

                int state = 0;
                int last = A[0];
                A[b++] = last;
                for (int i = 1; i < n; i++) {
                        if (state == 0) {
                                A[b++] = A[i];
                                if (A[i] == last) {
                                        state = 1;
                                } else {
                                        state = 0;
                                }
                        } else if (state == 1) {
                                if (last != A[i]) {
                                        state = 0;
                                        A[b++] = A[i];
                                }
                        }
                        last = A[i];
                }
                return b;
        }
};

int main()
{
        //int a[] = {0,0,0,0,0,0,1,2,2,3,3,3,4,4,4,4,4,4};
        int a[] = {1,1,1,2,2,2};

        Solution s;
        int r = s.removeDuplicates(a, sizeof(a)/sizeof(a[0]));
        cout << r << endl;
        for (int i = 0; i < r; i++)
                cout << a[i] << ' ';
        cout << endl;
        return 0;
}
