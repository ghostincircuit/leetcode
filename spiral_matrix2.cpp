#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
        vector<vector<int> > generateMatrix(int n) {
                vector<vector<int> > ret(n, vector<int>(n, 0));
                int px = 0;
                int py = 0;
                int dir = 0;
                for (int i = 1; i <= n*n; i++) {
                        while (1) {
                                int done = 0;
                                switch(dir) {
                                case 0:
                                        if (px == n || ret[py][px]) {
                                                px--;
                                                dir = 1;
                                                py++;
                                        } else {
                                                ret[py][px++] = i;
                                                done = 1;
                                        }
                                        break;
                                case 1:
                                        if (py == n || ret[py][px]) {
                                                py--;
                                                px--;
                                                dir = 2;
                                        } else {
                                                ret[py++][px] = i;
                                                done = 1;
                                        }
                                        break;
                                case  2:
                                        if (px == -1 || ret[py][px]) {
                                                px++;
                                                py--;
                                                dir = 3;
                                        } else {
                                                ret[py][px--] = i;
                                                done = 1;
                                        }
                                        break;
                                case 3:
                                        if (py == -1 || ret[py][px]) {
                                                py++;
                                                px++;
                                                dir = 0;
                                        } else {
                                                ret[py--][px] = i;
                                                done = 1;
                                        }
                                        break;
                                }
                                if (done)
                                        break;
                        }
                }
                return ret;
        }
};

int main()
{
        Solution s;
        const int n = 4;
        vector<vector<int> >ret = s.generateMatrix(n);

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cout << ret[i][j] << ' ';
                }
                cout << endl;
        }
        cout << endl;
        
        return 0;
}
