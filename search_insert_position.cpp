#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
        int searchInsert(int A[], int n, int target) {
                int *h = A;
                while (n) {
                        int n2 = n>>1;
                        if (target <= h[n2]) {
                                n = n2;
                        } else {
                                n = n - n2 - 1;
                                h = h + n2 + 1;
                        }
                }
                return h-A;
        }
};

int main()
{
        int a[] = {0,0,1,2,3,4,5,6,7};
        int n = sizeof(a)/sizeof(a[0]);
        Solution s;
        assert(s.searchInsert(a, n, 0) == 0);
        assert(s.searchInsert(a, n, 1) == +2);
        assert(s.searchInsert(a, n, 2) == +3);
        assert(s.searchInsert(a, n, 7) == n-1);
        assert(s.searchInsert(a, n, 8) == n);

        return 0;
}
