#include <string>
#include <iostream>

using namespace std;

#if 0
class Solution {
public:
        
        void reverseWords(string &s) {
                typedef string::iterator si;
                string n;
                si e = s.end()-1;
                si b;
                while (1) {
                        //jump blank
                        while (e >= s.begin() && *e == ' ') {
                                e--;
                        }
                        if (e < s.begin())
                                break;

                        //get the word front
                        for (b = e; b >= s.begin() && *b != ' '; b--)
                                ;

                        //copy
                        si m;
                        m = b+1;

                        while (m <= e) {
                                n.push_back(*m);
                                m++;
                        }
                        n.push_back(' ');
                        e = b;
                }
                if (n.size())
                        n.pop_back();
                s = n;

        }
};

#elif 0


class Solution {
public:
        void reverseWords(string &s) {
                stringstream ss(s);
                stack<string> store;
                string item;
                while(getline(ss, item, ' ')){
                        if (item.size())
                                store.push(item);
                }
                s.clear();
                while (!store.empty()) {
                        s += (store.top() + ' ');
                store.pop();
                }
                if (s.size())
                        s.pop_back();
        }
};

#elif 1

class Solution {
public:
        void reverseWords(string &s) {
                string ret;
                int state = 0;
                string::iterator e;
                if (s.size() == 0)
                        return;
                for (string::iterator i = s.end()-1;
                     i >= s.begin();
                     i--) {
                        switch (state) {
                        case 0:
                                if (*i == ' ' || *i == '\t')
                                        state = 0;
                                else {
                                        state = 1;
                                        e = i+1;
                                }
                                break;
                        case 1:
                                if (*i == ' ' || *i == '\t') {
                                        state = 0;
                                        ret.append(i+1, e);
                                        ret.push_back(' ');
                                } else {
                                        state = 1;
                                }
                                break;
                                        
                        }
                }
                if (state == 1) {
                        ret.append(s.begin(), e);
                } else if (ret.size()){
                        ret.pop_back();
                }
                s = ret;
        }
};


#endif

int main()
{
        //string str("    1 2 3");
        string str("");
        cout << str << endl;
        Solution s;
        s.reverseWords(str);
        cout << str << endl;
        return 0;
}
