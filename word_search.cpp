#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
        struct state {
                int i;
                int j;
                string::iterator k;
                int s;
                state(int a, int b, string::iterator c, int d) {
                        i = a;
                        j = b;
                        k = c;
                        s = d;
                };
        };

        bool valid(int i, int j, vector<vector<char> > &board) {
                if (i == -1 || j == -1 ||
                    i == int(board.size()) || j == int(board[0].size()) ||
                    board[i][j] == -1)
                        return false;
                else
                        return true;
        }

        bool dfs(int i, int j, string word, vector<vector<char> > &board) {
                string::iterator k = word.begin();
                vector<vector<char> > mk(board);
                stack<state> stk;
                stk.push(state(i, j, k, 0));
                while (!stk.empty()) {
                        state ta = stk.top();stk.pop();
                        int ii = ta.i;
                        int jj = ta.j;
                        string::iterator kk = ta.k;
                        int s = (ta.s)++;
                        stk.push(ta);

                        if (s == 0) {
                                if (*kk != board[ii][jj])
                                        stk.pop();
                                else {
                                        ta.k++;
                                        mk[ii][jj] = -1;
                                        if (ta.k == word.end())
                                                return true;
                                        if (valid(ii-1, jj, mk))
                                                stk.push(state(ii-1, jj, kk+1, 0));
                                }
                        } else if (s == 1) {
                                if (valid(ii, jj-1, mk)) {
                                        stk.push(state(ii, jj-1, kk+1, 0));
                                }
                        } else if (s == 2) {
                                if (valid(ii, jj+1, mk)) {
                                        stk.push(state(ii, jj+1, kk+1, 0));
                                }
                        } else if (s == 3) {
                                if (valid(ii+1, jj, mk)) {
                                        stk.push(state(ii+1, jj, kk+1, 0));
                                }
                        } else {//4
                                stk.pop();
                                mk[ii][jj] = 0;
                        }

                }
                return false;
        }

        bool exist(vector<vector<char> > &board, string word) {
                //1. the first point
                if (board.size() == 0 || board[0].size() == 0)
                        return false;
                if (word.size() == 0)
                        return true;

                for (int i = 0; i < int(board.size()); i++) {
                        for (int j = 0; j < int(board[0].size()); j++) {
                                if (board[i][j] == word[0] && dfs(i, j, word, board))
                                        return true;
                        }
                }
                return false;
        }
};


int main()
{
        int i;
        string str("1234");
        vector<vector<char> > b;

        b.push_back(vector<char>());
        for (i = 0; i < int(str.size()); i++)
                b.back().push_back(str[i]);

        str = string("4567");
        b.push_back(vector<char>());
        for (i = 0; i < int(str.size()); i++)
                b.back().push_back(str[i]);

        str = string("8901");
        b.push_back(vector<char>());
        for (i = 0; i < int(str.size()); i++)
                b.back().push_back(str[i]);


        Solution s;
        int r = s.exist(b, string("125489"));
        cout << r << endl;
        return 0;
}
