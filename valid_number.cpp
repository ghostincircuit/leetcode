#include <iostream>
using namespace std;

class Solution {
public:
        bool sign(const char **pp) {
                const char *h = *pp;
                if (*h == '+' || *h == '-') {
                        *pp = h+1;
                        return true;
                } else
                        return false;
        }

        bool e(const char **pp) {
                if (**pp == 'e') {
                        (*pp)++;
                        return true;
                }
                return false;
        }

        bool integer(const char **pp) {
                const char *h = *pp;
                while (*h != 0) {
                        if ('0' <= *h && *h <= '9')
                                h++;
                        else
                                break;
                }
                if (*pp == h)
                        return false;
                else {
                        *pp = h;
                        return true;
                }
        }
        
        bool dot(const char **pp) {
                if (**pp == '.') {
                        (*pp)++;
                        return true;
                } else
                        return false;
        }
        bool terminate(const char **pp) {
                const char *h = *pp;
                while (*h != 0) {
                        if (*h == ' ')
                                h++;
                        else
                                return false;
                }
                return true;
        }
        bool isNumber(const char *s) {
                while (*s == ' ') {
                        s++;
                }
                const char *h = s;
                const char *save;
                int state = 0;
                int ret = 0;
                while (1) {
                        switch (state) {
                        case 0:
                                sign(&h);
                                state = 1;
                                break;
                        case 1:
                                save = h;
                                if (dot(&h)) {
                                        state = 2;
                                        break;
                                }

                                h = save;
                                if (integer(&h)) {
                                        state = 3;
                                        break;
                                }
                                
                                 //other things
                                ret = -1;
                                break;
                        case 2:
                                if (integer(&h)) {
                                        state = 5;
                                        break;
                                }
                                ret = -1;
                                break;
                        case 3:
                                save = h;
                                if (dot(&h)) {
                                        state = 4;
                                        break;
                                }
                                h = save;
                                if (terminate(&h)) {
                                        ret = 2;
                                        break;
                                }
                                state = 5;
                                break;
                        case 4:
                                save = h;
                                if (integer(&h)) {
                                        state = 5;
                                        break;
                                }
                                h = save;
                                if (terminate(&h)) {
                                        ret = 2;
                                        break;
                                }
                                h = save;
                                state = 5;
                                break;
                        case 5:
                                save = h;
                                if (terminate(&h)) {
                                        ret = 2;
                                        break;
                                }
                                h = save;
                                if (e(&h)) {
                                        state = 8;
                                        break;
                                }
                                ret = -1;
                                break;
                        case 6:
                                if (integer(&h)) {
                                        state = 7;
                                        break;
                                }
                                ret = -1;
                                break;
                        case 7:
                                if (terminate(&h)) {
                                        ret = 2;
                                        break;
                                }
                                ret = -1;
                                break;
                        case 8:
                                sign(&h);
                                state = 6;
                                break;
                        } 
                        if (ret != 0)
                                break;
                }
                if (ret == -1)
                        return false;
                else
                        return true;
                
        }
};

int main()
{
        const char str[] = "456e+3 ";
        Solution s;
        bool r = s.isNumber(str);
        cout << r << endl;
        return 0;
}
