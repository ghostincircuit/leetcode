#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
        bool operator() (const Interval& a, const Interval& b) {
                if (a.start < b.start)
                        return true;
                else if (a.start == b.start && a.end < b.end)
                        return true;
                else
                        return false;
        }

        vector<Interval> merge(vector<Interval> &intervals) {
                vector<Interval> ret;
                if (intervals.size() <= 1)
                        return intervals;

                sort(intervals.begin(), intervals.end(), Solution());

                vector<Interval>::iterator vi = intervals.begin();
                Interval cur = *vi;
                for (vi++; vi != intervals.end(); vi++) {
                        if (vi->start <= cur.end) {//try merge
                                if (vi->end > cur.end)
                                        cur.end = vi->end;
                        } else {//can't merge
                                ret.push_back(cur);
                                cur = *vi;
                        }
                }
                ret.push_back(cur);
                return ret;
        }
};

int main()
{
        vector<Interval> t;


        t.push_back(Interval(0, 4));
        t.push_back(Interval(0, 0));
        t.push_back(Interval(0, 2));
        t.push_back(Interval(1, 5));


/*
        t.push_back(Interval(0, 0));
        t.push_back(Interval(1, 1));
        t.push_back(Interval(2, 3));
        t.push_back(Interval(3, 3));
*/
      
        Solution s;
        vector<Interval> ret = s.merge(t);

        for (int i = 0; i < ret.size(); i++) {
                cout << ret[i].start << ", " << ret[i].end << endl;
        }
        return 0;
}
