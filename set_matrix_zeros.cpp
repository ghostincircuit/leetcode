#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
        void setZeroes(vector<vector<int> > &matrix) {
                int m = matrix.size();
                int n = 0;
                if (m)
                        n = matrix[0].size();
                if (!m || !n)
                        return;

                int i, j;
                for (i = 0; i < m; i++) {
                        for (j = 0; j < n; j++) {
                                if (matrix[i][j] == 0)
                                        goto out;
                        }
                }
        out:
                if (i == m || j == n)
                        return;

                int sm = i;
                int sn = j;

                for (int i = 0; i < m; i++) {
                        for (int j = 0; j < n; j++) {
                                if (matrix[i][j] == 0) {
                                        matrix[sm][j] = 0;
                                        matrix[i][sn] = 0;
                                }
                        }
                }

                for (int i = 0; i < n; i++) {
                        if (i == sn)
                                continue;
                        if (matrix[sm][i] == 0)
                                for (int k = 0; k < m; k++)
                                        matrix[k][i] = 0;
                }
                
                for (int i = 0; i < m; i++) {
                        if (matrix[i][sn] == 0)
                                for (int k = 0; k < n; k++)
                                        matrix[i][k] = 0;
                }
                for (int i = 0; i < m; i++)
                        matrix[i][sn] = 0;

        }
};

void pm(vector<vector<int> >&r)
{
        for (int i = 0; i < int(r.size()); i++) {
                for (int j = 0; j < int(r[i].size()); j++)
                        cout << r[i][j] << ' ';
                cout << endl;
        }
        cout << endl;
}

int main()
{
        const int N = 1;
        const int M = 2;
        Solution s;
        vector<vector<int> > m(M, vector<int>(N, 0));
        int seed = 0;
        for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                        m[i][j] = seed++%9;
                }
        }
        pm(m);
        s.setZeroes(m);
        pm(m);
        return 0;

}
