#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
        void rotate(vector<vector<int> > &matrix) {
                int n = matrix.size();
                int x2 = n-1;
                int x1 = 0;
                int y1 = 0;
                int y2 = n-1;

                while (x1 < x2) {
                        int nn = x2-x1;
                        for (int i = 0; i < nn; i++) {
                                int save1, save2, save3;
                                save1 = matrix[y1+i][x2];
                                matrix[y1+i][x2] = matrix[y1][x1+i];
                                save2 = matrix[y2][x2-i];
                                matrix[y2][x2-i] = save1;
                                save3 = matrix[y2-i][x1];
                                matrix[y2-i][x1] = save2;
                                matrix[y1][x1+i] = save3;
                        }
                        x1++;
                        x2--;
                        y1++;
                        y2--;

                }
        }
};

void dp(vector<vector<int> >& in)
{
        int n = in.size();
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        printf("%02d ", in[i][j]);
                }
                cout << endl;
        }
        cout << endl;
}

int main()
{
        int n = 4;
        vector<vector<int> > in(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        in[i][j] = n*i+j;
                }
        }

        dp(in);
        Solution s;
        s.rotate(in);

        dp(in);

        return 0;
}
