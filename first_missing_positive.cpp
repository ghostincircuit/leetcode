#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
        int firstMissingPositive(int A[], int n) {
                for (int i = 0; i < n; i++) {
                        if (A[i] != i+1) {
                                if (A[i] > n || A[i] < 1) {
                                } else {
                                        int tid = A[i] -1;
                                        int t = A[tid];
                                        if (t != A[i]) {
                                                A[tid] = A[i];
                                                A[i] = t;
                                                i--;
                                        }
                                }
                        }
                }

                int i;
                for (i = 0; i < n; i++) {
                        if (A[i] != i+1)
                                break;
                }
                return i+1;
        }
};

int main()
{

        Solution s;

        int a0[] = {-3};
        assert(1 == s.firstMissingPositive(a0, sizeof(a0)/sizeof(a0[0])));

        int a1[] = {1,2,3,5,6,7};
        assert(4 == s.firstMissingPositive(a1, sizeof(a1)/sizeof(a1[0])));

        int a2[] = {1,2,3,4,5,6,7};
        assert(8 == s.firstMissingPositive(a2, sizeof(a2)/sizeof(a2[0])));

        int a3[] = {0,1,2};
        assert(3 == s.firstMissingPositive(a3, sizeof(a3)/sizeof(a3[0])));

        int a4[] = {1,1,2};
        assert(3 == s.firstMissingPositive(a4, sizeof(a4)/sizeof(a4[0])));

        return 0;
}
