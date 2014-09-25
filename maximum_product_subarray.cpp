#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
class Solution {
public:
    int maxProduct(int A[], int n) {
        int max = A[0];
        int sn = 1;
        int sp = 1;
        for (int i = 0; i < n; i++) {
            int cur = A[i];
            int nsn = min(sn*cur, sp*cur);
            int nsp = max(sn*cur, sp*cur);
            sn = min(cur, nsn);
            sp = max(cur, nsp);
            if (max < sp)
                max = sp;
        }
        return max;
    }
};

int main()
{
        Solution s;
        int A[] = {2,-1,2};
        auto r = s.maxProduct(A, 3);
        return 0;
}
