#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <map>
using namespace std;

struct UndirectedGraphNode {
        int label;
        vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x) : label(x) {};
};

typedef vector<UndirectedGraphNode *>::iterator vi;

class Solution {
public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
                if (!node)
                        return NULL;
                UndirectedGraphNode *ch = new UndirectedGraphNode(node->label);
                pair<UndirectedGraphNode *, UndirectedGraphNode *> np(node, ch);
                map<UndirectedGraphNode *, UndirectedGraphNode *> set;
                set.insert(np);
                queue<pair<UndirectedGraphNode *, UndirectedGraphNode *>> q;
                q.push(np);

                while (!q.empty()) {
                        pair<UndirectedGraphNode *, UndirectedGraphNode *> t = q.front();q.pop();

                        for (vi i = t.first->neighbors.begin(); i != t.first->neighbors.end(); i++) {
                                if (set.find(*i) == set.end()) {
                                        UndirectedGraphNode *tmp = new UndirectedGraphNode((*i)->label);
                                        pair<UndirectedGraphNode *, UndirectedGraphNode *> tp = pair<UndirectedGraphNode *, UndirectedGraphNode *>(*i, tmp);
                                        set.insert(tp);
                                        t.second->neighbors.push_back(tmp);
                                        q.push(pair<UndirectedGraphNode *, UndirectedGraphNode *>(tp));
                                } else {
                                        t.second->neighbors.push_back(set[*i]);
                                }
                        }
                }
                return ch;

        }
};

void print(UndirectedGraphNode *n)
{
        if (!n)
                return;
        if (n->label != -1)
                cout << n->label << " ";
        else
                return;
        n->label = -1;
        for (vi i = n->neighbors.begin(); i != n->neighbors.end(); i++) {
                print(*i);
        }
}

int main()
{
/*
        UndirectedGraphNode *n0 = new UndirectedGraphNode(0);
        UndirectedGraphNode *n1 = new UndirectedGraphNode(1);
        UndirectedGraphNode *n2 = new UndirectedGraphNode(2);
        UndirectedGraphNode *n3 = new UndirectedGraphNode(3);
        UndirectedGraphNode *n4 = new UndirectedGraphNode(4);

        n0->neighbors.push_back(n1);
        n0->neighbors.push_back(n2);
        n1->neighbors.push_back(n3);
        n2->neighbors.push_back(n4);
        n4->neighbors.push_back(n4);
*/

        UndirectedGraphNode *n0 = new UndirectedGraphNode(0);

        Solution s;

        UndirectedGraphNode *ne = s.cloneGraph(n0);
        print(ne);
        return 0;
}
