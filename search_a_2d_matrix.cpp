#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
                int m = matrix.size();
                if (m == 0)
                        return false;
                int n = matrix[0].size();
                if (n == 0)
                        return false;
                int lower = 0;
                int upper = m;
                int mid;
                while (lower < upper) {
                        mid = (lower + upper)/2;
                        int left = matrix[mid][0];
                        int right = matrix[mid].back();
                        if (target < left)
                                upper = mid;
                        else if (right < target)
                                lower = mid+1;
                        else {
                                vector<int>::iterator k = lower_bound(matrix[mid].begin(), matrix[mid].end(), target);
                                if (k != matrix[mid].end() && *k == target)
                                        return true;
                                else
                                        return false;
                        }
                }
                return false;
        }
};

#define N 32

int main()
{
        vector<vector<int> > in;
        int base = 0;
        int i;
/*
        in.push_back(vector<int>());
        for (i = 0; i < N; i++) {
                in.back().push_back(i+base);
        }

        base = i+base+N;
        in.push_back(vector<int>());
        for (i = 0; i < N; i++) {
                in.back().push_back(i+base);
        }

        base = i+base+N;
        in.push_back(vector<int>());
        for (i = 0; i < N; i++) {
                in.back().push_back(i+base);
        }
*/

        Solution s;
        int r = s.searchMatrix(in, 94);
        cout << r << endl;


        return 0;
}
