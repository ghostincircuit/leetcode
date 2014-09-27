#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
        vector<vector<int> > top, bot;
        void helper1(vector<vector<char> > &matrix) {
                auto h = matrix.size();
                auto w = matrix[0].size();

                top = vector<vector<int> >(h, vector<int>(w+1, 0));
                bot = vector<vector<int> >(h, vector<int>(w+1, 0));
                for (auto i = 0; i < w; i++) {
                        auto j = 0;
                        while (1) {
                                for (; j < h; j++) {
                                        if (matrix[j][i] == '0')
                                                bot[j][i] = 0;
                                        else
                                                break;
                                }
                                if (j == h)
                                        break;
                                int cnt = 1;
                                bot[j][i] = cnt;
                                j++;
                                while(j != h && matrix[j][i] == '1') {
                                        cnt++;
                                        bot[j][i] = cnt;
                                        j++;
                                }
                                if (j == h)
                                        break;
                        }
                        j = h-1;
                        while (1) {
                                for (; j != -1; j--) {
                                        if (matrix[j][i] == '0')
                                                top[j][i] = 0;
                                        else
                                                break;
                                }
                                if (j == -1)
                                        break;
                                int cnt = 1;
                                top[j][i] = cnt;
                                j--;
                                while(j != -1 && matrix[j][i] == '1') {
                                        cnt++;
                                        top[j][i] = cnt;
                                        j--;
                                }
                                if (j == -1)
                                        break;
                        }

                }

        }

        struct node {
                int u,l,d;
                node (int uu, int ll, int dd) {u = uu; l = ll; d = dd;}
        };

        int helper2(vector<int>& bot, vector<int>& top) {
                int n = bot.size();
                stack<node> stk;
                stk.push(node(-1, -1, -1));
                int max = 0;
                for (int i = 0; i < n; i++) {
                        node cur(bot[i], top[i], i);
                        if (stk.top().u <= cur.u &&
                            stk.top().l <= cur.l)
                                stk.push(cur);
                        else {
                                node pr(0,0,0);
                                while (!stk.empty() &&
                                       !(stk.top().u <= cur.u &&
                                         stk.top().l <= cur.l)) {
                                        pr = stk.top(); stk.pop();
                                        int s = (i - pr.d) * (pr.u + pr.l - 1);
                                        max = s > max ? s : max;
                                }
                                cur.u = cur.u > pr.u ? pr.u : cur.u;
                                cur.l = cur.l > pr.l ? pr.l : cur.l;
                                cur.d = pr.d;
                                stk.push(cur);
                        }
                }
                return max;
        }

        int maximalRectangle(vector<vector<char> > &matrix) {
                if (matrix.size() == 0)
                        return 0;
                helper1(matrix);
                int h = matrix.size();
                int max = 0;
                for (int i = 0; i < h; i++) {
                        auto sum = helper2(top[i], bot[i]);
                        max = sum > max ? sum : max;
                }
                return max;
        }
};

int main()
{
        vector<string > m = {
                "01101",
                "11010",
                "01110",
                "11110",
                "11111",
                "00000",
        };

        m = {
                "1111",
                "1110",
                "1111",
                "1111",
                "1111",
        };

        m = {
                "101001110",
                "111000001",
                "001100011",
                "011001001",
                "110110010",
                "011111101",
                "101110010",
                "111010001",
                "011110010",
                "100111000",
        };

        vector<vector<char> > mm(m.size(), vector<char>(m[0].size()));
        for (int i = 0; i < m.size(); i++)
                for (int j = 0; j < m[0].size(); j++) {
                        mm[i][j] = m[i][j];
                }

        Solution s;
        cout << s.maximalRectangle(mm);
        return 0;
}
