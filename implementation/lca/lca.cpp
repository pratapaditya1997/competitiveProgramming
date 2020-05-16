#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
 
const ll inf = 1e18;
const ll mod = 1e9+7;
 
inline ll add(ll x, ll y) { x += y; if (x >= mod) x -= mod; return x;}
inline ll sub(ll x, ll y) { x -= y; if (x < 0) x += mod; return x;}
inline ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod;}
inline ll gcd(ll x, ll y) { return x == 0 ? y : gcd(y % x, x); }
inline ll power(ll a, ll b) {
    ll x = 1;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline ll inv(ll a) { return power(a, mod - 2);}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+5;
vector<int> g[N];

int n,l,timer;
vi tin,tout;
vvi up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for(int i=1; i<=l; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(int u: g[v]) {
        if(u != p) dfs(u,v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if(is_ancestor(u,v)) return u;
    if(is_ancestor(v,u)) return v;
    for(int i=l; i>=0; i--) {
        if(!is_ancestor(up[u][i],v)) u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vi(l+1));
    dfs(root, root);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    return 0;
}