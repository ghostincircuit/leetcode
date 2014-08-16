#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
        vector<string> fullJustify(vector<string> &words, int L) {
                vector<string>::iterator i, b;
                int state = 0;
                int sz;
                int cnt;
                vector<string> ret;
                if (words.size() == 0)
                        return ret;

                for (i = words.begin(); i != words.end(); i++) {
                        if (state == 0) {
                                b = i;
                                state = 1;
                                sz = i->size();
                                cnt = 1;
                        } else {
                                if (i->size() + sz + cnt > L) {
                                        int blks = L - sz;
                                        int bps;
                                        string t;

                                        if (cnt == 1) {
                                                bps = 0;
                                                t.append(*b);
                                                t.append(L-t.size(), ' ');
                                        } else {
                                                bps = blks / (cnt-1);
                                                int rb = blks - bps*(cnt-1);
                                                while (b != i-1) {
                                                        t.append(*b);
                                                        if (rb > 0) {
                                                                t.append(bps+1, ' ');
                                                                rb--;
                                                        } else
                                                                t.append(bps, ' ');
                                                        b++;
                                                }
                                                t.append(*(i-1));
                                        }
                                        ret.push_back(t);
                                        b = i;
                                        sz = i->size();
                                        cnt = 1;
                                        state = 1;
                                } else {
                                        sz += i->size();
                                        cnt++;
                                }
                        }
                }
                ret.push_back(string());
                while (b != i) {
                        ret.back().append(*b);
                        if (ret.back().size() != L)
                                ret.back().append(1, ' ');
                        b++;
                }
                if (ret.back().size() != L) {
                        ret.back().append(L-ret.back().size(), ' ');
                }

                return ret;
        }
};


int main()
{
        Solution s;
        vector<string> iw;

        iw.push_back("12");
        iw.push_back("1");
        iw.push_back("12");
        iw.push_back("12");
        iw.push_back("12");
        iw.push_back("12");
        iw.push_back("12");


        vector<string> ret = s.fullJustify(iw, 7);
        for (int i = 0; i < ret.size(); i++) {
                cout << ret[i] << '|' << endl;
        }
        
        return 0;
}
