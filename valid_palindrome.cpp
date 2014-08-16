#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
        int helper(char a) {
                if (('0' <= a && a <= '9') ||
                    ('a' <= a && a <= 'z'))
                        return a;
                else if ('A' <= a && a <= 'Z')
                        return a - 'A'+'a';
                else
                        return -1;
        }

        bool isPalindrome(string s) {
                if (s.size() <= 1)
                        return true;

                string::iterator b = s.begin();
                string::iterator e = s.end()-1;
                while (b < e) {
                        while (helper(*b) == -1 && b != e)
                                b++;
                        while (helper(*e) == -1 && b != e)
                                e--;
                        if (b == e)
                                return true;
                        else {
                                if (helper(*b) == helper(*e)) {
                                        b++;
                                        e--;
                                } else {
                                        return false;
                                }
                        }

                }
                return true;

        }
};


int main()
{
        //string str("a b  acac aba");
        string str("aA");

        Solution s;
        bool r = s.isPalindrome(str);
        cout << r << endl;
        return 0;
}
