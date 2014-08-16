#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
        int lower_bound(int A[], int n, int target) {
                int *h = A;
                while (n) {
                        int nn = n>>1;
                        if (target <= h[nn]) {
                                n = nn;
                        } else {
                                h = h + nn + 1;
                                n = n - nn - 1;
                        }
                }
                return h - A;
        }

        int upper_bound(int A[], int n, int target) {
                int *h = A;
                while (n) {
                        int nn = n>>1;
                        if (h[nn] <= target) {
                                h = h + nn + 1;
                                n = n - nn - 1;
                        } else {
                                n = nn;
                        }
                }
                return h - A;
        }

        vector<int> searchRange(int A[], int n, int target) {
                int l = lower_bound(A, n, target);
                int h = upper_bound(A, n, target);
                vector<int> ret;

                if (n == 0) {
                        ret.push_back(-1);ret.push_back(-1);
                        return ret;
                }

                if (n == 1) {
                        if (target == A[0]) {
                                ret.push_back(0);ret.push_back(0);
                                return ret;
                        } else {
                                ret.push_back(-1);ret.push_back(-1);
                                return ret;
                        }
                }

                if (l == n || A[l] != target)
                        l = -1;

                if (A[h-1] != target || h == 0)
                        h = -1;
                else
                        h -= 1;

                ret.push_back(l);ret.push_back(h);
                return ret;
        }
};

int main()
{
        //int a[] = {0,0,0,1,2,3,3,3,4,5,6,6,6,7,7};
        int a[] = {1, 5};
        //int a[] = {};
        Solution s;
        vector<int> ret = s.searchRange(a, sizeof(a)/sizeof(a[0]), 4);
        cout << ret[0] << ", " << ret[1] << endl;
        return 0;
}
