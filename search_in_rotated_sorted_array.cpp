#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
        int search(int A[], int n, int target) {
                if (n == 0)
                        return -1;
                if (A[0] <= A[n-1]) {
                        int *r = lower_bound(A, A+n, target);
                        if (r == A+n)
                                return -1;
                        if (*r != target)
                                return -1;
                        return r-A;
                } else {
                        int mid = n/2;
                        int mv = A[mid];
                        if (mv == target)
                                return mid;
                        if (A[0] <= mv) {
                                if (A[0] <= target && target < mv)
                                        return search(A, mid, target);
                                else {
                                        int r = search(A+mid+1, n-mid-1, target);
                                        if (r == -1)
                                                return r;
                                        else
                                                return mid+1+r;
                                }       
                        } else {
                                if (mv < target && target <= A[n-1]) {
                                        int r = search(A+mid+1, n-mid-1, target);
                                        if (r == -1)
                                                return r;
                                        else
                                                return mid+1+r;
                                } else
                                        return search(A, mid, target);
                        }
                }
        
        }
};

int main()
{
        int a[] = {3,5,1};
        Solution s;
        auto r = s.search(a, 3, 1);
        cout << r << endl;
        return 0;
}
