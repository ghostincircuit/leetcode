#include <iostream>
#include <vector>

using namespace std;

struct Point {
        int x;
        int y;
        Point() : x(0), y(0) {}
        Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
        vector<Point> *p;
        int helper(int i, int j) {
                int x1 = (*p)[i].x;
                int y1 = (*p)[i].y;

                int x2 = (*p)[j].x;
                int y2 = (*p)[j].y;
                int dx = x2 - x1;
                int dy = y2 - y1;

                if (dx == dy && dx == 0)
                        return 2;
                int cnt = 0;
                for (int k = 0; k < p->size(); k++) {
                        if (i == k || j == k)
                                cnt++;
                        else {
                                int x = (*p)[k].x;
                                int y = (*p)[k].y;
                                int dxx = x - x1;
                                int dyy = y - y1;
                                if (dx == 0) {
                                        if (dxx != 0) {
                                        } else {
                                                cnt++;
                                        }
                                } else if (dxx == 0) {
                                        if (dyy == 0)
                                                cnt++;
                                } else if (((double)dy/dx) == ((double)dyy/dxx)) {
                                        cnt++;
                                }
                        }
                }
                return cnt;
        }

        int maxPoints(vector<Point> &points) {
                p = &points;
                if (points.size() <= 2)
                        return points.size();

                int j;
                for (j = 1; j < points.size(); j++)
                        if (points[0].x != points[j].x ||
                            points[0].y != points[j].y)
                                break;
                if (j == points.size())
                        return points.size();

                int max = 2;
                for (int i = 0; i < points.size()-1; i++) {
                        for (int j = i+1; j < points.size(); j++) {
                                int r = helper(i, j);
                                if (r > max)
                                        max = r;
                        }
                }
                return max;
        }
};

int main()
{
        vector<Point> points;
        points.push_back(Point(0,0));
        points.push_back(Point(0,0));
        points.push_back(Point(0,0));
        points.push_back(Point(0,0));
        points.push_back(Point(1,0));

        points.push_back(Point(1,1));
        points.push_back(Point(2,2));
        points.push_back(Point(3,3));

        Solution s;
        int r = s.maxPoints(points);
        cout << r << endl;
        return 0;
}
