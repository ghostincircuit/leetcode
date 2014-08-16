#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
        int helper(string& a) {
                int sum = 0;
                int sign = 1;
                int i = 0;
                if (a[0] == '-') {
                        sign = -1;
                        i = 1;
                } else if (a[0] == '+') {
                        i = 1;
                }
                for (; i < a.size(); i++) {
                        sum = sum * 10 + (a[i] - '0');
                }
                return sum*sign;
        }

        int evalRPN(vector<string> &tokens) {
                stack<int> stk;
                vector<string>::iterator vsi = tokens.begin();
                while (vsi != tokens.end()) {
                        if (*vsi == string("+")) {
                                int r1 = stk.top();stk.pop();
                                int r0 = stk.top();stk.pop();
                                stk.push(r0+r1);
                        } else if (*vsi == string("-")) {
                                int r1 = stk.top();stk.pop();
                                int r0 = stk.top();stk.pop();
                                stk.push(r0-r1);
                        } else if (*vsi == string("*")) {
                                int r1 = stk.top();stk.pop();
                                int r0 = stk.top();stk.pop();
                                stk.push(r0*r1);
                        } else if (*vsi == string("/")) {
                                int r1 = stk.top();stk.pop();
                                int r0 = stk.top();stk.pop();
                                stk.push(r0/r1);
                        } else {//number
                                int tmp = helper(*vsi);
                                stk.push(tmp);
                        }
                        vsi++;                        
                }
                return stk.top();
        }
};

int main()
{
        vector<string> str;
        str.push_back(string("48"));
        str.push_back(string("12"));
        str.push_back(string("12"));
        str.push_back(string("+"));
        str.push_back(string("/"));
        
        
        Solution s;
        int r = s.evalRPN(str);
        cout << r << endl;
        return 0;
}
