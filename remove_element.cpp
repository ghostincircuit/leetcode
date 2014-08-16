#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
        int removeElement(int A[], int n, int elem) {
                int j = 0;
                for (int i = 0; i < n; i++) {
                        if (elem == A[i]) {
                                
                        } else {
                                A[j++] = A[i];
                        }
                }
                return j;
        }
};

int main()
{
        int a[] = {1,3,0,0,34,3,0,3,0,22,22,3,3,3,0,1,2,3};
        Solution s;
        int r = s.removeElement(a, sizeof(a)/sizeof(a[0]), 0);
        assert(r == sizeof(a)/sizeof(a[0])-5);
        return 0;
}
