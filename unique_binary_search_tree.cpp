#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
        Solution() {
                cache.insert(make_pair(0, 1));
                cache.insert(make_pair(1, 1));
        }
        unordered_map<int, int> cache;
        int numTrees(int n) {
                auto r = cache.find(n);
                if (r != cache.end())
                        return r->second;

                int m = n-1;
                int sum = 0;
                for (int i = 0; i <= m; i++) {
                        auto l = numTrees(i);
                        auto r = numTrees(m-i);
                        sum += l*r;
                }
                return sum;
        }
};

int main()
{
        Solution s;
        for (auto i = 0; i < 4; i++)
                cout << i << ": " << s.numTrees(i) << endl;
        return 0;
}
