#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
        int singleNumber(int A[], int n) {
                unordered_map<int, int> mp;
                for (int i = 0; i < n; i++) {
                        unordered_map<int, int>::iterator j = mp.find(A[i]);
                        if (j == mp.end()) {
                                mp.insert(pair<int, int>(A[i], 1));
                        } else {
                                mp.erase(j);
                        }
                }
                return mp.begin()->first;
        }
};

int main()
{
        //int a[] = {1,2,3,4,5,6,7,1,3,4,5,6,7};
        int a[] = {1,2,1};
        Solution s;
        int r = s.singleNumber(a, sizeof(a)/sizeof(a[0]));
        cout << r <<endl;
}
