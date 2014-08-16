#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
        void merge(int A[], int m, int B[], int n) {
            int i = m-1;
            int j = n-1;
            int k = m+n-1;
            while (i >= 0 && j >= 0) {
                if (A[i] < B[j]) {
                    A[k--] = B[j--];
                } else {
                    A[k--] = A[i--];
                }
            }
            while (i >= 0) {
                A[k--] = A[i--];
            }
            while (j >= 0) {
                A[k--] = B[j--];
            }
        }
};

int main()
{
/*
        int a[64];
        int b[128];
        memset(b, 0, sizeof(b));
        for (int i = 0; i < 64; i++)
                a[i] = 64*i*i;

        for (int i = 0; i < 64; i++)
                b[i] = 18*i;
*/

        int a[] = {1,0};
        int b[] = {2};
        Solution s;
        s.merge(a, 1, b, 1);
        
        return 0;
}
