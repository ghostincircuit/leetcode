class Solution {

public:

    bool next_perm(vector<int>& v) {

        auto oe = v.end();

        oe--;

        auto e = oe;

        auto pe = e;

        pe--;

        auto b = v.begin();

        while (pe >= b && *pe >= *e) {

            e--;

            pe--;

        }

        auto se = e;

        while (e < oe) {

            std::swap(*e, *oe);

            e++;

            oe--;

        }

        if (se == v.begin())

            return true;

        while (*se <= *pe)

            se++;

        std::swap(*se, *pe);

        return false;

    }

    vector<vector<int> > permute(vector<int> &num) {

        vector<vector<int> > ret;

        vector<int> co = num;

        std::sort(co.begin(), co.end());

        ret.push_back(co);

        while (1) {

            bool r = next_perm(co);

            if (r)

                return ret;

            else {

                ret.emplace_back(co);

            }

        }

    }

};
