#include <cassert>
#include <iterator>

class Solution {
public:
        int kth(int A[], int m, int B[], int n, int k) {
                int m2 = m/2;
                int n2 = n/2;
                int am = A[m2];
                int bn = B[n2];
                int b4 = m2 + n2 + 1;
                if (m == 0) {
                        return B[k];
                }
                if (n == 0) {
                        return A[k];
                }
                if (k > b4) {
                        if (am <= bn)
                                return kth(A+m2+1, m-m2-1, B, n, k-(m2+1));
                        else
                                return kth(A, m, B+n2+1, n-n2-1, k-(n2+1));
                }
                if (k < b4) {
                        if (am <= bn)
                                return kth(A, m, B, n2, k);
                        else
                                return kth(A, m2, B, n, k);
                } else {
                        if (am <= bn) {
                                if (m2+1 == m || bn <= A[m2+1])
                                        return bn;
                                else
                                        return kth(A, m, B, n2, k);
                        } else {
                                if (n2+1 == n || am <= B[n2+1])
                                        return am;
                                else
                                        return kth(A, m2, B, n, k);
                        }
                }

        }
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
                int all = m+n;
                if (all % 2 == 0) {
                        auto l = kth(A, m, B, n, all/2);
                        auto r = kth(A, m, B, n, all/2-1);
                        return (l + r)*.5;
                } else {
                        auto l = kth(A, m, B, n, all/2);
                        return (l);
                }
                return 0;
        }
};

int main()
{
        auto r = 0.0;
        Solution s;
        int A[] = {1,1};
        int B[] = {1,1};
        int az = std::end(A)-std::begin(A);
        int bz = std::end(B)-std::begin(B);

        int E[] = {1,3,4};
        int F[] = {2};
        int ez = std::end(E)-std::begin(E);
        int fz = std::end(F)-std::begin(F);        
        r = s.findMedianSortedArrays(E, ez, F, fz);
        assert(r == 2.5);


        int C[] = {0,1,2,3,4,10,11,12};
        int D[] = {5,6,7,8,9,13,14};
        int cz = std::end(C)-std::begin(C);
        int dz = std::end(D)-std::begin(D);

        for (auto i = 0; i < cz+dz; i++) {
                r = s.kth(C, cz, D, dz, i);
                assert(r == i);
        }
        r = s.findMedianSortedArrays(A, az, B, bz);
        assert(r == 1);
        return 0;
}
