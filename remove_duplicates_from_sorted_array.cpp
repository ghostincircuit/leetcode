#include <iostream>
using namespace std;

class Solution {
public:
        int removeDuplicates(int A[], int n) {
                if (!n)
                        return 0;

                int p = 1;
                for (int i = 1; i < n; i++) {
                        if (A[i] != A[i-1])
                                A[p++] = A[i];
                }
                return p;
        }
};

int main()
{
        Solution s;
        int r[] = {0,1};
        int k = s.removeDuplicates(r, sizeof(r)/sizeof(r[0]));
        for (int i = 0; i < k; i++)
                cout << r[i] << ' ';
        cout << endl << endl << k << endl;
        return 0;
}
