#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
        int maxSubArray(int A[], int n) { 
                int sum;
                int max = sum = A[0]; 
                for (int i = 1; i < n; i++) {
                        sum = sum > 0 ? (A[i] + sum) : A[i]; 
                        max = std::max(max, sum); 
                }
                return max;
        }
};


int main()
{
        int a[] = {-1,-1,2,1,-2,3,-2,-2,-2};
        //int a[] = {0};
        Solution s;
        int ret = s.maxSubArray(a, sizeof(a)/sizeof(a[0]));
        cout << ret << endl;
        return 0;
}
