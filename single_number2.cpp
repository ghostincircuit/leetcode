#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
        int singleNumber(int A[], int n) {
                unordered_map<int, int> hash(n);
                unordered_map<int, int>::iterator j;
                typedef pair<int, int> pii;
                for (int i = 0; i < n; i++) {
                        j = hash.find(A[i]);
                        if (j == hash.end()) {
                                pii t(A[i], 1);
                                hash.insert(t);
                        } else if (j->second == 2){
                                hash.erase(j);
                        } else {
                                j->second++;
                        }
                }
                return hash.begin()->first;
        }
};

int main()
{
        //int a[] = {1,1,1,2,2,2,3,3,3,4,5,5,5};
        int a[] = {2};
        Solution s;
        cout << s.singleNumber(a, sizeof(a)/sizeof(a[0])) << endl;
        return 0;
}
