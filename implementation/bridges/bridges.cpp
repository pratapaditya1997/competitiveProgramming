/* 
 * Author: aps
 * Time: 2019-10-27 21:03:47
**/
#include<bits/stdc++.h>
 
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
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

const int N = 1e4+4;

vi g[N];
vector<bool> vis;
vi tin,low;
int dfsTimer;

void isBridge(int from, int to) {
    cout << from << " - " << to << "\n";
}

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = dfsTimer++;

    for(int to: g[v]) {
        if(to == p) continue;
        if(vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to,v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v]) {
                isBridge(v,to);
            }
        }
    }
}

void findBridges(int n) {
    dfsTimer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);

    for(int i=0; i<n; i++) {
        if(!vis[i]) dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    findBridges(n);
    
    return 0;
}
