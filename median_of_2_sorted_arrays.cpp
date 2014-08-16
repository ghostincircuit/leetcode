#include <iostream>
#include <cassert>
using namespace std;

#define INT_MIN ((-1)<<31)
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
class Solution {
public:
        int findKth(int A[], int m, int B[], int n, int k) {
                if (m == 0)
                        return B[k];
                if (n == 0)
                        return A[k];

                if (n == 1 && m == 1) {
                        if (k == 0)
                                return min(A[0], B[0]);
                        else
                                return max(A[0], B[0]);
                }
                

                assert(m+n > k);
                int i = k*m/(m+n);
                int j = k-i;
                if (j >= n) {
                        j = n-1;
                        i = k-j;
                }
                assert(i < m);
                assert(j < n);
                assert(i >= 0);
                assert(j >= 0);

                int Ai_1 = (i == 0) ? INT_MIN : A[i-1];
                int Bj_1 = (j == 0) ? INT_MIN : B[j-1];
                if (Ai_1 <= B[j] && B[j] <= A[i]) {
                        return B[j];
                } else if (Bj_1 <= A[i] && A[i] <= B[j]) {
                        return A[i];
                } else if (A[i] < B[j]) {//also A[i] < B[j-1]
                        //exclude A[i] and below
                        return findKth(A+i+1, m-i-1, B, j, k-i-1);
                } else if (B[j] < A[i]) {//also B[j] < A[j-1]
                        //exclude B[j] and above
                        return findKth(A, i, B+j+1, n-j-1, k-j-1);
                } else {
                        assert(0);
                }

        }

        double findMedianSortedArrays(int A[], int m, int B[], int n) {
                if ((m + n)%2 == 0) {
                        int i = findKth(A, m, B, n, (m+n)/2);
                        int j = findKth(A, m, B, n, (m+n)/2-1);
                        return double(i + j)/2;
                } else {
                        return findKth(A, m, B, n, (m+n)/2);
                }
        }
};

int main()
{
/*
        int a[] = {1};
        int b[] = {1};
*/

/*
        int a[] = {1,2,3};
        int b[] = {1,2};
*/

/*
        int a[] = {1,2,3};
        int b[] = {4,5,6};
*/

///*
        int a[] = {2};
        int b[] = {1};
//*/

        Solution s;
        double r = s.findMedianSortedArrays(a,
                                            sizeof(a)/sizeof(a[0]),
                                            b,
                                            sizeof(b)/sizeof(b[0]));
        cout << r << endl;

        return 0;
}
