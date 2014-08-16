#include <cassert>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache{
        struct node {
                int val;
                list<int>::iterator p;
                node(int val, list<int>::iterator p) : val(val), p(p) {}
        };
public:
        unordered_map<int, node> up;
        list<int> q;
        int sz;
        int cap;
        LRUCache(int capacity) : up(capacity), sz(0), cap(capacity) {
        }

        int get(int key) {
                unordered_map<int, node>::iterator i;
                i = up.find(key);
                if (i != up.end()) {
                        q.erase(i->second.p);
                        q.insert(q.begin(), key);
                        i->second.p = q.begin();
                        return i->second.val;
                }
                return -1;
        }

        void set(int key, int value) {
                unordered_map<int, node>::iterator i;
                i = up.find(key);
                if (i != up.end()) {
                        q.erase(i->second.p);
                        up.erase(key);
                        sz--;
                }

                if (sz == cap){
                        int ak = q.back();q.pop_back();
                        up.erase(ak);
                        sz--;
                }
                q.insert(q.begin(), key);
                up.insert(pair<int, node>(key, node(value, q.begin())));
                sz++;

        }
};

int main()
{

/*
        LRUCache lru(2);
        lru.set(0, 0);
        lru.set(1, 1);
        assert(lru.get(0) == 0);
        assert(lru.get(1) == 1);
        lru.set(2, 2);
        assert(lru.get(0) == -1);
        assert(lru.get(1) == 1);
        assert(lru.get(2) == 2);
        assert(lru.get(1) == 1);
        lru.set(3,3);
        assert(lru.get(2) == -1);
        assert(lru.get(1) == 1);
        assert(lru.get(3) == 3);
*/

/*
        LRUCache lru(3);
        lru.set(1, 1);
        lru.set(2, 2);
        lru.set(3, 3);
        lru.set(4, 4);
        assert(4 == lru.get(4));
        assert(3 == lru.get(3));
        assert(2 == lru.get(2));
        assert(-1 == lru.get(1));

        lru.set(5, 5);
        assert(-1 == lru.get(1));
        assert(2 == lru.get(2));
        assert(3 == lru.get(3));
        assert(-1 == lru.get(4));
        assert(5 == lru.get(5));
*/

/*
        LRUCache lru(3);
        lru.set(1, 1);
        lru.set(2, 2);
        lru.set(3, 3);
        lru.set(4, 4);
        lru.get(4);
        lru.get(3);
        lru.get(2);
        lru.get(1);

        lru.set(5, 5);
        lru.get(1);
        lru.get(2);
        lru.get(3);
        lru.get(4);
        lru.get(5);
*/

/*
        LRUCache lru(10);
        lru.set(10, 13);
        lru.set(3, 17);
        lru.set(6, 11);
        lru.set(10, 5);
        lru.set(9, 10);
        lru.get(13);
        lru.set(2, 19);
        lru.get(2);
        lru.get(3);
        lru.set(5, 25);
        lru.get(8);
*/

        LRUCache lru(10);
        for (int i = 0; i < 1024; i++) {
                int idx = (i*i+i)%10;
                lru.set(idx, i);
        }

        for (int i = 0; i < 1024; i++) {
                lru.get(i);
        }


        return 0;
}
