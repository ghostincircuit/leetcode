#include <cstdio>
#include <vector>
#include <map>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

class Solution {
public:
        int w;
        int h;
        vector<pii> bdr;
        int depth;
        stack<pii> stk;

        void dfs1(int i, int j, vector<vector<char>> &board) {
                pii t = pii(i, j);
                stk.push(t);
                while (!stk.empty()) {
                        t = stk.top();stk.pop();
                        i = t.first;
                        j = t.second;
                        if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                                bdr.push_back(pii(i, j));
                                board[i][j] = 'x';
                                continue;
                        } else {
                                //mark first
                                board[i][j] = 'x';

                                if (i != 0 && board[i-1][j] == 'O') {
                                        //dfs1(i-1, j, board);
                                        stk.push(pii(i-1, j));
                                }
                                if (i != w-1 && board[i+1][j] == 'O') {
                                        //dfs1(i+1, j, board);
                                        stk.push(pii(i+1, j));
                                }
                                if (j != 0 && board[i][j-1] == 'O') {
                                        //dfs1(i, j-1, board);
                                        stk.push(pii(i, j-1));
                                }
                                if (j != w-1 && board[i][j+1] == 'O') {
                                        //dfs1(i, j+1, board);
                                        stk.push(pii(i, j+1));
                                }

                        }
                }
        }

        void dfs2(int i, int j, vector<vector<char>> &board) {
                pii t;
                stk.push(pii(i, j));
                while (!stk.empty()) {
                        t = stk.top();stk.pop();
                        i = t.first;
                        j = t.second;
                        if (board[i][j] == 'O')
                                continue;

                        board[i][j] = 'O';
                        if (i != 0 && board[i-1][j] == 'x') {
                                //dfs2(i-1, j, board);
                                stk.push(pii(i-1, j));
                        }
                        if (i != h-1 && board[i+1][j] == 'x') {
                                //dfs2(i+1, j, board);
                                stk.push(pii(i+1, j));
                        }
                        if (j != 0 && board[i][j-1] == 'x') {
                                //dfs2(i, j-1, board);
                                stk.push(pii(i, j-1));
                        }
                        if (j != w-1 && board[i][j+1] == 'x') {
                                //dfs2(i, j+1, board);
                                stk.push(pii(i, j+1));
                        }
                }
        }

        void solve(vector<vector<char>> &board) {
                h = board.size();
                if (h)
                        w = board[0].size();
                else
                        w = 0;
                for (int i = 0; i < h; i++) {
                        for (int j = 0; j < w; j++) {
                                if (board[i][j] == 'O') {
                                        depth = 0;
                                        dfs1(i, j, board);
                                }
                        }
                }

                while (!bdr.empty()) {
                        pii t = bdr.back();bdr.pop_back();
                        depth = 0;
                        dfs2(t.first, t.second, board);
                }

                for (int i = 0; i < h; i++) {
                        for (int j = 0; j < w; j++) {
                                if (board[i][j] == 'x')
                                        board[i][j] = 'X';
                        }
                }

        }
};

int main()
{

#if 0
        const int N = 3;
        const char *map0 = "OOO";
        const char *map1 = "OOO";
        const char *map2 = "OOO";
        vector<vector<char>> tst = {
                vector<char>(map0, map0+N),
                vector<char>(map1, map1+N),
                vector<char>(map2, map2+N),
        };

#endif

#if 0
        const int N = 3;
        const char *map0 = "XOX";
        const char *map1 = "OXO";
        const char *map2 = "XOX";
        vector<vector<char>> tst = {
                vector<char>(map0, map0+N),
                vector<char>(map1, map1+N),
                vector<char>(map2, map2+N),
        };

#endif


#if 0
        const int N = 5;
        const char *map0 = "XXXXX";
        const char *map1 = "XOOOX";
        const char *map2 = "XXXXX";
        const char *map3 = "XOOOX";
        const char *map4 = "OOXXX";

        vector<vector<char>> tst = {
                vector<char>(map0, map0+N),
                vector<char>(map1, map1+N),
                vector<char>(map2, map2+N),
                vector<char>(map3, map3+N),
                vector<char>(map4, map4+N),
        };

#endif

#if 0
        const int N = 2;
        const char *map0 = "XX";
        const char *map1 = "XO";

        vector<vector<char>> tst = {
                vector<char>(map0, map0+N),
                vector<char>(map1, map1+N),
        };
#endif

#if 0
        const int N = 1;
        const char *map0 = "O";

        vector<vector<char>> tst = {
                vector<char>(map0, map0+N),
        };
#endif

#if 0
        const int N = 0;
        vector<vector<char>> tst = { };
#endif

#if 0
        const int N = 6;
        const char *map0 = "XOXOXO";
        const char *map1 = "OXOXOX";
        const char *map2 = "XOXOXO";
        const char *map3 = "OXOXOX";

        vector<vector<char>> tst = {
                vector<char>(map0, map0+N),
                vector<char>(map1, map1+N),
                vector<char>(map2, map2+N),
                vector<char>(map3, map3+N),
        };

#endif

#if 0
        const int N = 6;
        const char *map0 = "OOOOOO";
        const char *map1 = "OXXXXO";
        const char *map2 = "OXOOXO";
        const char *map3 = "OXOOXO";
        const char *map4 = "OXXXXO";
        const char *map5 = "OOOOOO";

        vector<vector<char>> tst = {
                vector<char>(map0, map0+N),
                vector<char>(map1, map1+N),
                vector<char>(map2, map2+N),
                vector<char>(map3, map3+N),
                vector<char>(map4, map4+N),
                vector<char>(map5, map5+N),
        };

#endif

#if 0
        const int N = 202;
        vector<vector<char>> tst;
        vector<char> allo(N, 'O');

        vector<char> r1;
        r1.push_back('O');
        for (int i = 0; i < N-2; i++)
                r1.push_back('X');
        r1.push_back('O');

        vector<char> r2;
        r2.push_back('O');
        r2.push_back('X');
        for (int i = 0; i < N-4; i++)
                r2.push_back('O');
        r2.push_back('X');
        r2.push_back('O');

        tst.push_back(allo);
        tst.push_back(r1);

        for (int i = 0; i < N-4; i++)
                tst.push_back(r2);

        tst.push_back(r1);
        tst.push_back(allo);

#endif


#if 0
        const int N = 200;
        vector<vector<char>> tst;
        vector<char> allo(N, 'O');

        vector<char> lef;
        lef.push_back('O');
        for (int i = 0; i < N-1; i++)
                lef.push_back('X');

        vector<char> rig;
        for (int i = 0; i < N-1; i++)
                rig.push_back('X');
        rig.push_back('O');

        int st = 0;
        for (int i = 0; i < N; i++) {
                if (st == 0)
                        tst.push_back(allo);
                if (st == 1)
                        tst.push_back(lef);
                if (st == 2)
                        tst.push_back(rig);
                st++;
                if (st == 3)
                        st = 0;
        }
#endif

        Solution s;
        s.solve(tst);

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        printf("%c", tst[i][j]);
                }
                printf("\n");
        }
        printf("\n");
        return 0;
}
