#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
        int *getm(int A[], int n) {
                if (n <= 1)
                        return A;

                if (n == 2) {
                        if (A[0] <= A[1])
                                return A;
                        else
                                return A+1;
                }
                int mid = n/2;
                //n>2

                if (A[0] < A[n-1])
                        return A;

                else if (A[0] > A[n-1]) {
                        int m = A[mid];
                        if (m <= A[n-1]) {
                                return getm(A, mid+1);
                        } else {
                                return getm(A+mid+1, n-mid-1);
                        }
                } else {
                        int m = A[mid];
                        if (m > A[0]) {
                                return getm(A+mid+1, n-mid-1);
                        } else if (m < A[0]) {
                                return getm(A, mid+1);
                        } else {
                                int *r1 = getm(A+mid+1, n-mid-1);
                                if (r1 != (A+mid+1))
                                        return r1;
                                int *r0 = getm(A, mid+1);
                                return r0;
                        }
                }
        }
        bool search(int A[], int n, int target) {
                int *m = getm(A, n);
                auto r = lower_bound(A, m, target);
                if (r != m && *r == target)
                        return true;
                r = lower_bound(m, A+n, target);
                if (r == A+n || *r != target)
                        return false;
                else
                        return true;
        }
};

int main()
{
        int a[] = {1,1,1,3,1};
        Solution s;
        auto r = s.search(a, std::end(a)-std::begin(a), 3);
        cout << r << endl;
        return 0;
}
