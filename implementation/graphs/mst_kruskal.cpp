#include<bits/stdc++.h>
using namespace std;

class dsu {
    public:
    vector<int> p, sz;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        sz.resize(n);
        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(x != y) {
            if (sz[x] < sz[y]) {
                swap(x, y);
            }
            p[y] = x;
            sz[x] += sz[y];
            return true;
        }
        return false;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

int n;
vector<Edge> edges;

int kruskal() {
    int cost = 0;
    vector<Edge> res;
    
    dsu d(n);
    sort(edges.begin(),edges.end());
    for (Edge e: edges) {
        if (d.get(e.u) != d.get(e.v)) {
            cost += e.w;
            res.push_back(e);
            d.unite(e.u, e.v);
        }
    }

    return cost;
}