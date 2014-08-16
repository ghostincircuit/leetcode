#include <list>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
        int longestConsecutive(vector<int> &num) {
                unordered_map<int, list<pair<int, int> >::iterator> lb;
                unordered_map<int, list<pair<int, int> >::iterator> ub;
                list<pair<int, int> > vp;
                unordered_set<int> st;
                int n = num.size();
                if (n <= 1)
                        return n;

                st.insert(num[0]);
                vp.push_back(pair<int, int>(num[0], num[0]));
                lb.insert(pair<int, list<pair<int, int> >::iterator>(num[0], --(vp.end())));
                ub.insert(pair<int, list<pair<int, int> >::iterator>(num[0], --(vp.end())));
                for (int i = 1; i < n; i++) {
                        int t = num[i];
                        pair<int, int> mp;
                        if (st.find(t) != st.end()) {
                                continue;
                        } else {
                                st.insert(t);
                        }

                        if (lb.find(t+1) != lb.end() && ub.find(t-1) != ub.end()) {
                                //merge
                                list<pair<int, int> >::iterator ll = (list<pair<int, int> >::iterator)lb.find(t+1)->second;
                                list<pair<int, int> >::iterator uu = (list<pair<int, int> >::iterator)ub.find(t-1)->second;
                                pair<int, int> lp = *ll;
                                pair<int, int> up = *uu;
                                lb.erase(lp.first);
                                lb.erase(up.first);
                                ub.erase(lp.second);
                                ub.erase(up.second);
                                vp.erase(ll);
                                vp.erase(uu);
                                mp = pair<int, int>(up.first, lp.second);

                        } else if (lb.find(t+1) != lb.end()) {
                                list<pair<int, int> >::iterator ll = lb.find(t+1)->second;
                                pair<int, int> lp = *ll;
                                lb.erase(lp.first);
                                ub.erase(lp.second);
                                vp.erase(ll);
                                mp = pair<int, int>(t, lp.second);

                        } else if (ub.find(t-1) != ub.end()) {
                                list<pair<int, int> >::iterator uu = ub.find(t-1)->second;
                                pair<int, int> up = *uu;
                                lb.erase(up.first);
                                ub.erase(up.second);
                                vp.erase(uu);
                                mp = pair<int, int>(up.first, t);

                        } else {
                                mp = pair<int, int>(t, t);
                        }

                        vp.push_back(mp);
                        lb.insert(pair<int, list<pair<int, int> >::iterator>(mp.first, --(vp.end())));
                        ub.insert(pair<int, list<pair<int, int> >::iterator>(mp.second, --(vp.end())));
                }
                
                int max  = 1;
                for (list<pair<int, int>>::iterator i = vp.begin(); i != vp.end(); i++) {
                        if (max < (i->second - i->first + 1))
                                max = (i->second - i->first + 1);
                }
                return max;
        }
};

int main()
{
        Solution s;
        //int arr[] = {1,2,3,4,0,-1,-2,-3};
        //int arr[] = {6,7, 2,4,3, 9,8};
        //int arr[] = {1,3,5,2,4};
        //int arr[] = {1,3,5,7,9,11,13,15, 2,4};
        int arr[] = {7,5 ,4,2, 0, 1, 3, 6};
        vector<int> a(arr, arr+sizeof(arr)/sizeof(arr[0]));
        int r = s.longestConsecutive(a);
        cout << r << endl;
        return 0;
}
