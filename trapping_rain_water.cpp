#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
        int helper(int A[], int n) {
                if (n <= 2)
                        return 0;
                int max = -1;
                int sec = -1;
                vector<int> mv;
                vector<int> sv;
                for (int i = 0; i < n; i++) {
                        if (A[i] > max) {
                                sec = max;
                                sv = vector<int>(mv);
                                max = A[i];
                                mv.clear();
                                mv.push_back(i);
                        } else if (A[i] == max) {
                                mv.push_back(i);
                        } else if (A[i] > sec) {
                                sec = A[i];
                                sv.clear();
                                sv.push_back(i);
                        } else if (A[i] == sec) {
                                sv.push_back(i);
                        } else {
                                //nothing happen, drop
                        }
                }
                int b;
                int e;

                int level;
                if (mv.size() > 1) {
                        b = mv[0];
                        e = mv.back()+1;
                        level = max;
                } else if (sv.size() == 1) {
                        b = mv[0];
                        e = sv[0];
                        if (b > e) {
                                int t = b;
                                b = e;
                                e = t;
                        }
                        e++;
                        level = sec;
                } else if (sv.size() > 1) {
                        b = sv[0];
                        e = sv.back();
                        b = sv[0] < mv[0] ? sv[0] : mv[0];
                        e = sv.back() < mv[0] ? mv[0] : sv.back();
                        level = sec;
                }

                //count on range [b, e)
                int sum = 0;
                for (int k = b; k < e; k++) {
                        if (A[k] < level) {
                                sum += (level - A[k]);
                        }
                }

                //count [0, b) and [e, n)
                int r1 = helper(A, b+1);
                int r2 = helper(A+e-1, n-e+1);
                return sum + r1 + r2;
        }

        int trap(int A[], int n) {
                return helper(A, n);
        }
};

int main()
{
        int a[] = {3,2,2,5,2,2,3};

        Solution s;
        int r = s.trap(a, sizeof(a)/sizeof(a[0]));
        cout << r << endl;
        return 0;
}
