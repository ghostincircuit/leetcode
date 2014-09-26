#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class Solution {
public:
        string tmp;
        void deal(char sym[], int b) {
                if (b == 9) {
                        tmp.push_back(sym[0]);
                        tmp.push_back(sym[2]);
                } else if (b >= 5) {
                        auto i = b-5;
                        tmp.push_back(sym[1]);
                        while (i--) {
                                tmp.push_back(sym[0]);
                        }
                } else if (b == 4) {
                        tmp.push_back(sym[0]);
                        tmp.push_back(sym[1]);
                } else {
                        while (b--) {
                                tmp.push_back(sym[0]);
                        }
                }
        }

        string intToRoman(int num) {
                char th[] = "CDM";
                char hu[] = "XLC";
                char te[] = "IVX";
                auto t = num/1000;
                for (int i = 0; i < t; i++)
                        tmp.push_back('M');

                num -= t*1000;
                t = num /100;
                deal(th, t);
                num -= t*100;
                t = num / 10;
                deal(hu, t);
                num -= t*10;
                t = num;
                deal(te, t);
                return tmp;
        }
};

int main()
{
        Solution s;
        cout << s.intToRoman(3444) << endl;
        return 0;
}
