class Solution {

public:

    vector<int> tmp;

    vector<vector<int> > ret;

    void helper(int start, int end, int k) {

        if (k == 0) {

            ret.push_back(tmp);

            return;

        }

        for (auto i = start; i <= end-k; i++) {

            tmp.push_back(i+1);

            helper(i+1, end, k-1);

            tmp.pop_back();

        }

            

    }

    vector<vector<int> > combine(int n, int k) {

        helper(0, n, k);

        return ret;

    }

};
